/*====================*/
/* Jason Charrier     */
/* 4/30/2001          */
/* CSC 3102           */
/*====================*/
/* Module: efl_end.c  */
/*========================================================*/
/* Purpose: this module contains the fucntion definition  */
/*          for game shutdown function                    */
/*========================================================*/

#include "types.h"
#include "globals.h"

/*=======================================*/
/* Operation: efl_end                    */
/*=====================================================*/
/* Purpose: this operation deinits all the game stuff  */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: game has finished running                    */
/*   POST:  all game stuff is deinited                 */
/* Processes: destroy all the rooms                    */
/*            destroy the player                       */
/*=====================================================*/

void efl_end(void)
{
    int i = 0, j = 0;
    for(i = 0; i < UNI_MAX_X; i++)
        for(j = 0; j < UNI_MAX_Y; j++)
            rmDestroyRoom(&rooms[i][j]);
    
    Player_DESTROY(&player);
}

/*====END OF FILE efl_end.c====*/
