/** 
 * @brief It implements the graphic engine interface
 * 
 * Contains the implementation of the functions associated to graphic_engine
 *
 * @file graphic_engine.c
 * @author Manuel Ardid
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "dialogue.h"
#include "screen.h"

/** Defines the constant variables */
#define MAX_CHAR 64
/** Defines the constant variables */
#define WIDE 28

/**
   Defines the data structure of Graphic_engine
*/
struct _Graphic_engine {
  Area *map;      /*!< Different pointers related to each area*/
  Area *descript; /*!< Different pointers related to each area*/
  Area *banner;   /*!< Different pointers related to each area*/
  Area *help;     /*!< Different pointers related to each area*/
  Area *feedback; /*!< Different pointers related to each area*/
};

/**
* @brief Set the string of objects 
*
* graphic_engine_set_string_obj It saves the object that are in the space
*
* @date 26-03-2021
* @author: Manuel Ardid
*
* @param game where it gets the information of the game
* @param obj where its going to be saved the string of objects 
* @param space where its going to print
* @return OK if it was saved correctly or ERROR if it fails
*/
STATUS graphic_engine_set_string_obj(Game *game, char *obj, Space *space);

/**
* @brief Set the string of the player objects 
*
* graphic_engine_set_string_player_obj It saves the objects that the player is carrying
*
* @date 06-04-2021
* @author: Manuel Ardid Clavería
*
* @param game where it gets the information of the game
* @param obj where its going to be saved the string of objects 
* @param player pointer to the player who is carrying the objects
* @return OK if it was saved correctly or ERROR if it fails
*/
STATUS graphic_engine_set_string_player_obj(Game *game, char *obj, Player *player);

/**
* @brief Print the information of the objects and it's location
*
* graphic_engine_print_objects_location It gets the string with the object information
*
* @date 19-03-2021
* @author: Manuel Ardid
*
* @param game where it gets the information of the game
* @return the string with the objects or NULL if it fails
*/
char *graphic_engine_print_objects_location(Game *game);

/**
* @brief Print the field link
*
* graphic_engine_print_field_link_descr It prints the linked spaces and number with the field
*
* @date 18-04-2021
* @author: Manuel Ardid
*
* @param ge graphic engine to paint
* @param game where it gets the information of the game
* @param space the space it want to print
* @param id the id of the space
* @return OK it has printed correctly or ERROR if it fails
*/
STATUS graphic_engine_print_field_link_descr(Graphic_engine *ge, Game *game, Space *space, Id id);

