/*====================*/
/* Jason Charrier     */
/* 4/5/2001           */
/* CSC 3102           */
/*====================*/
/* Module: room.c     */
/*========================================================*/
/* Purpose: this module contains the fucntion definitions */
/*          for the room ADT                              */
/*========================================================*/

#include "room.h"
//#include "globals.h"

/*===============================*/
/* Operation: rmCreateRoom(room) */
/*=====================================================*/
/* Purpose: this operation creates an empty room       */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to be created                           */
/*   POST: an empty room is created or displays error message*/
/* Processes: if room isn't valid, display error message*/
/*                  else set room to empty room        */
/*=====================================================*/

boolean rmCreateRoom(roomPtrType room)
{
    /*----local vars----*/
    short i = 0;
    
    /*----check for valid room pointer----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmCreateRoom!\n");
        return(FALSE);
    }
    
    /*----create list of items----*/
    if(!CreateList(&(room->fItems)))
    {
        fprintf(stderr, "Failed to create list of items!\n");
        return(FALSE);
    }
    
    /*----create switch----*/
    if(!swCreateSwitch(&(room->fSwitch)))
    {
        fprintf(stderr, "Failed to create switch!\n");
        return(FALSE);
    }
    
    room->fHasSwitch = FALSE;
    
    /*----create enemies----*/
    for(i = 0; i < ROOM_MAX_ENEMIES; i++)
    {
        enCreateEnemy(&(room->fEnemies[i]));
    }
    
    /*----init strings----*/
    for(i = 0; i < ROOM_MAX_TITLE_LEN; i++)
        room->fTitle[i] = '\0';
    
    for(i = 0; i < MAX_DESCRIP_LEN; i++)
        room->fDescrip[i] = '\0';
    
    /*----init flags----*/
    room->fIsWall = TRUE;
    room->fIsLocked = TRUE;
    room->fIsVisited = FALSE;
    
    room->fNumEnemies = 0;
    
    /*----init exits array----*/
    for(i = 0; i < MAX_DIRECTIONS; i++)
        room->fValidExits[i] = FALSE;
    
    return(TRUE);
    
}

/*================================*/
/* Operation: rmDestroyRoom(room) */
/*=====================================================*/
/* Purpose: this operation destroys a room             */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to be destroyed                         */
/*   POST: if room isn't valid, display error message  */
/*               else remove everything from the room  */
/*=====================================================*/

boolean rmDestroyRoom(roomPtrType room)
{
    /*----local vars----*/
    short i = 0;
    
    /*----check for valid room pointer----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmDestroyRoom!\n");
        return(FALSE);
    }
    
    /*----destroy list of items----*/
    if(!DestroyList(&(room->fItems)))
    {
        //      fprintf(stderr, "Failed to destroy list of items!\n");
        return(FALSE);
    }
    
    /*----destroy the switch----*/
    swDestroySwitch(&(room->fSwitch));
    room->fHasSwitch = FALSE;
    
    for(i = 0; i < room->fNumEnemies; i++)
        enDestroyEnemy(&(room->fEnemies[i]));
    
    /*----reinit strings----*/
    for(i = 0; i < ROOM_MAX_TITLE_LEN; i++)
        room->fTitle[i] = '\0';
    
    for(i = 0; i < MAX_DESCRIP_LEN; i++)
        room->fDescrip[i] = '\0';
    
    /*----init is wall and locked flags----*/
    room->fIsWall = TRUE;
    room->fIsLocked = TRUE;
    
    /*----init exits array----*/
    for(i = 0; i < MAX_DIRECTIONS; i++)
        room->fValidExits[i] = FALSE;
    
    return(TRUE);
}


/*========================================*/
/* Operation: rmSetTitle(room, title)     */
/*=====================================================*/
/* Purpose: this operation sets the room's title       */
/*          to the given title                         */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to set the title for and the title  */
/*   POST: room's title is set or error message        */
/* Processes: if room or title isn't valid, display error message*/
/*                  else set room's title to the new title */
/*=========================================================*/

boolean rmSetTitle(roomPtrType room, char * title)
{
    /*----check for valid room pointer----*/
    if(!room)
    {
        //fprintf(stderr, "/Invalid room pointer passed to rmSetTitle!\n");
        return(FALSE);
    }
    
    if(!title)
    {
        //fprintf(stderr, "Invalid title passed to rmSetTitle!\n");
        return(FALSE);
    }
    
    strncpy(room->fTitle, title, ROOM_MAX_TITLE_LEN);
    return(TRUE);
}


