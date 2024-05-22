/** 
 * @brief Funtions of link inteface
 * 
 * @file link.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 23-03-2021
 * @copyright GNU Public License
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

/** Defines the constant variables */
#define MAX_LINKS 100

/**
   Defines the type of data
*/

/** 
 * @brief Data structure to implement link. 
 *
 **/
typedef struct _Link Link;

/**
   Public functions
*/

/**
* @brief Creation of link
*
* link_create Allocates memory to the link and it inicialize 
* the values of the structure Link
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param id id of the link
* @return the direction of link or NULL if it fails
*/
Link *link_create(Id id);

/**
* @brief Destruction of link
*
* link_destroy Free the memory allocated to the link
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param link is the link to free
* @return ERROR in case of failure or OK otherwise
*/
STATUS link_destroy(Link *link);

/**
* @brief Set link name
*
* link_set_name It's going to set the name of the link
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param link where it gets the information
* @param name the name of the link
* @return ERROR in case of failure or OK otherwise
*/
STATUS link_set_name(Link *link, char *name);

/**
* @brief Set link space1
*
* link_set_link1 It's going to set the link of the space1
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param link where is going to be saved
* @param id the id of the space
* @return ERROR in case of failure or OK otherwise
*/
STATUS link_set_space1(Link *link, Id id);

/**
* @brief Set link space2
*
* link_set_link2 It going to set the link of the space2
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param link where is going to be saved
* @param id the id of the space
* @return ERROR in case of failure or OK otherwise
*/
STATUS link_set_space2(Link *link, Id id);

/**
* @brief Set link state
*
* link_set_state It sets the state of the link (open or close)
*
* @date 26/03/2021
* @author: Manuel Ardid
*
* @param link where is going to be saved
* @param close the state of the link 
* @return ERROR in case of failure or OK otherwise
*/
STATUS link_set_close(Link *link, BOOL close);

/**
* @brief Get link id
*
* link_get_id Where can get link id
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param link where it gets the information
* @return NO_ID if it fails or link id otherwise
*/
Id link_get_id(Link *link);

/**
* @brief get the link name
*
* link_get_name It returns the name of the link
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param link where it gets the information
* @return name of the link or NULL if it fails
*/
char *link_get_name(Link *link);

/**
* @brief Get the link of space1
*
* link_get_space1 It gets the id of the link space1
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param link where it gets the information
* @return the id of the space or NO_ID if it fails
*/
Id link_get_space1(Link *link);

/**
* @brief Get the link of space2
*
* link_get_space2 It gets the id of the link space2
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param link where it gets the information
* @return the id of the space or NO_ID if it fails
*/
Id link_get_space2(Link *link);

/**
* @brief link is close or no
*
* link_get_space2 It gets the state of the link
*
* @date 26/03/2021
* @author: Manuel Ardid
*
* @param link where it gets the information
* @return TRUE if the link is close, FALSE if is open or if there is an error
*/
BOOL link_is_close(Link *link);

/**
* @brief Print information of link
*
* link_print Print link ID, name, space1, space2 and the state of the link
*
* @date 23/03/2021
* @author: Manuel Ardid
*
* @param link the link where it gets the information
* @return ERROR in case of failure or OK otherwise
*/
STATUS link_print(Link *link);

#endif
