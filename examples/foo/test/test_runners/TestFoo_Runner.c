#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(DateProblem)
{
  RUN_TEST_CASE(DateProblem, NextDate1);
  RUN_TEST_CASE(DateProblem, NextDate2);
}