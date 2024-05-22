/** 
 * @brief It declares the tests for the inventory module
 * 
 * @file inventory_test.h
 * @author Manuel Ardid Clavería
 * @version 1.0 
 * @date 01-03-2021
 * @copyright GNU Public License
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

/**
 * @test Test function for inventory_create setting
 * @pre Inventory create
 * @post Output != NULL
 */
void test1_inventory_create();

/**
 * @test Test function for inventory_create setting
 * @post Output == NULL
 */
void test2_inventory_create();

/**
 * @test Test function for inventory_get_object_from_pos setting
 * @pre Inventory create
 * @pre inventory set max 3
 * @pre Inventory add 1
 * @post inventory get object from pos (0) == 1
 */
void test1_inventory_get_object_from_pos();

/**
 * @test Test function for inventory_get_object_from_pos setting
 * @post inventory get object from pos (0) == NO_ID
 */
void test2_inventory_get_object_from_pos();

/**
 * @test Test function for inventory_add_id setting
 * @pre Inventory create
 * @pre inventory set max 3
 * @pre Inventory add 9
 * @post inventory get object from pos (0) == 9
 */
void test1_inventory_add_id();

/**
 * @test Test function for inventory_get_object_from_pos setting
 * @post inventory add id (9) == ERROR
 */
void test2_inventory_add_id();

/**
 * @test Test function for inventory_del_id setting
 * @pre Inventory create
 * @pre inventory set max 3
 * @pre Inventory add 7
 * @post inventory del id (7) == OK
 */
void test1_inventory_del_id();

/**
 * @test Test function for inventory_del_id setting
 * @post inventory del id (7) == ERROR
 */
void test2_inventory_del_id();

/**
 * @test Test function for inventory_set_max setting
 * @pre Inventory create
 * @post inventory set max (5) == OK
 */
void test1_inventory_set_max();

/**
 * @test Test function for inventory_set_max setting
 * @post inventory set mac (5) == ERROR
 */
void test2_inventory_set_max();

/**
 * @test Test function for inventory_get_max setting
 * @pre Inventory create
 * @pre Inventory set max (5)
 * @post inventory get max == 5
 */
void test1_inventory_get_max();

/**
 * @test Test function for inventory_get_max setting
 * @post inventory get max == -1
 */
void test2_inventory_get_max();

/**
 * @test Test function for inventory_is_full setting
 * @pre Inventory create
 * @pre inventory set max 1
 * @pre Inventory add 1
 * @post inventory is full == TRUE
 */
void test1_inventory_is_full();

/**
 * @test Test function for inventory_is_full setting
 * @pre Inventory create
 * @pre inventory set max 10
 * @pre Inventory add 7
 * @post inventory del id (7) == FALSE
 */
void test2_inventory_is_full();

/**
 * @test Test function for inventory_is_empty setting
 * @pre Inventory create
 * @pre inventory set max 3
 * @post inventory is empty == TRUE
 */
void test1_inventory_is_empty();

/**
 * @test Test function for inventory_is_empty setting
 * @pre Inventory create
 * @pre inventory set max 3
 * @pre inventory add (1)
 * @post inventory is empty == FALSE
 */
void test2_inventory_is_empty();

/**
 * @test Test function for inventory_print setting
 * @post inventory print == ERROR
 */
void test1_inventory_print();

/**
 * @test Test function for inventory_print setting
 * @pre inventory create
 * @post inventory print == OK
 */
void test2_inventory_print();

/**
 * @test Test function for inventory_has_object setting
 * @pre pointer to inventory
 * @pre add an id to inventory
 * @post Ouput == TRUE
 */
void test1_inventory_has_object();

/**
 * @test Test function for inventory_has_object setting
 * @pre Pointer to inventory = NULL
 * @post Ouput == FALSE
 */
void test2_inventory_has_object();
#endif