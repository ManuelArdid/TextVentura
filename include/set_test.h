/** 
 * @brief It declares the tests for the set module
 * 
 * @file set_test.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 06-03-2021
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @test Test set creation
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test set creation
 * @pre Pointer to set
 * @post Number of ids == 0
 */
void test2_set_create();

/**
 * @test Test function for get number of ids
 * @pre pointer to set
 * @post Ouput==OK 
 */
void test1_set_get_num_of_ids();

/**
 * @test Test function for get number of ids
 * @pre pointer to set = NULL
 * @post Ouput==ERROR
 */
void test2_set_get_num_of_ids();

/**
 * @test Test function for set_has_id
 * @pre pointer to set
 * @pre supplied id
 * @post Ouput==1
 */
void test1_set_has_id();

/**
 * @test Test function for set_has_id
 * @pre pointer to set = NULL
 * @post Ouput==ERROR
 */
void test2_set_has_id();

/**
 * @test Test function for get id from position
 * @pre pointer to set
 * @pre add an id to set
 * @post Id == Supplied Id
 */
void test1_set_get_id_from_pos();

/**
 * @test Test function for get id from position
 * @pre pointer to set = NULL
 * @post Ouput==NO_ID
 */
void test2_set_get_id_from_pos();

/**
 * @test Test function for set adding 
 * @pre pointer to set
 * @post Ouput==OK 
 */
void test1_set_add();

/**
 * @test Test function for set adding 
 * @pre pointer to set = NULL
 * @post Ouput==ERROR
 */
void test2_set_add();

/**
 * @test Test function for set deleting 
 * @pre pointer to set
 * @pre id added
 * @post Output==OK
 */
void test1_set_del();

/**
 * @test Test function for set deleting 
 * @pre pointer to set = NULL
 * @post Ouput==ERROR
 */
void test2_set_del();

#endif
