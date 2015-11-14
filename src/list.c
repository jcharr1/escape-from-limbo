/*====================*/
/* Jason Charrier     */
/* 4/5/2001           */
/* CSC 3102           */
/*====================*/
/* Module: list.c     */
/*=================================================*/
/* Purpose: this module contains the function      */
/*          definitions for an implementation of a */
/*          list as a linked list.                 */
/*=================================================*/

/*----INCLUDES----*/
#include "list.h"

/*====the linked list data structures====*/

/*----the linked list node structure----*/
typedef struct listNodeType
{
    itemType data; // the data
    struct listNodeType *next; // pointer to the next node
}listNodeType, *listNodePtrType;

/*----the linked list head structure----*/
typedef struct LType
{
    listNodeType *fFirst,  // pointer to first node
    *fLast,   // pointer to last node
    *fCurrent; // pointer to current node
    
    short fNumItems; // number of items in list
}LType;

/*----PROTOTYPES----*/
void RecursiveListDelete(listNodePtrType nodePtr); // recursively deletes the list
// used by DestroyList

/*======================*/
/* Function: CreateList */
/*=====================================================*/
/* Purpose: this function creates an empty list        */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: list to be created                             */
/*   POST: an empty list is created or displays error  */
/*         message. Returns TRUE if successful or      */
/*         FALSE if not.                               */
/* Processes: set list to empty list                   */
/*=====================================================*/

boolean CreateList(listType *list)
{
    *list = (LType *)malloc(sizeof(LType));     // allocate memory for list
    if(*list == NULL)                   // check if allocated ok
    {
        printf("Unable to create ordered list!\n");
        return(FALSE);
    }
    
    (*list)->fNumItems = 0; // initialize NumItems
    (*list)->fFirst = NULL; // init first pointer
    (*list)->fCurrent = NULL; // initialize Current pointer
    (*list)->fLast = NULL;  // initialize last pointer
    
    return(TRUE);
}
/*====End of CreateList====*/

/*========================*/
/* Function: DestroyList */
/*=====================================================*/
/* Purpose: this function is the nonrecursive shell for*/
/*          RecursiveListDelete                       */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the list to be destroyed                       */
/*   POST: list is destroyed or displays error message */
/*   Processes: remove every item from the list        */
/*=====================================================*/

boolean DestroyList(listType *list)
{
    if((*list) && !EmptyList(*list))       // check for valid list pointer
    {
        RecursiveListDelete((*list)->fFirst);    // recursively remove all data
        (*list)->fNumItems = 0;                   // reset number of items
        return(TRUE);
    }
    else
    {
        /*----display error message----*/
        if(!(*list))
            //printf("Invalid list pointer passsed to DestroyList!\n");
            
            return(FALSE);
    }
    return(TRUE);
}
/*====end of DestroyList====*/

/*================================*/
/* Function: RecursiveListDelete */
/*=====================================================*/
/* Purpose: this function removes every item in list   */
/*          recursively                                */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: list has been declared                         */
/*   POST: list is destroyed. Returns TRUE if          */
/*         successful or FALSE if not                  */
/* Processes: If node exists delete next node          */
/*            Delete current node                      */
/*=====================================================*/

void RecursiveListDelete(listNodePtrType nodePtr)
{
    if(nodePtr)
    {
        RecursiveListDelete(nodePtr->next);
        free(nodePtr);
    }
}

/*===end of RecursiveListDelete====*/

/*======================*/
/* Function: EmptyList  */
/*=====================================================*/
/* Purpose: this function checks if the list is empty  */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: PRE: the list to check if it's empty           */
/*   POST: returns TRUE if empty, FALSE if not. List is*/
/*         not changed                                 */
/* Processes: check if the list is empty               */
/*=====================================================*/

boolean EmptyList(const listType list)
{
    if(!list)       // make sure pointer is valid
    {
        //printf("Invalid list pointer passed to EmptyList!\n");
        return(FALSE);
    }
    
    if(list->fNumItems == 0)
        return(TRUE);
    else
        return(FALSE);
}
/*====End of EmptyList====*/

/*======================*/
/* Function: FullList  */
/*=====================================================*/
/* Purpose: this function checks if the list is full   */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the list to check if it's full                 */
/*   POST: returns TRUE if full, FALSE if not. List is */
/*         not changed                                 */
/* Processes: check if the list is full                */
/*=====================================================*/

boolean FullList(const listType list)
{
    listNodePtrType tempNode;    // used to check memory allocation
    if((tempNode = (listNodeType *)malloc(sizeof(listNodeType))) == NULL) // try to allocate
    {
        return(TRUE);       // allocation failed
    }
    else
    {
        free(tempNode);      // allocation succeeded
        return(FALSE);
    }
    
}
/*====End of FullList====*/

