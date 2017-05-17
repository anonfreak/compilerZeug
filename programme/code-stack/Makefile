###############################################################################
# Project:  COCKTAIL training
# Descr:    Code generation for an expression language and a stack machine
# Kind:     Makefile
# Author: Dr. Juergen Vollmer <juegren.vollmer@informatik-vollmer.de>
# $Id: Makefile,v 1.3 2007/06/03 16:46:15 vollmer Exp $
###############################################################################

# The executable to produce:
MAIN		= code

# Source files
SRC_C		= main.c
SRC_H		=
SRC		= expr.scan 	\
		  expr.pars 	\
		  expr.ast  	\
		  simplify.puma \
		  stack.puma

# Generated files
GEN_C		= expr_scan.c expr_scanSource.c \
	          expr_pars.c 			\
                  expr_tree.c			\
		  simplify.c			\
		  stack.c

GEN_H		= expr_scan.h  expr_scanSource.h 	    \
	          expr_pars.h 				    \
	          expr_tree.h  yyexpr_tree.h		    \
		  simplify.h   yysimplify.h		    \
		  stack.h      yystack.h

GEN		= expr.rex expr_scan.rpp expr_pars.lrk expr_tree.TS

###############################################################################

include ../config.mk

###############################################################################

# Create your parser
all: $(MAIN)

# Run the test suite
test:
	./$(MAIN) $(TEST_OPTS) test*.prog

###############################################################################

# Create the Parser
expr_pars.lrk expr_scan.rpp: expr.pars
	lpp -cxzj expr.pars

LARK_OPTS = -cdi -Dw -5  # -5 ==> create the graphic LR-browser
LARK_OPTS = -cdi -Dw     #    ==> see ../config.mk
expr_pars.c expr_pars.h : expr_pars.lrk
	lark $(LARK_OPTS) expr_pars.lrk

# Create the Scanner
expr.rex: expr.scan expr_scan.rpp
	rpp < expr.scan expr_scan.rpp > expr.rex

expr_scan.c expr_scan.h expr_scanSource.c expr_scanSource.h: expr.rex
	rex -cdis -y expr.rex
	rm -f expr_scanDrv.c

# Create the Abstract Syntax Tree module
AST_OPTS = -cdi -4wemRk  # ==> see ../config.mk
expr_tree.TS expr_tree.c expr_tree.h yyexpr_tree.h: expr.ast
	ast $(AST_OPTS) expr.ast

# Create simply-transformation
simplify.c simplify.h yysimplify.h: expr_tree.TS simplify$(SOLUTION).puma
	puma -cdif simplify$(SOLUTION).puma

# Create code generation for the stack machine
stack.c stack.h yystack.h: expr_tree.TS 		\
			   simplify$(SOLUTION).puma 	\
			   stack$(SOLUTION).puma
	puma -cdif stack$(SOLUTION).puma

###############################################################################

include ../common.mk

###############################################################################
