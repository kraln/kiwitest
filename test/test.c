/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, You can
 * obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright 2013 KIWI.KI GmbH.
 */

#include "test.h"
#include <stdio.h>

bool test_verbose = false;

/*
 * Print out the provided name to the provided string, centered on a line
 * filled with dashes of length line_len.
 *
 * For example, if line_len is 15 and name is "hello", it would fill s with:
 * "---- hello ----"
 *
 * Note that this function isn't meant to be used externally, but it is
 * non-static so that the test harness unit tests can test it.
 */
void print_dashed_name_to_string(
  char *s, const char *name, const size_t name_len, const size_t line_len)
{
  size_t name_start = line_len / 2 - name_len / 2;
  /* We increment name_len by 1 here so that for odd name lengths, no
   * dimensional data is lost due to integer division. */
  size_t name_end = line_len / 2 + (name_len + 1) / 2;

  for (size_t i = 0; i < line_len; ++i)
  {
    if ((i >= name_start) && (i < name_end))
    {
      /* Since we are where the name will go, fill the string with the name. */
      *s++ = name[i - name_start];
    }
    else if ((i == name_start - 1) || (i == name_end))
    {
      /* Since we are around where the name will go, fill the string with
       * spaces. */
      *s++ = ' ';
    }
    else
    {
      /* Fill the string with dashes. */
      *s++ = '-';
    }
  }

  /* NUL-terminate the string. */
  *s = '\0';
}

static void print_dashed_name(
  const char *name, const size_t name_len, const size_t line_len)
{
  char line[120];
  print_dashed_name_to_string(line, name, name_len, line_len);
  printf("%s\n", line);
}

void test_runner(
  char *group_name, size_t group_name_len,
  size_t *pass_count, size_t *total_tests_ran,
  struct test test_list[], size_t num_tests)
{
  /* Keep track of the number of tests passed so that we can present
   * information about how many tests passed. */
  size_t runner_pass_count = 0;

  print_dashed_name(group_name, group_name_len, TEST_LINE_LEN);

  /* Run all the tests, printing out information about how things are going
   * along the way. */
  for (size_t i = 0; i < num_tests; ++i)
  {
    /* Run the test setup function, if it exists. */
    if (test_list[i].setup) test_list[i].setup();

    /* Print the name of the test now, just in case it hangs. This isn't
     * colored because we don't know if it will pass or fail yet. When it does
     * pass or fail, we'll print a '\r' to "erase" the non-colored print and
     * write over it with colored print. */
    printf("%s:", test_list[i].name);

    int failed = test_list[i].test();

    if (failed)
    {
      /* Display a detailed fail message for the failing test. */
      printf(
        "\r\e[1;%d;%dm%s:[%s]\e[0m\n",
        FOREGROUND_WHITE, BACKGROUND_RED,
        test_list[i].name, "FAIL"
      );
    }
    else
    {
      if (test_verbose)
      {
        /* Display a detailed pass message for the passing test. */
        printf(
          "\r\e[1;%d;%dm%s:[%s]\e[0m\n",
          FOREGROUND_WHITE, failed ? BACKGROUND_RED : BACKGROUND_GREEN,
          test_list[i].name, "PASS"
        );
      }

      /* Clear the line. Since we emitted some non-colored print for this test,
       * but we don't want to display very much print when not in verbose mode,
       * we need to erase the non-colored print. We do so by setting the cursor
       * to the start of the line and emitting spaces and resetting the cursor
       * back again. */
      printf("\r");
      for (int i = 0; i < TEST_LINE_LEN; ++i) printf(" ");
      printf("\r");
    }

    if (!failed) ++runner_pass_count;

    /* Run the test teardown function, if it exists. */
    if (test_list[i].teardown) test_list[i].teardown();
  }

  /* All tests have finished running, so display a summary of what happened. */
  printf(
    "\r\e[1;%d;%dm%lu/%lu %s tests passed.\e[0m\n\n",
    FOREGROUND_WHITE,
    runner_pass_count == num_tests ? BACKGROUND_GREEN : BACKGROUND_RED,
    runner_pass_count, num_tests,
    group_name
  );

  *pass_count += runner_pass_count;
  *total_tests_ran += num_tests;
}
