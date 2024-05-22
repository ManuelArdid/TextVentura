/** 
 * @brief It defines the game interface
 * for each command
 * 
 * @file game.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "dialogue.h"
#include "die.h"
#include "link.h"
#include "object.h"
#include "player.h"
#include "space.h"

/** Defines the constant variables */
#define N_CALLBACK 12

/** 
 * @brief Data structure to implement game. 
 **/
typedef struct _Game Game;

/**
* @brief Creation of the game
*
* game_create Create game based on game structure and it assigns memory for the new game
* 
* @date 24-03-2021
* @author: Manuel Ardid
*
* @return the address of the new game or NULL in case of failure
*/
Game *game_create();

/**
* @brief Add space
*
* game_add_space Add space in the game
*
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game where it can find the space
* @param space the space we want to add
* @return OK if it succeed or ERROR in case of error 
*/
STATUS game_add_space(Game *game, Space *space);

/**
* @brief Add object
*
* game_add_object Add object in the game
*
* @date 13-03-2021
* @author: Manuel Ardid
*
* @param game where it's going to be added in the structure
* @param object the object we want to add
* @return OK if it succeed or ERROR in case of error 
*/
STATUS game_add_object(Game *game, Object *object);

/**
* @brief Add player
*
* game_add_player Add player in the game
*
* @date 26-03-2021
* @author: Manuel Ardid
*
* @param game where it's going to be added in the structure
* @param player the player we want to add
* @return OK if it succeed or ERROR in case of error 
*/
STATUS game_add_player(Game *game, Player *player);

/**
* @brief Add link
*
* game_add_player Add link in the game
*
* @date 27-03-2021
* @author: Manuel Ardid
*
* @param game where it's going to be added in the structure
* @param link the link we want to add
* @return OK if it succeed or ERROR in case of error 
*/
STATUS game_add_link(Game *game, Link *link);

/**
* @brief Assigne a location to the player in the game
*
* game_set_player_location Save the player location 
* 
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game where to save the location
* @param id the id of the player location
* @return OK if it succeed or ERROR in case of error
*/
STATUS game_set_player_location(Game *game, Id id);

/**
* @brief Assigne a location to the object in the game
*
* game_set_object_location Save the object in the location 
* 
* @date 12-03-2021
* @author: Manuel Ardid
*
* @param game where to save the location
* @param space_id the id of the space
* @param object_id the id of the object to be placed
* @return OK if it succeed or ERROR in case of error
*/
STATUS game_set_object_location(Game *game, Id space_id, Id object_id);

/**
* @brief It gets the die's last value
*
* game_get_last_die_value It gets the die last value 
*
* @date 19-03-2021
* @author: Manuel Ardid
*
* @param game where it gets the information of the game
* @return the value of the last roll 
*/
int game_get_last_die_value(Game *game);

/**
* @brief Get object direction
*
* game_get_object It gets the object in the structure of game
*
* @date 24-03-2021
* @author: Manuel Ardid Abad 
*
* @param game pointer to game
* @param pos position of the object
* @return the pointer of the object or NULL if it fails
*/
Object *game_get_object(Game *game, int pos);

/**
* @brief Get link direction
*
* game_get_object It gets the link in the structure of game
*
* @date 8-04-2021
* @author: Manuel Ardid Abad 
*
* @param game pointer to game
* @param id the id of the link of the link
* @return the pointer of the link or NULL if it fails
*/
Link *game_get_link(Game *game, Id id);

/**
* @brief Get the player direction
*
* game_get_player It get the player in the structure of game
*
* @date 06-04-2021
* @author: Manuel Ardid Clavería
*
* @param game pointer to game
* @return the pointer of the player or NULL if it fails
*/
Player *game_get_player(Game *game);

/**
* @brief Get the die direction
*
* game_get_die It get the die in the structure of game
*
* @date 16-04-2021
* @author: Manuel Ardid
*
* @param game pointer to game
* @return the pointer of the die or NULL if it fails
*/
Die *game_get_die(Game *game);

