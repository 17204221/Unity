#include "DateProblem.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(DateProblem);

TEST_SETUP(DateProblem)
{
}

TEST_TEAR_DOWN(DateProblem)
{
}

TEST(DateProblem, NextDate1)
{
  TEST_ASSERT_EQUAL_STRING("01/01/1901", NextDate(31, 12, 1900));
  TEST_ASSERT_EQUAL_STRING("01/02/1900", NextDate(31, 1, 1900));
  TEST_ASSERT_EQUAL_STRING("01/03/1900", NextDate(28, 2, 1900));
}

TEST(DateProblem, NextDate2)
{
  TEST_ASSERT_EQUAL_STRING("01/01/2000", NextDate(31, 12, 1999));
  TEST_ASSERT_EQUAL_STRING("01/02/2000", NextDate(31, 1, 2000));
  TEST_ASSERT_EQUAL_STRING("01/03/2000", NextDate(29, 2, 2000));
}

TEST(DateProblem, NextDate2)
{

  TEST_ASSERT_EQUAL(2, foo(1,2));
}