/** 
 * @brief It implements the inventory interface
 *
 * Contains the implementation of the functions associated to inventory
 * 
 * @file inventory.c
 * @author Manuel Ardid Clavería 
 * @version 1.0 
 * @date 25-03-2021
 * @copyright GNU Public License
 */

#include "inventory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Defines the structure
*/

/** 
 * @brief Structure that defines the inventory
 */
struct _Inventory {
  Set *ids;          /*!< Set of objects ids */
  int max_inventory; /*!< The maximum number of ids you can store */
};

/**
   Public funtions implementation
*/

Inventory *inventory_create() {
  Inventory *new_inv = NULL;

  new_inv = (Inventory *)malloc(sizeof(Inventory));
  if (new_inv == NULL) {
    return NULL;
  }

  new_inv->ids = set_create();
  if (new_inv->ids == NULL) {
    inventory_destroy(new_inv);
    return NULL;
  }

  new_inv->max_inventory = 0;

  return new_inv;
}

STATUS inventory_destroy(Inventory *inv) {
  if (!inv)
    return ERROR;

  set_destroy(inv->ids);

  free(inv);
  inv = NULL;

  return OK;
}

STATUS inventory_add_id(Inventory *inv, Id id) {
  STATUS st = OK;
  if (!inv || !id)
    return ERROR;

  if (set_get_num_of_ids(inv->ids) == inv->max_inventory)
    return ERROR;

  st = set_add(inv->ids, id);

  return st;
}

STATUS inventory_del_id(Inventory *inv, Id id) {
  STATUS st = OK;
  if (!inv || !id)
    return ERROR;

  if (set_get_num_of_ids(inv->ids) == 0)
    return ERROR;

  st = set_del(inv->ids, id);

  return st;
}

Id inventory_get_object_from_pos(Inventory *inv, int pos) {
  if (!inv || pos < 0)
    return NO_ID;

  return set_get_id_from_pos(inv->ids, pos);
}

STATUS inventory_set_max(Inventory *inv, int max) {
  if (!inv || !max)
    return ERROR;

  inv->max_inventory = max;

  return OK;
}

int inventory_get_max(Inventory *inv) {
  if (!inv)
    return -1;

  return inv->max_inventory;
}

BOOL inventory_is_full(Inventory *inv) {
  int n;
  if (!inv)
    return TRUE;

  n = set_get_num_of_ids(inv->ids);

  if (n == inv->max_inventory)
    return TRUE;

  return FALSE;
}

BOOL inventory_is_empty(Inventory *inv) {
  if (!inv)
    return TRUE;

  if (set_get_num_of_ids(inv->ids) == 0)
    return TRUE;

  return FALSE;
}

BOOL inventory_has_object(Inventory *inv, Id id) {
  if (!inv)
    return FALSE;

  return set_has_id(inv->ids, id);
}

STATUS inventory_print(Inventory *inv) {
  if (!inv)
    return ERROR;

  fprintf(stdout, "--> Inventory: (max_inventory: %d)\n", inv->max_inventory);

  set_print(inv->ids);

  return OK;
}
