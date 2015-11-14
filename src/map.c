/****************************************/
/*                                      */
/*      Michael Simpson                 */
/*      cs310236                        */
/*      map.h                           */
/*      Purpose: Creates map as player advances from room to room*/
/*								 */
/*****************************************************************/


#include "map.h"
#include "globals.h"

void CreateMap(map row[])
{
    
    int rcount=0, ccount=0;
    
    while(rcount < UNI_MAX_X)
    {
        while(ccount < UNI_MAX_Y)
        {
            row[rcount].column[ccount] = 0;
            ccount++;
        }
        rcount++;
        ccount=0;
    }
}

/*
 
 printf("enter room x coordinate >");
 scanf("%d", &x);
 printf("\n");
 printf("enter room y coordinate >");
 scanf("%d", &y);
 printf("\n\n");
 
 */

void RoomVisited(map row[], int x, int y)
{
    
    row[x].column[y] = 1;
    
}

void PrintMap(map row[])
{
    
    int rcount=UNI_MAX_X, ccount=0;
    
    printf("****************************************************\n");
    
    while(rcount > 0)
    {
        if(rcount >= 19 && rcount <= 30)
        {
            printf("*");
            while(ccount < UNI_MAX_Y)
            {
                if (row[rcount].column[ccount] == 1)
                /* <JKC> 5/2/2001 Modified to print * if not current position*/
                    if((player.fx == rcount) && (player.fy == ccount))
                        printf("X");
                    else
                        printf("*");
                /* </JKC> */
                    else	
                        printf(" ");
                ccount++;
            }
            printf("*\n");
        }
        rcount--;
        ccount=0;
    }
    
    printf("****************************************************\n");
    
}
