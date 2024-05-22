/** 
 * @brief It tests game module
 * 
 * @file game_test.c
 * @author Manuel Ardid
 * @version 1.0 
 * @date 16-04-2021
 * @copyright GNU Public License
 */

#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_test.h"
#include "test.h"

/** Defines the constant variables */
#define MAX_TESTS 38

/** 
 * @brief Main function for GAME unit tests. 
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
    printf("Running all test for module Game:\n");
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
    test1_game_add_object();
  if (all || test == 2)
    test2_game_add_object();
  if (all || test == 3)
    test3_game_add_object();
  if (all || test == 4)
    test1_game_add_space();
  if (all || test == 5)
    test2_game_add_space();
  if (all || test == 6)
    test1_game_add_player();
  if (all || test == 7)
    test2_game_add_player();
  if (all || test == 8)
    test3_game_add_player();
  if (all || test == 9)
    test1_game_add_link();
  if (all || test == 10)
    test2_game_add_link();
  if (all || test == 11)
    test3_game_add_link();
  if (all || test == 12)
    test1_game_get_space();
  if (all || test == 13)
    test2_game_get_space();
  if (all || test == 14)
    test3_game_get_space();
  if (all || test == 15)
    test1_game_get_object();
  if (all || test == 16)
    test2_game_get_object();
  if (all || test == 17)
    test3_game_get_object();
  if (all || test == 18)
    test1_game_get_link();
  if (all || test == 19)
    test2_game_get_link();
  if (all || test == 20)
    test3_game_get_link();
  if (all || test == 21)
    test1_game_get_player();
  if (all || test == 22)
    test2_game_get_player();
  if (all || test == 23)
    test1_game_set_player_location();
  if (all || test == 24)
    test2_game_set_player_location();
  if (all || test == 25)
    test1_game_set_object_location();
  if (all || test == 26)
    test2_game_set_object_location();
  if (all || test == 27)
    test3_game_set_object_location();
  if (all || test == 28)
    test1_game_get_player_location();
  if (all || test == 29)
    test1_game_get_object_location();
  if (all || test == 30)
    test2_game_get_object_location();
  if (all || test == 31)
    test3_game_get_object_location();
  if (all || test == 32)
    test1_game_get_last_die_value();
  if (all || test == 33)
    test2_game_get_last_die_value();
  if (all || test == 34)
    test1_game_set_last_command_st();
  if (all || test == 35)
    test2_game_set_last_command_st();
  if (all || test == 36)
    test1_game_get_last_command_st();
  if (all || test == 37)
    test2_game_get_last_command_st();
  if (all || test == 38)
    test1_game_get_last_command();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_game_add_object() {
  Game *g = NULL;
  Object *obj = NULL;
  g = game_create();
  obj = object_create(5);
  PRINT_TEST_RESULT(game_add_object(g, obj) == OK);
  game_destroy(g);
}

void test2_game_add_object() {
  Game *g = NULL;
  Object *obj = NULL;
  g = game_create();
  PRINT_TEST_RESULT(game_add_object(g, obj) == ERROR);
  game_destroy(g);
}

void test3_game_add_object() {
  Game *g = NULL;
  Object *obj = NULL;
  obj = object_create(5);
  PRINT_TEST_RESULT(game_add_object(g, obj) == ERROR);
  object_destroy(obj);
}

void test1_game_add_space() {
  Game *g = NULL;
  Space *s = NULL;
  g = game_create();
  s = space_create(5);
  PRINT_TEST_RESULT(game_add_space(g, s) == OK);
  game_destroy(g);
}

void test2_game_add_space() {
  Game *g = NULL;
  Space *s = NULL;
  g = game_create();
  PRINT_TEST_RESULT(game_add_space(g, s) == ERROR);
  game_destroy(g);
}

void test1_game_add_player() {
  Game *g = NULL;
  Player *p = NULL;
  g = game_create();
  p = player_create(5);
  PRINT_TEST_RESULT(game_add_player(g, p) == OK);
  game_destroy(g);
}

void test2_game_add_player() {
  Game *g = NULL;
  Player *p = NULL;
  g = game_create();
  PRINT_TEST_RESULT(game_add_player(g, p) == ERROR);
  game_destroy(g);
}

void test3_game_add_player() {
  Game *g = NULL;
  Player *p = NULL;
  p = player_create(5);
  PRINT_TEST_RESULT(game_add_player(g, p) == ERROR);
  player_destroy(p);
}

void test1_game_add_link() {
  Game *g = NULL;
  Link *l = NULL;
  g = game_create();
  l = link_create(5);
  PRINT_TEST_RESULT(game_add_link(g, l) == OK);
  game_destroy(g);
}

void test2_game_add_link() {
  Game *g = NULL;
  Link *l = NULL;
  g = game_create();
  PRINT_TEST_RESULT(game_add_link(g, l) == ERROR);
  game_destroy(g);
}

void test3_game_add_link() {
  Game *g = NULL;
  Link *l = NULL;
  l = link_create(5);
  PRINT_TEST_RESULT(game_add_link(g, l) == ERROR);
  link_destroy(l);
}

void test1_game_get_space() {
  Game *g = NULL;
  Space *s = NULL;
  g = game_create();
  s = space_create(5);
  game_add_space(g, s);
  PRINT_TEST_RESULT(game_get_space(g, 5) != NULL);
  game_destroy(g);
}

void test2_game_get_space() {
  Game *g = NULL;
  g = game_create();
  PRINT_TEST_RESULT(game_get_space(g, NO_ID) == NULL);
  game_destroy(g);
}

void test3_game_get_space() {
  Game *g = NULL;
  g = game_create();
  PRINT_TEST_RESULT(game_get_space(g, 5) == NULL);
  game_destroy(g);
}

void test1_game_get_object() {
  Game *g = NULL;
  Object *obj = NULL;
  g = game_create();
  obj = object_create(5);
  game_add_object(g, obj);
  PRINT_TEST_RESULT(game_get_object(g, 0) != NULL);
  game_destroy(g);
}

void test2_game_get_object() {
  Game *g = NULL;
  g = game_create();
  PRINT_TEST_RESULT(game_get_object(g, -1) == NULL);
  game_destroy(g);
}

void test3_game_get_object() {
  Game *g = NULL;
  PRINT_TEST_RESULT(game_get_object(g, 0) == NULL);
}

void test1_game_get_link() {
  Game *g = NULL;
  Link *l = NULL;
  g = game_create();
  l = link_create(5);
  game_add_link(g, l);
  PRINT_TEST_RESULT(game_get_link(g, 5) != NULL);
  game_destroy(g);
}

void test2_game_get_link() {
  Game *g = NULL;
  g = game_create();
  PRINT_TEST_RESULT(game_get_link(g, NO_ID) == NULL);
  game_destroy(g);
}

void test3_game_get_link() {
  Game *g = NULL;
  PRINT_TEST_RESULT(game_get_link(g, 0) == NULL);
}

void test1_game_get_player() {
  Game *g;
  Player *p;
  g = game_create();
  p = player_create(1);
  game_add_player(g, p);
  PRINT_TEST_RESULT(game_get_player(g) == p);
  game_destroy(g);
}

void test2_game_get_player() {
  Game *g = NULL;
  PRINT_TEST_RESULT(game_get_player(g) == NULL);
}

void test1_game_set_player_location() {
  Game *g;
  Player *p;
  g = game_create();
  p = player_create(1);
  game_add_player(g, p);
  PRINT_TEST_RESULT(game_set_player_location(g, 1) == OK);
  game_destroy(g);
}

void test2_game_set_player_location() {
  Game *g;
  g = game_create();
  PRINT_TEST_RESULT(game_set_player_location(g, NO_ID) == ERROR);
  game_destroy(g);
}

void test1_game_set_object_location() {
  Game *g;
  Space *s;
  g = game_create();
  s = space_create(1);
  game_add_space(g, s);
  PRINT_TEST_RESULT(game_set_object_location(g, 1, 1) == OK);
  game_destroy(g);
}

void test2_game_set_object_location() {
  Game *g;
  g = game_create();
  PRINT_TEST_RESULT(game_set_object_location(g, NO_ID, 1) == ERROR);
  game_destroy(g);
}

void test3_game_set_object_location() {
  Game *g;
  g = game_create();
  PRINT_TEST_RESULT(game_set_object_location(g, 1, NO_ID) == ERROR);
  game_destroy(g);
}

void test1_game_get_player_location() {
  Game *g;
  Player *p;
  g = game_create();
  p = player_create(1);
  game_add_player(g, p);
  game_set_player_location(g, 1);
  PRINT_TEST_RESULT(game_get_player_location(g) == 1);
  game_destroy(g);
}

void test1_game_get_object_location() {
  Game *g;
  Space *s;
  g = game_create();
  s = space_create(1);
  game_add_space(g, s);
  game_set_object_location(g, 1, 1);
  PRINT_TEST_RESULT(game_get_object_location(g, 1) == 1);
  game_destroy(g);
}

void test2_game_get_object_location() {
  Game *g;
  Space *s;
  g = game_create();
  s = space_create(1);
  game_add_space(g, s);
  game_set_object_location(g, 1, 1);
  PRINT_TEST_RESULT(game_get_object_location(g, 2) == NO_ID);
  game_destroy(g);
}

void test3_game_get_object_location() {
  Game *g;
  g = game_create();
  PRINT_TEST_RESULT(game_get_object_location(g, NO_ID) == NO_ID);
  game_destroy(g);
}

void test1_game_get_last_die_value() {
  Game *g;
  Die *d;
  int die_value;
  g = game_create();
  d = game_get_die(g);
  die_roll(d);
  die_value = game_get_last_die_value(g);
  PRINT_TEST_RESULT(die_value > 0 && die_value <= 6);
  game_destroy(g);
}

void test2_game_get_last_die_value() {
  Game *g = NULL;
  PRINT_TEST_RESULT(game_get_last_die_value(g) == ERROR);
}

void test1_game_set_last_command_st() {
  Game *g;
  g = game_create();
  PRINT_TEST_RESULT(game_set_last_command_st(g, OK) == OK);
  game_destroy(g);
}

void test2_game_set_last_command_st() {
  Game *g = NULL;
  PRINT_TEST_RESULT(game_set_last_command_st(g, OK) == ERROR);
}

void test1_game_get_last_command_st() {
  Game *g;
  g = game_create();
  game_set_last_command_st(g, ERROR);
  PRINT_TEST_RESULT(game_get_last_command_st(g) == ERROR);
  game_destroy(g);
}

void test2_game_get_last_command_st() {
  Game *g = NULL;
  PRINT_TEST_RESULT(game_get_last_command_st(g) == ERROR);
}

void test1_game_get_last_command() {
  Game *g;
  g = game_create();
  game_update(g, ROLL);
  PRINT_TEST_RESULT(game_get_last_command(g) == ROLL);
  game_destroy(g);
}