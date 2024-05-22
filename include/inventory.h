/** 
 * @brief It defines the inventory of the game
 * 
 * @file inventory.h
 * @author Manuel Ardid Clavería 
 * @date 25-03-2021
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "object.h"
#include "set.h"
#include "types.h"

/** 
 * @brief Structure that defines the inventory, includes a set of ids and the maximum number of objects
 * 
 */
typedef struct _Inventory Inventory;

/**
* @brief Creates an inventory
*
* inventory_create It allocates memory to inventory
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
*
* @return pointer to the new inventory
*/
Inventory *inventory_create();

/**
* @brief Deletes an inventory
*
* inventory_destroy It frees the memory allocated to inventory
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
*
* @param inv pointer to the inventory
* @return OK or ERROR
*/
STATUS inventory_destroy(Inventory *inv);

/**
* @brief Adds an Id 
*
* inventory_add_id Adds an Id to the inventory
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
*
* @param inv pointer to the inventory
* @param id the Id you want to add
* @return OK or ERROR
*/
STATUS inventory_add_id(Inventory *inv, Id id);

/**
* @brief Deletes an Id
*
* inventory_del_id Deletes an Id from the inventory
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
*
* @param inv pointer to the inventory
* @param id the Id you want to delete
* @return OK or ERROR
*/
STATUS inventory_del_id(Inventory *inv, Id id);

/**
* @brief It set maximun of inventory
*
* inventory_set_max Updates the maximum number of ids that the set can save
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
*
* @param inv pointer to the inventory
* @param max maximun number of ids the set can save
* @return OK or ERROR
*/
STATUS inventory_set_max(Inventory *inv, int max);

/**
* @brief Inventory get maximun
*
* inventory_get_max Gets the maximum number of ids that the set can save from an inventory 
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
*
* @param inv pointer to the inventory
* @return maximun number of ids the set can save
*/
int inventory_get_max(Inventory *inv);

/**
* @brief Inventory is full
*
* inventory_is_full Checks if the set of the inventory is full
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
*
* @param inv pointer to the inventory
* @return TRUE or FALSE
*/
BOOL inventory_is_full(Inventory *inv);

/**
* @brief Inventory is empty
*
* inventory_is_empty Checks if the set of the inventory is empty
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
*
* @param inv pointer to the inventory
* @return TRUE or FALSE
*/
BOOL inventory_is_empty(Inventory *inv);

/**
* @brief Inventory has object
*
* inventory_has_object It finds if the inventory has the object
*
* @date 04-05-2021
* @author: Manuel Ardid
*
* @param inv where it gets the information
* @param id the id of the object
* @return TRUE if the inventory has the object or FALSE otherwise
*/
BOOL inventory_has_object(Inventory *inv, Id id);
/**
* @brief Inventory print
*
* inventory_print It prints al the information of the inventory
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
*
* @param inv pointer to the inventory
* @return ERROR or OK
*/
STATUS inventory_print(Inventory *inv);

/**
* @brief Gets an id from a specific position
*
* inventory_get_object_from_pos It get the object id from the position
*
* @date 25-03-2021
* @author: Manuel Ardid Clavería 
* 
* @param inv pointer to the inventory
* @param pos position of the object in the array
* @return the id in that position or NO_ID if it fails
*/
Id inventory_get_object_from_pos(Inventory *inv, int pos);

#endif