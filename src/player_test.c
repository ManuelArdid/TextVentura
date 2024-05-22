/** 
 * @brief It tests Player module
 * 
 * @file player_test.c
 * @author Manuel Ardid Clavería
 * @version 1.0 
 * @date 26-03-2021
 */

#include "player_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "test.h"
#include "types.h"

/** Defines the constant variables */
#define MAX_TESTS 27

/** 
 * @brief Main function for player unit tests. 
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
    printf("Running all test for module Player:\n");
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
    test1_player_create();
  if (all || test == 2)
    test2_player_create();

  if (all || test == 3)
    test1_player_get_id();
  if (all || test == 4)
    test2_player_get_id();

  if (all || test == 5)
    test1_player_set_name();
  if (all || test == 6)
    test2_player_set_name();

  if (all || test == 7)
    test1_player_get_name();
  if (all || test == 8)
    test2_player_get_name();

  if (all || test == 9)
    test1_player_set_location();
  if (all || test == 10)
    test2_player_set_location();

  if (all || test == 11)
    test1_player_get_location();
  if (all || test == 12)
    test2_player_get_location();

  if (all || test == 13)
    test1_player_add_object();
  if (all || test == 14)
    test2_player_add_object();

  if (all || test == 15)
    test1_player_del_object();
  if (all || test == 16)
    test2_player_del_object();

  if (all || test == 17)
    test1_player_get_object_from_pos();
  if (all || test == 18)
    test2_player_get_object_from_pos();

  if (all || test == 19)
    test1_player_has_object();
  if (all || test == 20)
    test2_player_has_object();

  if (all || test == 21)
    test1_player_get_num_of_objects();
  if (all || test == 22)
    test2_player_get_num_of_objects();

  if (all || test == 23)
    test1_player_set_max_objects();
  if (all || test == 24)
    test2_player_set_max_objects();
  if (all || test == 25)
    test3_player_set_max_objects();

  if (all || test == 26)
    test1_player_get_max_objects();
  if (all || test == 27)
    test2_player_get_max_objects();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_player_create() {
  Player *i = NULL;
  i = player_create(1);
  PRINT_TEST_RESULT(i != NULL);
  player_destroy(i);
}

void test2_player_create() {
  Player *i = NULL;
  i = player_create(1);
  PRINT_TEST_RESULT(player_get_id(i) == 1);
  player_destroy(i);
}

void test1_player_get_id() {
  Player *i = NULL;
  i = player_create(3);
  PRINT_TEST_RESULT(player_get_id(i) == 3);
  player_destroy(i);
}

void test2_player_get_id() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_get_object_from_pos(i, 0) == NO_ID);
}

void test1_player_set_name() {
  Player *i = NULL;
  char name[10] = "Hola";
  i = player_create(2);
  player_set_name(i, name);
  PRINT_TEST_RESULT(strcmp(name, player_get_name(i)) == 0);
  player_destroy(i);
}

void test2_player_set_name() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_get_name(i) == NULL);
}

void test1_player_get_name() {
  Player *i = NULL;
  char name[10] = "Hola";
  i = player_create(2);
  player_set_name(i, name);
  PRINT_TEST_RESULT(strcmp(name, player_get_name(i)) == 0);
  player_destroy(i);
}

void test2_player_get_name() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_get_name(i) == NULL);
}

void test1_player_set_location() {
  Player *i = NULL;
  int loc;
  i = player_create(2);
  player_set_location(i, 1);
  loc = player_get_location(i);
  PRINT_TEST_RESULT(loc == 1);
  player_destroy(i);
}

void test2_player_set_location() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_get_location(i) == NO_ID);
}

void test1_player_get_location() {
  Player *i = NULL;
  int loc;
  i = player_create(2);
  player_set_location(i, 1);
  loc = player_get_location(i);
  PRINT_TEST_RESULT(loc == 1);
  player_destroy(i);
}

void test2_player_get_location() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_get_location(i) == NO_ID);
}

void test1_player_add_object() {
  Player *i = NULL;
  i = player_create(2);
  player_set_max_objects(i, 1);
  PRINT_TEST_RESULT(player_add_object(i, 3) == OK);
  player_destroy(i);
}

void test2_player_add_object() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_has_object(i, 3) == FALSE);
}

void test1_player_del_object() {
  Player *i = NULL;
  i = player_create(2);
  player_add_object(i, 3);
  player_add_object(i, 5);
  player_del_object(i, 3);
  PRINT_TEST_RESULT(player_has_object(i, 3) == FALSE);
  player_destroy(i);
}

void test2_player_del_object() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_has_object(i, 3) == FALSE);
}

void test1_player_get_object_from_pos() {
  Player *i = NULL;
  i = player_create(2);
  player_set_max_objects(i, 3);
  player_add_object(i, 3);
  player_add_object(i, 5);
  player_add_object(i, 7);
  PRINT_TEST_RESULT(player_get_object_from_pos(i, 1) == 5);
  player_destroy(i);
}

void test2_player_get_object_from_pos() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_get_object_from_pos(i, 0) == NO_ID);
}

void test1_player_has_object() {
  Player *i = NULL;
  i = player_create(2);
  player_set_max_objects(i, 2);
  player_add_object(i, 3);
  player_add_object(i, 7);
  PRINT_TEST_RESULT(player_has_object(i, 7) == TRUE);
  player_destroy(i);
}

void test2_player_has_object() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_has_object(i, 0) == FALSE);
}

void test1_player_get_num_of_objects() {
  Player *i = NULL;
  i = player_create(2);
  player_set_max_objects(i, 3);
  player_add_object(i, 3);
  player_add_object(i, 7);
  player_add_object(i, 4);
  PRINT_TEST_RESULT(player_get_num_of_objects(i) == 3);
  player_destroy(i);
}

void test2_player_get_num_of_objects() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_get_num_of_objects(i) == -1);
}

void test1_player_set_max_objects() {
  Player *i = NULL;
  i = player_create(1);
  PRINT_TEST_RESULT(player_set_max_objects(i, 4) == OK);
  player_destroy(i);
}

void test2_player_set_max_objects() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_set_max_objects(i, 4) == ERROR);
}

void test3_player_set_max_objects() {
  Player *i;
  i = player_create(1);
  PRINT_TEST_RESULT(player_set_max_objects(i, -1) == ERROR);
  player_destroy(i);
}

void test1_player_get_max_objects() {
  Player *i;
  i = player_create(1);
  player_set_max_objects(i, 2);
  PRINT_TEST_RESULT(player_get_max_objects(i) == 2);
  player_destroy(i);
}
void test2_player_get_max_objects() {
  Player *i = NULL;
  PRINT_TEST_RESULT(player_get_max_objects(i) == -1);
}