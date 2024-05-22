/** 
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 *
 * Contains the implementation of the functions associated to game
 * 
 * @file game.c
 * @author Manuel Ardid
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_management.h"

/** Defines the constant variables */
#define DIE_ID1 1
/** Defines the constant variables */
#define MAX_DIE 6
/** Defines the constant variables */
#define MIN_DIE 1

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game *game);

/** 
 * @brief The Game structure
 * 
 * It stores information of the game interface
 */
struct _Game {
  Link *links[MAX_LINKS];          /*!< Define the maximum links we can have in the game */
  Player *player;                  /*!< Pointer to the player */
  Object *objects[MAX_OBJECTS];    /*!< Array of pointers to the object  */
  Space *spaces[MAX_SPACES + 1];   /*!< Define the maximum spaces we can have in the game */
  Die *die;                        /*!< Pointer to the die */
  Dialogue *dialogue;              /*!< Pointer to dialogue */
  T_Command last_cmd;              /*!< Command use in the game */
  STATUS last_cmd_st;              /*!< Status of the last command */
  char option[WORD_SIZE + 1];      /*!< The object to be taken or dropped or the move argument */
  char description[WORD_SIZE + 1]; /*!< Space or object description */
};

/**
   List of callbacks for each command in the game 
*/

/**
* @brief callback unknown
*
* game_callback_unknown 
*
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game 
*/
void game_callback_unknown(Game *game);

/**
* @brief callback exit
*
* game_callback_exit
*
* @date 22-02-2021
* @author: Manuel Ardid
*
* @param game 
*/
void game_callback_exit(Game *game);

/**
* @brief callback move
*
* game_callback_move Execute the move command, 
* the player will move to selected space
*
* @date 11-04-2021
* @author: Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_move(Game *game);

/**
* @brief callback take
*
* game_callback_take Execute the take command,
* the player will take the object
*
* @date 27-02-2021
* @author: Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_take(Game *game);

/**
* @brief callback drop
*
* game_callback_drop Execute the drop command,
* the player will drop the object
*
* @date 27-02-2021
* @author: Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_drop(Game *game);

/**
* @brief callback roll
*
* game_callback_roll Execute the roll command,
* the player will roll the die
*
* @date 19-03-2021
* @author: Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_roll(Game *game);

/**
* @brief callback inspect
*
* game_callback_inspect Execute the inspect command,
* the player will inspect the object or space
*
* @date 09-04-2021
* @author: Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_inspect(Game *game);

/**
* @brief callback open
*
* game_callback_open Execute the open command,
* the player will open a link using an object
*
* @date 26-04-2021
* @author Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_open(Game *game);

/**
* @brief callback turnon
*
* game_callback_turnon Execute the turnon command,
* the player will turnon the object which is not illuminated
*
* @date 20-04-2021
* @author: Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_turnon(Game *game);

/**
* @brief callback turnoff
*
* game_callback_turnoff Execute the turnoff command,
* the player will turnoff the object which is illuminated
*
* @date 20-04-2021
* @author: Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_turnoff(Game *game);

/**
* @brief callback save
*
* game_callback_save Execute the save command,
* the player will save the current game
*
* @date 01-05-2021
* @author: Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_save(Game *game);

/**
* @brief callback load
*
* game_callback_load Execute the load command,
* the player will load the game saved
*
* @date 1-05-2021
* @author: Manuel Ardid
*
* @param game where it uses the information
*/
void game_callback_load(Game *game);

/**
   Define the callbacks list
*/
static callback_fn game_callback_fn_list[N_CALLBACK] = {
    game_callback_unknown,
    game_callback_exit,
    game_callback_move,
    game_callback_take,
    game_callback_drop,
    game_callback_roll,
    game_callback_inspect,
    game_callback_turnon,
    game_callback_turnoff,
    game_callback_open,
    game_callback_save,
    game_callback_load};

/**
   Private functions
*/

/**
* @brief Gets an object from its name
* 
* game_get_object_by_name It gets the object pointer by its name
*
* @date 27-04-2021
* @author: Manuel Ardid
*
* @param game pointer to game
* @param name name of the object
* @return the object pointer or NULL if it doesn't exist
*/
Object *game_get_object_by_name(Game *game, char *name);