/**
* @brief Update game
*
* game_update Upadate game based on game structure and the last command
* 
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game where save the last command
* @param cmd The command we need to save
* @return OK if it succeed
*/
STATUS game_update(Game *game, T_Command cmd);

/**
* @brief It destroys the game
*
* game_destroy It frees the memory that the game occupies
* 
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game the game to be freed
* @return OK if it succeed
*/
STATUS game_destroy(Game *game);

/**
* @brief Game over
*
* game_is_over Finished the game
* 
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game the game to be finished
* @return FALSE if it ended
*/
BOOL game_is_over(Game *game);

/**
* @brief Print game data
*
* game_print_data Print information about the game based on its structure
* 
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game save the game data
*/
void game_print_data(Game *game);

/**
* @brief Get space
*
* game_get_space Get the sapce drection based on game structure and its id
* 
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game where save the space id
* @param id space id
* @return NULL if it fails or direction of the space otherwise
*/
Space *game_get_space(Game *game, Id id);

/**
* @brief Return the player's location in the game
*
* game_get_player_location Where can get the location of a player in the game
*
* @date 20-02-2021
* @author: Manuel Ardid
*
* @param game where the player is saved
* @return the id of player's location if it succeed or NO_ID otherwise
*/
Id game_get_player_location(Game *game);

/**
* @brief Returns object's location in the game
*
* game_get_object_location Where can get the location of the object
*
* @date 12-03-2021
* @author: Manuel Ardid
*
* @param game where it gets the information of the game
* @param id the id of the object to be found
* @return the id of object's location or NO_ID otherwise
*/
Id game_get_object_location(Game *game, Id id);

/**
* @brief It sets the description of the object or space
*
* game_get_description It saves the description of a certain object or space
*
* @date 03-05-2021
* @author: Manuel Ardid
*
* @param game it the object or space to be examinated
* @param desc the description to be saved
* @return OK if it was saved correctly or ERROR otherwise
*/
STATUS game_set_description(Game *game, char *desc);

/**
* @brief It returns the description of the object or space
*
* game_get_description It returns the description of a certain object or space
*
* @date 10-04-2021
* @author: Manuel Ardid
*
* @param game it the object or space to be examinated
* @return the object's or space's description or NULL in case of failure
*/
const char *game_get_description(Game *game);

/**
* @brief It sets the option that the player has entered
*
* game_get_option It saves the option chosen by the player
*
* @date 03-05-2021
* @author: Manuel Ardid
*
* @param game where it's located the information
* @param option the option to be saved
* @return OK if it was saved correctly or ERROR otherwise
*/
STATUS game_set_option(Game *game, char *option);

/**
* @brief It returns the option that the player has entered
*
* game_get_option It returns the option chosen by the player
*
* @date 26-04-2021
* @author: Manuel Ardid
*
* @param game where it's located the information
* @return the player option or NULL in case of failure
*/
const char *game_get_option(Game *game);

/**
* @brief It gets the dialogue message
*
* game_get_dialogue_message It returns the diaglogue massage
*
* @date 1-05-2021
* @author: Manuel Ardid
*
* @param game where it's located the information
* @return the dialogue message or NULL in case of failure
*/
const char *game_get_dialogue_message(Game *game);

/**
* @brief Get last command 
*
* game_get_last_command Get the last command of the game based on the game structure 
* 
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game where is save the last command
* @return the last command
*/
T_Command game_get_last_command(Game *game);

/**
* @brief Get last command status
*
* game_get_last_command Gets the status of the last command of the game 
* 
* @date 26-03-2021
* @author: Manuel Ardid
*
* @param game where is save the last command status
* @return the last command status
*/
STATUS game_get_last_command_st(Game *game);

/**
* @brief Set last command status
* 
* game_set_last_command_st It sets the last command status of the game
*
* @date 24-04-2021
* @author: Manuel Ardid
*
* @param game pointer to game
* @param st state we want to put
* @return OK or ERROR if it fails
*/
STATUS game_set_last_command_st(Game *game, STATUS st);

#endif