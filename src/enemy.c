/*====================*/
/* Jason Charrier     */
/* 4/24/2001          */
/* CSC 3102           */
/*====================*/
/* Module: enemy.c    */
/*========================================================*/
/* Purpose: this module contains the fucntion definitions */
/*          for the enemy ADT                            */
/*========================================================*/

#include "enemy.h"
#include "globals.h"
#include <unistd.h>

/*=================================*/
/* Operation: enCreateEnemy(enemy) */
/*=====================================================*/
/* Purpose: this operation creates an empty enemy      */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: enemy to be created                          */
/*   POST: an empty enemy is created or displays error message*/
/* Processes: if enemy isn't valid, display error message     */
/*                  else set enemy to empty enemy             */
/*============================================================*/

boolean enCreateEnemy(enemyPtrType enemy)
{
    /*----local vars----*/
    short i = 0;      // counter
    
    /*----check pointer----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enCreateEnemy!\n");
        return(FALSE);
    }
    
    /*----init all vars----*/
    enemy->fHealth = 1;
    enemy->fHitPer = 0.0;
    enemy->fState = ENEMY_STATE_ALIVE;
    enemy->fStrengh = 1;
    enemy->fType = ENEMY_TYPE_RANDOM;
    
    for(i = 0; i < MAX_NAME_LEN; i++)
        enemy->fName[i] = '\0';
    
    return(TRUE);
}


/*==================================*/
/* Operation: enDestroyEnemy(enemy) */
/*=====================================================*/
/* Purpose: this operation destroys an enemy           */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: enemy to be destroyed                        */
/*   POST: if enemy isn't valid, display error message */
/*               else remove everything from the enemy */
/*=====================================================*/

boolean enDestroyEnemy(enemyPtrType enemy)
{
    /*----local vars----*/
    short i = 0;      // counter
    
    /*----check pointer----*/
    if(!enemy)
    {
        //      fprintf(stderr, "Invalid enemy pointer passed to enDestroyEnemy!\n");
        return(FALSE);
    }
    
    /*----reinit all vars----*/
    enemy->fHealth = 1;
    enemy->fHitPer = 0.0;
    enemy->fState = ENEMY_STATE_ALIVE;
    enemy->fStrengh = 1;
    enemy->fType = ENEMY_TYPE_RANDOM;
    
    for(i = 0; i < MAX_NAME_LEN; i++)
        enemy->fName[i] = '\0';
    
    return(TRUE);
}

/*===================================*/
/* Operation: enSetName(enemy, name) */
/*=====================================================*/
/* Purpose: this operation sets the enemy's name to the*/
/*          given name                                 */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the enemy to set the name for and the name   */
/*   POST: enemy's name is set to the given name or    */
/*         displays error message                      */
/* Processes: if enemy or name isn't valid, display error message*/
/*                  else set enemy's name to the new name*/
/*=====================================================*/

