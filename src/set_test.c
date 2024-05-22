/** 
 * @brief It tests set module
 * 
 * @file set_test.c
 * @author Manuel Ardid
 * @version 1.0 
 * @date 06-03-2021
 * @copyright GNU Public License
 */

#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set_test.h"
#include "test.h"

/** Defines the constant variables */
#define MAX_TESTS 12

/** 
 * @brief Main function for SET unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char **argv) {
  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1)
    test1_set_create();
  if (all || test == 2)
    test2_set_create();
  if (all || test == 3)
    test1_set_get_num_of_ids();
  if (all || test == 4)
    test2_set_get_num_of_ids();
  if (all || test == 5)
    test1_set_has_id();
  if (all || test == 6)
    test2_set_has_id();
  if (all || test == 7)
    test1_set_get_id_from_pos();
  if (all || test == 8)
    test1_set_get_id_from_pos();
  if (all || test == 9)
    test1_set_add();
  if (all || test == 10)
    test2_set_add();
  if (all || test == 11)
    test1_set_del();
  if (all || test == 12)
    test2_set_del();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_set_create() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(s != NULL);
  set_destroy(s);
}

void test2_set_create() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_get_num_of_ids(s) == 0);
  set_destroy(s);
}

void test1_set_get_num_of_ids() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_get_num_of_ids(s) == 0);
  set_destroy(s);
}

void test2_set_get_num_of_ids() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_get_num_of_ids(s) == -1);
}

void test1_set_has_id() {
  Set *s;
  s = set_create();
  set_add(s, 5);
  PRINT_TEST_RESULT(set_has_id(s, 5) == 1);
  set_destroy(s);
}

void test2_set_has_id() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_has_id(s, 5) == 0);
}

void test1_set_get_id_from_pos() {
  Set *s;
  s = set_create();
  set_add(s, 7);
  PRINT_TEST_RESULT(set_get_id_from_pos(s, 0) == 7);
  set_destroy(s);
}

void test2_set_get_id_from_pos() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_get_id_from_pos(s, 0) == NO_ID);
}

void test1_set_add() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_add(s, 5) == OK);
  set_destroy(s);
}

void test2_set_add() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_add(s, 9) == ERROR);
}

void test1_set_del() {
  Set *s;
  s = set_create();
  set_add(s, 7);
  PRINT_TEST_RESULT(set_del(s, 7) == OK);
  set_destroy(s);
}

void test2_set_del() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_del(s, 7) == ERROR);
}
