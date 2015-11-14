/*====================*/
/* Vincent Nguyen     */
/* 4/5/2001           */
/* CSC 3102           */
/*====================*/
/* Module: parse.c    */
/*========================================================*/
/* Purpose: this module contains the fucntion definitions */
 /*          for the parse ADT                             */
/*========================================================*/

#include "types.h"
#include "globals.h"
#include "parse.h"


/* Operation: Check_Parse(string)
 Input: string to be checked
 Output: returns if player quit
 Processing: if string is found in list
 return true
 else give error message and return false
 */
boolean Check_Parse(char *strVerb, char *strObject){
    
    boolean moveChk = FALSE;
    //   char *title = (char *) malloc (sizeof(char));
    
    //   rmGetTitle( &rooms[player.fx][player.fx], title);
    
    //   puts(title);
    
    printf("\n\n||Enter command >> ");
    //gets(strVerb);
    scanf("%s", strVerb);
    
    if ( Check_Verb(strVerb, &moveChk) ){
        
        /*
         <JKC> Added case insensative comparisions. Added OS checks
         to see what str compare to use. Changed the way the input is read in
         so that the command and target obj don't have to be entered seperately
         </JKC>
         */
#if OS == WIN
        if ( stricmp(strVerb,"quit")!=0 )
#else
            if ( strcasecmp(strVerb,"quit")!=0 )
#endif
            {
                // get string for object only if it is valid with the command
                if ( Check_Object(strVerb) ){
                    //            if ( moveChk )
                    //               printf("\n   ||Enter in direction >> ");
                    //            else
                    //               printf("\n   ||Enter in object >> ");
                    //            gets(strObject);
                    ClearStr(strObject, MAX_NAME_LEN);
                    ReadLine(strObject, MAX_NAME_LEN, stdin);
                    
                }
            }
            else return TRUE;
    }
    return FALSE;
}


/* Operation: Check_Verb(string)
 Input: string to be checked
 Output: if string is found in command list
 Processing: if string is found in list
 return true
 else give error message and return false
 */
boolean Check_Verb(char * strVerb, boolean *moveChk){
    
    /*
     <JKC> See above function's notes
     Added "shortcut" keys
     </JKC>
     */
    
#if OS == WIN
    if ( stricmp(strVerb,"move") == 0 ){
        *moveChk = TRUE;
        return TRUE;
    }
    else if ( stricmp(strVerb,"n") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"s") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"e") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"w") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"north") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"south") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"east") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"west") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"unlock") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"switch") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"look") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"inv") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"eat") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"drop") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"get") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"hit") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"kick") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"health") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"quit") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"jump") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"sleep") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"map") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"drink") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"throw") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"status") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"i") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"l") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"use") == 0 ){
        return TRUE;
    }
    else{
        printf("\nDunno how to %s",strVerb);
        return FALSE;
    }
#else
    if ( strcasecmp(strVerb,"move") == 0 ){
        *moveChk = TRUE;
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"n") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"s") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"e") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"w") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"north") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"south") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"east") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"west") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"unlock") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"switch") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"look") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"inv") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"eat") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"drop") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"get") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"hit") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"kick") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"health") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"quit") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"jump") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"sleep") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"map") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"drink") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"throw") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"status") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"i") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"l") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"use") == 0 ){
        return TRUE;
    }
    else{
        printf("\nDunno how to %s",strVerb);
        return FALSE;
    }
#endif
    
    return FALSE;
}



/* Operation: Check_Object(string)
 Input: string to be checked
 Output: true or false whether verb needs an object
 Processing: if string is found in list
 return true
 else give error message and return false
 */
boolean Check_Object( char *strVerb ){
    
    /*
     <JKC> See above function's notes
     </JKC>
     */
    
#if OS == WIN
    if ( stricmp(strVerb,"move") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"use") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"eat") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"drink") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"drop") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"get") == 0 ){
        return TRUE;
    }
    else if ( stricmp(strVerb,"throw") == 0 ){
        return TRUE;
    }
#else
    if ( strcasecmp(strVerb,"move") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"use") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"eat") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"drink") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"drop") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"get") == 0 ){
        return TRUE;
    }
    else if ( strcasecmp(strVerb,"throw") == 0 ){
        return TRUE;
    }
#endif
    
    return FALSE;
}