/*========================================*/
/* Operation: rmGetTitle(room, title)     */
/*=====================================================*/
/* Purpose: this operation gets the room's title       */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to get the title from and and a container for the*/
/*             title                                                */
/*   POST: room's title in read into the title container or error   */
/* Processes: if room or title isn't valid, display error message   */
/*                  else set description title to the room's title  */
/*==================================================================*/

boolean rmGetTitle(roomPtrType room, char * title)
{
    /*----check for valid room pointer----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmGetTitle!\n");
        return(FALSE);
    }
    
    if(!title)
    {
        //fprintf(stderr, "Invalid title passed to rmGetTitle!\n");
        return(FALSE);
    }
    
    strncpy(title, room->fTitle, ROOM_MAX_TITLE_LEN);
    return(TRUE);
}


/*========================================*/
/* Operation: rmSetDescrip(room, descrip) */
/*=====================================================*/
/* Purpose: this operation sets the room's description */
/*          to the given description                   */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to set the description for and the description      */
/*   POST: an empty room is created or displays error message          */
/* Processes: if room or descrip isn't valid, display error message    */
/*                  else set room's description to the new description */
/*=====================================================================*/

boolean rmSetDescrip(roomPtrType room, char * descrip)
{
    /*----check for valid room pointer----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmSetDescrip!\n");
        return(FALSE);
    }
    
    if(!descrip)
    {
        //fprintf(stderr, "Invalid description passed to rmSetDescrip!\n");
        return(FALSE);
    }
    
    strncpy(room->fDescrip, descrip, MAX_DESCRIP_LEN);
    return(TRUE);
}


/*========================================*/
/* Operation: rmGetDescrip(room, descrip) */
/*=====================================================*/
/* Purpose: this operation gets the room's description */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to get the description from and and a container for the     */
/*             description                                                     */
/*   POST: room's description in read into the description container or error  */
/* Processes: if room or descrip isn't valid, display error message            */
/*                  else set description container to the room's description   */
/*=============================================================================*/

boolean rmGetDescrip(roomPtrType room, char * descrip)
{
    /*----check for valid room pointer----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmGetDescrip!\n");
        return(FALSE);
    }
    
    if(!descrip)
    {
        fprintf(stderr, "Invalid description passed to rmGetDescrip!\n");
        return(FALSE);
    }
    
    strncpy(descrip, room->fDescrip, MAX_DESCRIP_LEN);
    return(TRUE);
}


/*==================================*/
/* Operation: rmAddItem(room, item) */
/*=====================================================*/
/* Purpose: this operation adds an item to the room's  */
/*          list of items                              */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to add the item to and the item to add                      */
/*   POST: item is added to the room or displays error message                 */
/* Processes: if room or item isn't valid, display error message               */
/*                  if the room's list of items is full, display error message */
/*                  else add the item to the room                              */
/*=============================================================================*/

boolean rmAddItem(roomPtrType room, itemPtrType item)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmAddItem!\n");
        return(FALSE);
    }
    
    if(!item)
    {
        //fprintf(stderr, "Invalid item passed to rmAddItem!\n");
        return(FALSE);
    }
    
    if(!AddListItem(room->fItems, item))
    {
        fprintf(stderr, "There was an error adding the item to the list!\n");
        return(FALSE);
    }
    
    return(TRUE);
}


/*==================================*/
/* Operation: rmGetItem(room, item)*/
/*=====================================================*/
/* Purpose: this operation gets and removes an item from*/
/*          the room's list of items                   */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to get and remove the item from and container for the item*/
/*            which contains the name of the item to get and remove          */
/*   POST: item is removed from the room and put into the container or       */
/*               displays error message                                      */
/* Processes: if room or container isn't valid, display error message        */
/*                  if the room's list of items is empty display error message*/
/*                  Search the list of items for the name of the item to remove*/
/*                  If the item isn't found display error message              */
/*                  Else put item into container and remove the item from the room*/
/*================================================================================*/

boolean rmGetItem(roomPtrType room, itemPtrType item)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmGetItem!\n");
        return(FALSE);
    }
    
    if(!item)
    {
        //fprintf(stderr, "Invalid item passed to rmGetItem!\n");
        return(FALSE);
    }
    
    if(!GetListItemByKey(room->fItems, item))
    {
        return(FALSE);
    }
    
    if(!DeleteListItemByKey(room->fItems, item))
    {
        fprintf(stderr, "There was an error removing the item from the list!\n");
        return(FALSE);
    }
    
    return(TRUE);
}


