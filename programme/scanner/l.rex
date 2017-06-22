/* Project:  COCKTAIL training
 * Descr:    a simple scanner generated with rex
 * Kind:     REX scanner specification (solution)
 * Author:   Dr. Juergen Vollmer <juergen.vollmer@informatik-vollmer.de>
 * $Id: l.rex.in,v 1.13 2016/11/11 10:38:11 vollmer Exp $
 */

SCANNER l_scan

EXPORT {
/* code to be put into Scanner.h */

# include "Position.h"

/* Token Attributes.
 * For each token with user defined attributes, we need a typedef for the
 * token attributes.
 * The first struct-field must be of type tPosition!
 */
typedef struct {tPosition Pos; char* Value;} tint_const;
typedef struct {tPosition Pos; char* Value;} tstring_const;
typedef struct {tPosition Pos; char* Value;} tidentifier;


/* There is only one "actual" token, during scanning. Therfore
 * we use a UNION of all token-attributes as data type for that unique
 * token-attribute variable.
 * All token (with and without user defined attributes) have one
 * attribute: the source position:
 *     tPosition     Position;
 */
typedef union {
  tPosition     Position;
  tint_const    int_const;
  tstring_const string_const;
  tidentifier	identifier;
} l_scan_tScanAttribute;

/* Tokens are coded as int's, with values >=0
 * The value 0 is reserved for the EofToken, which is defined automatically
 */
# define tok_int_const   	1
# define tok_string_const 	2
# define tok_identifier 	3
} // EXPORT

GLOBAL {
  # include <stdlib.h>
  # include "rString.h"
} // GLOBAL

LOCAL {
 /* user-defined local variables of the generated GetToken routine */
# define MAX_STRING_LEN 2048
char string [MAX_STRING_LEN+1]; int length;
}  // LOCAL

DEFAULT {
  /* What happens if no scanner rule matches the input */
  MessageI ("Illegal character", xxError, l_scan_Attribute.Position, xxCharacter, (char*)l_scan_TokenPtr);
} // DEFAULT

EOF {
  /* What should be done if the end-of-input-file has been reached? */

  /* E.g.: check hat strings and comments are closed. */
  switch (yyStartState) {
  case STD:
    /* ok */
    break;
  case STRING:
    Message ("String not closed", xxError, l_scan_Attribute.Position);
    break;
  default:
    Message ("OOPS: that should not happen!!", xxFatal, l_scan_Attribute.Position);
    break;
  }

  /* implicit: return the EofToken */
} // EOF

/* Nur paar Abkürzungen, damit Regex unten nicht zu lange wird */
DEFINE  /* some abbreviations */
  digit  = {0-9}   .
  letter = {a-z_A-Z}.
  string = - {"\\\n\r\f}.

/* define start states, note STD is defined by default, separate several states by a comma */
/* START STRING */
START STRING

RULE

/*Bezeichner*/
#STD# letter (letter | digit) * :
	{
	  l_scan_Attribute.identifier.Value = malloc (l_scan_TokenLength+1);
	  l_scan_GetWord (l_scan_Attribute.identifier.Value);
	  return tok_identifier;
	}

/* Integers */
#STD# digit+ :
	{l_scan_Attribute.int_const.Value = malloc (l_scan_TokenLength+1);
	 l_scan_GetWord (l_scan_Attribute.int_const.Value);
	 return tok_int_const;
	}	
/* Goes into String state after the start of a string is detected */
#STD# \" :
	{yyStart(STRING);
	 length = 0;
	}
/*Strings*/
#STRING# string* :
	{
	  if (length + l_scan_TokenLength+1 >= MAX_STRING_LEN) {
	    Message ("String too long", xxError, l_scan_Attribute.Position);
	    length = 0;
	  } else {
	    /*Write input to acutal adress of string char array */
	    length += l_scan_GetWord (&string[length]); 
	  }
	}  
/*End of String*/
#STRING# \" :
	{
	  /* Back to start*/
	  yyStart(STD);
	  /*Add zero at the end of string*/
	  string[length] = '\0'; 
	   /*Allocate enough space in memory and pass startadress to const value*/ 
	  l_scan_Attribute.string_const.Value = malloc (length + 1);
	  /*copy real input to const */
	  strcpy (l_scan_Attribute.string_const.Value, string); 
	  return tok_string_const;
	}

#STRING# \\ \" :
	{
	  if (length + l_scan_TokenLength+1 >= MAX_STRING_LEN) {
	    Message ("String too long", xxError, l_scan_Attribute.Position);
	    length = 0;
	  } else {
	    /*Write input to acutal adress of string char array */
	    string[length++] = '"';
	  }
	}
#STRING# \\ n :
	{
	  if (length + l_scan_TokenLength+1 >= MAX_STRING_LEN) {
	    Message ("String too long", xxError, l_scan_Attribute.Position);
	    length = 0;
	  } else {
	    /*Write input to acutal adress of string char array */
	    string[length++] = '\n';
	  }
	}
#STRING# \\ :
	{
	  if (length + l_scan_TokenLength+1 >= MAX_STRING_LEN) {
	    Message ("String too long", xxError, l_scan_Attribute.Position);
	    length = 0;
	  } else {
	    /*Write input to acutal adress of string char array */
	    string[length++] = '\\';
	  }
	}
#STRING# \n :
	{ /* error handling of typical errors:
	   *  a string not closed at the end of a line
           */
          yyStart(STD);
	  yyEol (0);
          Message ("String nicht beendet", xxError, l_scan_Attribute.Position);
	  l_scan_Attribute.string_const.Value = "";
          return tok_string_const;
        }




/* Please add rules for: (don't forget to adapt main()) */
/* Float numbers */

/* case insensitive keywords: BEGIN PROCEDURE END CASE */

/* identifiers */

/* comment up to end of line */

/* C-style comment */

/* Modula2-style nested comment */

/* double quote delimited strings */
/**********************************************************************/
