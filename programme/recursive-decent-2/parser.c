/* Project:  COCKTAIL training
 * Descr:    A recursive Decent Parser for expressions
 * Kind:     The parser (solution)
 * Author:   Prof. Dr. Juergen Vollmer <juergen.vollmer@dhbw-karlsruhe.de>
 * $Id: parser.c.in,v 1.7 2014/11/27 08:49:30 vollmer Exp $
 */

# include <stdlib.h>
# include <string.h>
# include "expr_scan.h"
# include "parser.h"
# include "Errors.h"
      	/* contains: `Message', `MessageI', `xxFatal', `xxError' */

tToken CurToken;

/******************************************************************************/

static const char* token2string (tToken token)
/* maps token-code to token textual representation */
{
  switch (token) {
  case '+':    return "+";
  case '*':    return "*";
  case '(':    return "(";
  case ')':    return ")";
  case '[':    return "[";
  case ']':    return "]";
  case '.':    return ".";
  case tok_identifier:
    return "identifier";
  case tok_arrow:
    return "->";
  case expr_scan_EofToken:
    return "EOF";
  default:
    /* this should never happen */
    MessageI ("FATAL ERROR: unknown token", xxFatal,
	      expr_scan_Attribute.Position, xxInteger, (char*) &token);
    abort(); /* aborts the program */
  }
}

/*****************************************************************************/

bool match (tToken token)
/* Instead of writing for each token 't' a function 'f_t()', we use 'match (t)'. */
{
# ifdef DEBUG
  printf ("      cur = `%s' expected = `%s'\n", token2string(CurToken), token2string (token));
# endif
  if (CurToken == token) {
    if (CurToken != expr_scan_EofToken) CurToken = expr_scan_GetToken();
    return true;
  } else {
    char msg[255];
    sprintf (msg, "Syntax Error: found: `%s' expected: `%s'",
	     token2string (CurToken), token2string (token));
    Message (msg, xxError, expr_scan_Attribute.Position);
    return false;  /* Syntax Error */
  }
}

/*****************************************************************************
 * Given the following grammar:
 *   E ::= E "+" T   | T 
 *   T ::= T "*" F   | F
 *   F ::= "(" E ")" | D
 *   D ::= D "." identifier | D "[" E "]" | D "->" identifier | identifier
 * Implement a recurisve decent parser.
 ******************************************************************************/

static bool f_T(void);
static bool f_F(void);
static bool f_D(void);

bool f_E (void)
{
  return f_T() || (f_E() && match('+') && f_T());
}

bool f_T (void)
{
  return f_F() || (f_T && match('*') && f_F());
}

bool f_F (void)
{
  return (match('(') && f_E() && match(')')) || f_D();
}

bool f_D (void)
{
  return (f_D() && match('.') && match(tok_identifier)) || (f_D() && match(tok_arrow) && match(tok_identifier)) || match(tok_identifier);
}
/***********************  E  N  D  ***********************************************/
