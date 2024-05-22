/** 
 * @brief It declares the tests for the object module
 * 
 * @file object_test.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 09-04-2021
 * @copyright GNU Public License
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

/**
 * @test Test object creation
 * @pre Object ID
 * @post Non NULL pointer to object 
 */
void test1_object_create();

/**
 * @test Test object creation
 * @pre Object ID
 * @post Non NULL pointer to object 
 */
void test2_object_create();

/**
 * @test Test function for object_id getting
 * @pre Pointer to object
 * @post Object ID == Supplied object Id
 */
void test1_object_get_id();

/**
 * @test Test function for object_id getting
 * @pre Pointer to object = NULL 
 * @post Object ID == NO_ID
 */
void test2_object_get_id();

/**
 * @test Test function for object_name setting
 * @pre String with object name
 * @post Ouput==OK 
 */
void test1_object_set_name();

/**
 * @test Test function for object_name setting
 * @pre Pointer to object = NULL 
 * @post Output==ERROR
 */
void test2_object_set_name();

/**
 * @test Test function for object_name setting
 * @pre Pointer to object_name = NULL (point to object = NON NULL) 
 * @post Output==ERROR
 */
void test3_object_set_name();

/**
 * @test Test function for object_name getting
 * @pre Pointer to object
 * @pre String with object name
 * @post Object_name == Supplied object name
 */
void test1_object_get_name();

/**
 * @test Test function for lobject_name getting
 * @pre Pointer to object = NULL
 * @post Output==NULL
 */
void test2_object_get_name();

/**
 * @test Test function for object_description setting
 * @pre String with object description
 * @post Ouput==OK 
 */
void test1_object_set_description();

/**
 * @test Test function for object_description setting
 * @pre Pointer to object = NULL 
 * @post Output==ERROR
 */
void test2_object_set_description();

/**
 * @test Test function for object_description setting
 * @pre Pointer to object_description = NULL (point to object = NON NULL) 
 * @post Output==ERROR
 */
void test3_object_set_description();

/**
 * @test Test function for object_description getting
 * @pre Pointer to object
 * @pre String with object description
 * @post Object_description == Supplied object description
 */
void test1_object_get_description();

/**
 * @test Test function for lobject_description getting
 * @pre Pointer to object = NULL
 * @post Output==NULL
 */
void test2_object_get_description();

/**
 * @test Test function for object_set_movable getting
 * @pre Pointer to object
 * @post object_is_movable = FALSE
 */
void test1_object_set_movable();

/**
 * @test Test function for object_set_movable getting
 * @pre Pointer to object
 * @pre object_set_movable 1
 * @post object_is_movable = FALSE
 */
void test2_object_set_movable();

/**
 * @test Test function for object_is_movable getting
 * @pre Pointer to object
 * @post object_is_movable = FALSE
 */
void test1_object_get_movable();

/**
 * @test Test function for object_is_movable getting
 * @pre Pointer to object
 * @pre object_set_movable 1
 * @post object_is_movable = FALSE
 */
void test2_object_get_movable();

/**
 * @test Test function for object_set_illuminate getting
 * @pre Pointer to object
 * @post object_can_illuminate = FALSE
 */
void test1_object_set_illuminate();

/**
 * @test Test function for object_set_illuminate getting
 * @pre Pointer to object
 * @pre object_set_illuminate 1
 * @post object_can_illuminate = FALSE
 */
void test2_object_set_illuminate();

/**
 * @test Test function for object_can_illuminate getting
 * @pre Pointer to object
 * @post object_can_illuminate = FALSE
 */
void test1_object_can_illuminate();

/**
 * @test Test function for object_can_illuminate getting
 * @pre Pointer to object
 * @pre object_set_illuminate 1
 * @post object_can_illuminate = FALSE
 */
void test2_object_can_illuminate();

/**
 * @test Test function for object_set_turnedon setting
 * @pre Pointer to object
 * @post object_is_turnedon = FALSE
 */
void test1_object_set_turnedon();

/**
 * @test Test function for object_set_turnedon setting
 * @pre Pointer to object
 * @pre object_set_turnedon 1
 * @post object_is_turnedon = FALSE
 */
void test2_object_set_turnedon();

/**
 * @test Test function for object_is_turnedon getting
 * @pre Pointer to object
 * @post object_is_turnedon = FALSE
 */
void test1_object_is_turnedon();

/**
 * @test Test function for object_is_turnedon getting
 * @pre Pointer to object
 * @pre object_set_turnedon 1
 * @post object_is_turnedon = FALSE
 */
void test2_object_is_turnedon();

/**
 * @test Test function for object_set_dependency getting
 * @pre Pointer to object
 * @post Object_get_dependency = NO_ID
 */
void test1_object_set_dependency();

/**
 * @test Test function for object_set_dependency getting
 * @pre Pointer to object
 * @pre object_set_dependency 2
 * @post Object_get_dependency = 2
 */
void test2_object_set_dependency();

/**
 * @test Test function for object_get_dependency getting
 * @pre Pointer to object
 * @post Object_get_dependency = NO_ID
 */
void test1_object_get_dependency();

/**
 * @test Test function for object_get_dependency getting
 * @pre Pointer to object
 * @pre object_set_dependency 2
 * @post Object_get_dependency = 2
 */
void test2_object_get_dependency();

/**
 * @test Test function for object_set_open getting
 * @pre Pointer to object
 * @post Object_get_open = NO_ID
 */
void test1_object_set_open();

/**
 * @test Test function for object_set_open getting
 * @pre Pointer to object
 * @pre object_set_open 2
 * @post Object_get_open = 2
 */
void test2_object_set_open();

/**
 * @test Test function for object_get_open getting
 * @pre Pointer to object
 * @post Object_get_open = NO_ID
 */
void test1_object_get_open();

/**
 * @test Test function for object_get_open getting
 * @pre Pointer to object
 * @pre object_set_open 2
 * @post Object_get_open = 2
 */
void test2_object_get_open();

/**
 * @test Test function for object_discovery setting
 * @pre Pointer to object
 * @post Output = OK
 */
void test1_object_set_discovery();

/**
 * @test Test function for object_discovery setting
 * @pre Pointer to object = NULL
 * @post Output = ERROR
 */
void test2_object_set_discovery();

/**
 * @test Test function for object_is_discovered
 * @pre Pointer to object and set it to FALSE
 * @post Output = FALSE
 */
void test1_object_is_discovered();

/**
 * @test Test function for  object_is_discovered
 * @pre Pointer to object = NULL
 * @post Output = FALSE
 */
void test2_object_is_discovered();

#endif