/*=========================*/
/* Function: NumListItems  */
/*=====================================================*/
/* Purpose: this function returns # of items in list   */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: lthe list to get the number of items           */
/*   POST: returns the # of items in the list or error */
/*   message.   List isn't changed                     */
/*  Processes: retrieve and return the # of items in   */
/*  the list.                                          */
/*=====================================================*/

short NumListItems(const listType list)
{
    if(list)
    {
        return(list->fNumItems);
    }
    else
    {
        //printf("Invalid list passed to NumListItems!\n");
        return(0);
    }
}

/*====End of NumListItems====*/

/*NOTE: "End" refers to the position in the list one beyond the item that was added last*/

/*==========================*/
/* Function: AddListItem    */
/*=====================================================*/
/* Purpose: this function adds an item to the list     */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the data to add to the list and the list to add*/
/*      to                                             */
/*   POST: adds the data to the end of the list or     */
/*         error message                               */
/* Processes: Traverse to the end of the list          */
/*            Add the item to the end of the list      */
/*=====================================================*/

boolean AddListItem(listType list, itemType * data)
{
    /*----check to see if list is full----*/
    if(FullList(list))
    {
        return(FALSE);
    }// end of if
    
    /*----list is not full. Add the item----*/
    if(EmptyList(list))
    {
        list->fFirst = (listNodeType *)malloc(sizeof(listNodeType)); // allocate space for node
        list->fLast = list->fFirst;  // first time, first and last node are the same
        list->fCurrent = list->fFirst; // is also the Current node
        list->fFirst->next = NULL;     // init next pointer
        //Copy3(&(list->fFirst->data), data);  // add data to the list
        list->fFirst->data = *data;    // add data to the list
    }
    else
    {
        list->fLast->next = (listNodeType *)malloc(sizeof(listNodeType)); // allocate space
        //Copy3(&(list->fLast->next->data), data);  // add data to end of list
        list->fLast->next->data = *data;          // add data to the end of the list
        list->fLast = list->fLast->next;  // update last pointer
        list->fLast->next = NULL;
    }
    
    ++(list->fNumItems);  // increment NumItems
    
    return(TRUE);
}
/*====End of AddListItem====*/

/*==================================*/
/* Function: DeleteListItemByIndex  */
/*=====================================================*/
/* Purpose: this function deletes the item in the list */
/*          at the specified index                     */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the list to delete from and the index to delete*/
/*   POST: list item is deleted or error messege       */
/*         Returns TRUE if successful, FALSE if not    */
/* Processes: Search for the item to delete            */
/*            Delete the item                          */
/*=====================================================*/

boolean DeleteListItemByIndex(listType list, short index)
{
    
    /*----local variables----*/
    listNodeType *Current,   // pointer to current node
    *Previous;  // pointer to previous node
    
    short i = 0;             // counter variable
    
    Current = list->fFirst;  // initialize Current
    Previous = NULL;         // initialize Previous
    
    /*----check validity of index----*/
    if((index < 0) || (index >= list->fNumItems))
    {
        //printf("Invalid index passed to DeleteListItemByIndex!\n");
        return(FALSE);
    }
    
    for(i = 0; i < index; ++i) // traverse list until get to index
    {
        Previous = Current;
        Current = Current->next;
    }// end of for
    if(Previous)
    {
        Previous->next = Current->next; // set up for relinking
    }
    else
    {
        list->fFirst = Current->next; // reset first pointer
    }
    if(list->fLast == Current)       // node to delete is at the end
    {
        list->fLast = Previous;       // set last to point to new last node after deleting
    }
    if(list->fCurrent == Current)    // fCurrent is pointing to what will be deleted.
    {
        list->fCurrent = Current->next; // it is reset to the next node
    }// end of if
    
    free(Current);          // destroy the node
    --(list->fNumItems);    // decrement NumItems
    return(TRUE);
}
/*====End of DeleteListItemByIndex====*/

/*==================================*/
/* Function: DeleteListItemByKey    */
/*=====================================================*/
/* Purpose: this function deletes the item in the list */
/*          that has the specified key                 */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the list to delete from and the key to search  */
/*      for                                            */
/*   POST: list item is deleted or error message       */
/*         Returns TRUE if successful, FALSE if not    */
/* Processes: Search for list item with the key        */
/*           Delete the item with the key from the list*/
/*=====================================================*/

