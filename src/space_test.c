/** 
 * @brief It tests space module
 * 
 * @file space_test.c
 * @author Manuel Ardid
 * @version 3.0 
 * @date 16-01-2015
 * @copyright GNU Public License
 */

#include "space.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"
#include "space_test.h"
#include "test.h"

/** Defines the constant variables */
#define MAX_TESTS 73

/** 
 * @brief Main function for SPACE unit tests. 
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
    printf("Running all test for module Space:\n");
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
    test1_space_create();
  if (all || test == 2)
    test2_space_create();
  if (all || test == 3)
    test1_space_set_name();
  if (all || test == 4)
    test2_space_set_name();
  if (all || test == 5)
    test3_space_set_name();
  if (all || test == 6)
    test1_space_set_north_link();
  if (all || test == 7)
    test2_space_set_north_link();
  if (all || test == 8)
    test1_space_set_south_link();
  if (all || test == 9)
    test2_space_set_south_link();
  if (all || test == 10)
    test1_space_set_east_link();
  if (all || test == 11)
    test2_space_set_east_link();
  if (all || test == 12)
    test1_space_set_west_link();
  if (all || test == 13)
    test2_space_set_west_link();
  if (all || test == 14)
    test1_space_get_name();
  if (all || test == 15)
    test2_space_get_name();
  if (all || test == 16)
    test1_space_get_objects();
  if (all || test == 17)
    test2_space_get_objects();
  if (all || test == 18)
    test3_space_get_objects();
  if (all || test == 19)
    test1_space_get_north_link();
  if (all || test == 20)
    test2_space_get_north_link();
  if (all || test == 21)
    test1_space_get_south_link();
  if (all || test == 22)
    test2_space_get_south_link();
  if (all || test == 23)
    test1_space_get_east_link();
  if (all || test == 24)
    test2_space_get_east_link();
  if (all || test == 25)
    test1_space_get_west_link();
  if (all || test == 26)
    test2_space_get_west_link();
  if (all || test == 27)
    test1_space_get_id();
  if (all || test == 28)
    test2_space_get_id();
  if (all || test == 29)
    test1_space_add_object();
  if (all || test == 30)
    test2_space_add_object();
  if (all || test == 31)
    test3_space_add_object();
  if (all || test == 32)
    test1_space_remove_object();
  if (all || test == 33)
    test2_space_remove_object();
  if (all || test == 34)
    test3_space_remove_object();
  if (all || test == 35)
    test1_space_get_number_of_objects();
  if (all || test == 36)
    test2_space_get_number_of_objects();
  if (all || test == 37)
    test1_space_set_gdesc();
  if (all || test == 38)
    test2_space_set_gdesc();
  if (all || test == 39)
    test1_space_has_object();
  if (all || test == 40)
    test2_space_has_object();
  if (all || test == 41)
    test1_space_get_gdesc();
  if (all || test == 42)
    test2_space_get_gdesc();
  if (all || test == 43)
    test1_space_are_linked();
  if (all || test == 44)
    test2_space_are_linked();
  if (all || test == 45)
    test1_space_set_description();
  if (all || test == 46)
    test2_space_set_description();
  if (all || test == 47)
    test3_space_set_description();
  if (all || test == 48)
    test1_space_get_description();
  if (all || test == 49)
    test2_space_get_description();
  if (all || test == 50)
    test1_space_set_up_link();
  if (all || test == 51)
    test2_space_set_up_link();
  if (all || test == 52)
    test1_space_get_up_link();
  if (all || test == 53)
    test2_space_get_up_link();
  if (all || test == 54)
    test1_space_set_down_link();
  if (all || test == 55)
    test2_space_set_down_link();
  if (all || test == 56)
    test1_space_get_down_link();
  if (all || test == 57)
    test2_space_get_down_link();
  if (all || test == 58)
    test1_space_get_object_from_pos();
  if (all || test == 59)
    test2_space_get_object_from_pos();
  if (all || test == 60)
    test1_space_set_full_description();
  if (all || test == 61)
    test2_space_set_full_description();
  if (all || test == 62)
    test1_space_get_full_description();
  if (all || test == 63)
    test2_space_get_full_description();
  if (all || test == 64)
    test1_space_set_light_init();
  if (all || test == 65)
    test2_space_set_light_init();
  if (all || test == 66)
    test1_space_get_light_init();
  if (all || test == 67)
    test2_space_get_light_init();
  if (all || test == 68)
    test1_space_set_light_act();
  if (all || test == 69)
    test2_space_set_light_act();
  if (all || test == 70)
    test1_space_get_light_act();
  if (all || test == 71)
    test2_space_get_light_act();
  if (all || test == 72)
    test1_space_get_init_description();
  if (all || test == 73)
    test2_space_get_init_description();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_space_create() {
  int result;
  Space *s;
  s = space_create(5);
  result = s != NULL;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_create() {
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_get_id(s) == 4);
  space_destroy(s);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_set_north_link() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_north_link(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_north_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_north_link(s, 4) == ERROR);
}

void test1_space_set_south_link() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_south_link(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_south_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_south_link(s, 4) == ERROR);
}

void test1_space_set_east_link() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_east_link(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_east_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_east_link(s, 4) == ERROR);
}

void test1_space_set_west_link() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_west_link(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_west_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_west_link(s, 4) == ERROR);
}

void test1_space_add_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_add_object(s, TRUE) == OK);
  space_destroy(s);
}

void test2_space_add_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_add_object(s, TRUE) == ERROR);
}

void test3_space_add_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_add_object(s, NO_ID) == ERROR);
  space_destroy(s);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_get_objects() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_objects(s) == NULL);
  space_destroy(s);
}

void test2_space_get_objects() {
  Space *s;
  Id *ids;
  s = space_create(1);
  space_add_object(s, TRUE);
  ids = space_get_objects(s);
  PRINT_TEST_RESULT(ids != NULL);
  free(ids);
  space_destroy(s);
}

void test3_space_get_objects() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_objects(s) == NULL);
}

void test1_space_get_north_link() {
  Space *s;
  s = space_create(5);
  space_set_north_link(s, 4);
  PRINT_TEST_RESULT(space_get_north_link(s) == 4);
  space_destroy(s);
}

void test2_space_get_north_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_north_link(s) == NO_ID);
}

void test1_space_get_south_link() {
  Space *s;
  s = space_create(5);
  space_set_south_link(s, 2);
  PRINT_TEST_RESULT(space_get_south_link(s) == 2);
  space_destroy(s);
}

void test2_space_get_south_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_south_link(s) == NO_ID);
}

void test1_space_get_east_link() {
  Space *s;
  s = space_create(5);
  space_set_east_link(s, 1);
  PRINT_TEST_RESULT(space_get_east_link(s) == 1);
  space_destroy(s);
}

void test2_space_get_east_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_east_link(s) == NO_ID);
}

void test1_space_get_west_link() {
  Space *s;
  s = space_create(5);
  space_set_west_link(s, 6);
  PRINT_TEST_RESULT(space_get_west_link(s) == 6);
  space_destroy(s);
}

void test2_space_get_west_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_west_link(s) == NO_ID);
}

void test1_space_get_id() {
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
  space_destroy(s);
}

void test2_space_get_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

void test1_space_remove_object() {
  Space *s;
  s = space_create(1);
  space_add_object(s, 1);
  PRINT_TEST_RESULT(space_remove_object(s, 1) == OK);
  space_destroy(s);
}

void test2_space_remove_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_remove_object(s, NO_ID) == ERROR);
  space_destroy(s);
}

void test3_space_remove_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_remove_object(s, 1) == ERROR);
}

void test1_space_get_number_of_objects() {
  Space *s;
  s = space_create(1);
  space_add_object(s, 1);
  PRINT_TEST_RESULT(space_get_number_of_objects(s) == 1);
  space_destroy(s);
}

void test2_space_get_number_of_objects() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_number_of_objects(s) == 0);
  space_destroy(s);
}

void test1_space_set_gdesc() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_gdesc(s, "<O)__/ ", 1) == OK);
  space_destroy(s);
}

void test2_space_set_gdesc() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_gdesc(s, NULL, 1) == ERROR);
  space_destroy(s);
}

void test1_space_has_object() {
  Space *s;
  s = space_create(1);
  space_add_object(s, 1);
  PRINT_TEST_RESULT(space_has_object(s, 1) == TRUE);
  space_destroy(s);
}

void test2_space_has_object() {
  Space *s;
  s = space_create(1);
  space_add_object(s, 1);
  PRINT_TEST_RESULT(space_has_object(s, 2) == FALSE);
  space_destroy(s);
}

void test1_space_get_gdesc() {
  Space *s;
  s = space_create(1);
  space_set_gdesc(s, "<O)__/ ", 1);
  PRINT_TEST_RESULT(space_get_gdesc(s, 1) != NULL);
  space_destroy(s);
}

void test2_space_get_gdesc() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_gdesc(s, 3) == NULL);
  space_destroy(s);
}

void test1_space_are_linked() {
  Space *s;
  Link *l;
  s = space_create(1);
  l = link_create(1);
  link_set_space1(l, 2);
  link_set_space2(l, 3);
  PRINT_TEST_RESULT(space_are_linked(2, 3, l) == TRUE);
  link_destroy(l);
  space_destroy(s);
}

void test2_space_are_linked() {
  Space *s;
  Link *l;
  s = space_create(1);
  l = link_create(1);
  PRINT_TEST_RESULT(space_are_linked(2, 3, l) == FALSE);
  link_destroy(l);
  space_destroy(s);
}

void test1_space_set_description() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_description(s, "goose field") == OK);
  space_destroy(s);
}

void test2_space_set_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_description(s, "goose field") == ERROR);
}

void test3_space_set_description() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_description(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_get_description() {
  Space *s;
  s = space_create(1);
  space_set_description(s, "goose field");
  space_set_light_act(s, 1);
  PRINT_TEST_RESULT(strcmp(space_get_description(s), "goose field") == 0);
  space_destroy(s);
}

void test2_space_get_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_description(s) == NULL);
}

void test1_space_set_up_link() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_up_link(s, 1) == OK);
  space_destroy(s);
}

void test2_space_set_up_link() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_up_link(s, NO_ID) == ERROR);
  space_destroy(s);
}

void test1_space_get_up_link() {
  Space *s;
  s = space_create(1);
  space_set_up_link(s, 1);
  PRINT_TEST_RESULT(space_get_up_link(s) == 1);
  space_destroy(s);
}

void test2_space_get_up_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_up_link(s) == NO_ID);
}

void test1_space_set_down_link() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_down_link(s, 1) == OK);
  space_destroy(s);
}

void test2_space_set_down_link() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_down_link(s, NO_ID) == ERROR);
  space_destroy(s);
}

void test1_space_get_down_link() {
  Space *s;
  s = space_create(1);
  space_set_down_link(s, 1);
  PRINT_TEST_RESULT(space_get_down_link(s) == 1);
  space_destroy(s);
}

void test2_space_get_down_link() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_down_link(s) == NO_ID);
}

void test1_space_get_object_from_pos() {
  Space *s;
  s = space_create(1);
  space_add_object(s, 1);
  PRINT_TEST_RESULT(space_get_object_from_pos(s, 0) == 1);
  space_destroy(s);
}

void test2_space_get_object_from_pos() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_object_from_pos(s, 0) == NO_ID);
  space_destroy(s);
}

void test1_space_set_full_description() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_full_description(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_full_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_full_description(s, "hola") == ERROR);
}

void test1_space_get_full_description() {
  Space *s;
  s = space_create(1);
  space_set_full_description(s, "hola");
  PRINT_TEST_RESULT(strcmp(space_get_full_description(s), "hola") == 0);
  space_destroy(s);
}

void test2_space_get_full_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_full_description(s) == NULL);
}

void test1_space_set_light_init() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_light_init(s, 1) == OK);
  space_destroy(s);
}

void test2_space_set_light_init() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_light_init(s, 1) == ERROR);
}

void test1_space_get_light_init() {
  Space *s;
  s = space_create(1);
  space_set_light_init(s, 1);
  PRINT_TEST_RESULT(space_get_light_init(s) == 1);
  space_destroy(s);
}

void test2_space_get_light_init() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_light_init(s) == FALSE);
}

void test1_space_set_light_act() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_light_act(s, 1) == OK);
  space_destroy(s);
}

void test2_space_set_light_act() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_light_act(s, 1) == ERROR);
}

void test1_space_get_light_act() {
  Space *s;
  s = space_create(1);
  space_set_light_act(s, 1);
  PRINT_TEST_RESULT(space_get_light_act(s) == 1);
  space_destroy(s);
}

void test2_space_get_light_act() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_light_act(s) == FALSE);
}

void test1_space_get_init_description() {
  Space *s;
  s = space_create(1);
  space_set_description(s, "hola");
  space_set_light_act(s, 1);
  PRINT_TEST_RESULT(strcmp(space_get_init_description(s), "hola") == 0);
  space_destroy(s);
}

void test2_space_get_init_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_init_description(s) == NULL);
}