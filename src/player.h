//#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "list.h"
#include "map.h"
/*----player struct----*/
typedef struct playerType
{
    int fx;
    int fy;
    int fHealth;
    listType list;
}playerType, *playerPtrType;

boolean Player_CREATE(playerPtrType player);
boolean Player_DESTROY(playerPtrType player);
boolean Player_ALIVE();
boolean Player_MOVE( char * strObject );
void Player_USE(char * strObject);
void Player_UNLOCK(char * keyname);
boolean Player_SWITCH();
void Player_LOOK();
void Player_INV();
void Player_EAT(char * strObject);
void Player_DRINK(char * strObject);
void Player_THROW(char * strObject);
void Player_DROP(char * strObject);
void Player_GET(char * strObject);
boolean Player_HIT();
boolean Player_KICK();
void Player_HEALTH();
boolean Player_QUIT();

boolean Command_Call(char *strVerb, char *strObject, map row[]);

#endif
