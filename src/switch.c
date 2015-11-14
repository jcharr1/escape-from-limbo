/*====================*/
/* Jason Charrier     */
/* 4/23/2001          */
/* CSC 3102           */
/*====================*/
/* Module: switch.c   */
/*========================================================*/
/* Purpose: this module contains the fucntion definitions */
/*          for the switch ADT                            */
/*========================================================*/

#include "switch.h"
#include "globals.h"
#include "room.h"

/*----PROTOTYPES----*/
boolean swWarp(int x, int y);
boolean swUnlockRoom(int x, int y);

/*===================================*/
/* Operation: swCreateSwitch(switch) */
/*======================================================*/
/* Purpose: this operation creates an empty switch      */
/*======================================================*/
/* Conditions:                                          */
/*   PRE: switch to be created                          */
/*   POST: an empty switch is created or displays error message */
/* Processes: if switch isn't valid, display error message      */
/*            else set switch to empty switch                   */
/*==============================================================*/

boolean swCreateSwitch(switchPtrType theSwitch)
{
    /*----local vars----*/
    short i = 0;         // counter
    
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swCreateSwitch!\n");
        return(FALSE);
    }
    
    /*----init all vars----*/
    theSwitch->fJob = SW_JOB_UNLOCK;
    theSwitch->fState = SW_OFF;
    theSwitch->fUnlockX = -1;
    theSwitch->fUnlockY = -1;
    theSwitch->fWarpX = -1;
    theSwitch->fWarpY = -1;
    
    for(i = 0; i < MAX_NAME_LEN; i++)
        theSwitch->fName[i] = '\0';
    
    return(TRUE);
}



/*====================================*/
/* Operation: swDestroySwitch(switch) */
/*=====================================================*/
/* Purpose: this operation destroys a switch           */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: switch to be destroyed                       */
/*   POST: if switch isn't valid, display error message*/
/*               else remove everything from the switch*/
/*=====================================================*/

boolean swDestroySwitch(switchPtrType theSwitch)
{
    /*----local vars----*/
    short i = 0;         // counter
    
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swDestroySwitch!\n");
        return(FALSE);
    }
    
    /*----reinit all vars----*/
    theSwitch->fJob = SW_JOB_UNLOCK;
    theSwitch->fState = SW_OFF;
    theSwitch->fUnlockX = -1;
    theSwitch->fUnlockY = -1;
    theSwitch->fWarpX = -1;
    theSwitch->fWarpY = -1;
    
    for(i = 0; i < MAX_NAME_LEN; i++)
        theSwitch->fName[i] = '\0';
    
    return(TRUE);
}

/*====================================*/
/* Operation: swSetName(switch, name) */
/*=====================================================*/
/* Purpose: this operation sets the switch's name to the*/
/*          given name                                 */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the switch to set the name for and the name  */
/*   POST: switch's name is set or displays error message*/
/* Processes: if switch or name isn't valid, display error message*/
/*               else set switch's name to the new name*/
/*=====================================================*/

boolean swSetName(switchPtrType theSwitch, char * name)
{
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swSetName!\n");
        return(FALSE);
    }
    
    if(!name)
    {
        //fprintf(stderr, "Invalid name passed to swSetName!\n");
        return(FALSE);
    }
    
    strncpy(theSwitch->fName, name, MAX_NAME_LEN);
    return(TRUE);
}

/*====================================*/
/* Operation: swGetName(switch, name) */
/*=====================================================*/
/* Purpose: this operation gets the switch's name      */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the switch to get the namefrom and a container*/
/*          for the name                                */
/*   POST: switch's name in read into the name container*/
/*           or error                                   */
/* Processes: if switch or name isn't valid, display error*/
/*              message                                */
/*            else set name container to the switch's name*/
/*=====================================================*/

