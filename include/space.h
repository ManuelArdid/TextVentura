/** 
 * @brief Funtions of space inteface
 * 
 * @file space.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "link.h"
#include "types.h"

/** Defines the constant variables */
#define MAX_SPACES 100
/** Defines the constant variables */
#define FIRST_SPACE 1
/** Defines the constant variables */
#define INC1 3
/** Defines the constant variables */
#define INC2 7

/**
   Defines the type of data
*/

/** 
 * @brief Data structure to implement Space. 
 *
 **/
typedef struct _Space Space;

/**
   Public functions
*/

/**
* @brief Creation of space
*
* space_create Create space based on space structure
*
* @date 16/02/2021
* @author: Manuel Ardid
*
* @param id id of the space
* @return the direction of space or NULL if it fails
*/
Space *space_create(Id id);

/**
* @brief Destruction of space
*
* space_destroy Free the memory allocated to the space and objects element
*
* @date 12/03/2021
* @author: Manuel Ardid
*
* @param space is the space to free
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_destroy(Space *space);

/**
* @brief space has object
*
* space_has_object It find if the object it's in the space
*
* @date 09/03/2021
* @author: Manuel Ardid
*
* @param space where it get the direction of the objects
* @param id the id of the object to be examined
* @return TRUE if it in the set or FALSE if it's not
*/
BOOL space_has_object(Space *space, Id id);

/**
* @brief Get the identification of space
*
* space_get_id Where is able to get the id of space
*
* @date 16/02/2021
* @author: Manuel Ardid
*
* @param space where it gets the information
* @return space id or NO_ID if it fails
*/
Id space_get_id(Space *space);

/**
* @brief Set space name
*
* space_set_name Set name in the structure
*
* @date 16/02/2021
* @author: Manuel Ardid
*
* @param space where is going to be saved
* @param name name of space
* @return ERROR in case of error or OK otherwise
*/
STATUS space_set_name(Space *space, char *name);

/**
* @brief Get space name
*
* space_get_name Where can get the space name
*
* @date 16/02/2021
* @author: Manuel Ardid
*
* @param space where it can find the name
* @return NULL if it fails or space name otherwise
*/
const char *space_get_name(Space *space);

/**
* @brief space set graphic description
*
* space_set_gdesc It gives a graphic description to the space
*
* @date 14/03/2021
* @author: Manuel Ardid
*
* @param space where it's going to be saved
* @param gdesc the string with the description
* @param row it indicates the row of the graphic
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_set_gdesc(Space *space, char *gdesc, int row);

/**
* @brief Set space in the up with link id
*
* space_set_up_link Set up link id in the structure
*
* @date 19/04/2021
* @author: Manuel Ardid
*
* @param space where is going to be saved
* @param link_id the id of the linked space
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_set_up_link(Space *space, Id link_id);

/**
* @brief Get space up link
*
* space_get_up_link get up link from the space
*
* @date 19/04/2021
* @author: Manuel Ardid
*
* @param space where is going to be saved
* @return Id of the up link or NULL otherwise
*/
Id space_get_up_link(Space *space);

/**
* @brief Set space in the down with link id
*
* space_set_down_link Set down link id in the structure
*
* @date 19/04/2021
* @author: Manuel Ardid
*
* @param space where is going to be saved
* @param link_id the id of the linked space
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_set_down_link(Space *space, Id link_id);

/**
* @brief Get space down link
*
* space_get_down_link get down link from the space
*
* @date 19/04/2021
* @author: Manuel Ardid
*
* @param space where is going to be saved
* @return Id of the down link or NULL otherwise
*/
Id space_get_down_link(Space *space);

/**
* @brief Set space in the north with link id
*
* space_set_north_link Set northern link id in the structure
*
* @date 28/03/2021
* @author: Manuel Ardid
*
* @param space where is going to be saved
* @param link_id the id of the linked space
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_set_north_link(Space *space, Id link_id);

/**
* @brief Get space linked on the north
*
* space_get_north_link Where can get space link in north
*
* @date 28/03/2021
* @author: Manuel Ardid
*
* @param space where it gets the information
* @return NO_ID if it fails or northern linked id otherwise
*/
Id space_get_north_link(Space *space);

/**
* @brief Set space in the south with link id
*
* space_set_south_link Set southern link id in the structure
*
* @date 28/03/2021
* @author: Manuel Ardid
*
* @param space where is going to be saved
* @param link_id the id of the linked space 
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_set_south_link(Space *space, Id link_id);

/**
* @brief Get space linked on the south
*
* space_get_south_link Where can get space link in south
*
* @date 28/03/2021
* @author: Manuel Ardid
*
* @param space where it gets the information
* @return NO_ID if it fails or southern linked id otherwise
*/
Id space_get_south_link(Space *space);

/**
* @brief Set space in the east with link id
*
* space_set_east_link Set eastern link id in the structure
*
* @date 28/03/2021
* @author: Manuel Ardid
*
* @param space where is going to be saved
* @param link_id the id of the linked space
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_set_east_link(Space *space, Id link_id);

/**
* @brief Get space linked on the east
*
* space_get_east_link Where can get space link in east
*
* @date 28/03/2021
* @author: Manuel Ardid
*
* @param space where it gets the information
* @return NO_ID if it fails or eastern linked id otherwise
*/
Id space_get_east_link(Space *space);

