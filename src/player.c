/**
 * @brief New player implementation
 *
 * Contains the functions associated to a new player
 *
 * @file player.c
 * @author Manuel Ardid
 * @version 2.0
 * @date 28-02-2021
 * @copyright GNU Public License
 */

#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inventory.h"

/**
   Defines the structures
*/

/**
* @brief The structure of Player
*
* Save the id, the name, the location of the player and the object they take
*/
struct _Player {
  Id id;                    /*!< Player's id*/
  char name[WORD_SIZE + 1]; /*!< Player's name*/
  Id location;              /*!< Player's location*/
  Inventory *objects;       /*!< Player's object*/
};

/**
  Public funtions implementation
*/

Player *player_create(Id id) {
  Player *new_player = NULL;

  if (id == NO_ID)
    return NULL;

  new_player = (Player *)malloc(sizeof(Player));

  if (new_player == NULL) {
    return NULL;
  }

  new_player->id = id;

  new_player->name[0] = '\0';

  new_player->location = NO_ID;

  new_player->objects = inventory_create();
  if (new_player->objects == NULL) {
    player_destroy(new_player);
    return NULL;
  }

  return new_player;
}

STATUS player_destroy(Player *player) {
  if (!player) {
    return ERROR;
  }

  inventory_destroy(player->objects);

  free(player);
  player = NULL;

  return OK;
}

Id player_get_id(Player *player) {
  if (!player) {
    return NO_ID;
  }

  return player->id;
}

STATUS player_set_name(Player *player, char *name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}

const char *player_get_name(Player *player) {
  if (!player) {
    return NULL;
  }

  return player->name;
}

STATUS player_set_location(Player *player, Id location) {
  if (!player) {
    return ERROR;
  }

  player->location = location;

  return OK;
}

Id player_get_location(Player *player) {
  if (!player) {
    return NO_ID;
  }

  return player->location;
}

STATUS player_add_object(Player *player, Id id) {
  STATUS st = ERROR;

  if (!player) {
    return ERROR;
  }

  st = inventory_add_id(player->objects, id);

  return st;
}

STATUS player_del_object(Player *player, Id id) {
  STATUS st = ERROR;

  if (!player) {
    return ERROR;
  }

  st = inventory_del_id(player->objects, id);

  return st;
}

Id player_get_object_from_pos(Player *player, int pos) {
  if (!player || pos < 0) {
    return NO_ID;
  }

  return inventory_get_object_from_pos(player->objects, pos);
}

BOOL player_has_object(Player *player, Id id) {
  if (!player || id == NO_ID)
    return ERROR;

  return inventory_has_object(player->objects, id);
}

int player_get_num_of_objects(Player *player) {
  int len, i, count = 0;
  Id aux = NO_ID;

  if (!player)
    return -1;

  len = inventory_get_max(player->objects);
  for (i = 0; i < len; i++) {
    aux = inventory_get_object_from_pos(player->objects, i);
    if (aux != NO_ID)
      count++;
  }

  return count;
}

STATUS player_set_max_objects(Player *player, int max_objs) {
  if (!player || max_objs < 1) {
    return ERROR;
  }

  if (inventory_set_max(player->objects, max_objs) == ERROR) {
    return ERROR;
  }

  return OK;
}

int player_get_max_objects(Player *player) {
  if (!player) {
    return -1;
  }

  return inventory_get_max(player->objects);
}

STATUS player_print(Player *player) {
  int num_objs;
  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location: %ld)\n", player->id, player->name, player->location);

  num_objs = player_get_num_of_objects(player);
  if (num_objs > 0) {
    fprintf(stdout, "---> Objects of the player: ");
    inventory_print(player->objects);
  } else {
    fprintf(stdout, "---> No object of the player.\n");
  }

  return OK;
}
