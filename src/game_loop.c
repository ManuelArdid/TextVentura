/**
 * @brief It defines the game loop interface
 *
 * Contains the implementation of the functions associated to game_loop
 *
 * @file game_loop.c
 * @author Manuel Ardid
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_management.h"
#include "graphic_engine.h"

/** Defines the constant variables */
#define MAX_CHAR 64

/**
   Private functions
*/

/**
 * @brief Initialize a game loop
 * 
 * game_loop_init This function starts the game loop 
 *
 * @date 20/02/2021
 * @author: Manuel Ardid
 *
 * @param game game to destroy and create
 * @param gengine graphic engine to create
 * @param file_name file name to use
 *
 * @return 0 if it initialized correctly or 1 if an error has occurred
*/
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
 * @brief Runs the game loop
 * 
 * game_loop_run This function realize a running of game loop 
 * and it recives a file were it's going to write the command execution
 *
 * @date 20/02/2021
 * @author: Manuel Ardid
 * 
 * @param game the game it's going to use
 * @param gengine graphic engine to paint
 * @param log the log file that it's going to be used
 *
*/
void game_loop_run(Game *game, Graphic_engine *gengine, FILE *log);

/**
 * @brief Game loop cleanup
 * 
 * game_loop_cleanup This function realize a game loop cleanup by calling 
 * others functions
 *
 * @date 20/02/2021
 * @author: Manuel Ardid
 * 
 * @param game game to destroy
 * @param gengine graphic engine to destroy
 *
*/
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

/**
 * @brief Game loop print to log
 * 
 * game_loop_print_log This function write the information about 
 * the command being successfully performed or not in a file 
 *
 * @date 21/03/2021
 * @author: Manuel Ardid
 * 
 * @param game where save the information of game
 * @param log the file where its going to be written
 *
*/
void game_loop_print_log(Game *game, FILE *log);

/**
 * @brief Game loop end
 * 
 * game_loop_end This function ask the user whether to open the door
 *
 * @date 07/05/2021
 * @author: Manuel Ardid
 * 
 * @param game game to destroy
 * @param gengine graphic engine to destroy
 *
*/
STATUS game_loop_end(Game *game, Graphic_engine *gengine);

/**
   Main of the program
*/

