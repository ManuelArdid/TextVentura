/**
 * @brief It defines common types
 *
 * @file types.h
 * @author Manuel Ardid
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

/** Defines the constant variables */
#define WORD_SIZE 1000
/** Defines the constant variables */
#define NO_ID -1

/**
   Defines the type of data
*/

/**
   Define Id has a variable of type long
*/
typedef long Id;

/**
   Public enumerations
*/

/**
 * @brief Enumeration of BOOL
 */
typedef enum {
  FALSE, /*!< False value */
  TRUE   /*!< True value */
} BOOL;

/**
 * @brief Enumeration of STATUS
 */
typedef enum {
  ERROR, /*!< To codify an ERROR output */
  OK     /*!< To codify an OK output */
} STATUS;

/**
 * @brief Enumeration of DIRECTION
 */
typedef enum {
  N, /*!< Symbol of N(North) */
  S, /*!< Symbol of S(South) */
  E, /*!< Symbol of E(East) */
  W  /*!< Symbol of W(West) */
} DIRECTION;

#endif
