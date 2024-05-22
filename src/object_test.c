/** 
 * @brief It tests set module
 * 
 * @file set_test.c
 * @author Manuel Ardid
 * @version 1.0 
 * @date 06-04-2021
 * @copyright GNU Public License
 */

#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object_test.h"
#include "test.h"

#define MAX_TESTS 38

/** 
 * @brief Main function for object unit tests. 
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
    printf("Running all test for module Object:\n");
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
    test1_object_create();
  if (all || test == 2)
    test2_object_create();
  if (all || test == 3)
    test1_object_get_id();
  if (all || test == 4)
    test2_object_get_id();
  if (all || test == 5)
    test1_object_set_name();
  if (all || test == 6)
    test2_object_set_name();
  if (all || test == 7)
    test3_object_set_name();
  if (all || test == 8)
    test1_object_get_name();
  if (all || test == 9)
    test2_object_get_name();
  if (all || test == 10)
    test1_object_set_description();
  if (all || test == 11)
    test2_object_set_description();
  if (all || test == 12)
    test3_object_set_description();
  if (all || test == 13)
    test1_object_get_description();
  if (all || test == 14)
    test2_object_get_description();
  if (all || test == 15)
    test1_object_set_movable();
  if (all || test == 16)
    test2_object_set_movable();
  if (all || test == 17)
    test1_object_get_movable();
  if (all || test == 18)
    test2_object_get_movable();
  if (all || test == 19)
    test1_object_set_dependency();
  if (all || test == 20)
    test2_object_set_dependency();
  if (all || test == 21)
    test1_object_get_dependency();
  if (all || test == 22)
    test2_object_get_dependency();
  if (all || test == 23)
    test1_object_set_open();
  if (all || test == 24)
    test2_object_set_open();
  if (all || test == 25)
    test1_object_get_open();
  if (all || test == 26)
    test2_object_get_open();
  if (all || test == 27)
    test1_object_set_illuminate();
  if (all || test == 28)
    test2_object_set_illuminate();
  if (all || test == 29)
    test1_object_can_illuminate();
  if (all || test == 30)
    test2_object_can_illuminate();
  if (all || test == 31)
    test1_object_set_turnedon();
  if (all || test == 32)
    test2_object_set_turnedon();
  if (all || test == 33)
    test1_object_is_turnedon();
  if (all || test == 34)
    test2_object_is_turnedon();
  if (all || test == 35)
    test1_object_set_discovery();
  if (all || test == 36)
    test2_object_set_discovery();
  if (all || test == 37)
    test1_object_is_discovered();
  if (all || test == 38)
    test2_object_is_discovered();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_object_create() {
  Object *i = NULL;
  i = object_create(1);
  PRINT_TEST_RESULT(i != NULL);
  object_destroy(i);
}

void test2_object_create() {
  Object *i = NULL;
  i = object_create(1);
  PRINT_TEST_RESULT(object_get_id(i) == 1);
  object_destroy(i);
}

void test1_object_get_id() {
  Object *i = NULL;
  i = object_create(3);
  PRINT_TEST_RESULT(object_get_id(i) == 3);
  object_destroy(i);
}
void test2_object_get_id() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_get_id(i) == NO_ID);
}

void test1_object_set_name() {
  Object *i = NULL;
  char name[10] = "Hola";
  i = object_create(2);
  object_set_name(i, name);
  PRINT_TEST_RESULT(strcmp(name, object_get_name(i)) == 0);
  object_destroy(i);
}

void test2_object_set_name() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_get_name(i) == NULL);
}

void test3_object_set_name() {
  Object *i;
  i = object_create(5);
  PRINT_TEST_RESULT(object_set_name(i, NULL) == ERROR);
  object_destroy(i);
}

void test1_object_get_name() {
  Object *i = NULL;
  char name[10] = "Hola";
  i = object_create(2);
  object_set_name(i, name);
  PRINT_TEST_RESULT(strcmp(name, object_get_name(i)) == 0);
  object_destroy(i);
}

void test2_object_get_name() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_get_name(i) == NULL);
}

void test1_object_set_description() {
  Object *i = NULL;
  char description[20] = "red token";
  i = object_create(2);
  object_set_description(i, description);
  PRINT_TEST_RESULT(strcmp(description, object_get_description(i)) == 0);
  object_destroy(i);
}

void test2_object_set_description() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_get_description(i) == NULL);
}

void test3_object_set_description() {
  Object *i;
  i = object_create(5);
  PRINT_TEST_RESULT(object_set_description(i, NULL) == ERROR);
  object_destroy(i);
}

void test1_object_get_description() {
  Object *i = NULL;
  char description[20] = "red token";
  i = object_create(2);
  object_set_description(i, description);
  PRINT_TEST_RESULT(strcmp(description, object_get_description(i)) == 0);
  object_destroy(i);
}

void test2_object_get_description() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_get_description(i) == NULL);
}

void test1_object_set_movable() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_is_movable(i) == 0);
}

void test2_object_set_movable() {
  Object *i = NULL;
  i = object_create(1);
  object_set_movable(i, 1);
  PRINT_TEST_RESULT(object_is_movable(i) == 1);
  object_destroy(i);
}

void test1_object_get_movable() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_is_movable(i) == 0);
}

void test2_object_get_movable() {
  Object *i = NULL;
  i = object_create(1);
  object_set_movable(i, 1);
  PRINT_TEST_RESULT(object_is_movable(i) == 1);
  object_destroy(i);
}

void test1_object_set_dependency() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_get_dependency(i) == NO_ID);
}

void test2_object_set_dependency() {
  Object *i = NULL;
  i = object_create(1);
  object_set_dependency(i, 2);
  PRINT_TEST_RESULT(object_get_dependency(i) == 2);
  object_destroy(i);
}

void test1_object_get_dependency() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_get_dependency(i) == NO_ID);
}

void test2_object_get_dependency() {
  Object *i = NULL;
  i = object_create(1);
  object_set_dependency(i, 2);
  PRINT_TEST_RESULT(object_get_dependency(i) == 2);
  object_destroy(i);
}

void test1_object_set_open() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_get_open(i) == NO_ID);
}

void test2_object_set_open() {
  Object *i = NULL;
  i = object_create(1);
  object_set_open(i, 2);
  PRINT_TEST_RESULT(object_get_open(i) == 2);
  object_destroy(i);
}

void test1_object_get_open() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_get_open(i) == NO_ID);
}

void test2_object_get_open() {
  Object *i = NULL;
  i = object_create(1);
  object_set_open(i, 2);
  PRINT_TEST_RESULT(object_get_open(i) == 2);
  object_destroy(i);
}

void test1_object_set_illuminate() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_set_illuminate(i, FALSE) == 0);
}

void test2_object_set_illuminate() {
  Object *i = NULL;
  i = object_create(1);
  PRINT_TEST_RESULT(object_set_illuminate(i, TRUE) == OK);
  object_destroy(i);
}

void test1_object_can_illuminate() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_can_illuminate(i) == FALSE);
}

void test2_object_can_illuminate() {
  Object *i = NULL;
  i = object_create(1);
  object_set_illuminate(i, 1);
  PRINT_TEST_RESULT(object_can_illuminate(i) == 1);
  object_destroy(i);
}

void test1_object_set_turnedon() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_set_turnedon(i, FALSE) == ERROR);
}

void test2_object_set_turnedon() {
  Object *i = NULL;
  i = object_create(1);
  PRINT_TEST_RESULT(object_set_turnedon(i, 1) == 1);
  object_destroy(i);
}

void test1_object_is_turnedon() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_is_turnedon(i) == 0);
}

void test2_object_is_turnedon() {
  Object *i = NULL;
  i = object_create(1);
  object_set_turnedon(i, 1);
  PRINT_TEST_RESULT(object_is_turnedon(i) == 1);
  object_destroy(i);
}

void test1_object_set_discovery() {
  Object *i = NULL;
  i = object_create(1);
  PRINT_TEST_RESULT(object_set_discovery(i, TRUE) == OK);
  object_destroy(i);
}

void test2_object_set_discovery() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_set_discovery(i, FALSE) == ERROR);
}

void test1_object_is_discovered() {
  Object *i = NULL;
  i = object_create(1);
  object_set_discovery(i, FALSE);
  PRINT_TEST_RESULT(object_is_discovered(i) == FALSE);
  object_destroy(i);
}
void test2_object_is_discovered() {
  Object *i = NULL;
  PRINT_TEST_RESULT(object_is_discovered(i) == FALSE);
}