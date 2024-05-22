/** 
 * @brief It implements the space interface
 *
 * Contains the implementation of the functions associated to space
 * 
 * @file space.c
 * @author Manuel Ardid
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include "space.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"
#include "set.h"
#include "types.h"

/**
   Defines the structure
*/

/** 
 * @brief The Space structure
 * 
 * It stores the information about the space
 */
struct _Space {
  Id id;                                /*!< Sdentification in the space*/
  char name[WORD_SIZE + 1];             /*!< Space name*/
  Id north_link;                        /*!< Space link in the north*/
  Id south_link;                        /*!< Space link in the south*/
  Id east_link;                         /*!< Space link in the east*/
  Id west_link;                         /*!< Space link in the west*/
  Id up_link;                           /*!< Space link above*/
  Id down_link;                         /*!< Space link below*/
  Set *objects;                         /*!< Objects in the space*/
  char gdesc[INC1][INC2 + 1];           /*!< Space graphic description*/
  char description[WORD_SIZE + 1];      /*!< Space description */
  char full_description[WORD_SIZE + 1]; /*!< Space full description*/
  BOOL light_act;                       /*!< Current light*/
  BOOL light_init;                      /*!< Init light from data*/
};

/**
   Public funtions implementation
*/

Space *space_create(Id id) {
  int i, j;
  Space *new_space = NULL;

  if (id == NO_ID)
    return NULL;

  new_space = (Space *)malloc(sizeof(Space));
  if (new_space == NULL) {
    return NULL;
  }

  new_space->id = id;

  new_space->name[0] = '\0';

  new_space->up_link = NO_ID;
  new_space->down_link = NO_ID;
  new_space->north_link = NO_ID;
  new_space->south_link = NO_ID;
  new_space->east_link = NO_ID;
  new_space->west_link = NO_ID;

  new_space->objects = set_create();
  if (new_space->objects == NULL) {
    space_destroy(new_space);
    return NULL;
  }

  for (i = 0; i < INC1; i++) {
    for (j = 0; j < INC2; j++) {
      new_space->gdesc[i][j] = '\0';
    }
  }

  new_space->description[0] = '\0';
  new_space->full_description[0] = '\0';

  new_space->light_act = FALSE;
  new_space->light_init = FALSE;

  return new_space;
}

STATUS space_destroy(Space *space) {
  if (!space) {
    return ERROR;
  }

  set_destroy(space->objects);

  free(space);
  space = NULL;

  return OK;
}

BOOL space_has_object(Space *space, Id id) {
  if (!space || id == NO_ID) {
    return FALSE;
  }

  if (set_has_id(space->objects, id) == TRUE) {
    return TRUE;
  }

  return FALSE;
}

