#include "types.h"
#include "globals.h"
#include "player.h"
#include "room.h"
#include "switch.h"
#include "parse.h"
#include "utils.h"
#include "list.h"
#include "map.h"
#include <unistd.h>
/* Operation: void Player_MOVE(string)
 Input:  player to be created
 Output: a player is created or displays an error message
 Processing: if player isn't valid,
 display an error message
 else set player to empty room
 */
boolean Player_CREATE(playerPtrType player){
    
    if( !player ){
        //fprintf(stderr,"Invalid player pointer passed to Player_CREATE!");
        return FALSE;
    }
    
    if( !CreateList(&(player->list)) ){
        fprintf(stderr, "Failed to create list of items!\n");
        return(FALSE);
    }
    
    player->fx = 24;
    player->fy = 24;
    player->fHealth = PLAYER_MAX_HEALTH;
    
    return TRUE;
}



/* Operation: void Player_DESTROY(string)
 Input:  room to be destroyed
 Output: updated global player data
 Processing: if player isn't valid, display an error message
 else remove everything from the player
 */
boolean Player_DESTROY( playerPtrType player){
    
    if( !player ){
        //fprintf(stderr, "Invalid room pointer passed to Player_DESTROY!\n");
        return(FALSE);
    }
    
    if ( !DestroyList(&(player->list)) ){
        //      fprintf(stderr, "Failed to destroy list of items!\n");
        return(FALSE);
    }
    
    player->fx = 24;
    player->fy = 24;
    player->fHealth = PLAYER_MAX_HEALTH;
    
    return TRUE;
}



/* Operation: void Player_MOVE(string)
 Input:  string
 Output: return true or false if player able to move in direction
 Processing: If is able to move in direction
 return true
 else return false
 */
