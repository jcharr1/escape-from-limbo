/****************************************/
/*					*/
/*	Michael Simpson			*/
/*	cs310236			*/
/*	map.h				*/
/*	Purpose: Creates map as player advances from room to room*/
/*								 */
/*****************************************************************/



//#pragma once

#ifndef _MAP_H_
#define _MAP_H_

#include<stdio.h>
#include "types.h"

typedef struct map
{
    char column[UNI_MAX_X];
}map;

void CreateMap(map row[]);

void RoomVisited(map row[], int x, int y);

void PrintMap(map row[]);

#endif
