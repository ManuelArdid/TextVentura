/**
 * @brief It implements the link interface
 *
 * It contains the funtions implementation of the link
 *
 * @file link.c
 * @author Manuel Ardid
 * @version 1.0
 * @date 23-03-2021
 * @copyright GNU Public License
 */

#include "link.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Defines the structure
*/

/**
* @brief The link structure
*
* It saves the link of ids and the number of ids
*/
struct _Link {
  Id id;                    /*!< Link id */
  char name[WORD_SIZE + 1]; /*!< Link name*/
  Id space1;                /*!< Id of link space 1 */
  Id space2;                /*!< Id of link space 2 */
  BOOL close;               /*!< Link state (open or close) */
};

/**
   Public funtions implementation
*/

Link *link_create(Id id) {
  Link *new_link = NULL;

  if (id == NO_ID) {
    return NULL;
  }

  new_link = (Link *)malloc(sizeof(Link));
  if (new_link == NULL) {
    return NULL;
  }

  new_link->id = id;

  new_link->name[0] = '\0';

  new_link->space1 = NO_ID;
  new_link->space2 = NO_ID;

  new_link->close = FALSE;

  return new_link;
}

STATUS link_destroy(Link *link) {
  if (!link) {
    return ERROR;
  }

  free(link);
  link = NULL;

  return OK;
}

STATUS link_set_name(Link *link, char *name) {
  if (!link || !name) {
    return ERROR;
  }
  strcpy(link->name, name);

  return OK;
}

STATUS link_set_space1(Link *link, Id id) {
  if (!link || id == NO_ID) {
    return ERROR;
  }
  link->space1 = id;

  return OK;
}

STATUS link_set_space2(Link *link, Id id) {
  if (!link || id == NO_ID) {
    return ERROR;
  }
  link->space2 = id;

  return OK;
}

STATUS link_set_close(Link *link, BOOL close) {
  if (!link) {
    return ERROR;
  }
  link->close = close;

  return OK;
}

Id link_get_id(Link *link) {
  if (!link) {
    return NO_ID;
  }
  return link->id;
}

char *link_get_name(Link *link) {
  if (!link) {
    return NULL;
  }
  return link->name;
}

Id link_get_space1(Link *link) {
  if (!link) {
    return NO_ID;
  }
  return link->space1;
}

Id link_get_space2(Link *link) {
  if (!link) {
    return NO_ID;
  }
  return link->space2;
}

BOOL link_is_close(Link *link) {
  if (!link) {
    return FALSE;
  }
  return link->close;
}

STATUS link_print(Link *link) {
  if (!link) {
    return ERROR;
  }

  fprintf(stdout, "--> Link (Id: %ld; Name: %s, Space 1: %ld, Space 2: %ld)\n", link->id, link->name, link->space1, link->space2);

  if (link->close == TRUE) {
    fprintf(stdout, "--> Link is closed\n");
  } else {
    fprintf(stdout, "--> Link is open\n");
  }

  return OK;
}