/**
   Public funtions implementation
*/

Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();

  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));

  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 2, 60, 21);
  ge->descript = screen_area_init(65, 2, 89, 21);
  ge->banner = screen_area_init(1, 0, 60, 1);
  ge->help = screen_area_init(1, 24, 153, 5);
  ge->feedback = screen_area_init(1, 30, 153, 3);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID;
  Space *space_act = NULL, *space_back = NULL, *space_next = NULL;
  char obj[MAX_CHAR] = "", player_objs[MAX_CHAR] = "";
  char *objs = NULL;
  char description[WORD_SIZE + 1] = "";
  char str[300];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  Player *player = NULL;
  Link *link = NULL;

  /* Paint the in the map area */
  screen_area_clear(ge->map);

  if ((id_act = game_get_player_location(game)) != NO_ID) {
    space_act = game_get_space(game, id_act);

    link = game_get_link(game, space_get_north_link(space_act));
    id_back = link_get_space1(link);
    if (id_back == id_act) {
      id_back = link_get_space2(link);
    }
    link = game_get_link(game, space_get_south_link(space_act));
    id_next = link_get_space1(link);
    if (id_next == id_act) {
      id_next = link_get_space2(link);
    }

    space_back = game_get_space(game, id_back);
    space_next = game_get_space(game, id_next);

    graphic_engine_set_string_obj(game, obj, game_get_space(game, id_back));

    if (id_back != NO_ID) {
      graphic_engine_print_field_link_descr(ge, game, space_back, id_back);

      sprintf(str, "          |%s|", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "          +----------------------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                   ^ %s", link_get_name(game_get_link(game, space_get_north_link(space_act))));
      screen_area_puts(ge->map, str);
    }
    obj[0] = '\0';

    graphic_engine_set_string_obj(game, obj, game_get_space(game, id_act));

    if (id_act != NO_ID) {
      graphic_engine_print_field_link_descr(ge, game, space_act, id_act);

      sprintf(str, "          |%s|", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "          +----------------------------+");
      screen_area_puts(ge->map, str);
    }
    obj[0] = '\0';

    graphic_engine_set_string_obj(game, obj, game_get_space(game, id_next));

    if (id_next != NO_ID) {
      sprintf(str, "                   v %s", link_get_name(game_get_link(game, space_get_south_link(space_act))));
      screen_area_puts(ge->map, str);

      graphic_engine_print_field_link_descr(ge, game, space_next, id_next);

      sprintf(str, "          |%s|", obj);
      screen_area_puts(ge->map, str);
    }
    obj[0] = '\0';
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);

  screen_area_clear(ge->descript);
  sprintf(str, "  [Localizacion de los objetos] ");
  screen_area_puts(ge->descript, str);
  objs = graphic_engine_print_objects_location(game);
  screen_area_puts(ge->descript, objs);
  free(objs);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  player = game_get_player(game);
  /* Gets the objects the player is carrying as a string*/
  graphic_engine_set_string_player_obj(game, player_objs, player);
  sprintf(str, "  [Objetos del jugador. Capacidad de inventario: %d]", player_get_max_objects(player));
  screen_area_puts(ge->descript, str);

  sprintf(str, "  %s", player_objs);
  screen_area_puts(ge->descript, str);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "  [Descripcion] ");
  screen_area_puts(ge->descript, str);
  strcpy(description, "  ");
  strcat(description, (char *)game_get_description(game));
  screen_area_puts(ge->descript, description);

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "  [Descripcion del espacio] ");
  screen_area_puts(ge->descript, str);
  strcpy(description, "  ");
  strcat(description, (char *)space_get_description(space_act));
  screen_area_puts(ge->descript, description);

  /* Paint in the banner area */
  screen_area_puts(ge->banner, "         -LA MANSION DEL DUQUE DE HERTHAL-       ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " COMANDOS:");
  screen_area_puts(ge->help, str);
  sprintf(str, " [mover/m + <norte/n, este/e..., arriba/ar, abajo/ab>]    [coger/c + <objeto>]    [soltar/s + <objeto>]    [inspeccionar/i + <objeto>/espacio/e]");
  screen_area_puts(ge->help, str);
  sprintf(str, " [encender/e + <objeto>]    [apagar/a + <objeto>]    [abrir/abr + <enlace> + con + <objeto>]");
  screen_area_puts(ge->help, str);
  sprintf(str, " [guardar/gr + <archivo>]    [cargar/cr + <archivo>]    [salir/sl]");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */

  last_cmd = game_get_last_command(game);

  sprintf(str, " %s (%s): %s", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], game_get_dialogue_message(game));

  /*sprintf(str, " %s", game_get_dialogue_message(game));*/
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}

STATUS graphic_engine_set_string_obj(Game *game, char *obj, Space *space) {
  Id *id = NULL;
  int i, j, num;
  Object *pobj = NULL;

  if (!obj || !space)
    return ERROR;

  id = space_get_objects(space);
  num = space_get_number_of_objects(space);

  if (id == NULL || space_get_light_act(space) == FALSE) {
    for (i = strlen(obj); i < WIDE; i++) {
      obj[i] = ' ';
    }
    obj[i] = '\0';

    free(id);
    return OK;
  }

  obj[0] = '\0';

  for (j = 0; j < num; j++) {
    for (i = 0; i < MAX_OBJECTS; i++) {
      pobj = game_get_object(game, i);
      if (object_get_id(pobj) == id[j]) {
        strcat(obj, object_get_name(game_get_object(game, i)));
        strcat(obj, " ");
      }
      if (pobj == NULL) {
        break;
      }
    }
  }

  for (i = strlen(obj); i < WIDE; i++) {
    obj[i] = ' ';
  }
  obj[WIDE] = '\0';

  free(id);
  return OK;
}

