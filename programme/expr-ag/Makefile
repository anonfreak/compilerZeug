###############################################################################
# Project:  COCKTAIL training
# Descr:    A simple pocket computer (scanner, parser, evaluator)
# Kind:     Makefile
# Author:   Prof. Dr. Juergen Vollmer <vollmer@dwbw-karlsruhe.de>
# $Id: Makefile,v 1.9 2010/04/26 15:12:34 vollmer Exp $
###############################################################################

# The executable to produce:
MAIN		= expr-ag

# Source files
SRC_C		= main.c
SRC		= expr.scan 	        \
		  expr.pars 		\
		  expr$(SOLUTION).ag 	\

# Generated files
GEN_C		= expr_scan.c expr_scanSource.c expr_pars.c Tree.c           \
	          eval.c
GEN_H		= expr_scan.h expr_scanSource.h expr_pars.h Tree.h yyTree.h  \
		  eval.h
GEN		= expr.rex expr_scan.rpp expr_pars.lrk      Tree.TS

###############################################################################

include ../config.mk

###############################################################################

# Create your parser
all: $(MAIN)

# Run the test suite
test:
	./$(MAIN)   test1; echo
	./$(MAIN)   test2; echo
	./$(MAIN)   test3; echo
	- ./$(MAIN) test4; echo
	./$(MAIN)   test5; echo
	- ./$(MAIN) test6; echo

###############################################################################

# Create the Parser
expr_pars.lrk expr_scan.rpp: expr.pars
	lpp -cxzj  expr.pars

LARK_OPTS = -cdi -Dw -5  # -5 ==> create the graphic LR-browser
LARK_OPTS = -cdi -Dw     #    ==> see ../config.mk
expr_pars.c expr_pars.h: expr_pars.lrk
	lark $(LARK_OPTS) expr_pars.lrk

# Create the Scanner
expr.rex: expr.scan expr_scan.rpp
	rpp < expr.scan expr_scan.rpp > expr.rex

expr_scan.c expr_scan.h expr_scanSource.c expr_scanSource.h: expr.rex
	rex -cdis -y expr.rex
	rm -f expr_scanDrv.c

# Create the Abstract Syntax Tree module
# AST options
# -a generate all except -ceh (default)
# -4 generate tree/graph description in file TREE.TS
# -c generate C    source code
# -d generate header file or definition module
# -i generate implementation part or module
# -w generate text graph writer    WriteTREE
# -R generate list reverser        ReverseTREE, ForallTREE
# -t generate top down  traversal  TraverseTREETD
# -b generate bottom up traversal  TraverseTREEBU
# -k generate graph type checker   CheckTREE
# -q generate text  graph browser  QueryTREE
# -e generate graphic browser      procedure DrawTREE
Tree.TS Tree.c Tree.h yyTree.h: expr.ast expr$(SOLUTION).ag
	ast -cdi -4wemRk expr.ast expr$(SOLUTION).ag

# AG options
# -A generate all, same as -DI (default)
# -D generate header file or definition module
# -I generate implementation part or module
# -0 optimize attribute storage

# -P print dependency relations DP
# -S print dependency relations SNC
# -N print dependency relations DNC
# -O print dependency relations OAG
# -G print attribute instances sorted by declaration order
# -E print attribute instances sorted by evaluation order
# -C print dependencies introduced for total order
#AG_DEBUG = -P # -S -N -O -G -E -C
eval.c eval.h: Tree.TS expr.ast expr$(SOLUTION).ag
	ag -c -DI expr.ast expr$(SOLUTION).ag

###############################################################################

include ../common.mk

###############################################################################