/**
* @brief Gets an object from its id
* 
* game_get_object_by_id It gets the object pointer by its id
*
* @date 30-04-2021
* @author: Manuel Ardid
*
* @param game pointer to game
* @param id id of the object
* @return the object pointer or NULL if it doesn't exist
*/
Object *game_get_object_by_id(Game *game, Id id);

/**
* @brief Gets a link from its name
* 
* game_get_link_by_name It gets the link pointer by its name
*
* @date 27-04-2021
* @author: Manuel Ardid
*
* @param game pointer to game
* @param name name of the link
* @return the link with that name or NULL if it doesn't exist
*/
Link *game_get_link_by_name(Game *game, char *name);

/**
* @brief game update the light of a space
*
* game_update_space_light Evaluates and updates the light on the room
*
* @date 30-04-2021
* @author: Manuel Ardid
*
* @param game pointer to game
* @param space pointer to space
* @return OK or ERORR
*/
STATUS game_update_space_light(Game *game, Space *space);

/**
   Game interface implementation
*/

Game *game_create() {
  int i;
  Game *new_game = NULL;

  new_game = (Game *)malloc(sizeof(Game));
  if (new_game == NULL)
    return ERROR;

  for (i = 0; i < MAX_SPACES; i++) {
    new_game->spaces[i] = NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++) {
    new_game->objects[i] = NULL;
  }

  for (i = 0; i < MAX_LINKS; i++) {
    new_game->links[i] = NULL;
  }

  new_game->die = die_create(DIE_ID1, MAX_DIE, MIN_DIE);
  new_game->dialogue = dialogue_create();
  new_game->player = NULL;
  new_game->last_cmd = NO_CMD;
  new_game->last_cmd_st = OK;

  new_game->option[0] = '\0';
  new_game->description[0] = '\0';

  return new_game;
}

STATUS game_destroy(Game *game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
    game->spaces[i] = NULL;
  }

  for (i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++) {
    object_destroy(game->objects[i]);
    game->objects[i] = NULL;
  }

  for (i = 0; (i < MAX_LINKS) && (game->links[i] != NULL); i++) {
    link_destroy(game->links[i]);
    game->links[i] = NULL;
  }

  player_destroy(game->player);
  game->player = NULL;

  game->option[0] = '\0';
  game->description[0] = '\0';

  if (game->last_cmd != LOAD) {
    die_destroy(game->die);
    game->die = NULL;
    dialogue_destroy(game->dialogue);
    game->dialogue = NULL;

    free(game);
  }

  return OK;
}

STATUS game_add_object(Game *game, Object *object) {
  int i = 0;

  if (!game || !object) {
    return ERROR;
  }

  while ((i < MAX_OBJECTS) && (game->objects[i] != NULL)) {
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->objects[i] = object;

  return OK;
}

STATUS game_add_space(Game *game, Space *space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ((i < MAX_SPACES) && (game->spaces[i] != NULL)) {
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

STATUS game_add_player(Game *game, Player *player) {
  if (!game || !player) {
    return ERROR;
  }

  game->player = player;

  return OK;
}

STATUS game_add_link(Game *game, Link *link) {
  int i = 0;

  if (link == NULL || game == NULL) {
    return ERROR;
  }

  while ((i < MAX_LINKS) && (game->links[i] != NULL)) {
    i++;
  }

  if (i >= MAX_LINKS) {
    return ERROR;
  }

  game->links[i] = link;

  return OK;
}

Space *game_get_space(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])) {
      return game->spaces[i];
    }
  }

  return NULL;
}

Object *game_get_object(Game *game, int pos) {
  if (!game || pos < 0 || pos >= MAX_OBJECTS)
    return NULL;

  return game->objects[pos];
}

Link *game_get_link(Game *game, Id id) {
  int i;

  if (!game || id == NO_ID)
    return NULL;

  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++) {
    if (id == link_get_id(game->links[i])) {
      return game->links[i];
    }
  }

  return NULL;
}

