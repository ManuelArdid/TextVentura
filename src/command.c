/** 
 * @brief It implements the command interpreter
 * 
 * Contains the implementation of the functions associated to command
 *
 * @file command.c
 * @author Manuel Ardid
 * @version 2.0 
 * @date 13-01-2020 
 * @copyright GNU Public License
 */

#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * @brief List of the commands
 */
char *cmd_to_str[N_CMD][N_CMDT] = {{"", "Sin comando"}, {"", "Comando desconocido"}, {"sl", "salir"}, {"m", "mover"}, {"c", "coger"}, {"s", "soltar"}, {"rl", "Roll"}, {"i", "inspeccionar"}, {"e", "encender"}, {"a", "apagar"}, {"abr", "abrir"}, {"gr", "guardar"}, {"cr", "cargar"}};

/**
  Public funtions implementation
*/

T_Command command_get_user_input() {
  T_Command cmd = NO_CMD;
  char input[CMD_LENGHT] = "";
  int i = UNKNOWN - NO_CMD + 1;

  if (scanf("%s", input) > 0) {
    cmd = UNKNOWN;

    while (cmd == UNKNOWN && i < N_CMD) {
      if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL])) {
        cmd = i + NO_CMD;
      } else {
        i++;
      }
    }
  }

  return cmd;
}