boolean DeleteListItemByKey(listType list, itemType *data)
{
    
    /*----local variables----*/
    listNodeType *Current, // pointer to current node
    *Previous; // pointer to previous node
    
    boolean Found = FALSE;  // found flag
    
    Previous = NULL;    // initialize previous
    Current = list->fFirst; // initialize current
    
    /*----check if list is empty----*/
    if(EmptyList(list))
    {
        //		printf("The list is empty!\n");
        return(Found);
    }
    
    /*----look for node with matching key----*/
    while(!Found && Current)
    {
        char name1[MAX_NAME_LEN] = {'\0'},
        name2[MAX_NAME_LEN] = {'\0'};
        itemGetName(data, name1);
        itemGetName(&(Current->data), name2);
        //if(KeysAreEqual3(data, &(Current->data)))
#if OS == WIN
        if(stricmp(name1, name2) == 0)
#else
            if(strcasecmp(name1, name2) == 0)
#endif
            {
                Found = TRUE; // node found
            }
            else 	// traverse list until key found
            {
                Previous = Current;
                Current = Current->next;
            }// end of if
    }// end of while
    
    if(Found)
    {
        if(Previous)
        {
            Previous->next = Current->next;      //setup for
            // relink
        }
        else
        {
            list->fFirst = Current->next; // update 1st
            // pointer
        }// end of if
        if(list->fLast == Current) // delete last node
        {
            list->fLast = Previous; // reset last pointer
        }// end of if
        if(list->fCurrent == Current) // current will be
            // deleted
        {
            list->fCurrent = Current->next; // reset
            // fCurrent
        }// end of if
        
        free(Current);  // destroy the node
        --(list->fNumItems); // decrement NumItems
    }// end of if
    else
    {
        printf("The item with the specified key was not found!\n");
    }
    
    return(Found);
}
/*====End of DeleteListItemByKey ====*/

/*==================================*/
/* Function: GetListItemByIndex     */
/*=====================================================*/
/* Purpose: this function reads the item in the list   */
/*          with the specified index into data         */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the list to retrieve from, the index of the    */
/*      data, and a container to hold the data         */
/*      from the list                                  */
/*   POST: list item is read into data or error message*/
/*         Returns TRUE if successful, FALSE if not    */
/* Processes: Advance to the position denoted by index */
/*            Read data at that position into the data */
/*               container                             */
/*=====================================================*/

boolean GetListItemByIndex(const listType list, short index, itemType *data)
{
    /*----local variables----*/
    listNodeType *Current,   // pointer to current node
    *Previous;  // pointer to previous node
    
    short j = 0;
    
    Current = list->fFirst;  // initialize Current
    Previous = NULL;         // initialize Previous
    
    /*----check to see if list is empty----*/
    if(EmptyList(list))
    {
        //    printf("The list is empty!\n");
        return(FALSE);
    }// end of if
    
    /*----check validity of index----*/
    if((index >= list->fNumItems) || (index < 0))
    {
        //printf("Invalid index passed to GetListItemByIndex!\n");
        return(FALSE);
    }// end of if
    
    for(j = 0; j < index; ++j) // traverse list until get to index
    {
        Previous = Current;
        Current = Current->next;
    }// end of for
    
    //Copy3(data, &(Current->data)); // copy data from list to data
    *data = Current->data;
    return(TRUE);
}
/*====End of GetListItemByIndex====*/

/*==================================*/
/* Function: GetListItemByKey       */
/*=====================================================*/
/* Purpose: this function reads the item in the list   */
/*          with the specified key into data           */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the list to read from, and a container for the */
/*      data that contains the key to search for       */
/*   POST: list item is read into data or error message*/
/*         Returns TRUE if successful, FALSE if not    */
/* Processes: Search the list for the item with the key*/
/*            Read the data into the container         */
/*=====================================================*/

boolean GetListItemByKey(const listType list, itemType *data)
{
    
    /*----local variables----*/
    listNodeType *Current, // pointer to current node
    *Previous; // pointer to previous node
    
    boolean Found = FALSE;  // found flag
    
    Previous = NULL;    // initialize previous
    Current = list->fFirst; // initialize current
    
    /*----check if list is empty----*/
    if(EmptyList(list))
    {
        //      printf("The list is empty!\n");
        return(Found);
    }
    
    /*----look for node with matching key----*/
    while(!Found && Current)
    {
        char name1[MAX_NAME_LEN] = {'\0'},
        name2[MAX_NAME_LEN] = {'\0'};
        itemGetName(data, name1);
        itemGetName(&(Current->data), name2);
        //if(KeysAreEqual3(data, &(Current->data)))
#if OS == WIN
        if(stricmp(name1, name2) == 0)
#else
            if(strcasecmp(name1, name2) == 0)
#endif
            {
                Found = TRUE; // node found
            }
            else 	// traverse list until key found
            {
                Previous = Current;
                Current = Current->next;
            }// end of if
    }// end of while
    
    if(Found)
    {
        //Copy3(data, &(Current->data)); // copy data from
        // list to data
        *data = Current->data;
    }
    else
    {
        //      printf("The data with the specified key was not found!\n");
    }
    
    return(Found);
}
/*====End of GetListItemByKey====*/

