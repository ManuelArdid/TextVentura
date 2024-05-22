/**
 * @brief Funtions and structure of command interface
 *
 * @file command.h
 * @author Manuel Ardid
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

/** Defines the constant variables */
#define N_CMDT 2
/** Defines the constant variables */
#define N_CMD 13
/** Defines the constant variables */
#define CMD_LENGHT 30

/**
   Public enumerations
*/

/**
 * @brief Enumeration of T_CmdType
 */
typedef enum enum_CmdType {
  CMDS,
  CMDL
} T_CmdType;

/**
 * @brief Enumeration of T_Command
 */
typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  MOVE,
  TAKE,
  DROP,
  ROLL,
  INSPECT,
  TURNON,
  TURNOFF,
  OPEN,
  SAVE,
  LOAD
} T_Command;

/**
   Public functions
*/

/**
* @brief Get command of user input
*
* command_get_user_input It gets the command of user input 
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @return the command of the user input 
*/
T_Command command_get_user_input();

#endif