boolean Player_MOVE(char * strObject){
    
    directionType dir = NORTH;
    boolean liveEnemies = FALSE;
    
    char answer = '8';
    int i = 0;
    //   itemType item;
    
    char *keyname = (char *) malloc (sizeof(char));
    //   char *tempName = (char *) malloc (sizeof(char));
    
    
    // check if enemy is in the room
    while( i < ROOM_MAX_ENEMIES && !liveEnemies ){
        if ( rmEnemyIsAlive(&rooms[player.fx][player.fy], i) )
            liveEnemies = TRUE;
        ++i;
    }
    if ( liveEnemies ){
        printf("You cannot leave with the beast in the room!");
        return FALSE;
    }
    
    // check for valid exits
#if OS == WIN
    if ( stricmp(strObject,"north") == 0 )
#else
        if ( strcasecmp(strObject,"north") == 0 )
#endif
        {
            ++player.fx;
            if ( player.fx > UNI_MAX_X ||
                !rmIsValidExit(&rooms[player.fx-1][player.fy], NORTH) ||
                rmIsWall( &rooms[player.fx][player.fy])  ){
                --player.fx;
                printf("You cannot go North!\n");
                return FALSE;
            }
            else{
                if ( rmIsLocked( &rooms[player.fx][player.fy]) ){
                    printf("That door is locked in that direction!\n");
                    
                    printf("\nDo you want to unlock it? y or n >>");
                    answer = getchar();
                    answer = tolower(answer);
                    while((answer != 'y') && (answer != 'n'))
                    {
                        printf("\nPlease answer y or n!\n");
                        printf("Do you want to unlock the door? y or n >>");
                        answer = tolower(getchar());
                    }
                    if( answer == 'y' ){
                        printf("\nEnter key name: ");
                        scanf("%s",keyname);
                        getc(stdin);
                        //itemGetName(&item, keyname);
                        //if ( stricmp(keyname,tempName) == 0 )
                        Player_UNLOCK(keyname);
                    }
                    --player.fx;
                    return FALSE;
                }
                else {
                    dir = NORTH;
                    return TRUE;
                }
            }
        }
        else
# if OS == WIN
            if ( stricmp(strObject,"south") == 0 )
#else
                if ( strcasecmp(strObject,"south") == 0 )
#endif
                {
                    --player.fx;
                    if( player.fx < 0 ||
                       !rmIsValidExit(&rooms[player.fx+1][player.fy], SOUTH) ||
                       rmIsWall( &rooms[player.fx][player.fy]) ){
                        ++player.fx;
                        printf("You cannot go South!\n");
                        return FALSE;
                    }
                    else{
                        if ( rmIsLocked( &rooms[player.fx][player.fy]) ){
                            printf("That door is locked in that direction!\n");
                            printf("\nDo you want to unlock it? y or n >>");
                            answer = getchar();
                            answer = tolower(answer);
                            while((answer != 'y') && (answer != 'n'))
                            {
                                printf("\nPlease answer y or n!\n");
                                printf("Do you want to unlock the door? y or n >>");
                                answer = tolower(getchar());
                            }
                            if( answer == 'y' ){
                                printf("\nEnter key name: ");
                                scanf("%s",keyname);
                                getc(stdin);
                                //itemGetName(&item, keyname);
                                //if ( stricmp(keyname,tempName) == 0 )
                                Player_UNLOCK(keyname);
                            }
                            ++player.fx;
                            return FALSE;
                        }
                        else {
                            dir = SOUTH;
                            return TRUE;
                        }
                    }
                }
                else
#if OS == WIN
                    if ( stricmp(strObject,"east") == 0 )
#else
                        if ( strcasecmp(strObject,"east") == 0 )
#endif
                        {
                            ++player.fy;
                            if( player.fy > UNI_MAX_Y ||
                               !rmIsValidExit(&rooms[player.fx][player.fy-1], EAST) ||
                               rmIsWall( &rooms[player.fx][player.fy]) ){
                                --player.fy;
                                printf("You cannot go East!\n");
                                return FALSE;
                            }
                            else{
                                if ( rmIsLocked( &rooms[player.fx][player.fy]) ){
                                    printf("That door is locked in that direction!\n");
                                    printf("\nDo you want to unlock it? y or n >>");
                                    answer = getchar();
                                    answer = tolower(answer);
                                    while((answer != 'y') && (answer != 'n'))
                                    {
                                        printf("\nPlease answer y or n!\n");
                                        printf("Do you want to unlock the door? y or n >>");
                                        answer = tolower(getchar());
                                    }
                                    if( answer == 'y' ){
                                        printf("\nEnter key name: ");
                                        scanf("%s",keyname);
                                        getc(stdin);
                                        //itemGetName(&item, keyname);
                                        //if ( stricmp(keyname,tempName) == 0 )
                                        Player_UNLOCK(keyname);
                                    }
                                    --player.fy;
                                    return FALSE;
                                }
                                else {
                                    dir = EAST;
                                    return TRUE;
                                }
                            }
                        }
                        else
#if OS == WIN
                            if ( stricmp(strObject,"west") == 0 )
#else
                                if ( strcasecmp(strObject,"west") == 0 )
#endif
                                {
                                    --player.fy;
                                    if( player.fy < 0 ||
                                       !rmIsValidExit(&rooms[player.fx][player.fy+1], WEST) ||
                                       rmIsWall( &rooms[player.fx][player.fy]) ){
                                        ++player.fy;
                                        printf("You cannot go West!\n");
                                        return FALSE;
                                    }
                                    else{
                                        if ( rmIsLocked( &rooms[player.fx][player.fy]) ){
                                            printf("That door is locked in that direction!\n");
                                            printf("\nDo you want to unlock it? y or n >>");
                                            answer = getchar();
                                            answer = tolower(answer);
                                            while((answer != 'y') && (answer != 'n'))
                                            {
                                                printf("\nPlease answer y or n!\n");
                                                printf("Do you want to unlock the door? y or n >>");
                                                answer = tolower(getchar());
                                            }
                                            if( answer == 'y' ){
                                                printf("\nEnter key name: ");
                                                scanf("%s",keyname);
                                                getc(stdin);
                                                //itemGetName(&item, keyname);
                                                //if ( stricmp(keyname,tempName) == 0 )
                                                Player_UNLOCK(keyname);
                                            }
                                            ++player.fy;
                                            return FALSE;
                                        }
                                        else {
                                            dir = WEST;
                                            return TRUE;
                                        }
                                    }
                                }
                                else{
                                    
                                    printf("\nNot a valid direction");
                                    return FALSE;
                                }
}