/*========================================*/
/* Operation: rmSetSwitch(room, switch)   */
/*=====================================================*/
/* Purpose: this operation sets the room's switch to the*/
/*          given switch                               */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to add the switch to and the switch to add           */
/*   POST: object is added to the room or displays error message        */
/* Processes: if room or switch isn't valid, display error message      */
/*            else set the room's switch to the given switch            */
/*======================================================================*/

boolean rmSetSwitch(roomPtrType room, switchPtrType theSwitch)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmSetSwitch!\n");
        return(FALSE);
    }
    
    if(!theSwitch)
    {
        //fprintf(stderr, "Invalid switch pointer passed to rmSetSwitch!\n");
        return(FALSE);
    }
    
    room->fSwitch = *theSwitch;
    room->fHasSwitch = TRUE;
    return(TRUE);
}

/*==========================================*/
/* Operation: rmSetSwitchState(room, state) */
/*=====================================================*/
/* Purpose: this operation sets the room's switch to the*/
/*          given state                                */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to set the switch state for and the state to change it to */
/*   POST: room's switch state is set to given state or error message        */
/* Processes: if room or state isn't valid, display error message            */
/*            if the room doesn't have a switch, display error message       */
/*            else set the room's switches state to the given state          */
/*===========================================================================*/

boolean rmSetSwitchState(roomPtrType room, int state)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmSetSwitchState!\n");
        return(FALSE);
    }
    
    if(room->fHasSwitch)
        return(swSetState(&(room->fSwitch), state));
    else
    {
        fprintf(stderr, "There is no switch in this room!\n");
        return(FALSE);
    }
}

/*================================*/
/* Operation: rmSwitchDoJob(room) */
/*=====================================================*/
/* Purpose: this operation carries out the room's switch's*/
/*          job                                        */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room that has the switch to activate     */
/*   POST: room's switch is activated                  */
/* Processes: if room isn't valid, display error message*/
/*            if room the doesn't have a switch, display error message */
/*            else activate the room's switch          */
/*=====================================================*/

boolean rmSwitchDoJob(roomPtrType room)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmSwitchDoJob!\n");
        return(FALSE);
    }
    
    if(room->fHasSwitch)
        return(swDoJob(&(room->fSwitch)));
    else
    {
        fprintf(stderr, "There is no switch in this room!\n");
        return(FALSE);
    }
}

/*========================================*/
/* Operation: rmAddEnemy(room, enemy)    */
/*=====================================================*/
/* Purpose: this operation adds an enemy to the room's */
/*          list of enemies                            */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to add the enemy to and the enemy to add                */
/*   POST: enemy is added to the room or displays error message            */
/* Processes: if room or enemy isn't valid, display error message          */
/*            if the room's list of enemies is full, display error message */
/*            else add the enemy to the room                               */
/*=========================================================================*/

boolean rmAddEnemy(roomPtrType room, enemyPtrType enemy)
{
    /*---check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmAddEnemy!\n");
        return(FALSE);
    }
    
    if(!enemy)
    {
        //fprintf(stderr, "Invalid enemy passed to rmAddEnemy!\n");
        return(FALSE);
    }
    
    /*----make sure list isn't full----*/
    if(room->fNumEnemies >= ROOM_MAX_ENEMIES)
    {
        fprintf(stderr, "The room cannot hold any more enemies!\n");
        return(FALSE);
    }
    
    /*----insert the enemy----*/
    room->fEnemies[(room->fNumEnemies)] = *enemy;
    ++room->fNumEnemies;
    return(TRUE);
}

/*==============================*/
/* Operation: rmIsLocked(room)  */
/*=====================================================*/
/* Purpose: this operation checks if a room is locked  */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to check if locked                      */
/*   POST: status of room is returned or displays error message */
/* Processes: if room isn't valid, display error message        */
/*            else return the room's locked flag                */
/*==============================================================*/

boolean rmIsLocked(roomPtrType room)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmIsLocked!\n");
        return(FALSE);
    }
    
    return(room->fIsLocked);
}

