/** 
 * @brief Funtions of set interface
 * 
 * @file set.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 06-03-2021
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

#include "types.h"

/** Define the constant variable */
#define MAX_ID 100

/**
   Defines the type of data
*/

/** 
 * @brief Data structure to implement set. 
 *
 **/
typedef struct _Set Set;

/**
   Public functions
*/

/**
* @brief Create new set
*
* set_create It assigns memory for the new set
*
* @date 06-03-2021
* @author: Manuel Ardid
*
* @return the address of the new set or NULL in case of failure
*/
Set *set_create();

/**
* @brief It destroys a set
*
* set_destroy It frees the memory that the set occupies
*
* @date 06-03-2021
* @author: Manuel Ardid
*
* @param set the set to be freed
* @return OK in case of success or ERROR if it fails
*/
STATUS set_destroy(Set *set);

/**
* @brief Get number of ids in the set
*
* set_get_num_of_ids Where we can get the number of ids in the set
*
* @date 09/03/2021
* @author: Manuel Ardid
*
* @param set where it gets the number of objects
* @return number of the ids in the set or -1 if it fails 
*/
int set_get_num_of_ids(Set *set);

/**
* @brief It has id
*
* set_has_id It sees if the id is in set 
*
* @date 06-03-2021
* @author: Manuel Ardid
*
* @param set where it gets the information of the set
* @param id the id to be searched
* @return TRUE if it in the set or FALSE if it's not
*/
BOOL set_has_id(Set *set, Id id);

/**
* @brief Get id from position
* 
* set_get_id_from_pos It gets the id from the position of 
* the array in the structure
*
* @date 03-03-2021
* @author: Manuel Ardid 
*
* @param set pointer of the set
* @param pos position of the id
* @return the id or NO_ID if it fails
*/
Id set_get_id_from_pos(Set *set, int pos);

/**
* @brief It adds id
*
* set_add It save the id in the array
*
* @date 06-03-2021
* @author: Manuel Ardid
*
* @param set where to save the id
* @param id the id to be added
* @return OK in case of success or ERROR if it fails
*/
STATUS set_add(Set *set, Id id);

/**
* @brief It deletes the id
*
* set_del It delete the id from the array
*
* @date 06-03-2021
* @author: Manuel Ardid
*
* @param set where to save the id
* @param id the id to be deleted
* @return OK in case of success or ERROR if it fails
*/
STATUS set_del(Set *set, Id id);

/**
* @brief Shows the set information
*
* set_print It appears the information on the screen
*
* @date 06-03-2021
* @author: Manuel Ardid
*
* @param set where it gets the set information
* @return OK in case of success or ERROR if it fails
*/
STATUS set_print(Set *set);

#endif