/*==================================*/
/* Function: SetListItemByIndex       */
/*=====================================================*/
/* Purpose: this function sets the item in the list    */
/*          with the specified index to the passed     */
/*          data container                             */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the list to write to, the index of the item to */
/*      set, and the data container containing the new */
/*      data.                                          */
/*   POST: list item is set or error message. Data     */
/*         container is unchanged                      */
/*         Returns TRUE if successful, FALSE if not    */
/* Processes: Advance to the position denoted by index */
/*            Write new data into the list             */
/*=====================================================*/

boolean SetListItemByIndex(listType list, short index, itemType *data)
{
    
    /*----local variables----*/
    listNodeType *Current,   // pointer to current node
    *Previous;  // pointer to previous node
    
    short j = 0;
    
    Current = list->fFirst;  // initialize Current
    Previous = NULL;         // initialize Previous
    
    /*----check to see if list is empty----*/
    if(EmptyList(list))
    {
        //      printf("The list is empty!\n");
        return(FALSE);
    }// end of if
    
    /*----check validity of index----*/
    if((index >= list->fNumItems) || (index < 0))
    {
        //printf("Invalid index passed to SetListItemByIndex!\n");
        return(FALSE);
    }// end of if
    
    for(j = 0; j < index; ++j) // traverse list until get to index
    {
        Previous = Current;
        Current = Current->next;
    }// end of for
    
    //Copy3(&(Current->data), data); // copy data from data to list
    Current->data = *data;
    return(TRUE);
}
/*====End of SetListItemByIndex====*/

/*==================================*/
/* Function: SetListItemByKey      */
/*=====================================================*/
/* Purpose: this function sets the item in the list    */
/*          with the specified key to the passed       */
/*          data container                             */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the list to write to, and the data container   */
/*      containing the key and the new data.           */
/*   POST: list item is set or error message. Data     */
/*         container is unchanged                      */
/*         Returns TRUE if successful, FALSE if not    */
/* Processes: Search for item with specified key       */
/*            Write new data into the list             */
/*=====================================================*/

boolean SetListItemByKey(listType list, itemType *data)
{
    
    /*----local variables----*/
    listNodeType *Current, // pointer to current node
    *Previous; // pointer to previous node
    
    boolean Found = FALSE;  // found flag
    
    Previous = NULL;    // initialize previous
    Current = list->fFirst; // initialize current
    
    /*----check if list is empty----*/
    if(EmptyList(list))
    {
        //		printf("The list is empty!\n");
        return(Found);
    }
    
    /*----look for node with matching key----*/
    while(!Found && Current)
    {
        char name1[MAX_NAME_LEN] = {'\0'},
        name2[MAX_NAME_LEN] = {'\0'};
        itemGetName(data, name1);
        itemGetName(&(Current->data), name2);
        //if(KeysAreEqual3(data, &(Current->data)))
#if OS == WIN
        if(stricmp(name1, name2) == 0)
#else
            if(strcasecmp(name1, name2) == 0)
#endif
            {
                Found = TRUE; // node found
            }
            else 	// traverse list until key found
            {
                Previous = Current;
                Current = Current->next;
            }// end of if
    }// end of while
    
    if(Found)
    {
        //Copy3(&(Current->data), data); // copy data from
        // data to list
        Current->data = *data;
    }
    else
    {
        printf("The data with the specified key was not found!\n");
    }
    
    
    return(Found);
}
/*====End of SetListItemByKey====*/

/*==================================*/
/* Function: ResetListIterator      */
/*=====================================================*/
/* Purpose: this function sets the list iterator to    */
/*          point to the first item in the list        */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: list has been declared                         */
/*   POST: list iterator is reset                      */
/*         Returns TRUE if successful, FALSE if not    */
/*=====================================================*/

boolean ResetListIterator(listType list)
{
    list->fCurrent = list->fFirst;  // reset the iterator
    return(TRUE);
}
/*====End of ResetListIterator====*/

/*==================================*/
/* Function: GetNextListItem        */
/*=====================================================*/
/* Purpose: this function reads the next item in the   */
/*          list into data                             */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: list and data have been declared               */
/*   POST: next list item is read into data            */
/*         Returns TRUE if successful, FALSE if not    */
/*=====================================================*/

boolean GetNextListItem(const listType list, itemType *data)
{
    if(list->fCurrent != NULL)
    {
        //Copy3(data, &(list->fCurrent->data)); // copy next 
        // item to 
        // data
        *data = list->fCurrent->data;
        list->fCurrent = list->fCurrent->next; // update Current
        return(TRUE);
    }// end of if
    else
    {
        return(FALSE);
    }// end of if
}
/*====End of GetNextListItem====*/

/*===============END OF FILE list.c=================*/
