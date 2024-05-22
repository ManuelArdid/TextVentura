/** 
 * @brief It tests inventory module
 * 
 * @file inventory_test.c
 * @author Manuel Ardid Clavería
 * @version 1.0 
 * @date 26-03-2021
 * @copyright GNU Public License
 */

#include "inventory_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inventory.h"
#include "test.h"
#include "types.h"

/** Defines the constant variables */
#define MAX_TESTS 20

/** 
 * @brief Main function for inventory unit tests. 
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
    printf("Running all test for module Inventory:\n");
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
    test1_inventory_create();
  if (all || test == 2)
    test2_inventory_create();
  if (all || test == 3)
    test1_inventory_get_object_from_pos();
  if (all || test == 4)
    test2_inventory_get_object_from_pos();
  if (all || test == 5)
    test1_inventory_add_id();
  if (all || test == 6)
    test2_inventory_add_id();
  if (all || test == 7)
    test1_inventory_del_id();
  if (all || test == 8)
    test2_inventory_del_id();
  if (all || test == 9)
    test1_inventory_set_max();
  if (all || test == 10)
    test2_inventory_set_max();
  if (all || test == 11)
    test1_inventory_get_max();
  if (all || test == 12)
    test2_inventory_get_max();
  if (all || test == 13)
    test1_inventory_is_full();
  if (all || test == 14)
    test2_inventory_is_full();
  if (all || test == 15)
    test1_inventory_is_empty();
  if (all || test == 16)
    test2_inventory_is_empty();
  if (all || test == 17)
    test1_inventory_print();
  if (all || test == 18)
    test2_inventory_print();
  if (all || test == 19)
    test1_inventory_has_object();
  if (all || test == 20)
    test2_inventory_has_object();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_inventory_create() {
  Inventory *i = NULL;
  i = inventory_create();
  PRINT_TEST_RESULT(i != NULL);
  inventory_destroy(i);
}

void test2_inventory_create() {
  Inventory *i = NULL;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_get_max(i) == 0);
  inventory_destroy(i);
}

void test1_inventory_get_object_from_pos() {
  Inventory *i = NULL;
  i = inventory_create();
  inventory_set_max(i, 3);
  inventory_add_id(i, 1);
  PRINT_TEST_RESULT(inventory_get_object_from_pos(i, 0) == 1);
  inventory_destroy(i);
}

void test2_inventory_get_object_from_pos() {
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_get_object_from_pos(i, 0) == NO_ID);
  inventory_destroy(i);
}

void test1_inventory_add_id() {
  Inventory *i = NULL;
  i = inventory_create();
  inventory_set_max(i, 3);
  inventory_add_id(i, 9);
  PRINT_TEST_RESULT(inventory_get_object_from_pos(i, 0) == 9);
  inventory_destroy(i);
}

void test2_inventory_add_id() {
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_add_id(i, 9) == ERROR);
}

void test1_inventory_del_id() {
  Inventory *i = NULL;
  i = inventory_create();
  inventory_set_max(i, 3);
  inventory_add_id(i, 7);
  PRINT_TEST_RESULT(inventory_del_id(i, 7) == OK);
  inventory_destroy(i);
}

void test2_inventory_del_id() {
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_del_id(i, 7) == ERROR);
  inventory_destroy(i);
}

void test1_inventory_set_max() {
  Inventory *i = NULL;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_set_max(i, 5) == OK);
  inventory_destroy(i);
}

void test2_inventory_set_max() {
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_set_max(i, 5) == ERROR);
  inventory_destroy(i);
}

void test1_inventory_get_max() {
  Inventory *i = NULL;
  i = inventory_create();
  inventory_set_max(i, 5);
  PRINT_TEST_RESULT(inventory_get_max(i) == 5);
  inventory_destroy(i);
}

void test2_inventory_get_max() {
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_get_max(i) == -1);
  inventory_destroy(i);
}

void test1_inventory_is_full() {
  Inventory *i = NULL;
  i = inventory_create();
  inventory_set_max(i, 1);
  inventory_add_id(i, 1);
  PRINT_TEST_RESULT(inventory_is_full(i) == TRUE);
  inventory_destroy(i);
}

void test2_inventory_is_full() {
  Inventory *i = NULL;
  i = inventory_create();
  inventory_set_max(i, 10);
  PRINT_TEST_RESULT(inventory_is_full(i) == FALSE);
  inventory_destroy(i);
}

void test1_inventory_is_empty() {
  Inventory *i = NULL;
  i = inventory_create();
  inventory_set_max(i, 1);
  PRINT_TEST_RESULT(inventory_is_empty(i) == TRUE);
  inventory_destroy(i);
}

void test2_inventory_is_empty() {
  Inventory *i = NULL;
  i = inventory_create();
  inventory_set_max(i, 1);
  inventory_add_id(i, 1);
  PRINT_TEST_RESULT(inventory_is_empty(i) == FALSE);
  inventory_destroy(i);
}

void test1_inventory_print() {
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_print(i) == ERROR);
}

void test2_inventory_print() {
  Inventory *i = NULL;
  i = inventory_create();
  PRINT_TEST_RESULT(inventory_print(i) == OK);
  inventory_destroy(i);
}

void test1_inventory_has_object() {
  Inventory *i = NULL;
  i = inventory_create();
  inventory_set_max(i, 1);
  inventory_add_id(i, 1);
  PRINT_TEST_RESULT(inventory_has_object(i, 1) == TRUE);
  inventory_destroy(i);
}

void test2_inventory_has_object() {
  Inventory *i = NULL;
  PRINT_TEST_RESULT(inventory_has_object(i, 0) == FALSE);
}