/*=========================*/
/* Operation: rmLock(room) */
/*=====================================================*/
/* Purpose: this operation sets the rooms locked flag to true*/
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to lock                                 */
/*   POST: room is locked or displays error message     */
/* Processes: if room isn't valid, display error message */
/*            else set the room's locked flag to true    */
/*=======================================================*/

boolean rmLock(roomPtrType room)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmLock!\n");
        return(FALSE);
    }
    
    room->fIsLocked = TRUE;
    return(TRUE);
}


/*============================*/
/* Operation: rmUnlock(room)  */
/*=====================================================*/
/* Purpose: this operation sets the rooms locked flag to false */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to unlock                               */
/*   POST: room is unlocked or displays error message    */
/* Processes: if room isn't valid, display error message */
/*            else set the room's locked flag to false   */
/*=======================================================*/

boolean rmUnlock(roomPtrType room)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmLock!\n");
        return(FALSE);
    }
    
    room->fIsLocked = FALSE;
    return(TRUE);
}


/*===================================*/
/* Operation: rmSetWall(room, value) */
/*=====================================================*/
/* Purpose: this operation sets the room's flag that states*/
/*          whether or not it's actually a wall to the */
/*          given value                                */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to set the is wall flag and the value of that flag */
/*   POST: room's is wall flag is set or displays error message   */
/* Processes: if room isn't valid, display error message          */
/*            else set the room's is wall flag to the given value */
/*================================================================*/

boolean rmSetWall(roomPtrType room, boolean value)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmSetWall!\n");
        return(FALSE);
    }
    
    room->fIsWall = value;
    return(TRUE);
}


/*===========================*/
/* Operation: rmIsWall(room) */
/*=====================================================*/
/* Purpose: this operation checks if a room is a wall  */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to check if is a wall                   */
/*   POST: status of room is returned or displays error message */
/* Processes: if room isn't valid, display error message        */
/*                  else return the room's is wall flag         */
/*==============================================================*/

boolean rmIsWall(roomPtrType room)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmIsWall!\n");
        return(FALSE);
    }
    
    return(room->fIsWall);
}


/*=============================================*/
/* Operation: rmSetValidExit(room, direction)  */
/*=====================================================*/
/* Purpose: this operation sets the room's valid exit  */
/*           directions list at the given index to true*/
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to set the exits list, and the list of valid exit directions       */
/*   POST: room's is wall flag is set or displays error message                   */
/* Processes: if room or directions list isn't valid, display error message       */
/*            else fill the room's valid exit directions list with the contents of*/
/*               the given list                                                   */
/*================================================================================*/

boolean rmSetValidExit(roomPtrType room, directionType direction)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmSetValidExit!\n");
        return(FALSE);
    }
    
    /*----make sure direction is valid----*/
    if((direction < NORTH) || (direction > WEST))
    {
        //fprintf(stderr, "Invalid direction passed to rmSetValidExit!\n");
        return(FALSE);
    }
    
    /*----set the value in the valid exits list to true---*/
    room->fValidExits[direction] = TRUE;
    return(TRUE);
    
}


/*===========================================*/
/* Operation: rmIsValidExit(room, direction) */
/*=====================================================*/
/* Purpose: this operation checks if the given direction*/
/*          is a valid exit from the room              */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to check the direction for and the direction to check             */
/*   POST: room's is wall flag is set or displays error message                  */
/* Processes: if room or direction isn't valid, display error message            */
/*            else return the value of the valid exit list that contains the flag*/
/*               for that direction                                              */
/*===============================================================================*/

boolean rmIsValidExit(roomPtrType room, directionType direction)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmSetValidExit!\n");
        return(FALSE);
    }
    
    /*----make sure direction is valid----*/
    if((direction < NORTH) || (direction > WEST))
    {
        //fprintf(stderr, "Invalid direction passed to rmIsValidExit!\n");
        return(FALSE);
    }
    
    return(room->fValidExits[direction]);
}

/*================================*/
/* Operation: rmHasSwitch(room)   */
/*=====================================================*/
/* Purpose: this operation checks if the room has a swich*/
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to check if it has a switch             */
/*   POST: room's has switch flag is returned or error */
/* Processes: if room isn't valid, display error message*/
/*            else return the has switch flag          */
/*=====================================================*/

boolean rmHasSwitch(roomPtrType room)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmHasSwitch!\n");
        return(FALSE);
    }
    
    return(room->fHasSwitch);
}