Player *game_get_player(Game *game) {
  if (!game)
    return NULL;

  return game->player;
}

Die *game_get_die(Game *game) {
  if (!game)
    return NULL;

  return game->die;
}

STATUS game_set_player_location(Game *game, Id id) {
  if (id == NO_ID) {
    return ERROR;
  }

  if (player_set_location(game->player, id) == ERROR) {
    return ERROR;
  }

  return OK;
}

STATUS game_set_object_location(Game *game, Id space_id, Id object_id) {
  int i = 0;

  if (space_id == NO_ID || object_id == NO_ID) {
    return ERROR;
  }

  for (i = 0; (space_get_id(game->spaces[i]) != space_id); i++)
    ;

  space_add_object(game->spaces[i], object_id);

  return OK;
}

Id game_get_player_location(Game *game) {
  return player_get_location(game->player);
}

Id game_get_object_location(Game *game, Id id) {
  int i = 0;
  BOOL st = FALSE;

  if (id == NO_ID)
    return NO_ID;

  for (i = 0; i < MAX_SPACES && st == FALSE; i++) {
    st = space_has_object(game->spaces[i], id);
  }

  if (st == FALSE)
    return NO_ID;

  return space_get_id(game->spaces[i - 1]);
}

int game_get_last_die_value(Game *game) {
  if (!game)
    return 0;

  return die_get_last_num(game->die);
}

STATUS game_set_description(Game *game, char *desc) {
  if (!game || !desc) {
    return ERROR;
  }
  strcpy(game->description, desc);

  return OK;
}

const char *game_get_description(Game *game) {
  if (!game)
    return NULL;

  return game->description;
}

STATUS game_set_option(Game *game, char *option) {
  if (!game || !option) {
    return ERROR;
  }
  strcpy(game->option, option);

  return OK;
}

const char *game_get_option(Game *game) {
  if (!game)
    return NULL;

  return game->option;
}

const char *game_get_dialogue_message(Game *game) {
  Space *space = NULL;

  if (!game)
    return NULL;

  space = game_get_space(game, game_get_player_location(game));

  return dialogue_get_message(game->dialogue, game->last_cmd, game->last_cmd_st, space, game->option);
}

STATUS game_set_last_command_st(Game *game, STATUS st) {
  if (!game)
    return ERROR;

  game->last_cmd_st = st;

  return OK;
}

STATUS game_get_last_command_st(Game *game) {
  if (!game)
    return ERROR;

  return game->last_cmd_st;
}

STATUS game_update(Game *game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  game_update_space_light(game, game_get_space(game, game_get_player_location(game)));

  return OK;
}

T_Command game_get_last_command(Game *game) {
  return game->last_cmd;
}

void game_print_data(Game *game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Links: \n");
  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++) {
    link_print(game->links[i]);
  }

  printf("=> Objects: \n");
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    object_print(game->objects[i]);
  }

  printf("=> Player: \n");
  player_print(game->player);

  printf("=> Die: \n");
  die_print(game->die);

  printf("prompt:> ");
}

BOOL game_is_over(Game *game) {
  Id id_end = 99;

  if (player_has_object(game->player, id_end)) {
    return TRUE;
  }

  return FALSE;
}

/**
   Callbacks implementation for each action 
*/

void game_callback_unknown(Game *game) {
  game->last_cmd_st = ERROR;
}

void game_callback_exit(Game *game) {
  game->last_cmd_st = OK;
}

