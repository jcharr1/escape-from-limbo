/*====================*/
/* Jason Charrier     */
/* 4/23/2001          */
/* CSC 3102           */
/*====================*/
/* Module: switch.h    */
/*========================================================*/
/* Purpose: this module contains the struct declarations  */
/*          and fucntion prototypes for the switch ADT    */
/*========================================================*/

//#pragma once

#ifndef _SWITCH_H_
#define _SWITCH_H_

/*----INCLUDES---*/
#include "types.h"

/*----the room structure----*/
typedef struct switchType
{
    char fName[MAX_NAME_LEN]; // name of the switch
    int fState;    // state of the switch
    int fJob;      // the switch's job
    union
    {
        int fUnlockX;  // the x coord of room switch unlocks
        int fWarpX;    // the x coord switch warps to
    };
    union
    {
        int fUnlockY;  // the y coord of room switch unlocks
        int fWarpY;    // the y coord switch warps to
    };
}switchType, *switchPtrType;

/*----PROTOTYPES----*/
boolean swCreateSwitch(switchPtrType theSwitch);
boolean swDestroySwitch(switchPtrType theSwitch);
boolean swSetName(switchPtrType theSwitch, char * name);
boolean swGetName(switchPtrType theSwitch, char * name);
boolean swSetJob(switchPtrType theSwitch, int job);
int swGetJob(switchPtrType theSwitch);
boolean swSetState(switchPtrType theSwitch, int state);
int swGetState(switchPtrType theSwitch);
boolean swDoJob(switchPtrType theSwitch);
boolean swSetUnlockXY(switchPtrType theSwitch, int x, int y);
boolean swSetWarpXY(switchPtrType theSwitch, int x, int y);

/*====END OF FILE switch.h====*/

#endif
