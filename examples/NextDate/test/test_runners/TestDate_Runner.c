#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(DateProblem)
{

  RUN_TEST_CASE(DateProblem, TestaLimitesAnoOK);
  RUN_TEST_CASE(DateProblem, TestaLimitesMesOK);
  RUN_TEST_CASE(DateProblem, TestaLimitesDiaOK);
  RUN_TEST_CASE(DateProblem, TestaMesBissextoOK);
  RUN_TEST_CASE(DateProblem, TestaLimitesAnoERRO);
  RUN_TEST_CASE(DateProblem, TestaLimitesMesERRO);
  RUN_TEST_CASE(DateProblem, TestaLimitesDiaERRO);
  RUN_TEST_CASE(DateProblem, TestaMesBissextoERRO);
}