#@ line 1
/* Project:  COCKTAIL training
 * Descr:    LR parser for an expression language
 * Kind:     Scanner specification
 * Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
 * $Id: expr.scan,v 1.1 2007/06/01 11:37:53 vollmer draft $
 */

SCANNER expr_scan

EXPORT {
/* code to be put intp Scanner.h */
# include "Position.h"

/* Token Attributes.
 * For each token with user defined attributes, we need a typedef for the
 * token attributes.
 * LPP extracts the token-attribute declaration from the parser specification.
 * They are inserted here.
 */

#@ line 23
# ifndef CommonScanAttrs
# define CommonScanAttrs
# endif

# define zzCommonScanAttrs tPosition Position; CommonScanAttrs

typedef struct { zzCommonScanAttrs long Value; } zz_expr_scan_int_const;
typedef struct { zzCommonScanAttrs double Value; } zz_expr_scan_float_const;

typedef union {
tPosition Position;
struct { zzCommonScanAttrs } Common;
zz_expr_scan_int_const int_const;
zz_expr_scan_float_const float_const;
} expr_scan_tScanAttribute;

# undef zzCommonScanAttrs

extern void expr_scan_ErrorAttribute ARGS((int Token, expr_scan_tScanAttribute * pAttribute));
#@ line 20

}

GLOBAL {
/* code to be put into Scanner.c */
# include <stdlib.h>
# include "Errors.h"

/* Insert the routine computing "error-values" of attributes, in case the
 * parser decides during error repair to insert a token.
 */

#@ line 56
void expr_scan_ErrorAttribute
# ifdef HAVE_ARGS
 (int Token, expr_scan_tScanAttribute * pAttribute)
# else
 (Token, pAttribute) int Token; expr_scan_tScanAttribute * pAttribute;
# endif
{
 pAttribute->Position = expr_scan_Attribute.Position;
 switch (Token) {
 case /* int_const */ 1: 
pAttribute->int_const.Value = 0;
   break;
 case /* float_const */ 2: 
pAttribute->float_const.Value = 0.0;
 break;
 }
}
#@ line 31

}

LOCAL {
/* user-defined local variables of the generated GetToken routine */
# define MAX_STRING_LEN 2048
char string[MAX_STRING_LEN];
int nesting = 0;
int length = 0;
}

DEFAULT {
  /* What happens if no scanner rule matches the input */
  MessageI ("Illegal character",
	    xxError, expr_scan_Attribute.Position,
	    xxCharacter, expr_scan_TokenPtr);
}

EOF {
  /* What should be done if the end-of-input-file has been reached? */

  /* E.g.: check hat strings and comments are closed. */
  switch (yyStartState) {
  case STD:
    /* ok */
    break;
  case COMMENT:
    Message ("unclosed C-comment",
	     xxError, expr_scan_Attribute.Position);
    break;
  case COMMENT2:
    Message ("unclosed Modula-comment",
	     xxError, expr_scan_Attribute.Position);
    break;
  default:
    Message ("OOPS: that should not happen!!",
	     xxFatal, expr_scan_Attribute.Position);
    break;
  }

  /* implicit: return the EofToken */
}

DEFINE /* some abbreviations */
  digit  = {0-9}       .
  letter = {a-z_A-Z}.
  string = - {"\\\n\r\f}.

/* define start states, note STD is defined by default */
START COMMENT, COMMENT2, STRING

RULES

/* Integers */
#STD# {0-9}+ :
	{expr_scan_GetWord (string);
	 expr_scan_Attribute.int_const.Value = atol (string);
	 return 1;
	}

/* Float numbers */
#STD# digit + "." digit * (("E"|"e") ("+"|"-") ? digit +) ? :
	{expr_scan_GetWord (string);
	 expr_scan_Attribute.float_const.Value = atof (string);
	 return 2;
	}

#STD# < "--" ANY * > :
        { /* comment up to end of line, nothing to do */
        }

/* C-style comment */
#STD# "/*" :
	{ /**/
	  yyStart (COMMENT);
	}

#COMMENT# - {*\n\t} + | "*" :
        {}

#COMMENT# "*/" :
        {yyStart (STD);
	}

/* Modula2-style nested comment */
#STD,COMMENT2# "(*" :
	{ yyStart (COMMENT2);
	  nesting ++;
	}

#COMMENT2# - {*(\n\t} + | "*" | "(" :
        {}

#COMMENT2# "*)" :
        { nesting --;
	  if (nesting == 0) {
	    yyStart (STD);
	  }
	}


#@ line 176
 #STD#\,	: { return 3; }
 #STD#\+	: { return 4; }
 #STD#\-	: { return 5; }
 #STD#\*	: { return 6; }
 #STD#\/	: { return 7; }
 #STD#\^	: { return 8; }
 #STD#\(	: { return 9; }
 #STD#\)	: { return 10; }
#@ line 132

/* Bezeichner */
#STD# letter (letter | digit) * :
	{
	  return identifier;
	}

/* Goes into String state after the start of a string is detected */
#STD# \" :
	{
	  yyStart(STRING);
	  length = 0;
	}
/*Strings*/
#STRING# string* :
	{
	  if (length + expr_scan_TokenLength+1 >= MAX_STRING_LEN) {
	    Message ("String too long", xxError, expr_scan_Attribute.Position);
	    length = 0;
	  } else {
	    /*Write input to acutal adress of string char array */
	    length += expr_scan_GetWord (&string[length]); 
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
	  expr_scan_Attribute.string_const.Value = malloc (length + 1);
	  /*copy real input to const */
	  strcpy (expr_scan_Attribute.string_const.Value, string); 
	  return string_const;
	}

#STRING# \\ \" :
	{
	  if (length + expr_scan_TokenLength+1 >= MAX_STRING_LEN) {
	    Message ("String too long", xxError, expr_scan_Attribute.Position);
	    length = 0;
	  } else {
	    /*Write input to acutal adress of string char array */
	    string[length++] = '"';
	  }
	}
#STRING# \\ n :
	{
	  if (length + expr_scan_TokenLength+1 >= MAX_STRING_LEN) {
	    Message ("String too long", xxError, expr_scan_Attribute.Position);
	    length = 0;
	  } else {
	    /*Write input to acutal adress of string char array */
	    string[length++] = '\n';
	  }
	}
#STRING# \\ :
	{
	  if (length + expr_scan_TokenLength+1 >= MAX_STRING_LEN) {
	    Message ("String too long", xxError, expr_scan_Attribute.Position);
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
          Message ("String nicht beendet", xxError, expr_scan_Attribute.Position);
	  expr_scan_Attribute.string_const.Value = "";
          return string_const;
        }

/**********************************************************************/
