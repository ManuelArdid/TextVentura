/**
 * @brief It implements the set interface
 *
 * It contains the funtions implementation of the set
 *
 * @file set.c
 * @author Manuel Ardid
 * @version 1.0
 * @date 06-03-2021
 * @copyright GNU Public License
 */

#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* @brief The set structure
*
* It saves the set of ids and the number of ids
*/
struct _Set {
  Id id[MAX_ID]; /*!< set's ids */
  int num_ids;   /*!< number of ids */
};

Set *set_create() {
  int i;
  Set *new_set = NULL;

  new_set = (Set *)malloc(sizeof(Set));
  if (new_set == NULL) {
    return NULL;
  }

  for (i = 0; i < MAX_ID; i++) {
    new_set->id[i] = NO_ID;
  }

  new_set->num_ids = 0;

  return new_set;
}

STATUS set_destroy(Set *set) {
  if (!set) {
    return ERROR;
  }

  free(set);
  set = NULL;

  return OK;
}

int set_get_num_of_ids(Set *set) {
  if (!set)
    return -1;

  return set->num_ids;
}

BOOL set_has_id(Set *set, Id id) {
  int i;

  if (!set)
    return FALSE;

  for (i = 0; i < set->num_ids; i++) {
    if (set->id[i] == id)
      return TRUE;
  }

  return FALSE;
}

Id set_get_id_from_pos(Set *set, int pos) {
  int num;

  if (!set)
    return NO_ID;

  num = set_get_num_of_ids(set);
  if (num == 0)
    return NO_ID;

  return set->id[pos];
}

STATUS set_add(Set *set, Id id) {
  int i;
  Id aux = NO_ID;
  STATUS st = OK;

  if (!set || id == NO_ID || set->num_ids == MAX_ID) {
    return ERROR;
  }

  if (set->num_ids == MAX_ID) {
    return ERROR;
  }

  for (i = 0; i < set->num_ids && st == OK; i++) {
    aux = set->id[i];
    if (aux == id) {
      st = ERROR;
    }
  }
  if (st == ERROR) {
    return ERROR;
  }

  set->id[set->num_ids] = id;

  set->num_ids++;

  return OK;
}

STATUS set_del(Set *set, Id id) {
  int i;
  Id aux = NO_ID;
  STATUS st = ERROR;

  if (!set || id == NO_ID) {
    return ERROR;
  }

  if (set->num_ids == 0) {
    return ERROR;
  }

  for (i = 0; i < set->num_ids && st == ERROR; i++) {
    aux = set->id[i];
    if (aux == id) {
      st = OK;
      set->num_ids--;
      set->id[i] = set->id[set->num_ids];
      set->id[set->num_ids] = NO_ID;
    }
  }

  if (st == ERROR) {
    return ERROR;
  }

  return OK;
}

STATUS set_print(Set *set) {
  int i;

  if (!set) {
    return ERROR;
  }

  fprintf(stdout, "--> Set (Number of ids: %d)\n", set->num_ids);
  for (i = 0; i < set->num_ids && set->id[i] != NO_ID; i++) {
    fprintf(stdout, "Id %d: %ld ", i + 1, set->id[i]);
  }

  return OK;
}