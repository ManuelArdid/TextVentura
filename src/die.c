/**
 * @brief It implements the die interface
 *
 * It contains the funtions implementation of the die
 *
 * @file die.c
 * @author Manuel Ardid Clavería
 * @version 2.0
 * @date 24-03-2021
 * @copyright GNU Public License
 */

#include "die.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
   Defines the structure
*/

/**
* @brief The die structure
*
* It saves the die id, the maximum and minimum number and the last value of the die
*/
struct _Die {
  Id id;        /*!< die's id */
  int min_die;  /*!< dies minimum value */
  int max_die;  /*!< dies maximum value */
  int last_num; /*!< die's last value */
};

/**
   Public funtions implementation
*/

Die *die_create(Id id, int max, int min) {
  Die *new_die = NULL;

  if (id == NO_ID || min <= 0 || max < min)
    return NULL;

  new_die = (Die *)malloc(sizeof(Die));
  if (new_die == NULL)
    return NULL;

  new_die->id = id;
  new_die->min_die = min;
  new_die->max_die = max;
  new_die->last_num = 0;

  return new_die;
}

STATUS die_destroy(Die *die) {
  if (!die)
    return ERROR;

  free(die);
  die = NULL;

  return OK;
}

Id die_get_id(Die *die) {
  if (!die)
    return NO_ID;

  return die->id;
}

int die_get_min(Die *die) {
  if (!die)
    return -1;

  return die->min_die;
}

int die_get_max(Die *die) {
  if (!die)
    return -1;

  return die->max_die;
}

STATUS die_set_last_num(Die *die, int num) {
  if (!die)
    return ERROR;

  die->last_num = num;
  return OK;
}

int die_get_last_num(Die *die) {
  if (!die)
    return -1;

  return die->last_num;
}

STATUS die_roll(Die *die) {
  int num;

  if (!die) {
    return ERROR;
  }

  num = rand() % (die->max_die - die->min_die + 1) + die->min_die;
  if (num < die->min_die || num > die->max_die) {
    return ERROR;
  }

  die->last_num = num;

  return OK;
}

STATUS die_print(Die *die) {
  if (!die)
    return ERROR;

  fprintf(stdout, "--> Die (Id: %ld; Max: %d; Min: %d; Last_num: %d)\n", die->id, die->max_die, die->min_die, die->last_num);

  return OK;
}
