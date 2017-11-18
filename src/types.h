/*====================*/
/* Jason Charrier     */
/* 4/5/2001           */
/* CSC 3102           */
/*====================*/
/* Module: types.h    */
/*========================================================*/
/* Purpose: this module contains common includes and defines*/
/*          for the current program                       */
/*========================================================*/

//#pragma once

#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

// NOTE: Some things here are here just in case they're needed

typedef enum { FALSE, TRUE } boolean;

#define UNIX 0
#define WIN 1
#define OS UNIX

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

/*----Player stuff----*/
#define PLAYER_STATE_DEAD 100
#define PLAYER_STATE_ALIVE 101
#define PLAYER_STATE_DYING 102
#define PLAYER_MAX_HEALTH 500
#define PLAYER_MAX_EXTRA_DAMAGE 100    // max damage player can do in one hit
// in addition to the player's strenght
#define PLAYER_STRENGTH 50

/*----Universe and direction stuff----*/
#define UNI_MIN_X 0
#define UNI_MIN_Y 0
#define UNI_MAX_X 50
#define UNI_MAX_Y 50

typedef enum { NORTH, SOUTH, EAST, WEST } directionType;
#define MAX_DIRECTIONS 4

/*----Room stuff----*/
#define ROOM_MAX_TITLE_LEN 31
#define ROOM_MAX_ENEMIES 5          // max # of enemies in room

/*----Actions----*/
typedef enum { ACT_MOVE = 200, ACT_USE, ACT_HIT, ACT_KICK, ACT_UNLOCK,
    ACT_LOCK, ACT_LOOK, ACT_EAT, ACT_DRINK, ACT_SAVE,
    ACT_LOAD, ACT_DROP, ACT_GET, ACT_THROW, ACT_INV,
    ACT_MAP, ACT_SCORE, ACT_HEALTH, ACT_QUIT } actType;

/*----Item stuff----*/
typedef enum { ITEM_KEY = 700, ITEM_FOOD, ITEM_GEM, ITEM_WEAPON,
    ITEM_TAPE, ITEM_DRINK, ITEM_INVALID } typeofItem;

/*----Enemy stuff----*/
#define ENEMY_STATE_DEAD  400
#define ENEMY_STATE_ALIVE 401
#define ENEMY_STATE_DYING 402
#define ENEMY_TYPE_STATIC 403    // enemy has a static universe position
#define ENEMY_TYPE_RANDOM 404    // enemy has a random universe position
#define ENEMY_MAX_DAMAGE  100    // max damage an enemy can do in one hit

/*----Switch stuff----*/
#define SW_OFF 500
#define SW_ON  501
#define SW_JOB_WARP 502
#define SW_JOB_UNLOCK 503

/*----Altar stuff----*/
#define ALTAR_STATE_OFF 600     // all gems aren't in altar
#define ALTAR_STATE_ON 601      // all gems are in altar

/*----Misc stuff----*/
#define MAX_DESCRIP_LEN 2001
#define MAX_NAME_LEN 31
#define MAX_STR_LEN 81

/*========END OF FILE types.h=========*/

#endif
