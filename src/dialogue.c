/**
 * @brief It implements the dialogue interface
 *
 * It contains the funtions implementation of dialogue
 *
 * @file dialogue.c
 * @author Manuel Ardid
 * @version 1.0
 * @date 26-04-2021
 * @copyright GNU Public License
 */

#include "dialogue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * @brief The Game structure
 * 
 * It stores information of the game interface
 */
struct _Dialogue {
  char message[WORD_SIZE + 1]; /*!< Dialogue message*/
  T_Command previous_cmd;      /*!< Previous command used in the game */
  STATUS previous_cmd_st;      /*!< Status of the previous command */
  char option[WORD_SIZE + 1];  /*!< The object to be taken or dropped or the move argument */
};

Dialogue *dialogue_create() {
  Dialogue *new_dialogue = NULL;

  new_dialogue = (Dialogue *)malloc(sizeof(Dialogue));
  if (new_dialogue == NULL) {
    return NULL;
  }

  new_dialogue->message[0] = '\0';
  new_dialogue->previous_cmd = UNKNOWN;
  new_dialogue->previous_cmd_st = ERROR;
  new_dialogue->option[0] = '\0';

  return new_dialogue;
}

STATUS dialogue_destroy(Dialogue *dialogue) {
  if (!dialogue) {
    return ERROR;
  }

  free(dialogue);
  dialogue = NULL;

  return OK;
}

const char *dialogue_get_message(Dialogue *dialogue, T_Command cmd, STATUS st, Space *space, const char *option) {
  if (!dialogue || !space || !option) {
    return NULL;
  }

  if (cmd == dialogue->previous_cmd && dialogue->previous_cmd_st == ERROR && !strcmp(dialogue->option, option)) {
    strcpy(dialogue->message, "Ha hecho esta accion antes sin exito.");
    dialogue->previous_cmd_st = ERROR;
  } else if (cmd == dialogue->previous_cmd && dialogue->previous_cmd_st == OK && cmd != MOVE && cmd != ROLL && !strcmp(dialogue->option, option)) {
    strcpy(dialogue->message, "Ha hecho esta accion antes con exito.");
    dialogue->previous_cmd_st = OK;
  } else {
    switch (cmd) {
      case UNKNOWN:
        strcpy(dialogue->message, "Esta no es una accion valida. Pruebe otra vez.");
        break;
      case MOVE:
        if (strcmp(option, "norte") == 0 || strcmp(option, "n") == 0) {
          if (st == OK) {
            sprintf(dialogue->message, "Se ha movido hacia el norte. Ahora esta en %s.", space_get_description(space));
          } else {
            strcpy(dialogue->message, "No se puede mover hacia el norte. Pruebe otra accion.");
          }
        } else if (strcmp(option, "sur") == 0 || strcmp(option, "s") == 0) {
          if (st == OK) {
            sprintf(dialogue->message, "Se ha movido hacia el sur. Ahora esta en %s.", space_get_description(space));
          } else {
            strcpy(dialogue->message, "No se puede mover hacia el sur. Pruebe otra accion.");
          }
        } else if (strcmp(option, "oeste") == 0 || strcmp(option, "o") == 0) {
          if (st == OK) {
            sprintf(dialogue->message, "Se ha movido hacia el oeste. Ahora esta en %s.", space_get_description(space));
          } else {
            strcpy(dialogue->message, "No se puede mover hacia el oeste. Pruebe otra accion.");
          }
        } else if (strcmp(option, "este") == 0 || strcmp(option, "e") == 0) {
          if (st == OK) {
            sprintf(dialogue->message, "Se ha movido hacia el este. Ahora esta en %s.", space_get_description(space));
          } else {
            strcpy(dialogue->message, "No se puede mover hacia el este. Pruebe otra accion.");
          }
        } else if (strcmp(option, "arriba") == 0 || strcmp(option, "ar") == 0) {
          if (st == OK) {
            sprintf(dialogue->message, "Se ha movido hacia arriba. Ahora esta en %s.", space_get_description(space));
          } else {
            strcpy(dialogue->message, "No se puede mover hacia arriba. Pruebe otra accion.");
          }
        } else if (strcmp(option, "abajo") == 0 || strcmp(option, "ab") == 0) {
          if (st == OK) {
            sprintf(dialogue->message, "Se ha movido hacia abajo. Ahora esta en %s.", space_get_description(space));
          } else {
            strcpy(dialogue->message, "No se puede mover hacia abajo. Pruebe otra accion.");
          }
        }
        break;
      case TAKE:
        if (st == OK) {
          sprintf(dialogue->message, "Ha cogido el objeto %s.", option);
        } else {
          strcpy(dialogue->message, "No ha podido coger el objeto.");
        }
        break;
      case DROP:
        if (st == OK) {
          sprintf(dialogue->message, "Ha dejado el objeto %s.", option);
        } else {
          strcpy(dialogue->message, "No ha podido dejar el objeto.");
        }
        break;
      case ROLL:
        if (st == OK) {
          strcpy(dialogue->message, "Se ha lanzado el dado.");
        } else {
          strcpy(dialogue->message, "No ha se ha podido lanzar el dado.");
        }
        break;
      case INSPECT:
        if (st == OK) {
          if (strcmp(option, "espacio") == 0 || strcmp(option, "e") == 0) {
            sprintf(dialogue->message, "Has inspeccionado la estancia.");
          } else {
            sprintf(dialogue->message, "Has inspeccionado %s.", option);
          }
        } else {
          strcpy(dialogue->message, "No ha se ha podido inspeccionar.");
        }
        break;
      case TURNON:
        if (st == OK) {
          strcpy(dialogue->message, "Ahora el objeto esta encendido.");
        } else {
          strcpy(dialogue->message, "No se ha podido iluminar.");
        }
        break;
      case TURNOFF:
        if (st == OK) {
          strcpy(dialogue->message, "Ahora el objeto esta apagado.");
        } else {
          strcpy(dialogue->message, "No se ha podido apagar.");
        }
        break;
      case OPEN:
        if (st == OK) {
          sprintf(dialogue->message, "Ha abierto %s.", option);
        } else {
          sprintf(dialogue->message, "No se ha podido abrir %s.", option);
        }
        break;
      case SAVE:
        if (st == OK) {
          strcpy(dialogue->message, "Sa ha guardado la partida correctamente.");
        } else {
          strcpy(dialogue->message, "No se ha podido guardar la partida.");
        }
        break;
      case LOAD:
        if (st == OK) {
          strcpy(dialogue->message, "Sa ha cargado la partida correctamente.");
        } else {
          strcpy(dialogue->message, "No se ha podido cargar la partida.");
        }
        break;
      default:
        break;
    }

    dialogue->previous_cmd_st = st;
  }

  dialogue->previous_cmd = cmd;
  strcpy(dialogue->option, option);

  return dialogue->message;
}
