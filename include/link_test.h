/** 
 * @brief It declares the tests for the link module
 * 
 * @file link_test.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 26-03-2021
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Test link creation
 * @pre Link ID 
 * @post Non NULL pointer to link 
 */
void test1_link_create();

/**
 * @test Test link creation
 * @pre Link ID = NO_ID 
 * @post Output==NULL
 */
void test2_link_create();

/**
 * @test Test function for link_name setting
 * @pre String with link name
 * @post Ouput==OK 
 */
void test1_link_set_name();

/**
 * @test Test function for link_name setting
 * @pre Pointer to link = NULL 
 * @post Output==ERROR
 */
void test2_link_set_name();

/**
 * @test Test function for link_name setting
 * @pre Pointer to link_name = NULL (point to link = NON NULL) 
 * @post Output==ERROR
 */
void test3_link_set_name();

/**
 * @test Test function for link_space1 setting
 * @pre Id of a space
 * @post Ouput==OK 
 */
void test1_link_set_space1();

/**
 * @test Test function for link_space1 setting
 * @pre Pointer to link = NULL 
 * @post Output==ERROR
 */
void test2_link_set_space1();

/**
 * @test Test function for link_space1 setting
 * @pre Id of a space = NO_ID (point to link = NON NULL)
 * @post Ouput==ERROR 
 */
void test3_link_set_space1();

/**
 * @test Test function for link_space2 setting
 * @pre Id of a space
 * @post Ouput==OK 
 */
void test1_link_set_space2();

/**
 * @test Test function for link_space2 setting
 * @pre Pointer to link = NULL 
 * @post Output==ERROR
 */
void test2_link_set_space2();

/**
 * @test Test function for link_space2 setting
 * @pre Id of a link_space2 = NO_ID (point to link = NON NULL)
 * @post Ouput==ERROR 
 */
void test3_link_set_space2();

/**
 * @test Test function for link_close setting
 * @pre Set link close to TRUE
 * @post Ouput==OK 
 */
void test1_link_set_close();

/**
 * @test Test function for link_close setting
 * @pre Pointer to link = NULL 
 * @post Output==ERROR
 */
void test2_link_set_close();

/**
 * @test Test function for link_id getting
 * @pre Pointer to link
 * @post Link ID == Supplied Link Id
 */
void test1_link_get_id();

/**
 * @test Test function for link_id getting
 * @pre Pointer to link = NULL 
 * @post Link ID == NO_ID
 */
void test2_link_get_id();

/**
 * @test Test function for link_name getting
 * @pre Pointer to link
 * @pre String with link name
 * @post Link_name == Supplied Link name
 */
void test1_link_get_name();

/**
 * @test Test function for link_name getting
 * @pre Pointer to link = NULL
 * @post Output==NULL
 */
void test2_link_get_name();

/**
 * @test Test function for link_space1 getting
 * @pre Pointer to link
 * @pre Space's Id
 * @post Link_space1 == Supplied space Id
 */
void test1_link_get_space1();

/**
 * @test Test function for link_space1 getting
 * @pre Pointer to link = NULL 
 * @post Output == NO_ID
 */
void test2_link_get_space1();

/**
 * @test Test function for link_space2 getting
 * @pre Pointer to link
 * @pre Space's Id
 * @post Link_space2 == Supplied space Id
 */
void test1_link_get_space2();

/**
 * @test Test function for link_space2 getting
 * @pre Pointer to link = NULL 
 * @post Output == NO_ID
 */
void test2_link_get_space2();

/**
 * @test Test function for link_is_close 
 * @pre Pointer to link 
 * @pre Set link close to FALSE
 * @post Output == FALSE
 */
void test1_link_is_close();

/**
 * @test Test function for link_is_close
 * @pre Pointer to link = NULL 
 * @post Output == FALSE
 */
void test2_link_is_close();

#endif