/* Operation: void Player_ALIVE()
 Input:  global player health
 Output: return true or false if player is alive
 Processing: If player have more than 0 health
 return true for alive
 else return false for dead
 */
boolean Player_ALIVE(){
    
    if ( player.fHealth > 0 ){
        return TRUE;
    }
    else
        return FALSE;
}



/* Operation: void Player_USE(string)
 Input:  string
 Output: updated item data for global player
 Processing:
 */
void Player_USE(char * strObject){
    
    itemType item;
    
    /* <JKC> */
    itemSetName(&item, strObject);
    if ( !GetListItemByKey(player.list, &item) ){
        printf("%s is not in your inventory!\n", strObject);
    }
    else
    /* </JKC> */
        if ( itemGetType( &item ) == ITEM_FOOD )
            Player_EAT(strObject);
        else
            if ( itemGetType( &item ) == ITEM_KEY ) {}
    //      Player_UNLOCK();
            else
                if ( itemGetType( &item ) == ITEM_GEM ){
                }
                else
                    if ( itemGetType( &item ) == ITEM_TAPE ){
                        
                    }
}



/* Operation: void Player_UNLOCK(string)
 Input:  string
 Output: updated item data for global player
 Processing: check if room is unlocked
 and delete key if it is in the inventory
 and open room door
 and display message
 else display error message
 */
void Player_UNLOCK(/*void*/ char * keyName){
    
    itemType item;
    boolean found = TRUE;
    
    itemSetName( &item,keyName );
    if ( !GetListItemByKey(player.list,&item) )
        printf("%s is not in your inventory!\n", keyName);
    else if ( itemGetType(&item) != ITEM_KEY ){
        printf("%s is not a key!\n", keyName);
        found = FALSE;
    }
    else if ( rmIsLocked(&rooms[player.fx][player.fy]) ){
        DeleteListItemByKey( player.list, &item );
        rmUnlock( &(rooms[player.fx][player.fy]) ); // JKC
        printf("\nYou have unlocked the door!");
    }
    else printf("\nRoom is already unlocked!");
    
    if(!found)
        printf("\nYou don't have a key in your inventory!");
    
}



/* Operation: void Player_SWITCH()
 Input:  none
 Output:
 Processing:
 */
boolean Player_SWITCH(){
    
    boolean liveEnemies = FALSE;
    int i = 0;
    int state = SW_ON;
    
    // check if room has a switch
    if ( rmHasSwitch(&rooms[player.fx][player.fy]) ) {
        // check if enemy is in the room
        while( i < ROOM_MAX_ENEMIES && !liveEnemies ){
            if ( rmEnemyIsAlive(&rooms[player.fx][player.fy], i) ){
                liveEnemies = TRUE;
            }
            ++i;
            
        }
        if ( liveEnemies ){
            printf("The switch is blocked by the enemy!\n");
            //printf("You cannot leave with the beast in the room!");
            return FALSE;
        }
        
        // check for switch job and perform it
        rmSetSwitchState( &rooms[player.fx][player.fy], state );
        rmSwitchDoJob( &rooms[player.fx][player.fy] );
        
        return TRUE;
    }
    else{
        printf ("\nThere's no switch in the room!");
        return FALSE;
    }
}



/* Operation: void Player_LOOK(string)
 Input:  string
 Output: display the contents of the room
 Processing: display things in room
 */
void Player_LOOK(void){
    
    //boolean found = FALSE;
    
    /* <JKC> */
    char title[ROOM_MAX_TITLE_LEN] = {'\0'};
    char descrip[MAX_DESCRIP_LEN] = {'\0'};
    
    rmGetTitle( &rooms[player.fx][player.fy], title );
    rmGetDescrip( &rooms[player.fx][player.fy], descrip );
    printf("%s\n%s\n", title, descrip );
    
    printf("\nYou take a look at the room and notice the following...");
    
    if(rmHasSwitch(&rooms[player.fx][player.fy]))
        printf("\nA switch\n");
    
    rmPrintItems(&rooms[player.fx][player.fy]);
}



