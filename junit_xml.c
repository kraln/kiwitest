#include "junit_xml.h"

#if KIWITEST_JUNIT_XML

FILE *junit_xml_init(const char *path)
{
  FILE *junit_xml_file = NULL;
  if (path)
  {
    junit_xml_file = fopen(path, "w");
  }
  return junit_xml_file;
}

void junit_xml_finalize(FILE *junit_xml_file)
{
  if (!junit_xml_file) return;
  fclose(junit_xml_file);
}

void junit_xml_begin_testsuites(FILE *junit_xml_file)
{
  if (!junit_xml_file) return;
  fprintf(
    junit_xml_file,
    "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n"
    "<testsuites>\n"
  );
}

void junit_xml_end_testsuites(FILE *junit_xml_file)
{
  if (!junit_xml_file) return;
  fprintf(junit_xml_file, "</testsuites>\n");
}

void junit_xml_begin_testsuite(
  FILE *junit_xml_file, const char *testsuite_name, size_t num_tests)
{
  if (!junit_xml_file) return;
  static int testsuite_id = 0;
  fprintf(
    junit_xml_file,
    "  <testsuite id=\"%d\" tests=\"%zu\" package=\"%s\">\n",
    testsuite_id++, num_tests, testsuite_name
  );
}

void junit_xml_end_testsuite(FILE *junit_xml_file)
{
  if (!junit_xml_file) return;
  fprintf(junit_xml_file, "  </testsuite>\n");
}

void junit_xml_pass_testcase(
  FILE *junit_xml_file, const char *classname, const char *testcase_name,
  float time)
{
  if (!junit_xml_file) return;
  fprintf(
    junit_xml_file,
    "    <testcase classname=\"%s\" name=\"%s\" time=\"%0.14f\"/>\n",
    classname, testcase_name, time
  );
}

void junit_xml_fail_testcase(
  FILE *junit_xml_file,
  const char *classname, const char *testcase_name, float time,
  const char *failure_message)
{
  if (!junit_xml_file) return;
  fprintf(
    junit_xml_file,
    "    <testcase classname=\"%s\" name=\"%s\" time=\"%0.14f\">\n"
    "      <failure type=\"EPIC FAIL\">\n%s"
    "      </failure>\n"
    "    </testcase>\n",
    classname, testcase_name, time, failure_message
  );
}

#else

/* Define FILE to void so that FILE doesn't have to be defined in those
 * environments that lack a C library. */
#define FILE void

FILE *junit_xml_init(const char *path)
{
  FILE *junit_xml_file = NULL;
  return junit_xml_file;
}

void junit_xml_finalize(FILE *junit_xml_file)
{
}

void junit_xml_begin_testsuites(FILE *junit_xml_file)
{
}

void junit_xml_end_testsuites(FILE *junit_xml_file)
{
}

void junit_xml_begin_testsuite(
  FILE *junit_xml_file, const char *testsuite_name, size_t num_tests)
{
}

void junit_xml_end_testsuite(FILE *junit_xml_file)
{
}

void junit_xml_pass_testcase(
  FILE *junit_xml_file, const char *classname, const char *testcase_name,
  float time)
{
}

void junit_xml_fail_testcase(
  FILE *junit_xml_file,
  const char *classname, const char *testcase_name, float time,
  const char *failure_message)
{
}

#endif
