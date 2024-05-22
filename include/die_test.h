/** 
 * @brief It declares the tests for the die module
 * 
 * @file die_test.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 06-03-2021
 * @copyright GNU Public License
 */

#ifndef DIE_TEST_H
#define DIE_TEST_H

/**
 * @test Test die creation
 * @pre Die ID, min and max value
 * @post Non NULL pointer to die 
 */
void test1_die_create();

/**
 * @test Test die creation
 * @pre Die ID = NO_ID
 * @post Output==NULL
 */
void test2_die_create();

/**
 * @test Test die creation
 * @pre Die ID 
 * @pre Invalid min value
 * @pre Max value
 * @post Output==NULL
 */
void test3_die_create();

/**
 * @test Test die creation
 * @pre Die ID 
 * @pre Min value greater than max value
 * @post Output==NULL
 */
void test4_die_create();

/**
 * @test Test die_id getting
 * @pre Pointer to die_id
 * @post Die_ID == Supplied Die Id
 */
void test1_die_get_id();

/**
 * @test Test die_id getting
 * @pre Pointer to die_id = NULL
 * @post Die_ID == NO_ID
 */
void test2_die_get_id();

/**
 * @test Test die_roll
 * @pre Pointer to die_roll
 * @post Outout==OK
 */
void test1_die_roll();

/**
 * @test Test die_roll
 * @pre Pointer to die_roll = NULL
 * @post Outout==ERROR
 */
void test2_die_roll();

/**
 * @test Test die_last_value getting
 * @pre Pointer to die_last_value
 * @post Output==NO -1
 */
void test1_die_get_last_num();

/**
 * @test Test die_last_value getting
 * @pre Pointer to die_last_value = NULL
 * @post Output==-1
 */
void test2_die_get_last_num();

/**
 * @test Test die_min getting
 * @pre Pointer to die = NULL
 * @post Output == -1
 */
void test1_die_get_min();

/**
 * @test Test die_min getting
 * @pre Pointer to die
 * @post Die_ID == Supplied Die min
 */
void test2_die_get_min();

/**
 * @test Test die_max getting
 * @pre Pointer to die = NULL
 * @post Output == -1
 */
void test1_die_get_max();

/**
 * @test Test die_max getting
 * @pre Pointer to die
 * @post Die_ID == Supplied Die max
 */
void test2_die_get_max();

#endif