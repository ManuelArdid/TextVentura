/** 
 * @brief Funtions of game management interface
 * 
 * @file game_management.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 14-02-2021
 * @copyright GNU Public License
 */

#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "game.h"
#include "inventory.h"

/**
   Public functions
*/

/**
* @brief It restores a saved point
*
* game_management_create_from_file It creates the game from a file
*
* @date 26-04-2021
* @author: Manuel Ardid
*
* @param game where it's going to be saved
* @param filename file where it gets the information
* @return OK if it succeed or ERROR if it failed
*/
STATUS game_management_load(Game *game, char *filename);

/**
* @brief It creates a saving point
*
* game_management_save It places the current game into a file
*
* @date 26-04-2021
* @author: Manuel Ardid
*
* @param game where it gets the information
* @param filename file where it writes the information
* @return OK if it succeed or ERROR if it failed
*/
STATUS game_management_save(Game *game, char *filename);

#endif
