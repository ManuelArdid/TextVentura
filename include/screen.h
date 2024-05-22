/**
 * @brief Funtions of screen interface
 *
 * @file screen.h
 * @author Manuel Ardid
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

/** Defines the constant variables */
#define SCREEN_MAX_STR 80

/** Defines the constant variables */
#define ROWS 34
/** Defines the constant variables */
#define COLUMNS 155
/** Defines the constant variables */
#define TOTAL_DATA (ROWS * COLUMNS) + 1

/** Defines the constant variables */
#define BG_CHAR '~'
/** Defines the constant variables */
#define FG_CHAR ' '
/** Defines the constant variables */
#define PROMPT " prompt:> "

/** Defines the constant variables */
#define ACCESS(d, x, y) (d + ((y)*COLUMNS) + (x))

/**
   Defines the type of data
*/

/** 
 * @brief Data structure to implement the Area. 
 *
 **/
typedef struct _Area Area;

/**
   Public functions
*/

/**
* @brief Initialize screen
*
* screen_init This function allocates memory for __data and fill the background
*
* @date 20/02/2021
* @author: Manuel Ardid
*/
void screen_init();

/**
* @brief destroy screen
*
* screen_destroy The function for free dynamic memory reserved for a __data
*
* @date 20/02/2021
* @author: Manuel Ardid
*/
void screen_destroy();

/**
* @brief paint the screen
*
* screen_paint The function paint the screen with color
*
* @date 20/02/2021
* @author: Manuel Ardid
*/
void screen_paint();

/**
* @brief Initialize a screen area
*
* screen_area_init This function allocates memory for Area and initiate the area
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param x element in the area structure
* @param y element in the area structure
* @param width width of area
* @param height height of area
*  
* @return the initialized area in the screen
*/
Area *screen_area_init(int x, int y, int width, int height);

/**
* @brief Destroy the screen area
*
* screen_area_destroy The function for free dynamic memory reserved for a area
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param area the screen area to be destroyed
*/
void screen_area_destroy(Area *area);

/**
* @brief Clear the screen area
*
* screen_area_clear Call the function screen_area_reset_cursor and fill the background
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param area the screen area to be cleared
*/
void screen_area_clear(Area *area);

/**
* @brief Reset cursor of screen area 
*
* screen_area_reset_cursor It resets the cursor on the area
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param area where can find the screen area
*/
void screen_area_reset_cursor(Area *area);

/**
* @brief Area will be put in screen
*
* screen_area_puts This function put area in the screen
*
* @date 20/02/2021
* @author: Manuel Ardid
*
* @param area where can find the screen area
* @param str String to save characters
*/
void screen_area_puts(Area *area, char *str);

#endif
