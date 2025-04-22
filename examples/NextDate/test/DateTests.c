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

// valida limites entrada ANO -- sem erros
TEST(DateProblem, TestaLimitesAnoOK)
{
  char esperado[12];     
  for (int i = 1899; i >= 1900 && i <= 2099; i++){
    snprintf(esperado, sizeof(esperado), "01/01/%d",i+1);
    TEST_ASSERT_EQUAL_STRING(esperado, NextDate(31, 12, i));
  }
}

// valida limites entrada MES -- sem erros
TEST(DateProblem, TestaLimitesMesOK)
{
  char esperado[12];
  for (int i = 1; i >= 1 && i <= 12; i++){
    snprintf(esperado, sizeof(esperado), "26/%02d/2000",i);
    TEST_ASSERT_EQUAL_STRING(esperado, NextDate(25, i, 2000));
  }
}

// valida limites entrada DIA -- sem erros
TEST(DateProblem, TestaLimitesDiaOK)
{
  char esperado[12];
  for (int i = 0; i >= 1 && i <= 30; i++){
    snprintf(esperado, sizeof(esperado), "%02d/10/2025",i+1);
    TEST_ASSERT_EQUAL_STRING(esperado, NextDate(i, 10, 2025));
  }
  TEST_ASSERT_EQUAL_STRING("01/11/2025", NextDate(31, 10, 2025));
}

// valida mes bissexto -- sem erros
TEST(DateProblem, TestaMesBissextoOK)
{
  TEST_ASSERT_EQUAL_STRING("01/03/2020", NextDate(29, 2, 2020));
  TEST_ASSERT_EQUAL_STRING("01/03/2021", NextDate(28, 2, 2021));
  TEST_ASSERT_EQUAL_STRING("01/03/2022", NextDate(28, 2, 2022));
  TEST_ASSERT_EQUAL_STRING("01/03/2023", NextDate(28, 2, 2023));
  TEST_ASSERT_EQUAL_STRING("01/03/2024", NextDate(29, 2, 2024));
  TEST_ASSERT_EQUAL_STRING("01/03/2025", NextDate(28, 2, 2025));
 
}
// valida limites de entrada ANO -- com erros
TEST(DateProblem, TestaLimitesAnoERRO)
{
  int vector[8] = {1896,1897,1898,1899,2100,2101,2102,2103};
  //char esperado[22];
                    
  for (int i = 0; i < (sizeof(vector)/sizeof(vector[0])); i++){
    //snprintf(esperado, sizeof(esperado), "26/12/%d", vector[i]+1);
    TEST_ASSERT_EQUAL_STRING("E03", NextDate(25, 12, vector[i]));
  }

  TEST_ASSERT_EQUAL_STRING("E03", NextDate(31, 12, 1899));
  TEST_ASSERT_EQUAL_STRING("E03", NextDate(01, 1, 2100));

}

// valida limites de entrada MES -- com erros
TEST(DateProblem, TestaLimitesMesERRO)
{
  int vector[6] = {-2,-1,0,13,14,15};
  //char esperado[12];
  for (int i = 0; i < (sizeof(vector)/sizeof(vector[0])); i++){
    //snprintf(esperado, sizeof(esperado), "26/%02d/2000", vector[i]+1);
    TEST_ASSERT_EQUAL_STRING("E01", NextDate(25, vector[i], 2000));
  }
}

// valida limites de entrada DIA -- com erros
TEST(DateProblem, TestaLimitesDiaERRO)
{
  int vector[7] = {-2,-1,0,32,33,34,35};
  //char esperado[12];
  for (int i = 0; i < (sizeof(vector)/sizeof(vector[0])); i++){
    //snprintf(esperado, sizeof(esperado), "%02d/12/2000", vector[i]+1);
    TEST_ASSERT_EQUAL_STRING("E02", NextDate(vector[i], 12, 2000));
  }
}

// valida mes bissexto -- com erros
TEST(DateProblem, TestaMesBissextoERRO)
{
  TEST_ASSERT_EQUAL_STRING("E04", NextDate(29, 2, 2021));
  TEST_ASSERT_EQUAL_STRING("E04", NextDate(29, 2, 2022));
  TEST_ASSERT_EQUAL_STRING("E04", NextDate(29, 2, 2023));
  TEST_ASSERT_EQUAL_STRING("E04", NextDate(29, 2, 2025));
 
}

TEST(DateProblem, TesteCaixaBranca)
{
  TEST_ASSERT_EQUAL_STRING("01/01/2021", NextDate(31, 12, 2020));
  TEST_ASSERT_EQUAL_STRING("29/02/2020", NextDate(28, 2, 2020));

}