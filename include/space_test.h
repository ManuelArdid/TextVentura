/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Manuel Ardid
 * @version 2.0 
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK 
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test3_space_set_name();

/**
 * @test Test function for space_north setting
 * @pre pointer to space_north
 * @pre space_north ID
 * @post Output==OK
 */
void test1_space_set_north_link();

/**
 * @test Test function for space_north setting
 * @pre pointer to space_north = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test2_space_set_north_link();

/**
 * @test Test function for space_south setting
 * @pre pointer to space_south
 * @pre space_south ID
 * @post Output==OK
 */
void test1_space_set_south_link();

/**
 * @test Test function for space_south setting
 * @pre pointer to space_south = NULL (point to space = NON NULL) 
 * @pre space_south ID 
 * @post Output==ERROR
 */
void test2_space_set_south_link();

/**
 * @test Test function for space_east setting
 * @pre pointer to space_east
 * @pre space_east ID
 * @post Output==OK
 */
void test1_space_set_east_link();

/**
 * @test Test function for space_east setting
 * @pre pointer to space_east = NULL (point to space = NON NULL) 
 * @pre space_east ID 
 * @post Output==ERROR
 */
void test2_space_set_east_link();

/**
 * @test Test function for space_west setting
 * @pre pointer to space_west
 * @pre space_west ID
 * @post Output==OK
 */
void test1_space_set_west_link();

/**
 * @test Test function for space_west setting
 * @pre pointer to space_west = NULL (point to space = NON NULL) 
 * @pre space_west ID 
 * @post Output==ERROR
 */
void test2_space_set_west_link();

/**
 * @test Test function for space_id getting
 * @pre pointer to space_id
 * @post Space_ID == Supplied Space Id
 */
void test1_space_get_id();

/**
 * @test Test function for space_id getting
 * @pre pointer to space_id = NULL
 * @post Output==NO_ID
 */
void test2_space_get_id();

/**
 * @test Test function for space_object adding
 * @pre pointer to space_object
 * @pre space_object ID
 * @post Output==OK
 */
void test1_space_add_object();

/**
 * @test Test function for space_object adding
 * @pre pointer to space_object = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */
void test2_space_add_object();

/**
 * @test Test function for space_object adding
 * @pre pointer to space = NO_ID
 * @post Output==ERROR
 */
void test3_space_add_object();

/**
 * @test Test function for space_name getting
 * @pre pointer to space_name
 * @pre String with space name
 * @post Space_name == Supplied Space name
 */
void test1_space_get_name();

/**
 * @test Test function for space_name getting
 * @pre pointer to space_name = NULL
 * @post Output==NULL
 */
void test2_space_get_name();

/**
 * @test Test function for space_north getting
 * @pre pointer to space_north
 * @post Space_north = Supplied Space north Id
 */
void test1_space_get_north_link();

/**
 * @test Test function for space_north getting
 * @pre pointer to space_north = NULL
 * @post Output==NO_ID
 */
void test2_space_get_north_link();

/**
 * @test Test function for space_south getting
 * @pre pointer to space_south
 * @post Space_south == Supplied Space south Id
 */
void test1_space_get_south_link();

/**
 * @test Test function for space_south getting
 * @pre pointer to space_south = NULL
 * @post Output==NO_ID
 */
void test2_space_get_south_link();

/**
 * @test Test function for space_east getting
 * @pre pointer to space_east
 * @post Space_east == Supplied Space east Id
 */
void test1_space_get_east_link();

/**
 * @test Test function for space_east getting
 * @pre pointer to space_east = NULL
 * @post Output==NO_ID
 */
void test2_space_get_east_link();

/**
 * @test Test function for space_west getting
 * @pre pointer to space_west
 * @post Space_west == Supplied Space west Id
 */
void test1_space_get_west_link();

/**
 * @test Test function for space_west getting
 * @pre pointer to space_west = NULL
 * @post Output==NO_ID
 */
void test2_space_get_west_link();

/**
 * @test Test function for space_object getting
 * @pre pointer to space_object (with no object inside)
 * @post Output==NULL
 */
void test1_space_get_objects();

/**
 * @test Test function for space_object getting
 * @pre pointer to space_object
 * @post Output==NON NULL
 */
void test2_space_get_objects();

/**
 * @test Test function for space_object getting
 * @pre pointer to space_object = NULL
 * @post Output==NULL
 */
void test3_space_get_objects();

/**
 * @test Test function for space_object removing
 * @pre pointer to space_object 
 * @pre space_object ID
 * @post Output==OK
 */
void test1_space_remove_object();

/**
 * @test Test function for space_object removing
 * @pre pointer to space_object
 * @pre NO_ID 
 * @post Output==ERROR
 */
void test2_space_remove_object();

/**
 * @test Test function for space_object removing
 * @pre pointer to space_object = NULL (point to space = NON NULL) 
 * @pre space_object ID
 * @post Output==ERROR
 */
void test3_space_remove_object();

/**
 * @test Test function for space_number_of_objects getting
 * @pre pointer to space_number_of_objects
 * @post space_number_of_objects == Supplied number objects
 */
void test1_space_get_number_of_objects();

/**
 * @test Test function for space_number_of_objects getting
 * @pre pointer to space_number_of_objects (with no objects)
 * @post space_number_of_objects == -1
 */
void test2_space_get_number_of_objects();

/**
 * @test Test function for space_gdesc setting
 * @pre pointer to space_gdesc
 * @pre string with space description
 * @pre row of the description
 * @post Output==OK
 */
void test1_space_set_gdesc();

/**
 * @test Test function for space_gdesc setting
 * @pre pointer to space_gdesc (with invalid string)
 * @pre row of the description
 * @post Output==ERROR
 */
void test2_space_set_gdesc();