STATUS graphic_engine_set_string_player_obj(Game *game, char *obj, Player *player) {
  int i, j, num;
  Object *pobj = NULL;

  if (!obj || !player || !game)
    return ERROR;

  num = player_get_num_of_objects(player);

  obj[0] = '\0';

  for (j = 0; j < num; j++) {
    for (i = 0; i < MAX_OBJECTS; i++) {
      pobj = game_get_object(game, i);
      if (object_get_id(pobj) == player_get_object_from_pos(player, j)) {
        strcat(obj, object_get_name(pobj));
        strcat(obj, " ");
      }
      if (pobj == NULL) {
        break;
      }
    }
  }
  strcat(obj, "\0");

  return OK;
}

char *graphic_engine_print_objects_location(Game *game) {
  int i;
  char *objects = NULL, num_to_char[4] = "";
  Id obj_loc = NO_ID;
  Object *current_obj = NULL;

  objects = (char *)calloc(sizeof(char), WORD_SIZE + 1);
  if (objects == NULL) {
    return NULL;
  }

  strcpy(objects, "  ");

  for (i = 0; i < MAX_OBJECTS && game_get_object(game, i) != NULL; i++) {
    current_obj = game_get_object(game, i);
    if (object_is_discovered(current_obj) == TRUE) {
      obj_loc = game_get_object_location(game, object_get_id(current_obj));
      if (obj_loc != NO_ID) {
        strcat(objects, object_get_name(current_obj));
        strcat(objects, ":");
        sprintf(num_to_char, "%ld", obj_loc);
        strcat(objects, num_to_char);
        strcat(objects, " ");
      }
    }
  }

  return objects;
}

STATUS graphic_engine_print_field_link_descr(Graphic_engine *ge, Game *game, Space *space, Id id) {
  Link *link_east = NULL, *link_west = NULL;
  Id space1 = NO_ID, space2 = NO_ID;
  char str[255], link1[MAX_CHAR], link2[MAX_CHAR], player[MAX_CHAR];
  int i;

  if (!ge || !game || !space) {
    return ERROR;
  }

  link_east = game_get_link(game, space_get_east_link(space));
  link_west = game_get_link(game, space_get_west_link(space));

  if (id != NO_ID) {
    if (link_west != NULL) {
      sprintf(link1, "   %s ", link_get_name(link_west));
    } else {
      sprintf(link1, "          ");
    }
    if (link_east != NULL) {
      sprintf(link2, " %s", link_get_name(link_east));
    } else {
      sprintf(link2, "  ");
    }

    sprintf(str, "%s                              %s", link1, link2);
    screen_area_puts(ge->map, str);
    sprintf(str, "          +----------------------------+");
    screen_area_puts(ge->map, str);
  }

  if (id == game_get_player_location(game)) {
    sprintf(player, "(._.)");
  } else {
    sprintf(player, "     ");
  }

  space1 = link_get_space1(link_west);
  if (space1 == id) {
    space1 = link_get_space2(link_west);
  }
  space2 = link_get_space1(link_east);
  if (space2 == id) {
    space2 = link_get_space2(link_east);
  }

  if (link_east != NULL && link_west != NULL) {
    sprintf(str, "   %2d <-- | %s                    %2d| --> %2d", (int)space1, player, (int)id, (int)space2);
    screen_area_puts(ge->map, str);
  } else if (link_east != NULL && link_west == NULL) {
    sprintf(str, "          | %s                    %2d| --> %2d", player, (int)id, (int)space2);
    screen_area_puts(ge->map, str);
  } else if (link_east == NULL && link_west != NULL) {
    sprintf(str, "   %2d <-- | %s                    %2d|    ", (int)space1, player, (int)id);
    screen_area_puts(ge->map, str);
  } else {
    sprintf(str, "          | %s                    %2d|", player, (int)id);
    screen_area_puts(ge->map, str);
  }

  if (space_get_light_act(space) == FALSE) {
    for (i = 0; i < INC1; i++) {
      sprintf(str, "          |                            |");
      screen_area_puts(ge->map, str);
    }
  } else {
    for (i = 0; i < INC1; i++) {
      sprintf(str, "          |    %s                 |", space_get_gdesc(game_get_space(game, id), i));
      screen_area_puts(ge->map, str);
    }
  }

  return OK;
}