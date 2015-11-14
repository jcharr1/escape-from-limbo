/*====================*/
/* Jason Charrier     */
/* 4/30/2001          */
/* CSC 3102           */
/*====================*/
/* Module: main.c     */
/*====================*/

#include "player.h"
#include "room.h"

int efl_init(void);
int efl_main(void);
void efl_end(void);

playerType player;
roomType rooms[UNI_MAX_X][UNI_MAX_Y];

int main(void)
{
    if(!efl_init())
    {
        printf("There was an error while trying to initialize EFL!\n");
        printf("Exiting program...\n\n");
    }
    else
    {
        efl_main();
    }
    efl_end();
    return(0);
}

/*====END OF FILE main.c====*/
