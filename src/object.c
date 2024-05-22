/**
 * @brief It implements the object interface
 *
 * It contains the funtions implementation of an object
 *
 * @file object.c
 * @author Manuel Ardid
 * @version 1.0
 * @date 17-02-2021
 * @copyright GNU Public License
 */

#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Defines the structure
*/

/**
* @brief The object structure
*
* It saves the object id and name
*/
struct _Object {
  Id id;                           /*!< Object's id */
  char name[WORD_SIZE + 1];        /*!< Object's name */
  char description[WORD_SIZE + 1]; /*!< Object's description */
  BOOL movable;                    /*!< Object's movability */
  Id dependency;                   /*!< Object's dependency */
  Id open;                         /*!< Object can open or not*/
  BOOL illuminate;                 /*!< Object can illuminate or not*/
  BOOL turnedon;                   /*!< Object is turnedon or off*/
  BOOL discovery;                  /*!< Object is discovered or not*/
};

Object *object_create(Id id) {
  Object *new_object = NULL;

  if (id == NO_ID)
    return NULL;

  new_object = (Object *)malloc(sizeof(Object));
  if (new_object == NULL)
    return NULL;

  new_object->id = id;
  new_object->name[0] = '\0';
  new_object->description[0] = '\0';
  new_object->movable = FALSE;
  new_object->dependency = NO_ID;
  new_object->open = NO_ID;
  new_object->illuminate = FALSE;
  new_object->turnedon = FALSE;
  new_object->discovery = FALSE;

  return new_object;
}

STATUS object_destroy(Object *object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

Id object_get_id(Object *object) {
  if (!object)
    return NO_ID;

  return object->id;
}

STATUS object_set_name(Object *object, char *name) {
  if (!object || !name)
    return ERROR;

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}

const char *object_get_name(Object *object) {
  if (!object)
    return NULL;

  return object->name;
}

STATUS object_set_description(Object *object, char *description) {
  if (!object || !description)
    return ERROR;

  if (!strcpy(object->description, description)) {
    return ERROR;
  }

  return OK;
}

const char *object_get_description(Object *object) {
  if (!object)
    return NULL;

  return object->description;
}

STATUS object_set_movable(Object *object, BOOL value) {
  if (!object)
    return ERROR;

  object->movable = value;

  return OK;
}

BOOL object_is_movable(Object *object) {
  if (!object)
    return FALSE;

  return object->movable;
}

STATUS object_set_dependency(Object *object, Id id) {
  if (!object)
    return ERROR;

  object->dependency = id;

  return OK;
}

Id object_get_dependency(Object *object) {
  if (!object)
    return NO_ID;

  return object->dependency;
}

STATUS object_set_illuminate(Object *object, BOOL value) {
  if (!object)
    return ERROR;

  object->illuminate = value;

  return OK;
}

BOOL object_can_illuminate(Object *object) {
  if (!object)
    return FALSE;

  return object->illuminate;
}

STATUS object_set_turnedon(Object *object, BOOL value) {
  if (!object)
    return ERROR;

  object->turnedon = value;

  return OK;
}

BOOL object_is_turnedon(Object *object) {
  if (!object)
    return FALSE;

  return object->turnedon;
}

STATUS object_set_discovery(Object *object, BOOL value) {
  if (!object)
    return ERROR;

  object->discovery = value;

  return OK;
}

BOOL object_is_discovered(Object *object) {
  if (!object)
    return FALSE;
  return object->discovery;
}

STATUS object_set_open(Object *object, Id id) {
  if (!object)
    return ERROR;

  object->open = id;

  return OK;
}

Id object_get_open(Object *object) {
  if (!object)
    return NO_ID;

  return object->open;
}

STATUS object_print(Object *object) {
  if (!object)
    return ERROR;

  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Description: %s; Movable: %d; Dependency: %ld; Open: %ld; Illuminate: %d; Turnedon: %d)\n", object->id, object->name, object->description, object->movable, object->dependency, object->open, object->illuminate, object->turnedon);

  return OK;
}
