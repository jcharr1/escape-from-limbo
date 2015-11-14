/*====================*/
/* Jason Charrier     */
/* 4/30/2001          */
/* CSC 3102           */
/*====================*/
/* Module: enread.c   */
/*========================================================*/
/* Purpose: this module contains the fucntion definition  */
/*          for enemy data file reading fucntion          */
/*========================================================*/

#include "enread.h"
#include "globals.h"
//#include "EncDec.h"

/*=======================================*/
/* Operation: EnemiesReader              */
/*=====================================================*/
/* Purpose: this operation reads in the enemies from a */
/*          data file and adds them to the room        */
/*=====================================================*/
/* Conditions:                                         */
/*   PRE: the file to read from                        */
/*   POST:  all enemies are read in or error message   */
/* Processes: If data file is invalid, display error   */
/*            Else read in the enemies and add them    */
/*               to the appropriate room one by one    */
/*            Continue reading and adding until hit end*/
/*               of file                               */
/*=====================================================*/

void DecodeString(char * InputString, char * OutputString);

boolean EnemiesReader(FILE * datFile)
{
    int x = 0, y = 0,    // x,y coords
    i = 0,           // counter
    left = 0,        // bounding rectangle coords
    right = 0,
    bottom = 0,
    top = 0,
    health = 0,      // enemy's health
    strength = 0,    // enemy's str
    numEnemies = 0;  // # of enemies of a certain type
    
    double hitPer = 0.0;  // hit % rate
    
    char type,           // type of enemy
    name[MAX_NAME_LEN] = {'\0'}, // enemies name
    temp;           // used to check for eof
    
    enemyType enemy;     // used to read in enemies
    
    if(!datFile)
    {
        //printf("Invalid data file passed to EnemiesReader!\n");
        return(FALSE);
    }
    
    enCreateEnemy(&enemy);
    enSetState(&enemy, ENEMY_STATE_ALIVE);
    
    temp = fgetc(datFile);
    while(!feof(datFile))
    {
        char buffer[20] = {'\0'};
        
        ungetc(temp, datFile);
        ReadLine(name, MAX_NAME_LEN, datFile);
        //		DecodeString(name, name);
        //		EncDecString(name, "penguin", name);
        //		EncDecString(name, "wakkawakka", name);
        //		printf("Enemy's name is %s\n", name);
        enSetName(&enemy, name);
        ClearStr(name, (int)strlen(name));
        
        fscanf(datFile, " %d", &health);
        //		ReadLine(buffer, 100, datFile);
        //		DecodeString(buffer, buffer);
        //		EncDecString(buffer, "penguin", buffer);
        //		EncDecString(buffer, "wakkawakka", buffer);
        //		printf("Enemy's health is %s\n", buffer);
        //		health = atoi(buffer);
        enSetHealth(&enemy, health);
        
        //		ClearStr(buffer, strlen(buffer));
        //		ReadLine(buffer, 100, datFile);
        //		DecodeString(buffer, buffer);
        //   	EncDecString(buffer, "penguin", buffer);
        //		EncDecString(buffer, "wakkawakka", buffer);
        //		sscanf(buffer, " %d %lf", &strength, &hitPer);
        //		printf("Enemy's strength and hitPer are %d and %3.2lf\n",
        //			strength, hitPer);
        fscanf(datFile, " %d %lf", &strength, &hitPer);
        enSetStrength(&enemy, strength);
        enSetHitPer(&enemy, hitPer);
        
        //		ClearStr(buffer, strlen(buffer));
        //		ReadLine(buffer, 100, datFile);
        //		DecodeString(buffer, buffer);
        //		EncDecString(buffer, "penguin", buffer);
        //		EncDecString(buffer, "wakkawakka", buffer);
        //		numEnemies = atoi(buffer);
        //		printf("There are %d of these enemies\n", numEnemies);
        
        //		ClearStr(buffer, strlen(buffer));
        //		ReadLine(buffer, 100, datFile);
        //		DecodeString(buffer, buffer);
        //		EncDecString(buffer, "penguin", buffer);
        //		EncDecString(buffer, "wakkawakka", buffer);
        sscanf(buffer, " %c", &type);
        //
        //		printf("The type of enemy is %c\n", type);
        
        fscanf(datFile, " %d %c", &numEnemies, &type);
        //type = fgetc(datFile);
        for(i = 0; i < numEnemies; ++i)
        {
            if(type == 's')
            {
                fscanf(datFile, " %d %d", &x, &y);
                //ClearStr(buffer, strlen(buffer));
                //ReadLine(buffer, 100, datFile);
                //DecodeString(buffer, buffer);
                //				EncDecString(buffer, "penguin", buffer);
                //				EncDecString(buffer, "wakkawakka", buffer);
                //sscanf(buffer, " %d %d", &x, &y);
                //				printf("Enemy's x, y is %d,%d\n", x, y);
                rmAddEnemy(&rooms[x][y], &enemy);
            }
            else if(type == 'r')
            {
                printf("Generating random enemy posisition(s)...");
                //ClearStr(buffer, strlen(buffer));
                //ReadLine(buffer, 100, datFile);
                //DecodeString(buffer, buffer);
                //				EncDecString(buffer, "penguin", buffer);
                //				EncDecString(buffer, "wakkawakka", buffer);
                //sscanf(buffer, " %d %d %d %d %d", &left, &right, &bottom,
                //	&top);
                fscanf(datFile, " %d %d %d %d", &left, &right, &bottom,
                       &top);
                for(i = 0; i < numEnemies; i++)
                {
                    x = bottom + (rand() % (top - bottom));
                    y = left + (rand() % (right - left));
                    while(rmIsWall(&rooms[x][y]) ||
                          !rmAddEnemy(&rooms[x][y], &enemy))
                    {
                        x = bottom + (rand() % (top - bottom));
                        y = left + (rand() % (right - left));
                        //                  fprintf(stderr, "x = %d, y = %d\n", x, y);
                    }
                }
                printf("DONE!\n");
            }
            temp = fgetc(datFile);
            while(temp == ' ' || temp =='\t' || (temp == '\n'))
                temp = fgetc(datFile);
            //ungetc(temp, datFile);
        }
    }
    return(TRUE);
}

/*
void DecodeString(char * InputString, char * OutputString)
{
    EncDecString(InputString, "penguin", OutputString);
    EncDecString(InputString, "wakkawakka", OutputString);
}
*/
 
/*====END OF FILE enread.c====*/
