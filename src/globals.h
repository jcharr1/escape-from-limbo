/*====================*/
/* Jason Charrier     */
/* 4/23/2001          */
/* CSC 3102           */
/*====================*/
/* Module: globals.h  */
/*========================================================*/
/* Purpose: this module contains the global variabls for  */
/*          player and the rooms                          */
/*========================================================*/

//#pragma once

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include "player.h"
#include "room.h"


/*----GLOBALS----*/
extern playerType player;
extern roomType rooms[UNI_MAX_X][UNI_MAX_Y];

#endif

/*====END OF FILE globals.h====*/