STATUS space_set_name(Space *space, char *name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_up_link(Space *space, Id link_id) {
  if (!space || link_id == NO_ID) {
    return ERROR;
  }
  space->up_link = link_id;

  return OK;
}

STATUS space_set_down_link(Space *space, Id link_id) {
  if (!space || link_id == NO_ID) {
    return ERROR;
  }
  space->down_link = link_id;

  return OK;
}

STATUS space_set_north_link(Space *space, Id link_id) {
  if (!space || link_id == NO_ID) {
    return ERROR;
  }
  space->north_link = link_id;

  return OK;
}

STATUS space_set_south_link(Space *space, Id link_id) {
  if (!space || link_id == NO_ID) {
    return ERROR;
  }
  space->south_link = link_id;

  return OK;
}

STATUS space_set_east_link(Space *space, Id link_id) {
  if (!space || link_id == NO_ID) {
    return ERROR;
  }
  space->east_link = link_id;

  return OK;
}

STATUS space_set_west_link(Space *space, Id link_id) {
  if (!space || link_id == NO_ID) {
    return ERROR;
  }
  space->west_link = link_id;

  return OK;
}

STATUS space_set_gdesc(Space *space, char *gdesc, int row) {
  if (!space || !gdesc || row >= INC1 || row < 0) {
    return ERROR;
  }

  strcpy(space->gdesc[row], gdesc);

  return OK;
}

STATUS space_add_object(Space *space, Id id) {
  STATUS st = ERROR;
  if (!space) {
    return ERROR;
  }

  st = set_add(space->objects, id);
  if (st == ERROR)
    return ERROR;

  return OK;
}

STATUS space_remove_object(Space *space, Id id) {
  STATUS st = ERROR;

  if (!space)
    return ERROR;

  st = set_del(space->objects, id);

  return st;
}

int space_get_number_of_objects(Space *space) {
  int num;

  if (!space)
    return -1;

  num = set_get_num_of_ids(space->objects);

  return num;
}

Id space_get_object_from_pos(Space *space, int pos) {
  if (!space)
    return -1;

  return set_get_id_from_pos(space->objects, pos);
}

const char *space_get_name(Space *space) {
  if (!space) {
    return NULL;
  }

  return space->name;
}

Id space_get_id(Space *space) {
  if (!space) {
    return NO_ID;
  }

  return space->id;
}

Id space_get_up_link(Space *space) {
  if (!space) {
    return NO_ID;
  }

  return space->up_link;
}

Id space_get_down_link(Space *space) {
  if (!space) {
    return NO_ID;
  }

  return space->down_link;
}

Id space_get_north_link(Space *space) {
  if (!space) {
    return NO_ID;
  }

  return space->north_link;
}

Id space_get_south_link(Space *space) {
  if (!space) {
    return NO_ID;
  }

  return space->south_link;
}

Id space_get_east_link(Space *space) {
  if (!space) {
    return NO_ID;
  }

  return space->east_link;
}

Id space_get_west_link(Space *space) {
  if (!space) {
    return NO_ID;
  }

  return space->west_link;
}

char *space_get_gdesc(Space *space, int row) {
  if (!space || row >= INC1 || row < 0) {
    return NULL;
  }

  return space->gdesc[row];
}

Id *space_get_objects(Space *space) {
  Id *ids = NULL;
  int num, i;

  if (!space) {
    return NULL;
  }

  num = space_get_number_of_objects(space);
  if (num == 0)
    return NULL;

  ids = (Id *)malloc(num * sizeof(Id));
  if (ids == NULL)
    return NULL;

  for (i = 0; i < num; i++) {
    ids[i] = set_get_id_from_pos(space->objects, i);
  }

  return ids;
}

BOOL space_are_linked(Id space1, Id space2, Link *link) {
  if (space1 == NO_ID || space2 == NO_ID || !link) {
    return FALSE;
  }

  if ((space1 == link_get_space1(link)) && (space2 == link_get_space2(link))) {
    return TRUE;
  } else if ((space2 == link_get_space1(link)) && (space1 == link_get_space2(link))) {
    return TRUE;
  }

  return FALSE;
}

STATUS space_set_description(Space *space, char *description) {
  if (!space || !description)
    return ERROR;

  if (!strcpy(space->description, description)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_full_description(Space *space, char *description) {
  if (!space || !description)
    return ERROR;

  if (!strcpy(space->full_description, description)) {
    return ERROR;
  }

  return OK;
}

const char *space_get_description(Space *space) {
  if (!space)
    return NULL;

  if (space_get_light_act(space) == FALSE)
    return "Un lugar oscuro";

  return space->description;
}

const char *space_get_init_description(Space *space) {
  if (!space)
    return NULL;

  return space->description;
}

const char *space_get_full_description(Space *space) {
  if (!space)
    return NULL;

  return space->full_description;
}

STATUS space_set_light_act(Space *space, BOOL light) {
  if (!space)
    return ERROR;

  space->light_act = light;

  return OK;
}

STATUS space_set_light_init(Space *space, BOOL light) {
  if (!space)
    return ERROR;

  space->light_init = light;

  return OK;
}

BOOL space_get_light_act(Space *space) {
  if (!space)
    return FALSE;

  return space->light_act;
}

BOOL space_get_light_init(Space *space) {
  if (!space)
    return FALSE;

  return space->light_init;
}

STATUS space_print(Space *space) {
  Id idaux = NO_ID;
  Id *aux = NULL;
  int num;
  int i;
  char *pal = NULL;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_up_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Up link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No up link.\n");
  }

  idaux = space_get_down_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Down link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No down link.\n");
  }

  idaux = space_get_north_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  if (space->light_init == TRUE)
    fprintf(stdout, "---> Light init: TRUE\n");
  else
    fprintf(stdout, "---> Light init: FALSE\n");

  if (space->light_act == TRUE)
    fprintf(stdout, "---> Light act: TRUE\n");
  else
    fprintf(stdout, "---> Light act: FALSE\n");

  num = space_get_number_of_objects(space);
  if (num > 0) {
    aux = space_get_objects(space);
    fprintf(stdout, "---> Objects in the space Ids: ");
    for (i = 0; i < num; i++) {
      fprintf(stdout, "%ld ", aux[i]);
    }
  } else {
    fprintf(stdout, "\n---> No objects in the space.\n");
  }

  fprintf(stdout, "---> Graphic description:\n");
  for (i = 0; i < INC1; i++) {
    pal = space_get_gdesc(space, i);
    fprintf(stdout, "%s\n", pal);
  }

  fprintf(stdout, "---> Description: %s\n", space->description);

  fprintf(stdout, "---> Full description: %s\n", space->full_description);

  return OK;
}
