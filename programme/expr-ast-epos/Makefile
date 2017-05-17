###############################################################################
# Project:  COCKTAIL training
# Descr:    Build an AST for an expression language, compute end-positions
# Kind:     Makefile
# Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
# $Id: Makefile,v 1.1 2007/06/03 17:38:30 vollmer draft $
###############################################################################

# The executable to produce:
MAIN		= build-ast

# Source files
SRC_C		= main.c
SRC_H		=
SRC		= expr.scan expr.pars expr.ast

# Generated files
GEN_C		= expr_scan.c expr_scanSource.c expr_pars.c \
		  expr_tree.c
GEN_H		= expr_scan.h expr_scanSource.h expr_pars.h \
		  expr_tree.h yyexpr_tree.h
GEN		= expr.rex expr_scan.rpp expr_pars.lrk expr_tree.TS

###############################################################################

include ../config.mk

###############################################################################

# Create your parser
all: $(MAIN)

# Run the test suite
test:
	./$(MAIN) test1

###############################################################################

# Create the Parser
expr_pars.lrk expr_scan.rpp: expr$(SOLUTION).pars
	lpp -cxzj expr$(SOLUTION).pars

LARK_OPTS = -cdi -Dw -5  # -5 ==> create the graphic LR-browser
LARK_OPTS = -cdi -Dw     #    ==> see ../config.mk
expr_pars.c expr_pars.h: expr_pars.lrk
	lark $(LARK_OPTS) expr_pars.lrk

# Create the Scanner
expr.rex:	expr.scan expr_scan.rpp
	rpp < expr.scan expr_scan.rpp > expr.rex

expr_scan.c expr_scan.h expr_scanSource.c expr_scanSource.h: expr.rex
	rex -cdis -y expr.rex
	rm -f expr_scanDrv.c

# Create the Abstract Syntax Tree module
AST_OPTS = -cdi -emRk  # ==> see ../config.mk
expr_tree.TS expr_tree.c expr_tree.h yyextr_tree.h: expr$(SOLUTION).ast
	ast $(AST_OPTS) expr$(SOLUTION).ast

###############################################################################

include ../common.mk

###############################################################################
