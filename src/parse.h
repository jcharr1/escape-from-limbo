//#pragma once

#ifndef _PARSE_H_
#define _PARSE_H_

#include "room.h"
#include "switch.h"
#include "utils.h"

boolean Check_Parse(char *strVerb, char *strObject);
boolean Check_Verb(char * string, boolean *moveChk);
boolean Check_Object(char * string);

#endif