/*===============================*/
/* Operation: rmPrintItems(room) */
/*=====================================================*/
/* Purpose: this operation displays the descriptions of*/
/*          all the items in the room                  */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room print the list of items for             */
/*   POST: room's list of items is displayed or error message                 */
/* Processes: if room isn't valid, display error message                      */
/*            If list of items is empty display error message                 */
/*            else display the descriptions of the items in the list of items */
/*============================================================================*/

void rmPrintItems(roomPtrType room)
{
    /*----local vars----*/
    char Name[MAX_NAME_LEN] = {'\0'};   // holds item name
    short i = 0,                        // counter
    NumItems = 0;                 // # of items in list
    itemType item;                      // holds the item to print
    
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmPrintItems!\n");
        return;
    }
    
    /*----see if list is empty----*/
    if(EmptyList(room->fItems))
    {
        printf("There are no items in the room.\n");
    }
    
    /*----get number of items and print them out----*/
    else
    {
        NumItems = NumListItems(room->fItems);
        if(NumItems == 1)
        {
            printf("In the room is one item: \n\n");
        }
        else
        {
            printf("In the room are %hd items: \n\n", NumItems);
        }
        
        for(i = 0; i < NumItems; i++)
        {
            GetListItemByIndex(room->fItems, i, &item);
            itemGetName(&item, Name);
            if((NumItems == 2) && (i == 0))
                printf(YELLOW "%s " RESET, Name);
            else if(i < NumItems - 1)
                printf(YELLOW "%s, " RESET, Name);
            else if(NumItems == 1)
                printf(YELLOW "%s.\n" RESET, Name);
            else
                printf("and " YELLOW "%s.\n" RESET, Name);
            
        }
    }
}

/*=================================*/
/* Operation: rmPrintObjects(room) */
/*=====================================================*/
/* Purpose: this operation displays the descriptions of*/
/*          all the objects in the room                */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room print the list of objects for           */
/*   POST: room's list of objects is displayed or error message */
/* Processes: if room isn't valid, display error message        */
/*            If list of objects is empty display error message */
/*            else display the descriptions of the objects in the list of objects  */
/*==============================================================*/

void rmPrintObjects(roomPtrType room);

/*==============================*/
/* Operation: rmIsVisited(room) */
/*=====================================================*/
/* Purpose: this operation checks if the player has    */
/*          visited the room                           */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to check if visited                     */
/*   POST: status of room is returned or displays error message */
/* Processes: if room isn't valid, display error message        */
/*            else return the room's visited flag               */
/*==============================================================*/

boolean rmIsVisited(roomPtrType room)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmIsVisited!\n");
        return(FALSE);
    }
    
    return(room->fIsVisited);
}


/*==========================*/
/* Operation: rmVisit(room) */
/*=====================================================*/
/* Purpose: this operation sets the room's visited flag to true*/
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to visit                                */
/*   POST: room is visited or displays error message   */
/* Processes: if room isn't valid, display error message*/
/*            else set the room's visited flag to true */
/*=====================================================*/

boolean rmVisit(roomPtrType room)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmVisit!\n");
        return(FALSE);
    }
    
    room->fIsVisited = TRUE;
    return(TRUE);
}

/*===================================*/
/* Operation: rmProcessEnemies(room) */
/*=====================================================*/
/* Purpose: this operation lets the enemies in the room*/
/*          attack                                     */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to process enemies for                  */
/*   POST: enemies are processed or displays error message*/
/* Processes: if room isn't valid, display error message*/
/*            else                                     */
/*               FOR all enemies in the room that are alive*/
/*                  attack the player                  */
/*=====================================================*/

boolean rmProcessEnemies(roomPtrType room)
{
    /*----local vars----*/
    short i = 0;      // counter
    
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmProcessEnemies!\n");
        return(FALSE);
    }
    
    if(!rmEnemiesAllDead(room))
    {
        printf(BOLDRED "!!!!!!!!!!ENEMIES ENCOUNTERED!!!!!!!!!!\n" RESET);
    }
    
    for(i = 0; i < room->fNumEnemies; i++)
    {
        if(enGetState(&(room->fEnemies[i])) == ENEMY_STATE_ALIVE)
        {
            printf("Enemy number %d:", i);
            enAttackPlayer(&(room->fEnemies[i]));
        }
    }
    return(TRUE);
}

