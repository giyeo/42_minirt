#include <check.h>      
#include <stdlib.h>

int returtrue()
{
    return 0;
}

START_TEST(test_returtrue)
{
  ck_assert_int_eq(returtrue(), 1);
} END_TEST

START_TEST(test_returfalse)
{
  ck_assert_int_eq(returtrue(), 0);
} END_TEST

Suite *money_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Money");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_returtrue);
  tcase_add_test(tc_core, test_returfalse);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int no_failed = 0;                   
  Suite *s;                            
  SRunner *runner;                     

  s = money_suite();                   
  runner = srunner_create(s);          

  srunner_run_all(runner, CK_NORMAL);  
  no_failed = srunner_ntests_failed(runner); 
  srunner_free(runner);                   
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;  
}

//-lcheck -lm -lpthread -lrt