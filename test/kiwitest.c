/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, You can
 * obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright 2013 KIWI.KI GmbH.
 */

/*
 * Run all tests for this project.
 */

#include "test.h"

static void handle_command_line(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i)
  {
    if (argv[i][0] == '-')
    {
      switch (argv[i][1])
      {
        case 'v':
          test_verbose = true;
          break;
      }
    }
  }
}

/* If you provide "-v" on the command line, the test output will be more
 * verbose. */
int main(int argc, char *argv[])
{
  handle_command_line(argc, argv);

  TEST_INIT();

  RUN_TESTS(
    test,
    test_assert_true_pass,
    test_assert_true_fail,
    test_assert_false_pass,
    test_assert_false_fail,
    test_assert_gt_gt_with_lt,
    test_assert_gt_gt,
    test_assert_gt_lt,
    test_assert_gt_eq,
    test_assert_lt_lt_with_true,
    test_assert_lt_eq_with_true,
    test_assert_lt_gt,
    test_assert_lt_lt,
    test_assert_lt_eq,
    test_assert_ge_gt,
    test_assert_ge_lt,
    test_assert_ge_eq,
    test_assert_le_gt,
    test_assert_le_lt,
    test_assert_le_eq,
    test_assert_eq_gt_with_ne,
    test_assert_eq_gt,
    test_assert_eq_lt,
    test_assert_eq_eq,
    test_assert_ne_eq_with_gt,
    test_assert_ne_gt,
    test_assert_ne_lt,
    test_assert_ne_eq,
    print_dashed_name_to_string_odd_name_even_len,
    print_dashed_name_to_string_odd_name_odd_len,
    print_dashed_name_to_string_even_name_even_len,
    print_dashed_name_to_string_even_name_odd_len
  );

  TEST_FINALIZE();
}
