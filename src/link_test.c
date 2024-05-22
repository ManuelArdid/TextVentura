/** 
 * @brief It tests link module
 * 
 * @file link_test.c
 * @author Manuel Ardid
 * @version 1.0 
 * @date 26-03-2021
 * @copyright GNU Public License
 */

#include "link_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "link.h"
#include "test.h"

/** Defines the constant variables */
#define MAX_TESTS 23

/** 
 * @brief Main function for DIE unit tests. 
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
    printf("Running all test for module Link:\n");
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
    test1_link_create();
  if (all || test == 2)
    test2_link_create();
  if (all || test == 3)
    test1_link_set_name();
  if (all || test == 4)
    test2_link_set_name();
  if (all || test == 5)
    test3_link_set_name();
  if (all || test == 6)
    test1_link_set_space1();
  if (all || test == 7)
    test2_link_set_space1();
  if (all || test == 8)
    test3_link_set_space1();
  if (all || test == 9)
    test1_link_set_space2();
  if (all || test == 10)
    test2_link_set_space2();
  if (all || test == 11)
    test3_link_set_space2();
  if (all || test == 12)
    test1_link_set_close();
  if (all || test == 13)
    test2_link_set_close();
  if (all || test == 14)
    test1_link_get_id();
  if (all || test == 15)
    test2_link_get_id();
  if (all || test == 16)
    test1_link_get_name();
  if (all || test == 17)
    test2_link_get_name();
  if (all || test == 18)
    test1_link_get_space1();
  if (all || test == 19)
    test2_link_get_space1();
  if (all || test == 20)
    test1_link_get_space2();
  if (all || test == 21)
    test2_link_get_space2();
  if (all || test == 22)
    test1_link_is_close();
  if (all || test == 23)
    test2_link_is_close();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_link_create() {
  Link *l;
  l = link_create(1);
  PRINT_TEST_RESULT(l != NULL);
  link_destroy(l);
}

void test2_link_create() {
  Link *l;
  l = link_create(NO_ID);
  PRINT_TEST_RESULT(l == NULL);
}

void test1_link_set_name() {
  Link *l;
  l = link_create(1);
  PRINT_TEST_RESULT(link_set_name(l, "Link 1") == OK);
  link_destroy(l);
}

void test2_link_set_name() {
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_name(l, "Link 1") == ERROR);
}

void test3_link_set_name() {
  Link *l;
  l = link_create(1);
  PRINT_TEST_RESULT(link_set_name(l, NULL) == ERROR);
  link_destroy(l);
}

void test1_link_set_space1() {
  Link *l;
  l = link_create(1);
  PRINT_TEST_RESULT(link_set_space1(l, 2) == OK);
  link_destroy(l);
}

void test2_link_set_space1() {
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_space1(l, 2) == ERROR);
}

void test3_link_set_space1() {
  Link *l;
  l = link_create(1);
  PRINT_TEST_RESULT(link_set_space1(l, NO_ID) == ERROR);
  link_destroy(l);
}

void test1_link_set_space2() {
  Link *l;
  l = link_create(1);
  PRINT_TEST_RESULT(link_set_space2(l, 3) == OK);
  link_destroy(l);
}

void test2_link_set_space2() {
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_space2(l, 3) == ERROR);
}

void test3_link_set_space2() {
  Link *l;
  l = link_create(1);
  PRINT_TEST_RESULT(link_set_space2(l, NO_ID) == ERROR);
  link_destroy(l);
}

void test1_link_set_close() {
  Link *l;
  l = link_create(1);
  PRINT_TEST_RESULT(link_set_close(l, TRUE) == OK);
  link_destroy(l);
}

void test2_link_set_close() {
  Link *l = NULL;
  PRINT_TEST_RESULT(link_set_close(l, TRUE) == ERROR);
}

void test1_link_get_id() {
  Link *l;
  l = link_create(1);
  PRINT_TEST_RESULT(link_get_id(l) == 1);
  link_destroy(l);
}

void test2_link_get_id() {
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_id(l) == NO_ID);
}

void test1_link_get_name() {
  Link *l;
  l = link_create(1);
  link_set_name(l, "Link 1");
  PRINT_TEST_RESULT(strcmp(link_get_name(l), "Link 1") == 0);
  link_destroy(l);
}

void test2_link_get_name() {
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_name(l) == NULL);
}

void test1_link_get_space1() {
  Link *l;
  l = link_create(1);
  link_set_space1(l, 2);
  PRINT_TEST_RESULT(link_get_space1(l) == 2);
  link_destroy(l);
}

void test2_link_get_space1() {
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_space1(l) == NO_ID);
}

void test1_link_get_space2() {
  Link *l;
  l = link_create(1);
  link_set_space2(l, 3);
  PRINT_TEST_RESULT(link_get_space2(l) == 3);
  link_destroy(l);
}

void test2_link_get_space2() {
  Link *l = NULL;
  PRINT_TEST_RESULT(link_get_space2(l) == NO_ID);
}

void test1_link_is_close() {
  Link *l;
  l = link_create(1);
  link_set_close(l, FALSE);
  PRINT_TEST_RESULT(link_is_close(l) == FALSE);
  link_destroy(l);
}
void test2_link_is_close() {
  Link *l = NULL;
  PRINT_TEST_RESULT(link_is_close(l) == FALSE);
}
