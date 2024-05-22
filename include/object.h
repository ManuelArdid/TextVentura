/** 
 * @brief Funtions of object interface
 * 
 * @file object.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 17-02-2021
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/** Defines the constant variables */
#define MAX_OBJECTS 100

/**
   Defines the type of data
*/

/** 
 * @brief Data structure to implement Object. 
 *
 **/
typedef struct _Object Object;

/**
   Public functions
*/

/**
* @brief Create new object
*
* object_create It assigns memory for the new object
*
* @date 17-02-2021
* @author: Manuel Ardid
*
* @param id the id of the new object
* @return the address of the new object or NULL in case of failure
*/
Object *object_create(Id id);

/**
* @brief It destroys an object
*
* object_destroy It frees the memory that the object occupies
*
* @date 17-02-2021
* @author: Manuel Ardid
*
* @param object the object to be freed
* @return OK in case of success or ERROR if it fails
*/
STATUS object_destroy(Object *object);

/**
* @brief It returns the object's id
*
* object_get_id It returns the id of a certain object
*
* @date 17-02-2021
* @author: Manuel Ardid
*
* @param object the object to be examinated
* @return the object's id or NO_ID if it fails
*/
Id object_get_id(Object *object);

/**
* @brief It assigns a name to the object
*
* object_set_name It gives a name to the object
*
* @date 17-02-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @param name the name of the object
* @return OK in case of success or ERROR if it fails
*/
STATUS object_set_name(Object *object, char *name);

/**
* @brief It returns the name of the object
*
* object_get_name It returns the name of a certain object
*
* @date 17-02-2021
* @author: Manuel Ardid
*
* @param object it the object to be examinated
* @return the object's name or NULL in case of failure
*/
const char *object_get_name(Object *object);

/**
* @brief It assigns a description to the object
*
* object_set_ndescription It gives a description to the object
*
* @date 09-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @param description the description of the object
* @return OK in case of success or ERROR if it fails
*/
STATUS object_set_description(Object *object, char *description);

/**
* @brief It returns the description of the object
*
* object_get_description It returns the description of a certain object
*
* @date 09-04-2021
* @author: Manuel Ardid
*
* @param object it the object to be examinated
* @return the object's description or NULL in case of failure
*/
const char *object_get_description(Object *object);

/**
* @brief Object set movable
*
* object_set_movable It assigns a movable value to the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @param value value 
* @return OK in case of success or ERROR if it fails
*/
STATUS object_set_movable(Object *object, BOOL value);

/**
* @brief Object is movable
*
* object_is_movable It gets the movable value of the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @return TRUE if the object can be moved or FALSE otherwise
*/
BOOL object_is_movable(Object *object);

/**
* @brief Object set dependency
*
* object_set_dependency It assigns a dependency id to the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @param id dependency id
* @return OK in case of success or ERROR if it fails
*/
STATUS object_set_dependency(Object *object, Id id);

/**
* @brief Object get dependency
*
* object_get_dependency It gets the dependency id of the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @return dependency id of the object or NO_ID otherwise
*/
Id object_get_dependency(Object *object);

/**
* @brief Object set open
*
* object_set_open It assigns an open id to the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @param id open id
* @return OK in case of success or ERROR if it fails
*/
STATUS object_set_open(Object *object, Id id);

/**
* @brief Object get open
*
* object_get_open It gets the open id of the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @return open id of the object or NO_ID otherwise
*/
Id object_get_open(Object *object);

/**
* @brief Object set illuminate
*
* object_set_illuminate It assigns a illuminate value to the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @param value value 
* @return OK in case of success or ERROR if it fails
*/
STATUS object_set_illuminate(Object *object, BOOL value);

/**
* @brief Object can iluminate
*
* object_can_illuminate It sees the illuminate value of the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @return TRUE if the object iluminates or FALSE otherwise
*/
BOOL object_can_illuminate(Object *object);

/**
* @brief Object set turned on
*
* object_set_turnedon It assigns a turnedon value to the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @param value value 
* @return OK in case of success or ERROR if it fails
*/
STATUS object_set_turnedon(Object *object, BOOL value);

/**
* @brief Object is turned on
*
* object_is_turnedon It sees the turnedon value of the object
*
* @date 19-04-2021
* @author: Manuel Ardid
*
* @param object the object to be assigned
* @return TRUE if the object is turned on or FALSE otherwise
*/
BOOL object_is_turnedon(Object *object);

/**
* @brief Set discovery of an object
*
* object_set_discovery Set a true value if the player had discover the object
*
* @date 04-05-2021
* @author: Manuel Ardid
*
* @param object the discovered (or not) object 
* @param value TRUE or FALSE
* @return TRUE if the object is turned on or FALSE otherwise
*/
STATUS object_set_discovery(Object *object, BOOL value);

/**
* @brief Object is discovered
*
* object_is_discovered Returns a true value if the player had discover the object
*
* @date 04-05-2021
* @author: Manuel Ardid
*
* @param object the discovered (or not) object 
*
* @return TRUE or FALSE
*/
BOOL object_is_discovered(Object *object);

/**
* @brief Shows the object information
*
* object_print It appears the information on the screen
*
* @date 17-02-2021
* @author: Manuel Ardid
*
* @param object where it gets the object information
* @return OK in case of success or ERROR if it fails
*/
STATUS object_print(Object *object);

#endif