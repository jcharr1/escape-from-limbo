/*====================*/
/* Jason Charrier     */
/* 4/30/2001          */
/* CSC 3102           */
/*====================*/
/* Module: swread.c   */
/*========================================================*/
/* Purpose: this module contains the fucntion definition  */
/*          for switches data file reading fucntion       */
/*========================================================*/

#include "swread.h"
#include "globals.h"

/*=======================================*/
/* Operation: SwitchesReader             */
/*=====================================================*/
/* Purpose: this operation reads in the switches from a*/
/*          data file and adds them to the room        */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the file to read from                        */
/*   POST:  all switches are read in or error message  */
/* Processes: If data file is invalid, display error   */
/*            Else read in the switches and add them   */
/*               to the appropriate room one by one    */
/*            Continue reading and adding until hit end*/
/*               of file                               */
/*=====================================================*/

boolean SwitchesReader(FILE * datFile)
{
    /*----local vars----*/
    int x = 0, y = 0,    // x,y coords
    jobx = 0, joby = 0,
    i = 0,           // counter
    numSwitches = 0;
    
    char name[MAX_NAME_LEN] = {'\0'};
    
    switchType theSwitch;
    
    if(!datFile)
    {
        //fprintf(stderr, "Invalid data file passed to SwitchesReader!\n");
        return(FALSE);
    }
    
    swCreateSwitch(&theSwitch);
    
    fscanf(datFile, " %s %d", name, &numSwitches);
    swSetName(&theSwitch, name);
    swSetJob(&theSwitch, SW_JOB_UNLOCK);
    
    /*----unlocking switches-----*/
    for(i = 0; i < numSwitches; ++i)
    {
        fscanf(datFile, " %d %d %d %d", &x, &y, &jobx, &joby);
        swSetUnlockXY(&theSwitch, jobx, joby);
        rmSetSwitch(&rooms[x][y], &theSwitch);
    }
    
    /*----warping switches----*/
    swSetJob(&theSwitch, SW_JOB_WARP);
    swSetUnlockXY(&theSwitch, -1, -1);
    fscanf(datFile, " %d", &numSwitches);
    
    for(i = 0; i < numSwitches; ++i)
    {
        fscanf(datFile, " %d %d %d %d", &x, &y, &jobx, &joby);
        swSetWarpXY(&theSwitch, jobx, joby);
        rmSetSwitch(&rooms[x][y], &theSwitch);
    }
    return(TRUE);
    
}

/*====END OF FILE swread.c====*/
