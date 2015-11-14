/*====================*/
/* Jason Charrier     */
/* 4/24/2001          */
/* CSC 3102           */
/*====================*/
/* Module: enemy.h    */
/*========================================================*/
/* Purpose: this module contains the struct declarations  */
/*          and fucntion prototypes for the enemy ADT     */
/*========================================================*/

//#pragma once

#ifndef _ENEMY_H_
#define _ENEMY_H_

/*----INCLUDES----*/
#include "types.h"

/*----the enemy structure----*/
typedef struct enemyType
{
    char fName[MAX_NAME_LEN];  // the name of the enemy
    int fState;                // the state of the enemy
    int fType;                 // the type of enemy (random or static)
    int fHealth;               // enemy's health
    int fStrengh;              // enemy's strength
    double fHitPer;               // enemy's hit % rate as a decimal #
    
}enemyType, *enemyPtrType;

/*----PROTOTYPES----*/
boolean enCreateEnemy(enemyPtrType enemy);
boolean enDestroyEnemy(enemyPtrType enemy);
boolean enSetName(enemyPtrType enemy, char * name);
boolean enGetName(enemyPtrType enemy, char * name);
boolean enSetStrength(enemyPtrType enemy, int strength);
boolean enSetHealth(enemyPtrType enemy, int health);
boolean enSetState(enemyPtrType enemy, int state);
int enGetState(enemyPtrType enemy);
boolean enSetHitPer(enemyPtrType enemy, double hitPer);
boolean enAttackPlayer(enemyPtrType enemy);
boolean enDoDamage(enemyPtrType enemy, int damage);

#endif

/*====END OF FILE enemy.h====*/

