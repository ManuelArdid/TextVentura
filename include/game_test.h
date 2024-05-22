/** 
 * @brief It declares the tests for the game module
 * 
 * @file game_test.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 16-04-2021
 * @copyright GNU Public License
 */

#ifndef GAME_TEST_H
#define GAME_TEST_H

/**
 * @test Test function for game_object adding
 * @pre Pointer to game and pointer to object
 * @post Output == OK
 */
void test1_game_add_object();

/**
 * @test Test function for game_object adding
 * @pre Pointer to object = NULL (Pointer to game = NON NULL)
 * @post Output == ERROR
 */
void test2_game_add_object();

/**
 * @test Test function for game_object adding
 * @pre Pointer to game = NULL (Pointer to object = NON NULL)
 * @post Output == ERROR
 */
void test3_game_add_object();

/**
 * @test Test function for game_space adding
 * @pre Pointer to game and pointer to space
 * @post Output == OK
 */
void test1_game_add_space();

/**
 * @test Test function for game_space adding
 * @pre Pointer to space = NULL (Pointer to game = NON NULL)
 * @post Output == ERROR
 */
void test2_game_add_space();

/**
 * @test Test function for game_player adding
 * @pre Pointer to game and pointer to player
 * @post Output == OK
 */
void test1_game_add_player();

/**
 * @test Test function for game_player adding
 * @pre Pointer to player = NULL (Pointer to game = NON NULL)
 * @post Output == ERROR
 */
void test2_game_add_player();

/**
 * @test Test function for game_player adding
 * @pre Pointer to game = NULL (Pointer to player = NON NULL)
 * @post Output == ERROR
 */
void test3_game_add_player();

/**
 * @test Test function for game_link adding
 * @pre Pointer to game and pointer to link
 * @post Output == OK
 */
void test1_game_add_link();

/**
 * @test Test function for game_link adding
 * @pre Pointer to link = NULL (Pointer to game = NON NULL)
 * @post Output == ERROR
 */
void test2_game_add_link();

/**
 * @test Test function for game_link adding
 * @pre Pointer to game = NULL (Pointer to link = NON NULL)
 * @post Output == ERROR
 */
void test3_game_add_link();

/**
 * @test Test function for game_space getting
 * @pre Pointer to game and space id = supplied id
 * @post Output != NULL
 */
void test1_game_get_space();

/**
 * @test Test function for game_space getting
 * @pre Pointer to game and space id = NO_ID
 * @post Output == NULL
 */
void test2_game_get_space();

/**
 * @test Test function for game_space getting
 * @pre Pointer to game = NULL
 * @post Output == NULL
 */
void test3_game_get_space();

/**
 * @test Test function for game_object getting
 * @pre Pointer to game and position = 0
 * @post Output != NULL
 */
void test1_game_get_object();

/**
 * @test Test function for game_object getting
 * @pre Pointer to game and position = invalid 
 * @post Output == NULL
 */
void test2_game_get_object();

/**
 * @test Test function for game_object getting
 * @pre Pointer to game = NULL
 * @post Output == NULL
 */
void test3_game_get_object();

/**
 * @test Test function for game_link getting
 * @pre Pointer to game and link id = supplied id
 * @post Output != NULL
 */
void test1_game_get_link();

/**
 * @test Test function for game_link getting
 * @pre Pointer to game and link id = NO_ID
 * @post Output == NULL
 */
void test2_game_get_link();

/**
 * @test Test function for game_link getting
 * @pre Pointer to game = NULL
 * @post Output == NULL
 */
void test3_game_get_link();

/**
 * @test Test function for game_player getting
 * @pre Pointer to game
 * @post Output == OK
 */
void test1_game_get_player();

/**
 * @test Test function for game_player getting
 * @pre Pointer to game = NULL
 * @post Output == ERROR
 */
void test2_game_get_player();

/**
 * @test Test function for game_player_location setting
 * @pre Pointer to game and space id = supplied id
 * @post Output == OK
 */
void test1_game_set_player_location();

/**
 * @test Test function for game_player_location setting
 * @pre Pointer to game and space id = NO_ID
 * @post Output == ERROR
 */
void test2_game_set_player_location();

/**
 * @test Test function for game_object_location setting
 * @pre Pointer to game, space id and object id
 * @post Output == OK
 */
void test1_game_set_object_location();

/**
 * @test Test function for game_object_location setting
 * @pre Pointer to game, space id = NO_ID and object id
 * @post Output == ERROR
 */
void test2_game_set_object_location();

/**
 * @test Test function for game_object_location setting
 * @pre Pointer to game, space id and object id = NO_ID
 * @post Output == ERROR
 */
void test3_game_set_object_location();

/**
 * @test Test function for game_player_location getting
 * @pre Pointer to game
 * @post Output == Supplied player location
 */
void test1_game_get_player_location();

/**
 * @test Test function for game_object_location getting
 * @pre Pointer to game and object id = supplied id
 * @post Output == Supplied object location
 */
void test1_game_get_object_location();

/**
 * @test Test function for game_object_location getting
 * @pre Pointer to game and object id = supplied id (object not in game)
 * @post Output == NO_ID
 */
void test2_game_get_object_location();
/**
 * @test Test function for game_object_location getting
 * @pre Object id = NO_ID (Pointer to game = NON NULL)
 * @post Output == NO_ID
 */
void test3_game_get_object_location();

/**
 * @test Test function for game_last_die_value getting
 * @pre Pointer to game
 * @post 0 < die >= 6
 */
void test1_game_get_last_die_value();

/**
 * @test Test function for game_last_die_value getting
 * @pre Pointer to game = NULL
 * @post Output == ERROR
 */
void test2_game_get_last_die_value();

/**
 * @test Test function for game_last_command_st setting
 * @pre Pointer to game and set to OK
 * @post Output == OK
 */
void test1_game_set_last_command_st();

/**
 * @test Test function for game_last_command_st setting
 * @pre Pointer to game = NULL
 * @post Output == ERROR
 */
void test2_game_set_last_command_st();

/**
 * @test Test function for game_last_command getting
 * @pre Pointer to game
 * @post Output == OK
 */
void test1_game_get_last_command_st();

/**
 * @test Test function for game_last_command_st getting
 * @pre Pointer to game = NULL
 * @post Output == ERROR
 */
void test2_game_get_last_command_st();

/**
 * @test Test function for game_last_command getting
 * @pre Update command (Pointer to game = NON NULL)
 * @post Output == ROLL
 */
void test1_game_get_last_command();

#endif