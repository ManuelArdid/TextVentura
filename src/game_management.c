/** 
 * @brief Implementation of game management interface
 * 
 * Contains the implementation of the functions associated to game management
 *
 * @file game_management.c
 * @author Manuel Ardid
 * @version 1.0 
 * @date 14-01-2021 
 * @copyright GNU Public License
 */

#include "game_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/

/**
 * @brief Loads the space of the game
 *
 * game_management_load_spaces It creates the space by reading a file
 *
 * @date 14-02-2021
 * @author: Manuel Ardid
 *
 * @param game where the space of game is going to be saved
 * @param filename where it gets the space information
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_load_spaces(Game *game, char *filename);

/**
 * @brief Loads the objects into the game
 *
 * game_management_load_objects It places the objects into the spaces 
 * by reading a file
 *
 * @date 05-03-2021
 * @author: Manuel Ardid
 *
 * @param game where the objects of game is going to be saved
 * @param filename where it gets the objects information
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_load_objects(Game *game, char *filename);

/**
 * @brief Loads the player into the game
 *
 * game_management_load_player It places the objects into the game 
 * by reading a file
 *
 * @date 26-03-2021
 * @author: Manuel Ardid
 *
 * @param game where the player of game is going to be saved
 * @param filename where it gets the player information
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_load_player(Game *game, char *filename);

/**
 * @brief Loads the link into the game
 *
 * game_management_load_link It places the links into the game 
 * by reading a file
 *
 * @date 27-03-2021
 * @author: Manuel Ardid
 *
 * @param game where the links of game is going to be saved
 * @param filename where it gets the links information
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_load_links(Game *game, char *filename);

/**
 * @brief Loads the rest of the information from the save point
 *
 * game_management_load_rest_info It places the information from the save
 *
 * @date 03-04-2021
 * @author: Manuel Ardid
 *
 * @param game where the links of game is going to be saved
 * @param filename where it gets the information
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_load_rest_info(Game *game, char *filename);

/**
 * @brief Saves the sapces information to a file
 *
 * game_management_save_spaces It places the information to a file
 *
 * @date 09-05-2021
 * @author: Manuel Ardid
 *
 * @param game where it gets the information
 * @param filename where it going to be saved
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_save_spaces(Game *game, char *filename);

/**
 * @brief Saves the objects information to a file
 *
 * game_management_save_objects It places the information to a file
 *
 * @date 03-04-2021
 * @author: Manuel Ardid
 *
 * @param game where it gets the information
 * @param filename where it going to be saved
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_save_objects(Game *game, char *filename);

/**
 * @brief Saves the player information to a file
 *
 * game_management_save_player It places the information to a file
 *
 * @date 03-04-2021
 * @author: Manuel Ardid
 *
 * @param game where it gets the information
 * @param filename where it going to be saved
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_save_player(Game *game, char *filename);

/**
 * @brief Saves the links information to a file
 *
 * game_management_save_links It places the information to a file
 *
 * @date 03-04-2021
 * @author: Manuel Ardid
 *
 * @param game where it gets the information
 * @param filename where it going to be saved
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_save_links(Game *game, char *filename);

/**
 * @brief Saves the rest of the information to a file
 *
 * game_management_save_rest_info It places the information to a file
 *
 * @date 03-04-2021
 * @author: Manuel Ardid
 *
 * @param game where it gets the information
 * @param filename where it going to be saved
 * @return status if it succeed or ERROR if it failed
*/
STATUS game_management_save_rest_info(Game *game, char *filename);

/**
   Public funtions implementation
*/

STATUS game_management_load(Game *game, char *filename) {
  if (game_management_load_spaces(game, filename) == ERROR)
    return ERROR;

  if (game_management_load_objects(game, filename) == ERROR)
    return ERROR;

  if (game_management_load_player(game, filename) == ERROR)
    return ERROR;

  if (game_management_load_links(game, filename) == ERROR)
    return ERROR;

  if (game_management_load_rest_info(game, filename) == ERROR)
    return ERROR;

  return OK;
}

STATUS game_management_save(Game *game, char *filename) {
  if (game_management_save_spaces(game, filename) == ERROR)
    return ERROR;

  if (game_management_save_objects(game, filename) == ERROR)
    return ERROR;

  if (game_management_save_player(game, filename) == ERROR)
    return ERROR;

  if (game_management_save_links(game, filename) == ERROR)
    return ERROR;

  if (game_management_save_rest_info(game, filename) == ERROR)
    return ERROR;

  return OK;
}

/**
   Private funtions implementation
*/