/**
* @brief main
*
* main Principal funcion that calls the rest of the functions, 
* it also show error if the argument passed its invalid
*
* @date 14-02-2021
* @author: Manuel Ardid
*
* @param argc number of arguments 
* @param argv the names of the arguments
* @return 0 if the game was executed successfully or 1 if it fails
*/
int main(int argc, char *argv[]) {
  Game *game = NULL;
  Graphic_engine *gengine = NULL;
  char log_file_name[MAX_CHAR] = "";
  FILE *log = NULL;

  if (argc < 2 || argc == 3 || argc > 4) {
    fprintf(stderr, "Use: %s <game_data_file> or Use: %s <game_data_file> -l <game_log_file>\n", argv[0], argv[0]);
    return 1;
  }
  if (argc < 4 && argc != 2) {
    fprintf(stderr, "Use: %s <game_data_file> -l <game_log_file>\n", argv[0]);
    return 1;
  }

  if (argc == 4) {
    if (strcmp(argv[2], "-l")) {
      fprintf(stderr, "Use: %s <game_data_file> -l <game_log_file>\n", argv[0]);
      return 1;
    }
    strcpy(log_file_name, argv[3]);
    log = fopen(log_file_name, "w");
  }

  game = game_create();
  if (game == ERROR) {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if (!game_loop_init(game, &gengine, argv[1])) {
    game_loop_run(game, gengine, log);
    game_loop_cleanup(game, gengine);
  }

  if (argc == 4) {
    fclose(log);
  }
  return 0;
}

/**
   Private funtions implementation
*/

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name) {
  if (game_management_load(game, file_name) == ERROR) {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL) {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

void game_loop_run(Game *game, Graphic_engine *gengine, FILE *log) {
  T_Command command = NO_CMD;

  while ((command != EXIT) && !game_is_over(game)) {
    graphic_engine_paint_game(gengine, game);
    command = command_get_user_input();
    game_update(game, command);
    game_loop_print_log(game, log);
  }
}

void game_loop_cleanup(Game *game, Graphic_engine *gengine) {
  char respuesta = '0';

  graphic_engine_destroy(gengine);

  if (game_is_over(game) == TRUE) {
    printf("\nHas llegado al final, tienes en tus manos el cofre que yace en medio de la sala del tesoro del Duque.\nPuedes oir como palpita y como al cogerlo te quema la piel.\nTodo el mal del castillo proviene de aquí.");
    printf("\n¿Lo abres? S/N\n");
    scanf(" %c", &respuesta);

    while (respuesta != 'S' && respuesta != 'N' && respuesta != 's' && respuesta != 'n') {
      printf("Escribe S para aceptar y N para negarte\n");
      scanf(" %c", &respuesta);
    }

    if (respuesta == 'S' || respuesta == 's') {
      printf("Durante un segundo llegas a ver lo que hay en su interior, pero de poco te sirve.\nTodo ha pasado demasiado rapido.\nUn nuevo esqueleto sin manos adorna la recepción.\n");
      printf("\n--FIN--\n");
    }

    if (respuesta == 'N' || respuesta == 'n') {
      printf("Has decidido que no vale la pena, tiras el cofre al suelo y abandonas el lugar.\nDesde el exterior, prendes fuego a esa horrible mansion.\nVivirás un día más.\n");
      printf("\n--FIN--\n");
    }
  }

  game_destroy(game);
}

void game_loop_print_log(Game *game, FILE *log) {
  char last_cmd_st[MAX_CHAR];
  extern char *cmd_to_str[N_CMD][N_CMDT];
  T_Command last_cmd = UNKNOWN;

  last_cmd = game_get_last_command(game);

  if (game_get_last_command_st(game) == OK) {
    strcpy(last_cmd_st, "OK");
  } else {
    strcpy(last_cmd_st, "ERROR");
  }

  if (log != NULL) {
    /*if (last_cmd == UNKNOWN || last_cmd == EXIT || last_cmd == ROLL || last_cmd == OPEN) {
      fprintf(log, " %s\n", cmd_to_str[last_cmd - NO_CMD][CMDL]);
    } else {
      fprintf(log, " %s %s\n", cmd_to_str[last_cmd - NO_CMD][CMDL], game_get_option(game));
    }*/
    fprintf(log, " %s: %s\n", cmd_to_str[last_cmd - NO_CMD][CMDL], last_cmd_st);
  }

  return;
}

STATUS game_loop_end(Game *game, Graphic_engine *gengine) {
  char respuesta = '0';
  if (game)
    return ERROR;

  printf("\nHas llegado al final, tienes en tus manos el cofre que yace en medio de la sala del tesoro del Duque.\nPuedes oir como palpita y como cogerlo te quema la piel.\nTodo el mal del castillo proviene de aquí.");
  printf("\n¿Lo abres? S/N\n");
  scanf("%c", &respuesta);

  while (respuesta != 'S' && respuesta != 'N') {
    printf("Escribe S para aceptar y N para negarte\n");
    scanf("%c", &respuesta);
  }

  if (respuesta == 'S') {
    printf("Durante un segundo llegas a ver lo que hay en su interior, pero de poco te sirve.\nTodo ha pasado demasiado rapido.\nUn nuevo esqueleto sin manos adorna la recepción.");
    game_loop_cleanup(game, gengine);
    return OK;
  }

  if (respuesta == 'N') {
    printf("Has decidido que no vale la pena, tiras el cofre al suelo y abandonas el lugar.\nDesde el exterior prendes fuego a esa horrible mansion.\nVivirás un día más.");
    game_loop_cleanup(game, gengine);
    return OK;
  }

  return ERROR;
}