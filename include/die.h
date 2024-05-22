/** 
 * @brief Funtions of die interface
 * 
 * @file die.h
 * @author Manuel Ardid
 * @version 2.0 
 * @date 24-03-2021
 * @copyright GNU Public License
 */

#ifndef DIE_H
#define DIE_H

#include "types.h"

/** 
 * @brief Data structure to implement die. 
 *
 **/
typedef struct _Die Die;

/**
* @brief Create new die
*
* die_create It assigns memory for the new die
*
* @date 02-03-2021
* @author: Manuel Ardid
*
* @param id the id of the new die
* @param min the minimum value of the die (bigger than 0)
* @param max the maximum value of the die
* @return the address of the new die or NULL in case of failure
*/
Die *die_create(Id id, int max, int min);

/**
* @brief It destroys a die
*
* die_destroy It frees the memory that the die occupies
*
* @date 02-03-2021
* @author: Manuel Ardid
*
* @param die the die to be freed
* @return OK in case of success or ERROR if it fails
*/
STATUS die_destroy(Die *die);

/**
* @brief Get id of a die
*
* die_destroy It returns the id of the die
*
* @date 08-03-2021
* @author: Manuel Ardid
*
* @param die where it gets the information
* @return the id of the die or NO_ID if it fails
*/
Id die_get_id(Die *die);

/**
* @brief get the min value of the die
*
* die_get_min It returns the min value that the die
*
* @date 24-03-2021
* @author: Manuel Ardid
*
* @param die where it gets the information of the die
* @return the die's last value or NULL if it fails
*/
int die_get_min(Die *die);

/**
* @brief get the max value of the die
*
* die_get_max It returns the max value that the die
*
* @date 24-03-2021
* @author: Manuel Ardid
*
* @param die where it gets the information of the die
* @return the die's last value or NULL if it fails
*/
int die_get_max(Die *die);

/**
* @brief get the last value of the die
*
* die_get_last_num It returns the last value that the die got
*
* @date 02-03-2021
* @author: Manuel Ardid
*
* @param die where it gets the information of the die
* @return the die's last value or NULL if it fails
*/
int die_get_last_num(Die *die);

/**
* @brief set the last value of the die
*
*
* @date 26-04-2021
* @author: Manuel Ardid
*
* @param die where it gets the information of the die
* @param num number
* @return OK or ERROR
*/
STATUS die_set_last_num(Die *die, int num);

/**
* @brief It rolls the die
*
* die_roll It generates a random number between the min and max value
*
* @date 02-03-2021
* @author: Manuel Ardid
*
* @param die where it gets the information of the die
* @return OK in case of success or ERROR if it fails
*/
STATUS die_roll(Die *die);

/**
* @brief Shows the die information
*
* die_print It appears the information on the screen
*
* @date 02-03-2021
* @author: Manuel Ardid
*
* @param die where it gets the die information
* @return OK in case of success or ERROR if it fails
*/
STATUS die_print(Die *die);

#endif