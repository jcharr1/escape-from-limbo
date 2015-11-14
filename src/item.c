/****************************************/
/*					*/
/*      Michael Simpson                 */
/*      cs310236			*/
/*      item.c                          */
/*      Purpose: Reads item datafile, and places items in rooms  */
/*								 */
/*****************************************************************/

#include "types.h"
#include "globals.h"
#include "item.h"
#include "room.h"

void itemCreate(itemType * item)
{
    itemSetName(item,NULL);
    itemSetType(item,'\0');
}

void itemGetName(itemType * item, char * name)
{
    strcpy(name, item->fName);
}

void itemSetName(itemType * item, char * name)
{
    if(name)
    {
        strcpy(item->fName, name);
    }
}

void itemSetType(itemType * item, char type)
{
    switch(type)
    {
        case 'f':
        {
            item->type = ITEM_FOOD;
            break;
        }
        case 'k':
        {
            item->type = ITEM_KEY;
            break;
        }
        case 'g':
        {
            item->type = ITEM_GEM;
            break;
        }
        case 'w':
        {
            item->type = ITEM_WEAPON;
            break;
        }
        case 't':
        {
            item->type = ITEM_TAPE;
            break;
        }
        case 'd':
        {
            item->type = ITEM_DRINK;
            break;
        }
    }
    
}

typeofItem itemGetType(itemType * item)
{
    
    if (!item)
    {
        printf("That is not a valid item\n");
        return ITEM_INVALID;
    }
    else
        return item->type;
}

void itemReadDataFile(FILE * fp)
{
    
    int x, y, count=0, numitems;
    itemType item;
    char name[50];
    //roomType rooms[UNI_MAX_X][UNI_MAX_Y];
    char type;
    
    
    fscanf(fp, "%d%d", &x, &y);
    while(!feof(fp))
    {
        fscanf(fp, "%d", &numitems);
        while(count < numitems)
        {
            fscanf(fp, "%s %c", name, &type);
            itemSetName(&item, name);
            itemSetType(&item, type);
            rmAddItem(&rooms[x][y], &item);
            count++;
        }
        count=0;
        fscanf(fp, "%d%d", &x, &y);
    }
}