STATUS game_management_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "", description[WORD_SIZE] = "", full_description[WORD_SIZE] = "";
  char gdesc[INC1][INC2 + 1];
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  int i, j;
  BOOL light_init = FALSE, light_act = FALSE, fd_exist = FALSE;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    for (i = 0; i < INC1; i++) {
      for (j = 0; j < INC2; j++) {
        gdesc[i][j] = ' ';
      }
      gdesc[i][j] = '\0';
    }

    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      north = atol(toks);

      toks = strtok(NULL, "|");
      west = atol(toks);

      toks = strtok(NULL, "|");
      south = atol(toks);

      toks = strtok(NULL, "|");
      east = atol(toks);

      toks = strtok(NULL, "|");
      up = atol(toks);

      toks = strtok(NULL, "|");
      down = atol(toks);

      toks = strtok(NULL, "|");
      light_init = atoi(toks);

      toks = strtok(NULL, "|");
      light_act = atoi(toks);

      toks = strtok(NULL, "|");

      if (toks != NULL) {
        fd_exist = TRUE;
        strcpy(description, toks);
        toks = strtok(NULL, "|");
        strcpy(full_description, toks);
        toks = strtok(NULL, "|");
      }

      if (toks != NULL) {
        for (i = 0; i < INC1; i++) {
          strcpy(gdesc[i], toks);
          toks = strtok(NULL, "|");
        }
      }

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%d|%d|%s|\n", id, name, north, west, south, east, up, down, light_init, light_act, description);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north_link(space, north);
        space_set_east_link(space, east);
        space_set_south_link(space, south);
        space_set_west_link(space, west);
        space_set_up_link(space, up);
        space_set_down_link(space, down);
        game_add_space(game, space);
        space_set_light_init(space, light_init);
        space_set_light_act(space, light_act);

        if (fd_exist == TRUE) {
          space_set_description(space, description);
          space_set_full_description(space, full_description);
        }

        for (i = 0; i < INC1; i++) {
          space_set_gdesc(space, gdesc[i], i);
        }
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_load_objects(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "", description[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, position = NO_ID, dependency = NO_ID, open = NO_ID;
  BOOL movable, illuminate, turnedon, discovery, exist = FALSE;
  Object *object = NULL;
  STATUS status = OK;

  if (!filename || !game) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      position = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(description, toks);

      toks = strtok(NULL, "|");
      movable = atoi(toks);

      toks = strtok(NULL, "|");
      dependency = atol(toks);

      toks = strtok(NULL, "|");
      open = atol(toks);

      toks = strtok(NULL, "|");
      illuminate = atoi(toks);

      toks = strtok(NULL, "|");
      turnedon = atoi(toks);

      toks = strtok(NULL, "|");
      if (toks != NULL) {
        exist = TRUE;
        discovery = atoi(toks);
      }

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%s|%d|%ld|%ld|%d|%d|\n", id, name, position, description, movable, dependency, open, illuminate, turnedon);
#endif
      object = object_create(id);
      if (object != NULL) {
        object_set_name(object, name);
        game_set_object_location(game, position, id);
        game_add_object(game, object);
        object_set_description(object, description);
        object_set_movable(object, movable);
        object_set_dependency(object, dependency);
        object_set_open(object, open);
        object_set_illuminate(object, illuminate);
        object_set_turnedon(object, turnedon);
        if (exist == TRUE) {
          object_set_discovery(object, discovery);
        }
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_load_player(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, position = NO_ID, objs[MAX_OBJECTS];
  int max_objs = 0, num_obj = 0, i;
  Player *player = NULL;
  STATUS status = OK;
  BOOL exist = FALSE;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#p:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      position = atol(toks);
      toks = strtok(NULL, "|");
      max_objs = atol(toks);
      toks = strtok(NULL, "|");
      if (toks != NULL) {
        exist = TRUE;
        num_obj = atoi(toks);
        toks = strtok(NULL, "|");
        for (i = 0; i < num_obj; i++) {
          objs[i] = atol(toks);
          toks = strtok(NULL, "|");
        }
      }
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%d|\n", id, name, position, max_objs);
#endif
      player = player_create(id);

      if (player != NULL) {
        game_add_player(game, player);

        if (player_set_name(player, name) == ERROR) {
          return ERROR;
        }

        if (game_set_player_location(game, position) == ERROR) {
          return ERROR;
        }

        if (player_set_max_objects(player, max_objs) == ERROR) {
          return ERROR;
        }

        if (exist == TRUE) {
          for (i = 0; i < num_obj; i++) {
            player_add_object(player, objs[i]);
          }
        }
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_load_links(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, space1 = NO_ID, space2 = NO_ID;
  BOOL close = FALSE;
  Link *link = NULL;
  STATUS status = OK;

  if (!filename || !game) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#l:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space1 = atol(toks);
      toks = strtok(NULL, "|");
      space2 = atol(toks);
      toks = strtok(NULL, "|");
      close = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|\n", id, name, space1, space2, close);
#endif
      link = link_create(id);
      if (link != NULL) {
        link_set_name(link, name);
        link_set_space1(link, space1);
        link_set_space2(link, space2);
        link_set_close(link, close);
        game_add_link(game, link);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_load_rest_info(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char option[WORD_SIZE] = "", description[WORD_SIZE] = "";
  char *toks = NULL;
  int die_value;
  Die *d = NULL;
  STATUS status = OK;

  if (!filename || !game) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#r:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      die_value = atoi(toks);
      toks = strtok(NULL, "|");
      strcpy(option, toks);
      toks = strtok(NULL, "|");
      strcpy(description, toks);
      toks = strtok(NULL, "|");
#ifdef DEBUG
      printf("Leido: %d|%s|%s|\n", die_value, option, description);
#endif

      d = game_get_die(game);
      die_set_last_num(d, die_value);

      game_set_option(game, option);

      game_set_description(game, description);
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_save_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  Space *s = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID;
  BOOL light_init = FALSE, light_act = FALSE;
  char name[WORD_SIZE] = "";
  int i, j;
  STATUS status = OK;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "a");
  if (!file)
    return ERROR;

  for (i = 1; i < MAX_SPACES; i++) {
    s = game_get_space(game, i);
    if (s != NULL) {
      id = space_get_id(s);
      strcpy(name, space_get_name(s));
      north = space_get_north_link(s);
      west = space_get_west_link(s);
      south = space_get_south_link(s);
      east = space_get_east_link(s);
      up = space_get_up_link(s);
      down = space_get_down_link(s);
      light_init = space_get_light_init(s);
      light_act = space_get_light_act(s);
      fprintf(file, "#s:%ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%d|%d|%s|%s|", id, name, north, west, south, east, up, down, light_init, light_act, space_get_init_description(s), space_get_full_description(s));
      for (j = 0; j < INC1; j++) {
        fprintf(file, "%s|", space_get_gdesc(s, j));
      }
      fprintf(file, "\n");
    } else {
      break;
    }
  }

  fprintf(file, "\n");

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_save_objects(Game *game, char *filename) {
  FILE *file = NULL;
  Object *o = NULL;
  Id id = NO_ID;
  char name[WORD_SIZE] = "", description[WORD_SIZE] = "";
  Id position = NO_ID, dependency = NO_ID, open = NO_ID;
  BOOL movable, illuminate, turnedon, discovery;
  int i;
  STATUS status = OK;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "a");
  if (!file)
    return ERROR;

  for (i = 0; i < MAX_OBJECTS; i++) {
    o = game_get_object(game, i);
    if (o != NULL) {
      id = object_get_id(o);
      strcpy(name, object_get_name(o));
      position = game_get_object_location(game, id);
      strcpy(description, object_get_description(o));
      movable = object_is_movable(o);
      dependency = object_get_dependency(o);
      open = object_get_open(o);
      illuminate = object_can_illuminate(o);
      turnedon = object_is_turnedon(o);
      discovery = object_is_discovered(o);
      fprintf(file, "#o:%ld|%s|%ld|%s|%d|%ld|%ld|%d|%d|%d|\n", id, name, position, description, movable, dependency, open, illuminate, turnedon, discovery);
    } else {
      break;
    }
  }

  fprintf(file, "\n");

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_save_player(Game *game, char *filename) {
  FILE *file = NULL;
  Player *p = NULL;
  Id id = NO_ID, position = NO_ID;
  char name[WORD_SIZE] = "";
  int i, num_obj, max_objs;
  STATUS status = OK;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "a");
  if (!file)
    return ERROR;

  p = game_get_player(game);
  id = player_get_id(p);
  strcpy(name, player_get_name(p));
  position = player_get_location(p);
  max_objs = player_get_max_objects(p);
  fprintf(file, "#p:%ld|%s|%ld|%d|", id, name, position, max_objs);
  num_obj = player_get_num_of_objects(p);
  fprintf(file, "%d|", num_obj);
  for (i = 0; i < num_obj; i++) {
    fprintf(file, "%ld|", player_get_object_from_pos(p, i));
  }

  fprintf(file, "\n\n");

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_save_links(Game *game, char *filename) {
  FILE *file = NULL;
  Link *l = NULL;
  Id id = NO_ID;
  char name[WORD_SIZE] = "";
  BOOL close;
  Id space1 = NO_ID, space2 = NO_ID;
  int i;
  STATUS status = OK;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "a");
  if (!file)
    return ERROR;

  for (i = 1; i < MAX_LINKS; i++) {
    l = game_get_link(game, i);
    if (l != NULL) {
      id = link_get_id(l);
      strcpy(name, link_get_name(l));
      space1 = link_get_space1(l);
      space2 = link_get_space2(l);
      close = link_is_close(l);
      fprintf(file, "#l:%ld|%s|%ld|%ld|%d|\n", id, name, space1, space2, (int)close);
    } else {
      break;
    }
  }

  fprintf(file, "\n");

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_management_save_rest_info(Game *game, char *filename) {
  FILE *file = NULL;
  char description[WORD_SIZE] = "";
  STATUS status = OK;

  if (!game || !filename)
    return ERROR;

  file = fopen(filename, "a");
  if (!file)
    return ERROR;

  fprintf(file, "#r:");
  fprintf(file, "%d|", game_get_last_die_value(game));
  fprintf(file, "%s|", game_get_option(game));
  strcpy(description, game_get_description(game));
  if (description[0] == '\0') {
    fprintf(file, " |");
  } else {
    fprintf(file, "%s|", description);
  }

  fprintf(file, "\n");

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}