/*===================================*/
/* Operation: rmEnemiesAllDead(room) */
/*=====================================================*/
/* Purpose: this operation checks if all the enemies in*/
/*          the given room are dead                    */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: room to process enemies for                  */
/*   POST: enemies are processed or displays error message*/
/*   Processes: if room isn't valid, display error message*/
/*            else                                     */
/*               FOR all enemies in the room           */
/*                  return false if any 1 is alive     */
/*               else return true                      */
/*=====================================================*/

boolean rmEnemiesAllDead(roomPtrType room)
{
    for(int i = 0; i < room->fNumEnemies; i++)
    {
        if(enGetState(&(room->fEnemies[i])) == ENEMY_STATE_ALIVE)
        {
            return(FALSE);
        }
    }
    return(TRUE);
}

/*================================================*/
/* Operation: rmAttackEnemyAtIndex(room, index)   */
/*=====================================================*/
/* Purpose: this operation attacks the enemy at the given index*/
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room that the enemy is in and the index of the enemy */
/*   POST:  enemy sustains 0 or more damage or error message       */
/* Processes: if index or room isn't valid, display error message  */
/*            else calculate the damage to be done to the enemy    */
/*               Reduce the enemies health by the damage           */
/*=================================================================*/

boolean rmAttackEnemyAtIndex(roomPtrType room, int index, boolean withWeapon)

{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmAttackEnemyAtIndex!\n");
        return(FALSE);
    }
    
    if((index < 0) || (index >= room->fNumEnemies))
    {
        fprintf(stderr, "There is no enemy at index %d!\n", index);
        return(TRUE);
    }
    
    if(enGetState(&(room->fEnemies[index])) == ENEMY_STATE_DEAD)
    {
        char enName[MAX_NAME_LEN] = {'\0'};
        enGetName(&(room->fEnemies[index]), enName);
        printf("The %s is already dead!\n", enName);
    }
    else if(!withWeapon)
    {
        enDoDamage(&(room->fEnemies[index]), PLAYER_STRENGTH);
    }
    else
    {
        enDoDamage(&(room->fEnemies[index]), PLAYER_STRENGTH*5);
    }
    return(TRUE);
}

/*==========================================*/
/* Operation: rmEnemyIsAlive(room, index)   */
/*=====================================================*/
/* Purpose: this operation checks if the enemy at the  */
/*          index is alive                             */
 /*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room that the enemy is in and the index of the enemy */
/*   POST:  return TRUE if enemy is alive, FALSE is dead, or error */
/*          message                                                */
/* Processes: if index or room isn't valid, display error message  */
/*            else check if enemy is alive                         */
/*            if alive return TRUE, esle return FALSE              */
/*=================================================================*/

boolean rmEnemyIsAlive(roomPtrType room, int index)
{
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmEnemyIsAlive!\n");
        return(FALSE);
    }
    
    if((index < 0) || (index >= room->fNumEnemies))
    {
        //      fprintf(stderr, "There is no enemy at index %d!\n", index);
        return(FALSE);
    }
    
    if(enGetState(&(room->fEnemies[index])) == ENEMY_STATE_ALIVE)
        return(TRUE);
    else
        return(FALSE);
}


/*=======================================*/
/* Operation: rmItemIsInRoom(room, name) */
/*=====================================================*/
/* Purpose: this operation checks if the given item with*/
/*          the given name is in the room              */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the room to check and the name of the item   */
/*   POST:  returns TRUE if found, FALSE otherwise     */
/* Processes: if index or room isn't valid, display error message  */
/*            if list is empty, return FALSE           */
/*            else search for the item                 */
/*               if the item was found return TRUE     */
/*               else return FALSE                     */
/*=====================================================*/

boolean rmItemIsInRoom(roomPtrType room, char * name)
{
    /*----local vars-----*/
    itemType temp;       // used to search for the name
    
    /*----check for valid pointers----*/
    if(!room)
    {
        //fprintf(stderr, "Invalid room pointer passed to rmItemIsInRoom!\n");
        return(FALSE);
    }
    
    if(!name)
    {
        //fprintf(stderr, "Invalid name passed to rmAttackEnemyAtIndex!\n");
        return(FALSE);
    }
    
    itemSetName(&temp, name);
    
    return(GetListItemByKey(room->fItems, &temp));
}

/*====END OF FILE room.c====*/
