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
} l_scan_tScanAttribute;

/* Tokens are coded as int's, with values >=0
 * The value 0 is reserved for the EofToken, which is defined automatically
 */
# define tok_int_const    1
} // EXPORT

GLOBAL {
  # include <stdlib.h>
  # include "rString.h"
} // GLOBAL

LOCAL {
 /* user-defined local variables of the generated GetToken routine */
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
  default:
    Message ("OOPS: that should not happen!!", xxFatal, l_scan_Attribute.Position);
    break;
  }

  /* implicit: return the EofToken */
} // EOF

DEFINE  /* some abbreviations */
  digit  = {0-9}       .

/* define start states, note STD is defined by default, separate several states by a comma */
/* START STRING */

RULE

/* Integers */
#STD# digit+ :
	{l_scan_Attribute.int_const.Value = malloc (l_scan_TokenLength+1);
	 l_scan_GetWord (l_scan_Attribute.int_const.Value);
	 return tok_int_const;
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
