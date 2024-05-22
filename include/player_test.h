/** 
 * @brief It declares the tests for the player module
 * 
 * @file player_test.h
 * @version 1.0 
 * @author Manuel Ardid
 * @date 28-03-2021
 */

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

/**
 * @test Test function for player_create setting
 * @pre Player ID
 * @post Output!=NULL
 */
void test1_player_create();

/**
 * @test Test function for player_create setting
 * @pre Player ID
 * @post Output!=NULL
 */
void test2_player_create();

/**
 * @test Test function for player_get_id setting
 * @pre Pointer to player
 * @post player_id == ID
 */
void test1_player_get_id();

/**
 * @test Test function for player_get_id setting
 * @pre Pointer to player = NULL
 * @post player_id == NO_ID
 */
void test2_player_get_id();

/**
 * @test Test function for player_set_name setting
 * @pre Player name
 * @post player_name == Player name
 */
void test1_player_set_name();

/**
 * @test Test function for player_set_name setting
 * @pre Pointer to player = NULL
 * @post player_name == NULL
 */
void test2_player_set_name();

/**
 * @test Test function for player_get_name setting
 * @pre Player name
 * @post player_name == Player name
 */
void test1_player_get_name();

/**
 * @test Test function for player_get_name setting
 * @pre Pointer to player = NULL
 * @post player_name == NULL
 */
void test2_player_get_name();

/**
 * @test Test function for player_set_location setting
 * @pre Player location
 * @post player_location == Player location
 */
void test1_player_set_location();

/**
 * @test Test function for player_set_location setting
 * @pre Pointer to player = NULL
 * @post player_location == NO_ID
 */
void test2_player_set_location();

/**
 * @test Test function for player_get_location setting
 * @pre Player location
 * @post player_location == Player location
 */
void test1_player_get_location();

/**
 * @test Test function for player_get_location setting
 * @pre Pointer to player = NULL
 * @post player_location == NO_ID
 */
void test2_player_get_location();

/**
 * @test Test function for player_add_object setting
 * @pre Player max objects
 * @post output == OK
 */
void test1_player_add_object();

/**
 * @test Test function for player_add_object setting
 * @pre Pointer to player = NULL
 * @post output == FALSE
 */
void test2_player_add_object();

/**
 * @test Test function for player_del_object setting
 * @pre Player add objects (3, 5)
 * @pre Player del objects (3)
 * @post Player has object (3) == FALSE
 */
void test1_player_del_object();

/**
 * @test Test function for player_del_object setting
 * @pre Pointer to player = NULL
 * @post Player has object (3) == FALSE
 */
void test2_player_del_object();

/**
 * @test Test function for player_get_object_from_pos setting
 * @pre Player set max objects 3
 * @pre Player add objects (3, 5, 7)
 * @post Player get object from pos (1) == 3
 */
void test1_player_get_object_from_pos();

/**
 * @test Test function for player_get_object_from_pos setting
 * @pre Pointer to player = NULL
 * @post Player get object from pos (1) == NO_ID
 */
void test2_player_get_object_from_pos();

/**
 * @test Test function for player_has_object setting
 * @pre Player set max objects 2
 * @pre Player add objects (3, 7)
 * @post Player has object (7) == TRUE
 */
void test1_player_has_object();

/**
 * @test Test function for player_has_object setting
 * @pre Pointer to player = NULL
 * @post Player has object (7) == FALSE
 */
void test2_player_has_object();

/**
 * @test Test function for player_get_num_of_objects setting
 * @pre Player set max objects 3
 * @pre Player add objects (3, 7, 4)
 * @post Player get num of objects == 3
 */
void test1_player_get_num_of_objects();

/**
 * @test Test function for player_get_num_of_objects setting
 * @pre Pointer to player = NULL
 * @post Player get num of objects == -1
 */
void test2_player_get_num_of_objects();

/**
 * @test Test function for player_set_max_objects setting
 * @pre Pointer to player
 * @post Player set max objects (4) == OK
 */
void test1_player_set_max_objects();

/**
 * @test Test function for player_set_max_objects setting
 * @pre Pointer to player = NULL
 * @post Player set max objects (4) == ERROR
 */
void test2_player_set_max_objects();

/**
 * @test Test function for player_set_max_objects setting
 * @pre Pointer to player
 * @post Player set max objects (-1) == ERROR
 */
void test3_player_set_max_objects();

/**
 * @test Test function for player_get_num_of_objects setting
 * @pre Player set max objects 2
 * @post Player get max objects == 2
 */
void test1_player_get_max_objects();

/**
 * @test Test function for player_get_num_of_objects setting
 * @pre Pointer to player = NULL
 * @post Player get max objects == -1
 */
void test2_player_get_max_objects();

#endif