/* Operation: void Player_INV(string)
 Input:  global player
 Output: display the items in the player inventory
 Processing: if inventory is not empty
 display inventory
 */
void Player_INV(){
    
    char Name[MAX_NAME_LEN] = {'\0'};   // holds item name
    short i = 0;                        // counter
    short NumItems = 0;                 // # of items in list
    itemType item;                      // holds the item to print
    
    if( !player.list ){
        //fprintf(stderr, "\nInvalid player pointer passed!");
        return;
    }
    
    if ( EmptyList( player.list ) ){
        printf("\nThere are no items in your inventory.");
    }
    else{
        NumItems = NumListItems( player.list );
        if ( NumItems == 1 ){
            printf("You have one item: \n\n");
        }
        else{
            printf("You have %hd items: \n\n", NumItems);
        }
        for(i = 0; i < NumItems; i++){
            GetListItemByIndex( player.list, i, &item);
            itemGetName(&item, Name);
            if ( NumItems == 2 && i == 0 )
                printf("%s ", Name);
            else if(i < NumItems - 1)
                printf("%s, ", Name);
            else if(NumItems == 1)
                printf("%s.\n", Name);
            else
                printf("and %s.\n", Name);
            
        }
    }
}



/* Operation: void Player_EAT(string)
 Input:  string
 Output: updated item data for global player
 Processing: if item is a valid food
 then delete item by key
 and display message for full health and minus inventory
 else display error message
 */

void Player_EAT(char * strObject){
    
    itemType item;
    boolean found = FALSE;
    
    /* <JKC> */
    itemSetName(&item, strObject);
    if(!GetListItemByKey(player.list, &item))
        printf("%s is not in your inventory!\n", strObject);
    else
    /* </JKC> */
        
        if ( itemGetType( &item ) == ITEM_FOOD ){
            // delete item from inventory
            if ( DeleteListItemByKey( player.list, &item ) ){
                found = TRUE;
            }
            
            if ( found ){
                // restore player's health to maximum
                player.fHealth = PLAYER_MAX_HEALTH;
                printf("\nYou have regained full health from the food!");
                printf("\nThat's one less thing in your inventory!");
            }
            else
                printf("\nYou don't have that food in your inventory");
        }
        else{
            printf("\nYou can't eat that!");
        }
    
}

void Player_DRINK(char * strObject){
    
    //  **  Michael Simpson  **
    
    itemType item;
    boolean found = FALSE;
    
    /* <JKC> */
    itemSetName(&item, strObject);
    if(!GetListItemByKey(player.list, &item))
        printf("%s is not in your inventory!\n", strObject);
    else
    /* </JKC> */
        
        if ( itemGetType( &item ) == ITEM_DRINK ){
            // delete item from inventory
            if ( DeleteListItemByKey( player.list, &item ) ){
                found = TRUE;
            }
            
            if ( found ){
                // restore player's health to maximum
                player.fHealth = PLAYER_MAX_HEALTH;
                printf("\nYou have regained full health from the drink!");
                printf("\nThat's one less thing in your inventory!");
            }
            else
                printf("\nYou don't have that drink in your inventory");
        }
        else{
            printf("\nYou can't drink that!");
        }
    
}



/* Operation: void Player_DROP(string)
 Input:  string
 Output: updated item data for global player and room
 Processing: delete item from inventory if found
 and place item in the room
 and display transaction messages
 else display error message
 */
void Player_DROP(char * strObject){
    
    itemType item;
    
    /* <JKC> */
    itemSetName(&item, strObject);
    if(!GetListItemByKey(player.list, &item))
        printf("%s is not in your inventory!\n", strObject);
    else
    /* </JKC> */
        
        
        // delete item from inventory
        if ( DeleteListItemByKey( player.list, &item ) ){
            rmAddItem(&rooms[player.fx][player.fy], &item);
            printf("\nYou just dropped that item in the room!");
        }
        else
            printf("\nYou don't have that item in your inventory");
}



