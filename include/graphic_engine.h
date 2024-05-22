/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.h
 * @author Manuel Ardid
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

/**
   Defines the type of data
*/

/** 
 * @brief Data structure to implement the Graphic_engine. 
 *
 **/
typedef struct _Graphic_engine Graphic_engine;

/**
   Public functions
*/

/**
* @brief Creation of graphic engine
*
* graphic_engine_create This function allocates memory for the graphic engine and 
* create it
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @return the graphic engine created if it was done correctly or NULL otherwise
*/
Graphic_engine *graphic_engine_create();

/**
* @brief Destruction of graphic engine 
*
* graphic_engine_destroy This function free the dynamic memory reserved for a graph
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param ge graphic engine to destroy
*/
void graphic_engine_destroy(Graphic_engine *ge);

/**
* @brief Paint graphic engine of game
*
* graphic_engine_paint_game This function paint graphic engine in the game area
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param ge graphic engine to paint
* @param game the game it gets the information
*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