boolean swGetName(switchPtrType theSwitch, char * name)
{
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swGetName!\n");
        return(FALSE);
    }
    
    if(!name)
    {
        //fprintf(stderr, "Invalid name passed to swGetName!\n");
        return(FALSE);
    }
    
    strncpy(name, theSwitch->fName, MAX_NAME_LEN);
    return(TRUE);
}


/*==================================*/
/* Operation: swSetJob(switch, job) */
/*=====================================================*/
/* Purpose: this operation sets the switch's job to the*/
/*          given job                                  */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the switch to set the job for and the job    */
/*   POST: the switch's job is set to the given job or error message */
/* Processes: if switch or job isn't valid, display error message    */
/*                  else set switch's job to the new job             */
/*===================================================================*/

boolean swSetJob(switchPtrType theSwitch, int job)
{
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swSetJob!\n");
        return(FALSE);
    }
    
    if((job != SW_JOB_UNLOCK) && (job != SW_JOB_WARP))
    {
        //fprintf(stderr, "Invalid job passed to swSetJob!\n");
        return(FALSE);
    }
    
    theSwitch->fJob = job;
    return(TRUE);
}


/*==================================*/
/* Operation: swGetJob(switch, job) */
/*=====================================================*/
/* Purpose: this operation gets the switch's job       */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the switch to get the job from and and a container for the job */
/*   POST: switch's job in read into the job container or error          */
/* Processes: if switch or job isn't valid, display error message        */
/*                  else set job container to the switch's job           */
/*=======================================================================*/

int swGetJob(switchPtrType theSwitch)
{
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swGetJob!\n");
        return(-1);
    }
    
    return(theSwitch->fJob);
}

/*======================================*/
/* Operation: swSetState(switch, state) */
/*=====================================================*/
/* Purpose: this operation sets the switch's state to  */
/*          the given state                            */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the switch to set the state for and the state*/
/*   POST: the switch's state is set to the given state or error message */
/* Processes: if switch or state isn't valid, display error message      */
/*                  else set switch's state to the new state             */
/*=======================================================================*/

boolean swSetState(switchPtrType theSwitch, int state)
{
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swSetState!\n");
        return(FALSE);
    }
    
    if((state != SW_ON) && (state != SW_OFF))
    {
        //fprintf(stderr, "Invalid state passed to swSetState!\n");
        return(FALSE);
    }
    
    theSwitch->fState = state;
    return(TRUE);
}

/*======================================*/
/* Operation: swGetState(switch, state) */
/*=====================================================*/
/* Purpose: this operation gets the switch's state     */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the switch to get the state from and and a container for the state */
/*   POST: switch's state in read into the state container or error          */
/* Processes: if switch or state isn't valid, display error message          */
/*                  else set state container to the switch's state           */
/*===========================================================================*/

int swGetState(switchPtrType theSwitch)
{
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swGetState!\n");
        return(-1);
    }
    
    return(theSwitch->fState);
}

/*==============================*/
/* Operation: swDoJob(switch)   */
/*=====================================================*/
/* Purpose: this operation carries out the switch's job*/
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the switch to do the job                     */
/*   POST: switch's job is done                        */
/* Processes: if switch isn't valid, display error message  */
/*                  else determine what the switch's job is */
/*                  Perform appropriate action based on the job*/
/*                     (warp or unlock)                     */
/*                  Reset the switch state to off           */
/*==========================================================*/

boolean swDoJob(switchPtrType theSwitch)
{
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swDoJob!\n");
        return(FALSE);
    }
    
    if(theSwitch->fState == SW_ON)
    {
        if(theSwitch->fJob == SW_JOB_UNLOCK)
        {
            swUnlockRoom(theSwitch->fUnlockX, theSwitch->fUnlockY);
        }
        else
        {
            swWarp(theSwitch->fWarpX, theSwitch->fWarpY);
        }
        
        theSwitch->fState = SW_OFF;
    }
    
    return(TRUE);
}


