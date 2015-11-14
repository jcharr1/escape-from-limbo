#include <stdlib.h>

#include <stdio.h>

#include "types.h"

#include "map.h"

#include "enemy.h"

#include "item.h"

#include "room.h"

#include "utils.h"

#include "globals.h"

#include "switch.h"

#include "parse.h"

#include "player.h"
#include "swread.h"



int main(void)

{
    
    //   roomPtrType roomPtr;
    
    itemType item;
    
    switchType theSwitch;
    
    switchType switch2;
    
    
    
    //char name[MAX_NAME_LEN] = {'\0'};
    
    char title[ROOM_MAX_TITLE_LEN] = {'\0'};
    
    //char descrip[MAX_DESCRIP_LEN] = {'\0'};
    
    
    
    char *strVerb; // vincent
    
    char *strObject; // vincent
    
    char *tempString;
    
    
    
    boolean Moved = FALSE;
    
    boolean done = FALSE;
    
    
    
    int i = 0;
    
    int j = 0;
    
    FILE * switches3Dat = NULL;
    
    
    
    directionType dir = NORTH;
    
    
    
    swCreateSwitch(&theSwitch);
    
    swSetUnlockXY(&theSwitch, 0, 1);
    
    swSetJob(&theSwitch, SW_JOB_UNLOCK);
    rmSetSwitch(&(rooms[1][1]), &theSwitch);
    
    
    
    swCreateSwitch(&switch2);
    
    swSetWarpXY(&switch2, 0, 0);
    
    swSetJob(&switch2, SW_JOB_WARP);
    
    switches3Dat = fopen("switches3.dat", "r");
    SwitchesReader(switches3Dat);
    fclose(switches3Dat);
    
    
    
    for(i = 0; i < UNI_MAX_X; i++)
        
    {
        
        for(j = 0; j < UNI_MAX_Y; j++)
            
        {
            
            rmCreateRoom(&rooms[i][j]);
            
            sprintf(title, "Room %d %d", i, j);
            
            rmSetTitle(&(rooms[i][j]), title);
            
            rmUnlock(&rooms[i][j]);
            
            rmSetWall(&rooms[i][j], FALSE);
            
        }
        
    }
    
    
    
    //   roomPtr = &room;
    
    
    
    
    
    itemSetName(&item, "Blue key");
    
    rmAddItem(&rooms[1][0], &item);
    
    //   rmPrintItems(roomPtr);
    
    
    
    itemSetName(&item, "Torch");
    
    rmAddItem(&rooms[0][0], &item);
    
    //   rmPrintItems(roomPtr);
    
    
    
    //   itemSetName(&item, "Ham sandwhich");
    
    //   rmAddItem(roomPtr, &item);
    
    itemSetName(&item, "Tux the Penguin");
    
    rmAddItem(&rooms[0][1], &item);
    
    itemSetName(&item, "Dwarf Ax");
    
    rmAddItem(&rooms[0][1], &item);
    
    itemSetName(&item, "All your base");
    
    rmAddItem(&rooms[0][1], &item);
    
    itemSetName(&item, "are belong to us");
    
    rmAddItem(&rooms[0][1], &item);
    
    itemSetName(&item, "There is one more items");
    
    rmAddItem(&rooms[0][1], &item);
    
    itemSetName(&item, "This is the last item");
    
    rmAddItem(&rooms[0][1], &item);
    
    
    
    /*   rmPrintItems(roomPtr);
     
     
     
     itemSetName(&item, "Tux the Penguin");
     
     rmGetItem(roomPtr, &item);
     
     
     
     itemGetName(&item, name);
     
     printf("\nYou picked up %s\n\n", name);
     
     
     
     rmPrintItems(roomPtr);
     
     */
    
    
    
    /*
     
     
     
     MAP:
     
     
     
     0   1
     
     ----------
     
     ----------
     
     2 |   <|   |
     
     |-----  -|
     
     |-v---- -|
     
     |   | |  |
     
     1 | s    u |
     
     |   | |  |
     
     |-  -----|
     
     |-  -----|
     
     |   |&|  |
     
     0 |   |&|l |
     
     ---------
     
     
     
     s = start
     
     l = locked
     
     u = unlocks l
     
     |> = one way path
     
     | | or space = open doorway
     
     |&| = locked door
     
     */
    
    
    
    rmSetValidExit(&rooms[1][0], SOUTH);
    
    rmSetValidExit(&rooms[1][0], EAST);
    
    
    
    rmSetValidExit(&rooms[1][1], NORTH);
    
    rmSetValidExit(&rooms[1][1], WEST);
    
    
    
    rmSetValidExit(&rooms[2][1], SOUTH);
    
    rmSetValidExit(&rooms[2][1], WEST);
    
    
    
    rmSetValidExit(&rooms[2][0], SOUTH);
    
    
    
    rmSetValidExit(&rooms[0][0], NORTH);
    
    rmSetValidExit(&rooms[0][0], EAST);
    
    
    
    rmSetValidExit(&rooms[0][1], WEST);
    
    
    
    rmLock(&rooms[0][1]);
    
    
    
    rmGetTitle(&rooms[player.fx][player.fy], title);
    
    printf("You are in %s\n\n", title);
    
    rmPrintItems(&rooms[player.fx][player.fy]);
    
    printf("\n");
    
    
    
    strVerb = (char *) malloc (sizeof(char));
    
    strObject = (char *) malloc (sizeof(char));
    
    tempString = (char *) malloc (sizeof(char));
    
    
    
    
    
    Player_CREATE( &player );
    
    
    
    itemSetName(&item, "Burger");
    
    itemSetType(&item, 'f');
    
    AddListItem(player.list,&item);
    
    
    
    itemSetName(&item, "Black Key");
    
    itemSetType(&item, 'k');
    
    AddListItem(player.list,&item);
    
    
    
    itemSetName(&item, "Fries");
    
    itemSetType(&item, 'f');
    
    AddListItem(player.list,&item);
    
    
    
    while( !done ){
        
        
        
        if ( !Player_ALIVE() ){
            
            printf("\nPlayer dead: GAME OVER!");
            
            done = TRUE;
            
        }
        
        rmProcessEnemies(&rooms[player.fx][player.fy]);
        
        printf("\n\n||Enter in command >> ");
        
        gets(strVerb);
        
        
        boolean moveCheck = FALSE;
        if ( Check_Verb(strVerb, &moveCheck) ){
            
            // get string for object only if it is valid with the command
            
            if ( Check_Object(strVerb) ){
                
                printf("\n   ||Enter in object >> ");
                
                gets(strObject);
                
            }
            
            
            
            if ( !Command_Call(strVerb,strObject,NULL) ){
                
                printf("\nThanks for quitting loser!");
                
                done = TRUE;
                
            }
            
        }
        
        
        
        if( !done && Moved ){
            
            if( rmIsWall(&rooms[player.fx][player.fy]) ||
               
               rmIsLocked(&rooms[player.fx][player.fy])){
                
                
                
                printf("That way is blocked!\n");
                
                switch(dir){
                        
                    case NORTH:
                        
                        --player.fx;
                        
                        break;
                        
                    case SOUTH:
                        
                        ++player.fx;
                        
                        break;
                        
                    case EAST:
                        
                        --player.fy;
                        
                        break;
                        
                    case WEST:
                        
                        ++player.fy;
                        
                        break;
                        
                }
                
            }
            
        }
        
        
        
    }// end while
    
    
    
    
    
    Player_DESTROY(&player);
    
    
    
    
    
    for(i = 0; i < UNI_MAX_X; i++){
        
        for(j = 0; j < UNI_MAX_Y; j++){
            
            rmDestroyRoom(&rooms[i][j]);
            
        }
        
    }
    
    
    
    printf("\n\n");
    return(0);
}