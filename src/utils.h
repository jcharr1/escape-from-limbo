/*====================*/
/* Jason Charrier     */
/* 4/25/2001          */
/* CSC 3102           */
/*====================*/
/* Module: utils.h    */
/*========================================================*/
/* Purpose: this module contains prototypes for string    */
/*          utility functions                             */
/*========================================================*/

//#pragma once

#ifndef _UTILS_H_
#define _UTILS_H_

#include "types.h"

boolean ClearStr(char * string, int size);
boolean ReadLine(char * Str, int MaxChars, FILE * stream);
boolean ReadUntil(char * Str, int MaxChars, char Delimiter, FILE *stream);

/*====END OF FILE utils.h====*/

#endif
