/*====================*/
/* Jason Charrier     */
/* 4/25/2001          */
/* CSC 3102           */
/*====================*/
/* Module: utils.c    */
/*========================================================*/
/* Purpose: this module contains definitions for string   */
/*          utility functions                             */
/*========================================================*/

#include "utils.h"

/*==============================*/
/* Name: ClearStr(string, size) */
/*=====================================================*/
/* Purpose: this operation sets a string to all \0     */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the the string to clear and size of the string */
/*   POST: the string is cleared or displays error     */
/*         message. Returns TRUE if successful or      */
/*         FALSE if not.                               */
/* Processes: If string and size are valid, clear the  */
/*               string                                */
/*			     Else display error message               */
/*=====================================================*/

/*
 
 NOTE: there is a bug in this function that sometimes causes a struct
 to be set to NULL if it's used with a struct. PLEASE DO
 NOT USE THIS FUNCTION WITH STRING INSIDE YOUR STRUCTS!!!
 */

boolean ClearStr(char * string, int size)
{
    /*----Local variables----*/
    short i = 0;         // counter
    
    /*----check string pointer and size----*/
    if(!string)
    {
        //fprintf(stderr, "Invalid string passed to ClearStr!\n");
        return(FALSE);
    }
    
    if(size <=0)
    {
        //fprintf(stderr, "Invalid string size passed to Clear Str! Size must be > 0!\n");
        return(FALSE);
    }
    
    /*----clear out the string----*/
    for(i = 0; i < size; i++)
        string[i] = '\0';
    
    return(TRUE);
}

/*==========================================*/
/* Name: ReadLine(string, maxchars, input)  */
/*=====================================================*/
/* Purpose: this operation reads a line of data into   */
/*          string                                     */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the the string to read into, the max # of chars*/
/*      to read, and where to get the input            */
/* POST: the data in read into the string or displays error*/
/*         message. Returns TRUE if successful or      */
/*         FALSE if not.                               */
/* Processes: If string, maxchars, input aren't valid, */
/*               display error message                 */
/*			     Else read in the line until the line ends*/
/*               or until maxchars are read in         */
/*=====================================================*/

boolean ReadLine(char * Str, int MaxChars, FILE * stream)
{
    char temp;
    int i = 0;
    
    if(!Str)
    {
        //fprintf(stderr, "Invalid string passed to ReadLine!\n");
        return(FALSE);
    }
    
    if(MaxChars <= 0)
    {
        fprintf(stderr, "ReadLine: MaxChars must be > 0!\n");
        return(FALSE);
    }
    
    if(!stream)
    {
        //fprintf(stderr, "Invalid stream passed to ReadLine!\n");
        return(FALSE);
    }
    
    temp = getc(stream);
    
    while((temp == ' ') || (temp == '\t') || (temp == '\n'))
        temp = getc(stream);
    
    while((temp != EOF) && (temp != '\n') && (i < MaxChars))
    {
        Str[i] = temp;
        ++i;
        temp = getc(stream);
    }
    
    //   --i;
    
    //   for(; i < MaxChars; i++)
    //      Str[i] = '\0';
    
    return(TRUE);
}

/*=====================================================*/
/* Name: ReadUntil(string, maxchars, delimiter, input) */
/*=====================================================*/
/* Purpose: this operation reads a data into a string  */
/*          until it either it reads in the max # of   */
/*          of chars given, it reads in the delimiter, */
/*          or reaches the end of the input            */
/*=====================================================*/
/* Conditions:                                         */
/*	PRE: the the string to read into, the max # of chars*/
/*      to read, the delimiter to stop at and where to */
/*      get the input                                 */
/* POST: the data in read into the string or displays error*/
/*         message. Returns TRUE if successful or      */
/*         FALSE if not. If the delimiter is read, it's*/
/*         NOT put into the string                     */
 /* Processes: If string, maxchars, input aren't valid, */
/*               display error message                 */
/*			     Else read in the line until the input ends,*/
/*               until maxchars are read in, or the    */
/*               delimiter is read in                  */
/*=====================================================*/

boolean ReadUntil(char * Str, int MaxChars, char Delimiter, FILE *stream)
{
    char temp;
    int i = 0;
    
    if(!Str)
    {
        //fprintf(stderr, "Invalid string passed to ReadUntil!\n");
        return(FALSE);
    }
    
    if(MaxChars <= 0)
    {
        fprintf(stderr, "ReadUntil: MaxChars must be > 0!\n");
        return(FALSE);
    }
    
    if(!stream)
    {
        //fprintf(stderr, "Invalid stream passed to ReadUntil!\n");
        return(FALSE);
    }
    
    temp = getc(stream);
    
    while((temp != EOF) && (temp != Delimiter) && (i < MaxChars))
    {
        Str[i] = temp;
        ++i;
        temp = getc(stream);
    }
    
    for(; i < MaxChars; i++)
        Str[i] = '\0';
    
    return(TRUE);
}

/*====END OF FILE utils.c====*/
