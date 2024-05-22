/** 
 * @brief Funtions of dialogue interface
 * 
 * @file dialogue.h
 * @author Manuel Ardid
 * @version 1.0 
 * @date 26-04-2021
 * @copyright GNU Public License
 */

#ifndef DIALOGUE_H
#define DIALOGUE_H

#include "command.h"
#include "space.h"
#include "types.h"

/** 
 * @brief Data structure to implement dialogue. 
 **/
typedef struct _Dialogue Dialogue;

/**
* @brief It creates a new dialogue
*
* dialogue_create It returns the diaglogue pointer
*
* @date 1-05-2021
* @author: Manuel Ardid
*
* @return the dialogue pointer or NULL in case of failure
*/
Dialogue *dialogue_create();

/**
* @brief It drestroys a dialogue
*
* dialogue_destroy It returns the diaglogue pointer
*
* @date 1-05-2021
* @author: Manuel Ardid
*
* @return OK if it succeed or ERROR if it fails
*/
STATUS dialogue_destroy(Dialogue *dialogue);

/**
* @brief It gets dialogue message
*
* dialogue_get_message It returns the diaglogue message
*
* @date 1-05-2021
* @author: Manuel Ardid
*
* @return the dialogue message or NULL in case of failure
*/
const char *dialogue_get_message(Dialogue *dialogue, T_Command cmd, STATUS st, Space *space, const char *option);

#endif