/* Operation: void Player_GET(string)
 Input:  string
 Output: updated item data for global player and room
 Processing: add item if list is not full
 and place delete item from room
 and display transaction messages
 else display error message
 */
void Player_GET(char * strObject){
    
    itemType item;
    
    itemSetName(&item, strObject); // JKC
    
    // JKC: make sure item is in the room first!!!
    
    if(!rmGetItem(&rooms[player.fx][player.fy], &item))
        printf("I see no %s here! Have you ever considered glasses?\n",
               strObject);
    else
    /* </JKC> */
        
        // add item from inventory
        if ( AddListItem(player.list,&item) ){
            printf("\nYou have taken the item from the room and put it in your inventory!");
        }
}



/* Operation: boolean Player_HIT(string)
 Input:  string
 Output: updated item data for global player
 Processing:
 */
boolean Player_HIT(){
    
    int i = 0,
    enIndex = -1;
    boolean liveEnemies = FALSE;
    
    // check if enemy is in the room
    while( i < ROOM_MAX_ENEMIES && !liveEnemies ){
        if ( rmEnemyIsAlive(&rooms[player.fx][player.fy], i) ){
            liveEnemies = TRUE;
        }
        ++i;
    }
    
    if ( liveEnemies ){
        printf("Enter the number of the enemy you want to hit>>");
        scanf(" %d", &enIndex);
        getc(stdin);            // get rid of trailing \n
        printf("\n");
        printf(MAGENTA "You attack, hitting the enemy with your fist!\n" RESET);
        fflush(stdout);
        sleep(1);
        rmAttackEnemyAtIndex( &rooms[player.fx][player.fy], enIndex, FALSE);
    }
    
    
    return FALSE;
}






/* Operation: boolean Player_KICK()
 
 Input:  none
 
 Output: updated item data for global player
 
 Processing:
 
 */

boolean Player_KICK(){
    
    int i = 0,
    enIndex = -1;
    boolean liveEnemies = FALSE;
    
    // check if enemy is in the room
    while( i < ROOM_MAX_ENEMIES && !liveEnemies ){
        if ( rmEnemyIsAlive(&rooms[player.fx][player.fy], i) ){
            liveEnemies = TRUE;
        }
        ++i;
    }
    
    if ( liveEnemies ){
        printf("Enter the number of the enemy you want to kick>>");
        scanf(" %d", &enIndex);
        printf("\n");
        getc(stdin);            // get rid of trailing \n
        printf(MAGENTA "You attack, giving the enemy a hard kick!\n" RESET);
        sleep(1);
        rmAttackEnemyAtIndex( &rooms[player.fx][player.fy], enIndex, FALSE);
    }
    
    
    return FALSE;
}


void Player_THROW(char * strObject){
    
    //  **  Michael Simpson  **
    
    int i = 0,
    enIndex = -1;
    boolean liveEnemies = FALSE;
    char dec[2];
    itemType item;
    boolean found = FALSE;
    
    
    
    itemSetName(&item, strObject);
    if(!GetListItemByKey(player.list, &item))
        printf("%s is not in your inventory!\n", strObject);
    
    if ( DeleteListItemByKey( player.list, &item ) ){
        found = TRUE;
        if ( found ){
            
            // check if enemy is in the room
            while( i < ROOM_MAX_ENEMIES && !liveEnemies ){
                if ( rmEnemyIsAlive(&rooms[player.fx][player.fy], i) ){
                    liveEnemies = TRUE;
                }
                ++i;
            }
            
            if ( liveEnemies ){
                printf("Do you want to throw it at the enemy?  (y/n) :> ");
                scanf("%s", dec);
#if OS == WIN
                if(stricmp(dec, "y") == 0 || stricmp(dec, "yes") == 0)
#else
                    if(strcasecmp(dec, "y") == 0 || strcasecmp(dec, "yes") == 0)
#endif
                    {
                        printf("Enter the number of the enemy you want to throw it at>>");
                        scanf(" %d", &enIndex);
                        printf("\n");
                        getc(stdin);            // get rid of trailing \n
                        printf("You throw the object at the enemy!\n");
                        if ( itemGetType( &item ) == ITEM_WEAPON )
                            rmAttackEnemyAtIndex(&rooms[player.fx][player.fy], enIndex, TRUE);
                        else
                            printf("That was a silly thing to throw at an enemy!\n");
                    }
            }
            printf("The item has been thrown, now it is gone.\n");
        }
        else
            printf("\nYou don't have that item in your inventory");
    }
    
}