/**
* @brief Set space in the west with link id
*
* space_set_west_link Set western link id in the structure
*
* @date 28/03/2021
* @author: Manuel Ardid
*
* @param space where is going to be saved
* @param link_id the id of the linked space
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_set_west_link(Space *space, Id link_id);

/**
* @brief Get space linked on the west
*
* space_get_west_link Where can get space link in east 
*
* @date 28/03/2021
* @author: Manuel Ardid
*
* @param space where it gets the information
* @return NO_ID if it fails or western linked id otherwise
*/
Id space_get_west_link(Space *space);

/**
* @brief Set object in the space
*
* space_add_object add object to space in the structure
*
* @date 09/03/2021
* @author: Manuel Ardid
*
* @param space where it get the direction of the objects
* @param id the id of the object
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_add_object(Space *space, Id id);

/**
* @brief space get graphic description
*
* space_get_gdesc where we can get the graphic description of the space 
* in regards of the specific row
*
* @date 14/03/2021
* @author: Manuel Ardid
*
* @param space where it get the direction of the gdesc
* @param row it indicates the row of the graphic
* @return the string with the graphic of the specific row or NULL if it failes 
*/
char *space_get_gdesc(Space *space, int row);

/**
* @brief Deletes the object in the space
*
* space_remove_object It takes out the object in the space
*
* @date 09/03/2021
* @author: Manuel Ardid
*
* @param space where it get the direction of the objects
* @param id the id of the object to be deleted
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_remove_object(Space *space, Id id);

/**
* @brief Get number of objects in the space
*
* space_get_number_of_objects Where can get number of objects in the space
*
* @date 09/03/2021
* @author: Manuel Ardid
*
* @param space the space where it gets the number of objects
* @return number of the object in the space or -1 if it fails 
*/
int space_get_number_of_objects(Space *space);

/**
* @brief Get objects in the space
*
* space_get_objects Where it can get the object array in the space
*
* @date 09/03/2021
* @author: Manuel Ardid
*
* @param space the space where it gets the information
* @return the direction of the array of objects in the space or NULL if it fails
* or if there aren't any objects
*/
Id *space_get_objects(Space *space);

/**
* @brief Get object from pos
*
* space_get_object_from_pos It gets the id of the object from the postiion
*
* @date 26/04/2021
* @author: Manuel Ardid
*
* @param space the space where it gets the information
* @param pos the position
* @return id of the object or -1 if it fails
*/
Id space_get_object_from_pos(Space *space, int pos);

/**
* @brief spaces are linked
*
* space_are_linked It sees if two spaces are linked
*
* @date 28/03/2021
* @author: Manuel Ardid
*
* @param space1 first space
* @param space2 second space
* @param link the direction of the link to be examined
* @return TRUE if the spaces are linked or FALSE if it's not
*/
BOOL space_are_linked(Id space1, Id space2, Link *link);

/**
* @brief It assigns a description to the space
*
* space_set_ndescription It gives a description to the space
*
* @date 09-04-2021
* @author: Manuel Ardid
*
* @param space the space to be assigned
* @param description the description of the space
* @return OK in case of success or ERROR if it fails
*/
STATUS space_set_description(Space *space, char *description);

/**
* @brief It assigns a full description to the space
*
* space_set_full_description It gives a full description to the space
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param space the space to be assigned
* @param description the full description of the space
* @return OK in case of success or ERROR if it fails
*/
STATUS space_set_full_description(Space *space, char *description);

/**
* @brief It returns the description of the space
*
* space_get_description It returns the description of a certain space
*
* @date 09-04-2021
* @author: Manuel Ardid
*
* @param space it the space to be examinated
* @return the space's description or NULL in case of failure
*/
const char *space_get_description(Space *space);

/**
* @brief It returns the description of the init space
*
* space_get_init_description It returns the init description of a certain space
*
* @date 03-05-2021
* @author: Manuel Ardid
*
* @param space it the space to be examinated
* @return the space's description or NULL in case of failure
*/
const char *space_get_init_description(Space *space);

/**
* @brief It returns the full description of the space
*
* space_get_full_description It returns the full description of a certain space
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param space the space to be examinated
* @return the space's full description or NULL in case of failure
*/
const char *space_get_full_description(Space *space);

/**
* @brief Get light at the beginIt determinates if a space is iluminated or not
* @date 30-04-2021
* @author: Manuel Ardid
*
* @param space the space to be examinated
* @return TRUE if there is light or FALSE if there is not
*/
BOOL space_get_light_init(Space *space);

/**
* @brief Get light at a current act space
*
* space_get_light_act It returns if there is light or not in a space
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param space the space to be examinated
* @return TRUE if there is light or FALSE if there is not
*/
BOOL space_get_light_act(Space *space);

/**
* @brief Set init light
*
* space_set_light_init It sets the initial light value of the space
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param space the space 
* @param light the boolean value of the light in that space
*
* @return OK in case of success or ERROR if it fails
*/
STATUS space_set_light_init(Space *space, BOOL light);

/**
* @brief Set act light
*
* space_set_light_act It determinates if a space is iluminated or not
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param space the space 
* @param light the boolean value of the light in that space
*
* @return OK in case of success or ERROR if it fails
*/
STATUS space_set_light_act(Space *space, BOOL light);

/**
* @brief Print information of space
*
* space_print Print space ID, name, link and object information
* (if there is space)
*
* @date 16/02/2021
* @author: Manuel Ardid
*
* @param space the space where it gets the information
* @return ERROR in case of failure or OK otherwise
*/
STATUS space_print(Space *space);

#endif
