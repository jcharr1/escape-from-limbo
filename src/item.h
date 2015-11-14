/****************************************/
/*                                      */
/*      Michael Simpson                 */
/*      cs310236                        */
/*      item.h                          */
/*      Purpose: Reads item datafile, and places items in rooms  */
/*                                                               */
/*****************************************************************/

//#pragma once

#ifndef _ITEM_H_
#define _ITEM_H_

#include "types.h"
#include "utils.h"

typedef struct itemType
{
    char fName[MAX_NAME_LEN];
    typeofItem type;
}itemType, *itemPtrType;

void itemCreate(itemType * item);
void itemGetName(itemType * item, char * name);
void itemSetName(itemType * item, char * name);
void itemSetType(itemType * item, char type);
typeofItem itemGetType(itemType * item);
void itemReadDataFile(FILE *fp);

#endif
