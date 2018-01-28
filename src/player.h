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
boolean Player_ALIVE(void);
boolean Player_MOVE( char * strObject );
void Player_USE(char * strObject);
void Player_UNLOCK(char * keyname);
boolean Player_SWITCH(void);
void Player_LOOK(void);
void Player_INV(void);
void Player_EAT(char * strObject);
void Player_DRINK(char * strObject);
void Player_THROW(char * strObject);
void Player_DROP(char * strObject);
void Player_GET(char * strObject);
boolean Player_HIT(void);
boolean Player_KICK(void);
void Player_HEALTH(void);
boolean Player_QUIT(void);

boolean Command_Call(char *strVerb, char *strObject, map row[]);

#endif
