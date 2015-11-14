/*====================*/
/* Jason Charrier     */
/* 4/5/2001           */
/* CSC 3102           */
/*====================*/
/* Module: list.h     */
/*========================================================*/
/* Purpose: this module contains the struct declarations  */
/*          and fucntion prototypes for the list          */
/*========================================================*/

/*
	list.h
	Copyright 2000 Nigel Gwee.
	All rights reserved.
 */

/*============*/
/* NOTE       */
/*================================*/
/* Code in this file is based on  */
/* code provided by Dr. Nigel     */
/* Gwee from his CSC 2290 class in*/
/* Spring 2000                    */
/*================================*/

//#pragma once

#ifndef _LIST_H_
#define _LIST_H_

#include "item.h"
#include "types.h"

typedef struct LType * listType;

boolean CreateList ( listType * list ); /* Creates an empty list */
boolean DestroyList ( listType * list ); /* Removes every itemType in the list */
boolean EmptyList ( const listType list ); /* Returns true if the list is empty, false otherwise */
boolean FullList ( const listType list ); /* Returns true if the list is full, false otherwise */
short	NumListItems ( const listType list ); /* Returns the number of itemTypes in the list */
boolean AddListItem ( listType list, itemType * data ); /* Adds a new itemType to the list */
boolean DeleteListItemByIndex ( listType list, short index ); /* Deletes from the list an itemType specified
                                                               by index */
boolean DeleteListItemByKey ( listType list, itemType * data ); /* Deletes itemType whose key matches
                                                                 that given in data
                                                                 */
boolean GetListItemByIndex ( const listType list, short index, itemType * data ); /* Fills in details of
                                                                                   itemType specified by
                                                                                   index ( 0 <= index <= kMaxLen -1 ) */
boolean GetListItemByKey ( const listType list, itemType * data ); /* Gets list itemType whose key matches
                                                                    that given in
                                                                    data */
boolean SetListItemByIndex ( listType list, short index, itemType * data ); /* Modifies details of
                                                                             itemType specified
                                                                             by index ( 0 <= index <= kMaxLen - 1 ) */
boolean SetListItemByKey ( listType list, itemType * data ); /* Modifies list itemType whose key
                                                              matches that given
                                                              in data */
boolean PrintList ( const listType list, FILE * stream ); /* Prints the contents of the list */

boolean ResetListIterator ( listType list );
boolean GetNextListItem ( const listType list, itemType * data );
/*
	End of file list.h  ------------------------------------------------------------------------
 */

#endif
