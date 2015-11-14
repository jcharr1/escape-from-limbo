/********************************************/
/*                                          */
/*      Michael Simpson                     */
/*  With lots of debugging help from Jason  */
/*      cs310236                            */
/*      efl_main.c                          */
/*      Purpose: Driver function for the Game                    */
/*								 */
/*****************************************************************/

#include "enemy.h"
#include "globals.h"
#include "item.h"
#include "list.h"
#include "map.h"
#include "parse.h"
#include "player.h"
#include "room.h"
#include "switch.h"
#include "types.h"
#include "utils.h"
#include "roomread.h"
#include "enread.h"
#include "swread.h"

void DoEnding(void);

int efl_main ()
{
    
    itemType item;
    map theMap[UNI_MAX_X];
    
    //char name[MAX_NAME_LEN] = {'\0'};
    char title[ROOM_MAX_TITLE_LEN] = {'\0'};
    char descrip[MAX_DESCRIP_LEN] = {'\0'};
    
    char *strVerb; // vincent
    char *strObject; // vincent
    char *tempString;
    
    //boolean Moved = FALSE;
    boolean done = FALSE;
    
    //int i = 0;
    //int j = 0;
    
    //directionType dir = NORTH;
    
    strVerb = (char *) malloc (sizeof(char));
    strObject = (char *) malloc (sizeof(char));
    tempString = (char *) malloc (sizeof(char));
    
    
    Player_CREATE( &player );
    CreateMap(theMap);
    
    /*
     itemSetName(&item, "Ruby");
     rmAddItem(&rooms[24][25], &item);
     itemSetName(&item, "Diamond");
     rmAddItem(&rooms[24][25], &item);
     itemSetName(&item, "Sapphire");
     rmAddItem(&rooms[24][25], &item);
     */
    
    printf("\n\nWelcome to Escape from Limbo - The exciting text based adventure game!!\n");
    
    while( !done ){
        
        if(!done && Player_ALIVE())
        {
            rmGetTitle(&rooms[player.fx][player.fy], title);
            printf("\nYou are in \"%s\"\n\n", title);
            if(!rmIsVisited(&rooms[player.fx][player.fy]))
            {
                rmGetDescrip(&rooms[player.fx][player.fy], descrip);
                printf("%s", descrip);
                rmVisit(&rooms[player.fx][player.fy]);
                RoomVisited(theMap, player.fx, player.fy);
                
            }
            rmProcessEnemies(&rooms[player.fx][player.fy]);
        }
        
        if ( !Player_ALIVE() )
        {
            printf(BOLDRED "\nPlayer dead: GAME OVER, MAN!\n" RESET);
            done = TRUE;
        }
        
        if(!done && Player_ALIVE())
        {
            if ( !Check_Parse( strVerb, strObject ) )
            {
                Command_Call(strVerb,strObject, theMap);
            }
            else
            {
                printf("\nThanks for quitting loser!\n\n");
                done = TRUE;
            }
            
            if((player.fx == 24) && (player.fy == 24))
            {
                if(rmItemIsInRoom(&rooms[player.fx][player.fy], "Ruby") &&
                   rmItemIsInRoom(&rooms[player.fx][player.fy], "Sapphire") &&
                   rmItemIsInRoom(&rooms[player.fx][player.fy], "Diamond"))
                {
                    player.fx = player.fy = 0;
                }
            }
            
            itemSetName(&item, "SecurityTape");
            //AddListItem(player.list, &item);
            if(GetListItemByKey(player.list, &item))
            {
                DoEnding();
                done = TRUE;
            }
            
            /*      if( !done && Moved ){
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
             */
        }
        
        
        
    }// end while
    
    /*
     
     *** DoEnding was all Jason Charrier  ***
     
     */
    
    return 0;
}

void DoEnding(void)
{
    printf("\n\"Ha, ha!\" you shout as you snatch the tape from the VCR. \"I can finally get out of this place!\"\n\n");
    printf("A bony finger taps you on the shoulder. You whip around and come face to top of hood with Bob. His reaches his hand out to you expectantly.\n");
    printf("\n");
    printf("\"Come on, boy!\" he snarls. \"Hand it over!\" You hand over the tape, but the \ninstant it touches Bob's hand, he and the tape vanish into thin air!\n");
    printf("\n");
    printf("\"HEY!\" you shout. \"COME BACK HERE! WE HAD A DEAL! LET ME OUT! I THOUGHT THE NAME OF THIS GAME WAS 'Escape from Limbo!'\"\n");
    printf("\n");
    printf("\"HA HA HA HA! Foolish mortal! Maybe one day you'll learn that you can't believe everything you read! Maybe if this were a commercial game, it would have had a \nprofessional writer to do the ending. Oh, well. It's no skin off my teeth!\"\n");
    printf("\n");
#if OS == WIN
    system("PAUSE");
#else
    printf("Press enter to continue...");
    getc(stdin);
#endif
    printf("\nAfter feeling sorry for yourself for a few minutes, you decide to have a closer look ");
    printf("around the room. After snooping around for about an hour, you notice that \none of the ");
    printf("shelves seems a bit loose. It swings easily on some hidden hinges you hadn't noticed ");
    printf(" before. The shelves now moved, you can now see a long staircase leading down. Your ");
    printf("footsteps echo hollowly as you descend. To your surprise, \nyou find a VERY nice sleek, ");
    printf("black Porsche. \"This must be Bob's\" you think to \nyourself. You try the driver side door. ");
    printf("Unlocked! What luck! The keys are in the ignition! You turn the key and hear the ");
    printf("satisfying purr of the engine. You \ndecide that this will be ample compensation for ");
    printf("weaseling out of your deal. You flip the headlights on and now notice a sign that was ");
    printf("once shrouded by the \ndarkness. The sign says, \"Exit\" and has a large arrow pointing ");
    printf("deeper into the \ncavern. You figure that, even if it's not actually the exit, it has to be better ");
    printf("than this place. You speed off towards the opening. After a few minutes of \ndriving, you ");
    printf("catch a small whiff of what seems to be fresh air. And then you \ncatch sight of the light! ");
    printf("Yes! This is indeed the exit! Putting the pedal to the metal, you race back into the mortal ");
    printf("world. Just as the back wheels pass the \nthreshold, you could swear that you hear a ");
    printf("ghastly scream (and other words that would be best not repeated here), the sound of a dull ");
    printf("scythe hitting the ground, and then silence... YOU HAVE ESCAPED FROM LIMBO!!!\n\n");
#if OS == WIN
    system("PAUSE");
#else
    printf("Press enter to exit...");
    getc(stdin);
#endif
    
}