/**
 * @test Test function for space_object having
 * @pre pointer to space_object
 * @pre Object ID
 * @post Output==TRUE
 */
void test1_space_has_object();

/**
 * @test Test function for space_object having
 * @pre pointer to space_object 
 * @pre Object ID that it's not in the space
 * @post Output==FALSE
 */
void test2_space_has_object();

/**
 * @test Test function for space_gdesc getting
 * @pre pointer to space_gdesc
 * @pre row of the description
 * @post Output==NON NULL
 */
void test1_space_get_gdesc();

/**
 * @test Test function for space_gdesc getting
 * @pre pointer to space_gdesc (with invalid row)
 * @post Output==NULL
 */
void test2_space_get_gdesc();

/**
 * @test Test function for space_are_linked
 * @pre two space id and a pointer of a link
 * @post Output==TRUE
 */
void test1_space_are_linked();

/**
 * @test Test function for space_are_linked
 * @pre two space id that are not linked and a pointer of a link 
 * @post Output==FALSE
 */
void test2_space_are_linked();

/**
 * @test Test function for space_set_description
 * @pre space_create (1)
 * @post space_set_description("goose field")== OK
 */
void test1_space_set_description();

/**
 * @test Test function for space_set_description
 * @post space_set_description("goose field")== FALSE
 */
void test2_space_set_description();

/**
 * @test Test function for space_set_description
 * @pre space_create (1)
 * @post space_set_description(NULL)== ERROR
 */
void test3_space_set_description();

/**
 * @test Test function for space_set_description
 * @pre space_create (1)
 * @pre space_set_description("goose field")
 * @post Output == 0
 */
void test1_space_get_description();

/**
 * @test Test function for space_set_description
 * @post space_get_description == NULL
 */
void test2_space_get_description();

/**
 * @test Test function for space_set_up_link
 * @pre pointer to space
 * @pre add an id to up link
 * @post Output == OK
 */
void test1_space_set_up_link();

/**
 * @test Test function for space_set_up_link
 * @pre pointer to space
 * @pre NO_ID
 * @post Output == ERROR
 */
void test2_space_set_up_link();

/**
 * @test Test function for space_get_up_link
 * @pre pointer to space
 * @post Output == 1
 */
void test1_space_get_up_link();

/**
 * @test Test function for space_get_up_link
 * @pre pointer to space = NULL
 * @post Output == NO_ID
 */
void test2_space_get_up_link();

/**
 * @test Test function for space_get_down_link
 * @pre pointer to space
 * @pre down link id
 * @post Output == OK
 */
void test1_space_set_down_link();

/**
 * @test Test function for space_get_down_link
 * @pre pointer to space
 * @pre NO_ID
 * @post Output == ERROR
 */
void test2_space_set_down_link();

/**
 * @test Test function for space_get_down_link
 * @pre pointer to space
 * @post Output == 1
 */
void test1_space_get_down_link();

/**
 * @test Test function for space_get_down_link
 * @pre pointer to space = NULL
 * @post Output == NO_ID
 */
void test2_space_get_down_link();

/**
 * @test Test function for pace_get_object_from_pos
 * @pre pointer to space
 * @pre object position
 * @pre add a object
 * @post Output == object id
 */
void test1_space_get_object_from_pos();

/**
 * @test Test function for pace_get_object_from_pos
 * @pre pointer to space
 * @pre object position
 * @post Output == NO_ID
 */
void test2_space_get_object_from_pos();

/**
 * @test Test function for space_set_full_description
 * @pre pointer to space
 * @pre "hola"
 * @post Output == OK
 */
void test1_space_set_full_description();

/**
 * @test Test function for space_set_full_description
 * @pre pointer to space = NULL
 * @pre "hola"
 * @post Output == ERROR
 */
void test2_space_set_full_description();

/**
 * @test Test function for space_get_full_description
 * @pre pointer to space
 * @pre "hola"
 * @post Output == 0
 */
void test1_space_get_full_description();

/**
 * @test Test function for space_get_full_description
 * @pre pointer to space = NULL
 * @pre "hola"
 * @post Output == NULL
 */
void test2_space_get_full_description();

/**
 * @test Test function for space_set_light_init
 * @pre pointer to space
 * @pre the boolean value of the light init
 * @post Output == OK
 */
void test1_space_set_light_init();

/**
 * @test Test function for space_set_light_init
 * @pre pointer to space = NULL
 * @pre the boolean value of the light init
 * @post Output == ERROR
 */
void test2_space_set_light_init();

/**
 * @test Test function for space_get_light_init
 * @pre pointer to space
 * @post Output == 1
 */
void test1_space_get_light_init();

/**
 * @test Test function for space_get_light_init
 * @pre pointer to space
 * @post Output == FALSE
 */
void test2_space_get_light_init();

/**
 * @test Test function for space_set_light_act
 * @pre pointer to space
 * @pre the boolean value of the light act
 * @post Output == OK
 */
void test1_space_set_light_act();

/**
 * @test Test function for space_set_light_act
 * @pre pointer to space = NULL
 * @pre the boolean value of the light act
 * @post Output == ERROR
 */
void test2_space_set_light_act();

/**
 * @test Test function for space_get_light_act
 * @pre pointer to space
 * @post Output == 1
 */
void test1_space_get_light_act();

/**
 * @test Test function for space_get_light_act
 * @pre pointer to space = NULL
 * @post Output == FALSE
 */
void test2_space_get_light_act();

/**
 * @test Test function for space_get_init_description
 * @pre pointer to space
 * @post Output == 0
 */
void test1_space_get_init_description();

/**
 * @test Test function for space_get_init_description
 * @pre pointer to space = NULL
 * @post Output == NULL
 */
void test2_space_get_init_description();

#endif
