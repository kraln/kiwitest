/*
 * This Source Code Form is subject to the terms of the Mozilla Public License,
 * v. 2.0. If a copy of the MPL was not distributed with this file, You can
 * obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright 2013 KIWI.KI GmbH.
 */

#include <string.h> // strcmp

#ifndef TEST_ASSERTS_H
#define TEST_ASSERTS_H

#include "test_colors.h"

#define TEST_TRUE(condition) \
do { \
  if (!(condition)) \
  { \
    if (with_color) \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        "\r\e[1;%d;%dm" __FILE__ ":%d\nTest failed: '" #condition \
        "' (expected true, was false)\e[0m\n", \
        FOREGROUND_WHITE, BACKGROUND_RED, \
        __LINE__ \
      ); \
    } \
    else \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        __FILE__ ":%d\nTest failed: '" #condition \
        "' (expected true, was false)\n", \
        __LINE__ \
      ); \
    } \
    printf("%s", failure_message_buffer); \
    return 1; \
  } \
} while(0)

#define TEST_FALSE(condition) \
do { \
  if (condition) \
  { \
    if (with_color) \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        "\r\e[1;%d;%dm" __FILE__ ":%d\nTest failed: '" #condition \
        "' (expected false, was true)\e[0m\n", \
        FOREGROUND_WHITE, BACKGROUND_RED, \
        __LINE__ \
      ); \
    } \
    else \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        __FILE__ ":%d\nTest failed: '" #condition \
        "' (expected false, was true)\n", \
        __LINE__ \
      ); \
    } \
    printf("%s", failure_message_buffer); \
    return 1; \
  } \
} while(0)

#define TEST_GT(a, b) \
do { \
  if (!((a) > (b))) \
  { \
    if (with_color) \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        "\r\e[1;%d;%dm" __FILE__ ":%d\nTest failed: '" #a " > " #b \
        "' (" #a "=%d, " #b "=%d)\e[0m\n", \
        FOREGROUND_WHITE, BACKGROUND_RED, \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    else \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        __FILE__ ":%d\nTest failed: '" #a " > " #b \
        "' (" #a "=%d, " #b "=%d)\n", \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    printf("%s", failure_message_buffer); \
    return 1; \
  } \
} while(0)

#define TEST_LT(a, b) \
do { \
  if (!((a) < (b))) \
  { \
    if (with_color) \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        "\r\e[1;%d;%dm" __FILE__ ":%d\nTest failed: '" #a " < " #b \
        "' (" #a "=%d, " #b "=%d)\e[0m\n", \
        FOREGROUND_WHITE, BACKGROUND_RED, \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    else \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        __FILE__ ":%d\nTest failed: '" #a " < " #b \
        "' (" #a "=%d, " #b "=%d)\n", \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    printf("%s", failure_message_buffer); \
    return 1; \
  } \
} while(0)

#define TEST_GE(a, b) \
do { \
  if (!((a) >= (b))) \
  { \
    if (with_color) \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        "\r\e[1;%d;%dm" __FILE__ ":%d\nTest failed: '" #a " >= " #b \
        "' (" #a "=%d, " #b "=%d)\e[0m\n", \
        FOREGROUND_WHITE, BACKGROUND_RED, \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    else \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        __FILE__ ":%d\nTest failed: '" #a " >= " #b \
        "' (" #a "=%d, " #b "=%d)\n", \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    printf("%s", failure_message_buffer); \
    return 1; \
  } \
} while(0)

#define TEST_LE(a, b) \
do { \
  if (!((a) <= (b))) \
  { \
    if (with_color) \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        "\r\e[1;%d;%dm" __FILE__ ":%d\nTest failed: '" #a " <= " #b \
        "' (" #a "=%d, " #b "=%d)\e[0m\n", \
        FOREGROUND_WHITE, BACKGROUND_RED, \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    else \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        __FILE__ ":%d\nTest failed: '" #a " <= " #b \
        "' (" #a "=%d, " #b "=%d)\n", \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    printf("%s", failure_message_buffer); \
    return 1; \
  } \
} while(0)

#define TEST_EQ(a, b) \
do { \
  if (!((a) == (b))) \
  { \
    if (with_color) \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        "\r\e[1;%d;%dm" __FILE__ ":%d\nTest failed: '" #a " == " #b \
        "' (" #a "=%d, " #b "=%d)\e[0m\n", \
        FOREGROUND_WHITE, BACKGROUND_RED, \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    else \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        __FILE__ ":%d\nTest failed: '" #a " == " #b \
        "' (" #a "=%d, " #b "=%d)\n", \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    printf("%s", failure_message_buffer); \
    return 1; \
  } \
} while(0)

#define TEST_NE(a, b) \
do { \
  if (!((a) != (b))) \
  { \
    if (with_color) \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        "\r\e[1;%d;%dm" __FILE__ ":%d\nTest failed: '" #a " != " #b \
        "' (" #a "=%d, " #b "=%d)\e[0m\n", \
        FOREGROUND_WHITE, BACKGROUND_RED, \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    else \
    { \
      snprintf( \
        failure_message_buffer, \
        sizeof(failure_message_buffer), \
        __FILE__ ":%d\nTest failed: '" #a " != " #b \
        "' (" #a "=%d, " #b "=%d)\n", \
        __LINE__, (int)a, (int)b \
      ); \
    } \
    printf("%s", failure_message_buffer); \
    return 1; \
  } \
} while(0)

#define TEST_STRING_EQ(a, b) \
do { \
  if (strcmp(a, b)) \
  { \
    printf( \
      "\r\e[1;%d;%dm" __FILE__ ":%d\nTest failed: '" #a " != " #b \
      "' (" #a "=%s, " #b "=%s)\e[0m\n", \
      FOREGROUND_WHITE, BACKGROUND_RED, \
      __LINE__, a, b \
    ); \
    return 1; \
  } \
} while(0)

#endif