/* Operation: void Player_HEALTH()
 
 Input:  none
 
 Output: displays player health
 
 Processing:
 
 */

void Player_HEALTH(){
    
    
    
    
    
    printf("\nYou have %d health left",player.fHealth);
    
}






/* Operation: Command_Call(string)
 Input:  string
 Output: true or false if the command was found
 Processing: if command is found from list of verbs
 then call the corresponding functions
 */
boolean Command_Call(char *strVerb, char *strObject, map row[]){
    
#if OS == WIN
    if ( stricmp(strVerb,"move") == 0 )
#else
        if ( strcasecmp(strVerb,"move") == 0 )
#endif
        {
            Player_MOVE(strObject);
            return TRUE;
        }
    
#if OS == WIN
    if ( stricmp(strVerb,"north") == 0  || stricmp(strVerb,"n") == 0 )
#else
        if ( strcasecmp(strVerb,"north") == 0  || strcasecmp(strVerb,"n") == 0 )
#endif
        {
            Player_MOVE("NORTH");
            return TRUE;
        }
    
#if OS == WIN
    if ( stricmp(strVerb,"south") == 0  || stricmp(strVerb,"s") == 0 )
#else
        if ( strcasecmp(strVerb,"south") == 0  || strcasecmp(strVerb,"s") == 0 )
#endif
        {
            Player_MOVE("SOUTH");
            return TRUE;
        }
    
#if OS == WIN
    if ( stricmp(strVerb,"east") == 0  || stricmp(strVerb,"e") == 0)
#else
        if ( strcasecmp(strVerb,"east") == 0  ||strcasecmp(strVerb,"e") ==0)
#endif
        {
            Player_MOVE("EAST");
            return TRUE;
        }
    
#if OS == WIN
    if ( stricmp(strVerb,"west") == 0  || stricmp(strVerb,"w") == 0 )
#else
        if ( strcasecmp(strVerb,"west") == 0  || strcasecmp(strVerb,"w") ==0 )
#endif
        {
            Player_MOVE("WEST");
            return TRUE;
        }
        else
#if OS == WIN
            if ( stricmp(strVerb,"map") == 0 )
#else
                if ( strcasecmp(strVerb,"map") == 0 )
#endif
                {
                    
                    //  **  Michael Simpson  **
                    
                    PrintMap(row);
                    return TRUE;
                }
                else
#if OS == WIN
                    if ( stricmp(strVerb,"use") == 0 )
#else
                        if ( strcasecmp(strVerb,"use") == 0 )
#endif
                        {
                            Player_USE(strObject);
                            return TRUE;
                        }
                        else
#if OS == WIN
                            if ( stricmp(strVerb,"unlock") == 0 )
#else
                                if ( strcasecmp(strVerb,"unlock") == 0 )
#endif
                                {
                                    Player_UNLOCK(strObject); // JKC: specify name of key
                                    return TRUE;
                                }
                                else
#if OS == WIN
                                    if ( stricmp(strVerb,"switch") == 0 )
#else
                                        if ( strcasecmp(strVerb,"switch") == 0 )
#endif
                                        {
                                            Player_SWITCH();
                                            return TRUE;
                                        }
                                        else
#if OS == WIN
                                            if ( stricmp(strVerb,"look") == 0 || stricmp(strVerb, "l") == 0)
#else
                                                if ( strcasecmp(strVerb,"look") == 0  || strcasecmp(strVerb, "l") == 0)
#endif
                                                {
                                                    Player_LOOK();
                                                    return TRUE;
                                                }
#if OS == WIN
    if ( stricmp(strVerb,"inv") == 0 || stricmp(strVerb, "i") == 0)
#else
        if ( strcasecmp(strVerb,"inv") == 0  || strcasecmp(strVerb, "i") == 0)
#endif
        {
            Player_INV();
            return TRUE;
        }
        else
#if OS == WIN
            if ( stricmp(strVerb,"eat") == 0 )
#else
                if ( strcasecmp(strVerb,"eat") == 0 )
#endif
                {
                    Player_EAT(strObject);
                    return TRUE;
                }
    
                else
#if OS == WIN
                    if ( stricmp(strVerb,"drink") == 0 )
#else
                        if ( strcasecmp(strVerb,"drink") == 0 )
#endif
                        {
                            
                            //  **  Michael Simpson  **
                            
                            Player_DRINK(strObject);
                            return TRUE;
                        }
                        else
#if OS == WIN
                            if ( stricmp(strVerb,"drop") == 0 )
#else
                                if ( strcasecmp(strVerb,"drop") == 0 )
#endif
                                {
                                    Player_DROP(strObject);
                                    return TRUE;
                                }
                                else
#if OS == WIN
                                    if ( stricmp(strVerb,"get") == 0 )
#else
                                        if ( strcasecmp(strVerb,"get") == 0 )
#endif
                                        {
                                            Player_GET(strObject);
                                            return TRUE;
                                        }
                                        else
#if OS == WIN
                                            if ( stricmp(strVerb,"hit") == 0 )
#else
                                                if ( strcasecmp(strVerb,"hit") == 0 )
#endif
                                                {
                                                    
                                                    Player_HIT();
                                                    return TRUE;
                                                }
    
                                                else
#if OS == WIN
                                                    if ( stricmp(strVerb,"kick") == 0 )
#else
                                                        if ( strcasecmp(strVerb,"kick") == 0 )
#endif
                                                        {
                                                            
                                                            Player_KICK();
                                                            
                                                            return TRUE;
                                                            
                                                        }
    
                                                        else
#if OS == WIN
                                                            if ( stricmp(strVerb,"health") == 0 )
#else
                                                                if ( strcasecmp(strVerb,"health") == 0 )
#endif
                                                                {
                                                                    
                                                                    Player_HEALTH();
                                                                    
                                                                    return TRUE;
                                                                    
                                                                }
                                                                else
#if OS == WIN
                                                                    if ( stricmp(strVerb,"status") == 0 )
#else
                                                                        if ( strcasecmp(strVerb,"status") == 0 )
#endif
                                                                        {
                                                                            
                                                                            //  **  Michael Simpson  **
                                                                            
                                                                            printf("You aren't dead yet...your status is LUCKY, ha, ha, ha...\n");
                                                                            
                                                                            return TRUE;
                                                                            
                                                                        }
                                                                        else
#if OS == WIN
                                                                            if ( stricmp(strVerb,"throw") == 0 )
#else
                                                                                if ( strcasecmp(strVerb,"throw") == 0 )
#endif
                                                                                {
                                                                                    
                                                                                    //  **  Michael Simpson  **
                                                                                    
                                                                                    Player_THROW(strObject);
                                                                                    
                                                                                    return TRUE;
                                                                                    
                                                                                }
                                                                                else
#if OS == WIN
                                                                                    if ( stricmp(strVerb,"jump") == 0 )
#else
                                                                                        if ( strcasecmp(strVerb,"jump") == 0 )
#endif
                                                                                        {
                                                                                            
                                                                                            //  **  Michael Simpson  **
                                                                                            
                                                                                            printf("You jumpped. Nothing happened. You feel silly now don't you?!\n");
                                                                                            
                                                                                            return TRUE;
                                                                                            
                                                                                        }
                                                                                        else
#if OS == WIN
                                                                                            if ( stricmp(strVerb,"sleep") == 0 )
#else
                                                                                                if ( strcasecmp(strVerb,"sleep") == 0 )
#endif
                                                                                                {
                                                                                                    
                                                                                                    //  **  Michael Simpson  **
                                                                                                    
                                                                                                    printf("There's no bed here!\n");
                                                                                                    
                                                                                                    return TRUE;
                                                                                                    
                                                                                                }
                                                                                                else{
                                                                                                    printf("\nYou must start a sentence with an action Player!");
                                                                                                    return FALSE;
                                                                                                }
}
