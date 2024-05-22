/** 
 * @brief Functions of the player interface
 * 
 * @file player.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 20-02-2021
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "inventory.h"
#include "types.h"

/**
   Defines the type of data
*/

/** 
 * @brief Data structure to implement Player
 *
 **/
typedef struct _Player Player;

/**
   Public functions
*/

/**
* @brief Crate a new player
*
* player_create Assign memory to the new player and saves the
* id in the structure
*
* @date 20-02-2021
* @author: Manuel Ardid
*
* @param id the id of the new player
* @return Direction of player or NULL if it fails
*/
Player *player_create(Id id);

/**
* @brief Destroy the player
*
* player_destroy Free the memory allocated to the player element
*
* @date 20-02-2021
* @author: Manuel Ardid
*
* @param player is the object to free
* @return OK if successful or ERROR if failed
*/
STATUS player_destroy(Player *player);

/**
* @brief Return the player id
*
* player_get_id Where can get a player's id
*
* @date 20-02-2021
* @author: Manuel Ardid
*
* @param player where it can find the id
* @return the player's id or NO_ID if it fails
*/
Id player_get_id(Player *player);

/**
* @brief Return the player's name
*
* player_get_name Where can get a player's name
*
* @date 20-02-2021
* @author: Manuel Ardid
*
* @param player where the name is
* @return the player's name or NULL if it fails
*/
const char *player_get_name(Player *player);

/**
* @brief give a name to the player
*
* player_set_name Save the name in the structure
*
* @date 20-02-2021
* @author: Manuel Ardid
*
* @param player where the name will be saved
* @param name name of the player
* @return OK if successful or ERROR if failed
*/
STATUS player_set_name(Player *player, char *name);

/**
* @brief Return the player's location
*
* player_get_location Where can get the location of a player
*
* @date 20-02-2021
* @author: Manuel Ardid
*
* @param player where the location is
* @return the player's location or NO_ID if it fails
*/
Id player_get_location(Player *player);

/**
* @brief Assigne a location to the player
*
* player_set_location Save the location id in the structure
*
* @date 20-02-2021
* @author: Manuel Ardid
*
* @param player where to save the location
* @param location the id location of the player to be set
* @return OK if successful or ERROR if failed
*/
STATUS player_set_location(Player *player, Id location);

/**
* @brief Add object to the player
*
* player_add_object It gives the player an object
*
* @date 28-04-2021
* @author: Manuel Ardid
*
* @param player where to save the object
* @param id the id of the object
* @return OK if successful or ERROR if failed
*/
STATUS player_add_object(Player *player, Id id);

/**
* @brief Deletes object of the player
*
* player_add_object It removes a object that the player has
*
* @date 28-04-2021
* @author: Manuel Ardid
*
* @param player where to remove the object
* @param id the id of the object
* @return OK if successful or ERROR if failed
*/
STATUS player_del_object(Player *player, Id id);

/**
* @brief Get object from position
*
* player_add_object It gets the object in the array with the position
*
* @date 28-04-2021
* @author: Manuel Ardid
*
* @param player where it gets the information
* @param pos the position to find the object
* @return the Id of the object if successful or NO_ID if failed
*/
Id player_get_object_from_pos(Player *player, int pos);

/**
* @brief Player has object
*
* player_has_object It finds if the player has the object
*
* @date 28-04-2021
* @author: Manuel Ardid
*
* @param player where it gets the information
* @param id the id of the object
* @return TRUE if the player has the object or FALSE otherwise
*/
BOOL player_has_object(Player *player, Id id);

/**
* @brief Gets player number of objects
*
* player_add_object It gets how many objects it has the player
*
* @date 28-04-2021
* @author: Manuel Ardid
*
* @param player where to save the object
* @return the number of objects if successful or -1 if failed
*/
int player_get_num_of_objects(Player *player);

/**
* @brief Assign a number of objects can take by the player
*
* player_set_max_objects Save maximum objects that the player can carry
* in the structure
*
* @date 26-03-2021
* @author: Manuel Ardid
*
* @param player where to save the object
* @param max_objs maximum objects that the player can carry
* @return OK if successful or ERROR if failed
*/
STATUS player_set_max_objects(Player *player, int max_objs);

/**
* @brief The maximum objects that the player can carry 
*
* player_get_max_objects Where can get the maximum objects 
* that the player can carry
*
* @date 26-03-2021
* @author: Manuel Ardid
*
* @param player where the maximum objects is
* @return the maximum objects that the player can carry or -1 if it fails
*/
int player_get_max_objects(Player *player);

/**
* @brief Show player information
*
* player_print Displays the player's data on the screen
*
* @date 20-02-2021
* @author: Manuel Ardid
*
* @param player where it can get the player information
* @return OK if successful or ERROR if failed
*/
STATUS player_print(Player *player);

#endif
