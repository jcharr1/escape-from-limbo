/****************************************/
/*                                      */
/*      Michael Simpson                 */
/*      cs310236                        */
/*      efl_init.c                      */
/*      Purpose: Initializes everything for Main                 */
/*                                                               */
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

boolean efl_init()
{
    
    short i = 0, j = 0;
    
    map row[UNI_MAX_X];
    
    FILE * enFile;
    FILE * rmFile;
    FILE * itFile;
    FILE * swFile;
    
    //enFile = fopen("enemies3.dat", "r");
    
    // <JKC> 1/22/2002: added file open checks
    // <JKC> ?/??/2002: added "progress reports"
    
    printf("Initializing...\n");
    
    //enFile = fopen("enemies3.enc", "r");
    enFile = fopen("enemies3.dat", "r");
    if(!enFile)
    {
        fprintf(stderr, "Failed to open enemies data file!\n");
        return(FALSE);
    }
    
    
    rmFile = fopen("rooms1.dat", "r");
    if(!rmFile)
    {
        fprintf(stderr, "Failed to open rooms data file!\n");
        fclose(enFile);
        return(FALSE);
    }
    
    
    
    itFile = fopen("items1.dat", "r");
    if(!itFile)
    {
        fprintf(stderr, "Failed to open items data file!\n");
        fclose(enFile);
        fclose(rmFile);
        return(FALSE);
    }
    
    
    swFile = fopen("switches3.dat", "r");
    if(!swFile)
    {
        fprintf(stderr, "Failed to open switches data file!\n");
        fclose(enFile);
        fclose(rmFile);
        fclose(itFile);
        return(FALSE);
    }
    
    printf("Creating rooms...\n");
    
    for(i = 0; i < UNI_MAX_X; i++)
    {
        for(j = 0; j < UNI_MAX_Y; j++)
        {
            rmCreateRoom(&rooms[i][j]);
        }
    }
    
    printf("Creating map...\n");
    CreateMap(row);
    
    printf("Loading rooms...\n");
    RoomReader(rmFile);
    
    printf("Loading enemies...\n");
    EnemiesReader(enFile);
    
    printf("Loading items...\n");
    itemReadDataFile(itFile);
    
    printf("Loading switches...\n");
    SwitchesReader(swFile);
    
    printf("Creating player...\n");
    Player_CREATE(&player);
    
    fclose(enFile);
    fclose(rmFile);
    fclose(itFile);
    fclose(swFile);
    
    printf("READY!!!...\n");
    
    //return 0;
    return(TRUE);
}