void game_callback_move(Game *game) {
  Id current_space = NO_ID;
  Id space_id = NO_ID;
  Link *link = NULL;

  if (!game) {
    game->last_cmd_st = ERROR;
    return;
  }

  current_space = game_get_player_location(game);

  scanf("%s", game->option);

  if (strcmp(game->option, "norte") == 0 || strcmp(game->option, "n") == 0) {
    link = game_get_link(game, space_get_north_link(game_get_space(game, current_space)));
  }

  else if (strcmp(game->option, "sur") == 0 || strcmp(game->option, "s") == 0) {
    link = game_get_link(game, space_get_south_link(game_get_space(game, current_space)));
  }

  else if (strcmp(game->option, "oeste") == 0 || strcmp(game->option, "o") == 0) {
    link = game_get_link(game, space_get_west_link(game_get_space(game, current_space)));
  }

  else if (strcmp(game->option, "este") == 0 || strcmp(game->option, "e") == 0) {
    link = game_get_link(game, space_get_east_link(game_get_space(game, current_space)));
  }

  else if (strcmp(game->option, "arriba") == 0 || strcmp(game->option, "ar") == 0) {
    link = game_get_link(game, space_get_up_link(game_get_space(game, current_space)));
  }

  else if (strcmp(game->option, "abajo") == 0 || strcmp(game->option, "ab") == 0) {
    link = game_get_link(game, space_get_down_link(game_get_space(game, current_space)));
  }

  else {
    game->last_cmd_st = ERROR;
    return;
  }

  if (link_is_close(link) == TRUE || link == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  space_id = link_get_space1(link);
  if (space_id == current_space) {
    space_id = link_get_space2(link);
  }

  game_set_player_location(game, space_id);
  game->description[0] = '\0';
  game->last_cmd_st = OK;
  return;
}

void game_callback_take(Game *game) {
  Id current_space = NO_ID;
  Id selected_object = NO_ID;
  Id obj_depen = NO_ID;
  int num;
  BOOL aux = TRUE;
  Object *obj = NULL;

  if (game == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  scanf("%s", game->option);

  obj = game_get_object_by_name(game, game->option);
  if (obj == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  current_space = game_get_player_location(game);

  num = space_get_number_of_objects(game_get_space(game, current_space));
  if (num == 0) {
    game->last_cmd_st = ERROR;
    return;
  }

  if (!strcmp(game->option, object_get_name(obj))) {
    selected_object = object_get_id(obj);

    aux = space_has_object(game_get_space(game, current_space), selected_object);
    if (aux == FALSE) {
      game->last_cmd_st = ERROR;
      return;
    }
  }

  if (player_has_object(game->player, selected_object) == TRUE) {
    game->last_cmd_st = ERROR;
    return;
  }

  if (object_is_movable(obj) == FALSE) {
    game->last_cmd_st = ERROR;
    return;
  } else {
    obj_depen = object_get_dependency(obj);
    if (obj_depen != NO_ID && player_has_object(game->player, obj_depen) == FALSE) {
      game->last_cmd_st = ERROR;
      return;
    }
  }

  if (player_add_object(game->player, selected_object) == ERROR) {
    game->last_cmd_st = ERROR;
    return;
  }

  space_remove_object(game_get_space(game, current_space), selected_object);

  game->last_cmd_st = OK;
  return;
}

void game_callback_drop(Game *game) {
  Id current_space = NO_ID;
  Id selected_object = NO_ID;
  Id obj_depen = NO_ID;
  Object *current_obj = NULL;
  Object *obj = NULL;
  int i;

  if (game == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  scanf("%s", game->option);

  current_space = game_get_player_location(game);

  obj = game_get_object_by_name(game, game->option);
  if (obj == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  selected_object = object_get_id(obj);
  if (selected_object == NO_ID) {
    game->last_cmd_st = ERROR;
    return;
  }

  if (player_has_object(game->player, selected_object) == FALSE) {
    game->last_cmd_st = ERROR;
    return;
  }

  player_del_object(game->player, selected_object);
  space_add_object(game_get_space(game, current_space), selected_object);

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    current_obj = game->objects[i];
    obj_depen = object_get_id(current_obj);
    if (object_get_dependency(current_obj) == selected_object && player_has_object(game->player, obj_depen) == TRUE) {
      player_del_object(game->player, obj_depen);
      space_add_object(game_get_space(game, current_space), obj_depen);

      game->last_cmd_st = OK;
      return;
    }
  }
  game->last_cmd_st = OK;
  return;
}

void game_callback_roll(Game *game) {
  if (game == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }
  die_roll(game->die);
  game->last_cmd_st = OK;
  return;
}

void game_callback_inspect(Game *game) {
  Id space_id = NO_ID;
  Space *current_space = NULL;
  BOOL light1, light2, has_object;
  Object *selected_object = NULL;

  scanf("%s", game->option);

  if (game == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game->last_cmd_st = ERROR;
    return;
  }
  current_space = game_get_space(game, space_id);

  if (strcmp(game->option, "espacio") == 0 || strcmp(game->option, "e") == 0) {
    light1 = space_get_light_act(current_space);
    if (light1 == TRUE)
      strcpy(game->description, (char *)space_get_full_description(current_space));

    else
      strcpy(game->description, "No puedes ver nada");

    game->last_cmd_st = OK;
    return;
  }

  else {
    selected_object = game_get_object_by_name(game, game->option);
    if (!selected_object) {
      game->last_cmd_st = ERROR;
      return;
    }
    has_object = space_has_object(current_space, object_get_id(selected_object));
    if (has_object == FALSE && player_has_object(game->player, object_get_id(selected_object)) == FALSE) {
      game->last_cmd_st = ERROR;
      return;
    }
    if (object_get_id(selected_object) == 22) {
    }

    light2 = object_can_illuminate(selected_object);
    strcpy(game->description, (char *)object_get_description(selected_object));
    if (light2 == TRUE)
      strcat(game->description, " (Es iluminable)");

    game->last_cmd_st = OK;
    object_set_discovery(selected_object, TRUE);
    return;
  }
}

void game_callback_open(Game *game) {
  char link_name[WORD_SIZE + 1];
  char object_name[WORD_SIZE + 1];
  char conector[WORD_SIZE + 1];
  Object *selected_object = NULL;
  Link *selected_link = NULL;
  Space *player_location = NULL;
  Id selected_link_id = NO_ID;

  if (game == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  player_location = game_get_space(game, player_get_location(game->player));
  if (!player_location) {
    game->last_cmd_st = ERROR;
    return;
  }

  scanf("%s %s %s", link_name, conector, object_name);

  strcpy(game->option, link_name);

  if (strcmp(conector, "with") != 0 && strcmp(conector, "con") != 0) {
    game->last_cmd_st = ERROR;
    return;
  }

  selected_object = game_get_object_by_name(game, object_name);

  if (!selected_object) {
    game->last_cmd_st = ERROR;
    return;
  }

  if (player_has_object(game->player, object_get_id(selected_object)) == FALSE) {
    game->last_cmd_st = ERROR;

    if (!space_has_object(player_location, object_get_id(selected_object))) {
      game->last_cmd_st = ERROR;

      return;
    }
  }

  selected_link = game_get_link_by_name(game, link_name);

  if (!selected_link) {
    game->last_cmd_st = ERROR;
    return;
  }

  selected_link_id = link_get_id(selected_link);

  if (link_is_close(selected_link) == FALSE) {
    game->last_cmd_st = ERROR;
    return;
  }

  if (object_get_open(selected_object) != selected_link_id) {
    game->last_cmd_st = ERROR;
    return;
  }

  if (space_get_down_link(player_location) != selected_link_id &&
      space_get_up_link(player_location) != selected_link_id &&
      space_get_north_link(player_location) != selected_link_id &&
      space_get_south_link(player_location) != selected_link_id &&
      space_get_east_link(player_location) != selected_link_id &&
      space_get_west_link(player_location) != selected_link_id) {
    game->last_cmd_st = ERROR;
    return;
  }

  game->last_cmd_st = OK;

  link_set_close(selected_link, FALSE);

  return;
}

void game_callback_turnon(Game *game) {
  Id space_id = NO_ID;
  BOOL has_object = TRUE;
  Object *selected_object = NULL;
  Space *current_space = NULL;

  if (game == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  scanf("%s", game->option);

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game->last_cmd_st = ERROR;
    return;
  }

  current_space = game_get_space(game, space_id);

  selected_object = game_get_object_by_name(game, game->option);
  if (selected_object == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  has_object = space_has_object(current_space, object_get_id(selected_object));
  if (has_object == FALSE && player_has_object(game->player, object_get_id(selected_object)) == FALSE) {
    game->last_cmd_st = ERROR;
    return;
  }

  if (object_is_turnedon(selected_object) == TRUE) {
    game->last_cmd_st = ERROR;
    return;
  }

  object_set_turnedon(selected_object, TRUE);

  game->last_cmd_st = OK;
  return;
}

void game_callback_turnoff(Game *game) {
  Id space_id = NO_ID;
  BOOL has_object = TRUE;
  Object *selected_object = NULL;
  Space *current_space = NULL;

  if (game == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  scanf("%s", game->option);

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    game->last_cmd_st = ERROR;
    return;
  }

  current_space = game_get_space(game, space_id);

  selected_object = game_get_object_by_name(game, game->option);
  if (selected_object == NULL) {
    game->last_cmd_st = ERROR;
    return;
  }

  has_object = space_has_object(current_space, object_get_id(selected_object));
  if (has_object == FALSE && player_has_object(game->player, object_get_id(selected_object)) == FALSE) {
    game->last_cmd_st = ERROR;
    return;
  }

  if (object_is_turnedon(selected_object) == FALSE) {
    game->last_cmd_st = ERROR;
    return;
  }

  object_set_turnedon(selected_object, FALSE);

  game->last_cmd_st = OK;
  return;
}

void game_callback_save(Game *game) {
  char file_name[WORD_SIZE + 1];

  scanf("%s", file_name);

  if (game_management_save(game, file_name) == ERROR) {
    game->last_cmd_st = ERROR;
    return;
  }
  game->last_cmd_st = OK;
  return;
}

void game_callback_load(Game *game) {
  char file_name[WORD_SIZE + 1];

  scanf("%s", file_name);

  game_destroy(game);

  if (game_management_load(game, file_name) == ERROR) {
    game_destroy(game);
    game->last_cmd_st = ERROR;
    return;
  }

  game->last_cmd_st = OK;
  return;
}

/**
   Private functions
*/

Object *game_get_object_by_name(Game *game, char *name) {
  int i;

  if (!game || !name)
    return NULL;

  for (i = 0; game->objects[i] != NULL; i++) {
    if (strcmp(object_get_name(game->objects[i]), name) == 0)
      return game->objects[i];
  }

  return NULL;
}

Object *game_get_object_by_id(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if (id == object_get_id(game->objects[i])) {
      return game->objects[i];
    }
  }

  return NULL;
}

Link *game_get_link_by_name(Game *game, char *name) {
  int i;

  if (!game || !name)
    return NULL;

  for (i = 0; game->links[i] != NULL; i++) {
    if (strcmp(link_get_name(game->links[i]), name) == 0)
      return game->links[i];
  }

  return NULL;
}

STATUS game_update_space_light(Game *game, Space *space) {
  BOOL light_init = FALSE, light_act = FALSE, flag = FALSE, light = FALSE;
  Id *objects = NULL;
  Object *player_obj = NULL;
  int i, n;

  light_init = space_get_light_init(space);

  if (light_init == TRUE) {
    space_set_light_act(space, TRUE);
    return OK;
  }

  light = space_get_light_act(space);

  for (i = 0; i < player_get_num_of_objects(game->player) && flag == FALSE; i++) {
    player_obj = game_get_object_by_id(game, player_get_object_from_pos(game->player, i));

    if (object_is_turnedon(player_obj) == TRUE) {
      flag = TRUE;
      light_act = TRUE;
    }
  }

  if (flag == FALSE) {
    objects = space_get_objects(space);
    n = space_get_number_of_objects(space);

    for (i = 0; i < n && flag == FALSE; i++) {
      if (object_is_turnedon(game_get_object_by_id(game, objects[i])) == TRUE) {
        light_act = TRUE;
        flag = TRUE;
      }
    }
  }

  space_set_light_act(space, light_act);

  if (light_act != light)
    game->description[0] = '\0';

  free(objects);

  return OK;
}