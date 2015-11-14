/*====================*/
/* Jason Charrier     */
/* 4/30/2001          */
/* CSC 3102           */
/*====================*/
/* Module: roomread.c */
/*========================================================*/
/* Purpose: this module contains the fucntion definition  */
/*          for room data file reading fucntion           */
/*========================================================*/

#include "roomread.h"
#include "globals.h"

/*=======================================*/
/* Operation: RoomReader                 */
/*=====================================================*/
/* Purpose: this operation reads in the rooms from a   */
/*          data file and adds them to the universe    */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the file to read from                        */
/*   POST:  all rooms are read in or error message     */
/* Processes: If data file is invalid, display error   */
/*            Else read in the rooms and adding to the */
/*               appropriate place in universe         */
/*            Continue reading and adding until hit end*/
/*               of file                               */
/*=====================================================*/


boolean RoomReader(FILE * datFile)
{
    /*----local vars----*/
    int x = 0, y = 0,    // x,y coords
    i = 0,           // counter
    value = 0;       // generic input value
    
    char title[ROOM_MAX_TITLE_LEN] = {'\0'},
    descrip[MAX_DESCRIP_LEN] = {'\0'},
    delimiter,
    temp;        // used to check for eof
    
    //roomType rooms[UNI_MAX_X][UNI_MAX_Y]; //update 4/30 Michael Simpson
    
    
    if(!datFile)
    {
        //fprintf(stderr, "Invalid data file passed to RoomReader!\n");
        return(FALSE);
    }
    
    temp = fgetc(datFile);
    while(!feof(datFile))
    {
        ungetc(temp, datFile);
        fscanf(datFile, " %d %d", &x, &y);
        ReadLine(title, ROOM_MAX_TITLE_LEN, datFile);
        rmSetTitle(&(rooms[x][y]), title);
        delimiter = fgetc(datFile);
        ReadUntil(descrip, MAX_DESCRIP_LEN, delimiter, datFile);
        rmSetDescrip(&(rooms[x][y]), descrip);
        for(i = 0; i < MAX_DIRECTIONS; i++)
        {
            fscanf(datFile, " %d", &value);
            if(value == 1)
            {
                directionType dir = (directionType)i;
                rmSetValidExit(&(rooms[x][y]), dir);
            }
        }
        fscanf(datFile, " %d", &value);
        if(value == 0)
            rmUnlock(&(rooms[x][y]));
        
        rmSetWall(&(rooms[x][y]), FALSE);
        
        ClearStr(title, ROOM_MAX_TITLE_LEN);
        ClearStr(descrip, MAX_DESCRIP_LEN);
        value = 0;
        
        temp = fgetc(datFile);
    }
    
    return(TRUE);
}

/*====END OF FILE roomread.c====*/
