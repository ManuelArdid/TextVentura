/** 
 * @brief It implements the screen of the game interface
 *
 * Contains the implementation of the functions associated to screen
 * 
 * @file screen.c
 * @author Manuel Ardid
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include "screen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wpedantic"

/**
   Defines the structures
*/

/**
* @brief The structure of Area
*
* Save the diffetent aspect of an area
*/
struct _Area {
  int x;        /*!< The x axe*/
  int y;        /*!< The y axes */
  int width;    /*!< The width of the area */
  int height;   /*!< The height of the area */
  char *cursor; /*!< Save the information of cursor */
};

char *__data; /*!< Defines the type of data */

/**
   Private functions
*/

/**
* @brief Return area cursor is out of bounds in the screen
*
* screen_area_cursor_is_out_of_bounds This function find if the screen cursor is 
* out of bounds based on area structure
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param area where it finds the cursor
*  
* @return the screen area cursor is out of bounds
*/
int screen_area_cursor_is_out_of_bounds(Area *area);

/**
* @brief scroll up the screen area
*
* screen_area_scroll_up scroll up the screen area
* based on area structure
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param area where it can find the elements of area
*/
void screen_area_scroll_up(Area *area);

/**
* @brief screen utils to replace special characters
*
* screen_utils_replaces_special_chars It uses screen utils to 
* replace special characters 
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param str string to save characters
*/
void screen_utils_replaces_special_chars(char *str);

/**
   Public funtions implementation
*/

void screen_init() {
  screen_destroy(); /* Dispose if previously initialized */
  __data = (char *)malloc(sizeof(char) * TOTAL_DATA);

  if (__data) {
    memset(__data, (int)BG_CHAR, TOTAL_DATA); /*Fill the background*/
    *(__data + TOTAL_DATA - 1) = '\0';        /*NULL-terminated string*/
  }
}

void screen_destroy() {
  if (__data)
    free(__data);
}

void screen_paint() {
  char *src = NULL;
  char dest[COLUMNS + 1];
  int i = 0;

  memset(dest, 0, COLUMNS + 1);

  if (__data) {
    /* puts(__data); */ /*Dump data directly to the terminal*/
                        /*It works fine if the terminal window has the right size*/

    puts("\033[2J"); /*Clear the terminal*/
    for (src = __data; src < (__data + TOTAL_DATA - 1); src += COLUMNS) {
      memcpy(dest, src, COLUMNS);
      /* printf("%s\n", dest); */

      for (i = 0; i < COLUMNS; i++) {
        if (dest[i] == BG_CHAR) {
          printf("\033[0;40;31m%c\033[0m", dest[i]); /* fg:black(40);bg:red(31) */
        } else {
          printf("\033[0;30;47m%c\033[0m", dest[i]); /* fg:black(30);bg:white(47)*/
        }
      }

      printf("\n");
    }
  }
}

Area *screen_area_init(int x, int y, int width, int height) {
  int i = 0;
  Area *area = NULL;

  if ((area = (Area *)malloc(sizeof(struct _Area)))) {
    *area = (struct _Area){x, y, width, height, ACCESS(__data, x, y)};

    for (i = 0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int)FG_CHAR, (size_t)area->width);
  }

  return area;
}

void screen_area_destroy(Area *area) {
  if (area)
    free(area);
}

void screen_area_clear(Area *area) {
  int i = 0;

  if (area) {
    screen_area_reset_cursor(area);

    for (i = 0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int)FG_CHAR, (size_t)area->width);
  }
}

void screen_area_reset_cursor(Area *area) {
  if (area)
    area->cursor = ACCESS(__data, area->x, area->y);
}

void screen_area_puts(Area *area, char *str) {
  int len = 0;
  char *ptr = NULL;

  if (screen_area_cursor_is_out_of_bounds(area))
    screen_area_scroll_up(area);

  screen_utils_replaces_special_chars(str);

  for (ptr = str; ptr < (str + strlen(str)); ptr += area->width) {
    memset(area->cursor, FG_CHAR, area->width);
    len = (strlen(ptr) < area->width) ? strlen(ptr) : area->width;
    memcpy(area->cursor, ptr, len);
    area->cursor += COLUMNS;
  }
}

/**
   Private funtions implementation
*/

int screen_area_cursor_is_out_of_bounds(Area *area) {
  return area->cursor > ACCESS(__data, area->x + area->width, area->y + area->height - 1);
}

void screen_area_scroll_up(Area *area) {
  for (area->cursor = ACCESS(__data, area->x, area->y); area->cursor < ACCESS(__data, area->x + area->width, area->y + area->height - 2);
       area->cursor += COLUMNS) {
    memcpy(area->cursor, area->cursor + COLUMNS, area->width);
  }
}

void screen_utils_replaces_special_chars(char *str) {
  char *pch = NULL;

  /* Replaces acutes and tilde with '??' */
  while ((pch = strpbrk(str, "ÁÉÍÓÚÑáéíóúñ")))
    memcpy(pch, "??", 2);
}