/*========================================*/
/* Operation: swSetUnlockXY(switch, x, y) */
/*=====================================================*/
/* Purpose: this operation sets the switch's X and Y   */
/*          coordinates of the room it unlocks (both -1*/
/*          if it's job is not to unlock a room)       */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the switch to set the unlock x and y coords for and the x and y coords */
/*   POST: the switch's unlock x and y coords are set to the given x and y coords*/
/*              or error message                                                 */
/* Processes: if switch, x, or y isn't valid, display error message              */
/*                  else set switch's unlock x and y coords to the given x and y */
/*===============================================================================*/

boolean swSetUnlockXY(switchPtrType theSwitch, int x, int y)
{
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to swSetUnlockXY!\n");
        return(FALSE);
    }
    
    if((x < -1) || (y < -1) ||
       (x > UNI_MAX_X) || (y > UNI_MAX_Y))
    {
        //fprintf(stderr, "Invalid coordinates passed to swSetUnlockXY!\n");
        return(FALSE);
    }
    
    theSwitch->fUnlockX = x;
    theSwitch->fUnlockY = y;
    return(TRUE);
}

/*======================================*/
/* Operation: swSetWarpXY(switch, x, y) */
/*=====================================================*/
/* Purpose: this operation sets the switch's X and Y   */
/*          coordinates of the room it warps player to */
/*          (both -1 if it's job is not to warp to a room)*/
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the switch to set the warp x and y coords for and the x and y coords */
/*   POST: the switch's warp x and y coords are set to the given x and y coords*/
/*              or error message                                               */
/* Processes: if switch, x, or y isn't valid, display error message            */
/*                  else set switch's warp x and y coords to the given x and y */
/*=============================================================================*/

boolean swSetWarpXY(switchPtrType theSwitch, int x, int y)
{
    /*----check for valid switch pointer----*/
    if(!theSwitch)
    {
        ///fprintf(stderr, "Invalid switch pointer passed to swSetWarpkXY!\n");
        return(FALSE);
    }
    
    if((x < UNI_MIN_X) || (y < UNI_MIN_Y) ||
       (x > UNI_MAX_X) || (y > UNI_MAX_Y))
    {
        //fprintf(stderr, "Invalid coordinates passed to swSetWarpXY!\n");
        return(FALSE);
    }
    
    theSwitch->fWarpX = x;
    theSwitch->fWarpY = y;
    return(TRUE);
}

/*==========================*/
/* Operation: swWarp(x,y)   */
/*======================================================*/
/* Purpose: this operation warps the player to the specified*/
/*          x,y coords                                  */
/*======================================================*/
/* Conditions:                                          */
/*   PRE: the x and y coords to warp to                 */
/*   POST: player is warped to the x,y coords           */
/* Processes: change the player's x and y coords        */
/*======================================================*/

boolean swWarp(int x, int y)
{
    player.fx = x;
    player.fy = y;
    printf("\n<< SWOOSH!!! >> \n\n");
    return(TRUE);
}

/*==============================*/
/* Operation: swUnlockRoom(x,y) */
/*======================================================*/
/* Purpose: this operation unlocks the room at the specified*/
/*          x,y coords                                  */
/*======================================================*/
/* Conditions:                                          */
/*   PRE: the x and y coords of the room to unlock      */
/*   POST: room at the x,y coords is unlocked           */
/* Processes: unlock room at x and y coords             */
/*======================================================*/

boolean swUnlockRoom(int x, int y)
{
    char title[ROOM_MAX_TITLE_LEN] = {'\0'};
    rmGetTitle(&(rooms[x][y]), title);
    
    if(rmIsLocked(&(rooms[x][y])))
    {   
        rmUnlock(&rooms[x][y]);
        printf("%s has been unlocked!\n", title);
    }
    else
    {
        printf("%s has already been unlocked!\n", title);
    }
    return(TRUE);
}


/*====END OF FILE switch.c====*/
