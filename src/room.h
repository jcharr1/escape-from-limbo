/*====================*/
/* Jason Charrier     */
/* 4/5/2001           */
/* CSC 3102           */
/*====================*/
/* Module: room.h     */
/*========================================================*/
/* Purpose: this module contains the struct declarations  */
/*          and fucntion prototypes for the room ADT      */
/*========================================================*/

//#pragma once

#ifndef _ROOM_H_
#define _ROOM_H_

/*----INCLUDES---*/
#include "types.h"
#include "list.h"
#include "item.h"
#include "enemy.h"
#include "switch.h"

/*----the room structure----*/
typedef struct roomType
{
    boolean fIsWall;        // is the room actually a wall?
    boolean fIsLocked;      // is the room locked?
    boolean fIsVisited;     // has the room been visited?
    boolean fHasSwitch;     // is there a switch in the room?
    
    char fTitle[ROOM_MAX_TITLE_LEN];       // title of the room
    char fDescrip[MAX_DESCRIP_LEN];        // description of the room
    
    listType fItems;        // list of items (unordered)
    switchType fSwitch;     // the switch if the room has one
    
    enemyType fEnemies[ROOM_MAX_ENEMIES];   // enemies in the room
    int fNumEnemies;        // # of enemies in the room
    
    boolean fValidExits[MAX_DIRECTIONS];// which ways the player can
    // exit
    
    
}roomType, *roomPtrType;

/*----PROTOTYPES----*/
boolean rmCreateRoom(roomPtrType room);
boolean rmDestroyRoom(roomPtrType room);
boolean rmSetTitle(roomPtrType room, char * title);
boolean rmGetTitle(roomPtrType room, char * title);
boolean rmSetDescrip(roomPtrType room, char * descrip);
boolean rmGetDescrip(roomPtrType room, char * descrip);
boolean rmAddItem(roomPtrType room, itemPtrType item);
boolean rmGetItem(roomPtrType room, itemPtrType item);
boolean rmSetSwitch(roomPtrType room, switchPtrType theSwitch);
boolean rmSetSwitchState(roomPtrType room, int state);
boolean rmSwitchDoJob(roomPtrType room);
boolean rmAddEnemy(roomPtrType room, enemyPtrType enemy);
boolean rmGetEnemy(roomPtrType room, enemyPtrType enemy);
boolean rmIsLocked(roomPtrType room);
boolean rmLock(roomPtrType room);
boolean rmUnlock(roomPtrType room);
boolean rmSetWall(roomPtrType room, boolean value);
boolean rmIsWall(roomPtrType room);
boolean rmSetValidExit(roomPtrType room, directionType direction);
boolean rmIsValidExit(roomPtrType room, directionType direction);
boolean rmHasSwitch(roomPtrType room);
void rmPrintItems(roomPtrType room);
void rmPrintObjects(roomPtrType room);
boolean rmIsVisited(roomPtrType room);
boolean rmVisit(roomPtrType room);
boolean rmProcessEnemies(roomPtrType room);
boolean rmAttackEnemyAtIndex(roomPtrType room, int index, boolean withWeapon);
boolean rmEnemyIsAlive(roomPtrType room, int index);
boolean rmItemIsInRoom(roomPtrType room, char * name);
boolean rmEnemiesAllDead(roomPtrType room);

/*=======END OF FILE room.h========*/

#endif