boolean enSetName(enemyPtrType enemy, char * name)
{
    /*----check pointers----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enSetName!\n");
        return(FALSE);
    }
    
    if(!name)
    {
        //fprintf(stderr, "Invalid name passed to enSetName!\n");
        return(FALSE);
    }
    
    strncpy(enemy->fName, name, MAX_NAME_LEN);
    return(TRUE);
}

/*===================================*/
/* Operation: enGetName(enemy, name) */
/*=====================================================*/
/* Purpose: this operation gets the enemy's name       */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the enemy to get the name from and and a     */
/*        container for the name                       */
/*   POST: enemy's name in read into the name container or error */
/* Processes: if enemy or name isn't valid, display error message*/
/*            else set name container to the enemy's name        */
/*===============================================================*/

boolean enGetName(enemyPtrType enemy, char * name)
{
    /*----check pointers----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enGetName!\n");
        return(FALSE);
    }
    
    if(!name)
    {
        //fprintf(stderr, "Invalid name passed to enGetName!\n");
        return(FALSE);
    }
    
    strncpy(name, enemy->fName, MAX_NAME_LEN);
    return(FALSE);
}


/*===========================================*/
/* Operation: enSetStrength(enemy, strength) */
/*=====================================================*/
/* Purpose: this operation sets the enemy's strength to*/
/*          the given strengh                          */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the enemy to set the strength for and the strength         */
/*   POST: an empty enemy is created or displays error message       */
/* Processes: if enemy or strength isn't valid, display error message*/
/*                  else set enemy's strength to the new strength    */
/*===================================================================*/

boolean enSetStrength(enemyPtrType enemy, int strength)
{
    /*----check pointers----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enSetStrength!\n");
        return(FALSE);
    }
    
    enemy->fStrengh = strength;
    return(FALSE);
}

/*=======================================*/
/* Operation: enSetHealth(enemy, health) */
/*=====================================================*/
/* Purpose: this operation sets the enemy's health to  */
/*          the given health                           */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the enemy to set the health for and the health            */
/*   POST: an empty enemy is created or displays error message      */
/* Processes: if enemy or health isn't valid, display error message */
/*                  else set enemy's health to the new health       */
/*==================================================================*/

boolean enSetHealth(enemyPtrType enemy, int health)
{
    /*----check pointers----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enSetHealth!\n");
        return(FALSE);
    }
    
    enemy->fHealth = health;
    return(TRUE);
}

/*=====================================*/
/* Operation: enSetState(enemy, state) */
/*=====================================================*/
/* Purpose: this operation sets the enemy's state to   */
/*          the given state                            */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the enemy to set the state for and the state */
/*   POST: the enemy's state is set to the given state or error message*/
/* Processes: if enemy or state isn't valid, display error message     */
/*                  else set enemy's state to the new state            */
/*=====================================================================*/

boolean enSetState(enemyPtrType enemy, int state)
{
    /*----check pointers----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enSetState!\n");
        return(FALSE);
    }
    
    /*----make sure state is valid----*/
    if((state < ENEMY_STATE_DEAD) && (state > ENEMY_STATE_DYING))
    {
        //fprintf(stderr, "Invalid state passed to enSetState!\n");
        return(FALSE);
    }
    
    enemy->fState = state;
    return(TRUE);
}

/*=====================================*/
/* Operation: enGetState(enemy, state) */
/*=====================================================*/
/* Purpose: this operation gets the enemy's state      */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the enemy to get the state from and and a container for the state */
/*   POST: enemy's state in read into the state container or error          */
/* Processes: if enemy or state isn't valid, display error message          */
/*                  else set state container to the enemy's state           */
/*==========================================================================*/

int enGetState(enemyPtrType enemy)
{
    /*----check pointers----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enGetState!\n");
        return(-1);
    }
    
    return(enemy->fState);
}

/*=======================================*/
/* Operation: enSetHitPer(enemy, hitper) */
/*=====================================================*/
/* Purpose: this operation sets the enemy's hit % rate */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the enemy to set the hit % rate for and the hit % rate                 */
/*   POST: the enemy's hit % rate is set to the given hit % rate or error message*/
/* Processes: if enemy or state isn't valid, display error message               */
/*                  else set enemy's state to the new state                      */
/*===============================================================================*/

boolean enSetHitPer(enemyPtrType enemy, double hitPer)
{
    /*----check pointers----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enSetHitPer!\n");
        return(FALSE);
    }
    
    enemy->fHitPer = hitPer;
    return(TRUE);
}

/*==========================================*/
/* Operation: enAttackPlayer(enemy, player) */
/*=====================================================*/
/* Purpose: this operation attacks the player          */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the enemy that is attacking and the player that's being attacked     */
/*   POST:  player sustains 0 or more damage or error message                  */
/* Processes: if enemy or player isn't valid, display error message            */
/*            else generate random number based on hit % to determine if the   */
/*               attack will be successful                                     */
/*            If random # is in appropriate range, deal damage to player based */
/*               on the enemy's strength                                       */
/*=============================================================================*/

boolean enAttackPlayer(enemyPtrType enemy)
{
    /*----local vars----*/
    double success = 0.0;      // used to determine if attack hits or not
    
    int damage = 0,            // used to calculate damage
    random = 0;            // used to determine if attack hits or not
    
    /*----check pointers----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enDoDamage!\n");
        return(FALSE);
    }
    
    printf(MAGENTA "%s attacks, " RESET, enemy->fName);
    fflush(stdout);
    
    sleep(1);
    random = rand() % 100;
    success = (double)random * enemy->fHitPer;
    if(success <= 30.0)
    {
        printf(CYAN "but misses you!\n" RESET);
    }
    else
    {
        damage = enemy->fStrengh + (rand() % 5);
        player.fHealth -= damage;
        printf(RED "and does %d damage to you!\n" RESET, damage);
    }
    fflush(stdout);
    sleep(1);
    printf("You have " BOLDCYAN "%d" RESET " health remaining.\n\n", player.fHealth);
    return(TRUE);
}

/*========================================*/
/* Operation: enDoDamage(enemy, damage)   */
/*=====================================================*/
/* Purpose: this operation deals damage to the enemy   */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the enemy that being attacked and the damage to be dealt        */
/*   POST:  enemy health is reduced by amount of damage or error message  */
/* Processes: if enemy or damage isn't valid, display error message       */
/*            else reduce enemy health by amount of damage                */
/*            If enemy health is < 0, change state to dead                */
/*========================================================================*/

boolean enDoDamage(enemyPtrType enemy, int damage)
{
    /*----check pointers----*/
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy pointer passed to enDoDamage!\n");
        return(FALSE);
    }
    
    if(damage < 0)
    {
        fprintf(stderr, "enDoDamage: damage must be a positive number!\n");
        return(FALSE);
    }
    
    damage += rand() % PLAYER_MAX_EXTRA_DAMAGE;
    if(enemy->fState == ENEMY_STATE_ALIVE)
    {
        enemy->fHealth -= damage;
        printf(RED "The %s suffers %d damage!\n" RESET, enemy->fName, damage);
        sleep(1);
    }
    
    if(enemy->fHealth <= 0)
    {
        enemy->fState = ENEMY_STATE_DEAD;
        printf("You have defeated the %s!\n\n", enemy->fName);
        sleep(1);
    }
    
    return(TRUE);
}

/*====END OF FILE enemy.c====*/
