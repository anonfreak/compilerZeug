###############################################################################
# Project:  COCKTAIL training
# Descr:    A Recursive Decent Parser for expressions
# Kind:     Makefile
# Author:   Prof. Dr. Juergen Vollmer <Juergen.Vollmer@dhbw-karlsruhe.de>
# $Id: Makefile,v 1.16 2014/11/27 08:40:57 vollmer Exp $
###############################################################################

# The executable to produce:
MAIN		= parser

# Source files
SRC_H		= parser.h
SRC_C		= parser$(SOLUTION).c main.c
SRC		= expr.rex

# Generated files
GEN		=
GEN_H		= expr_scan.h expr_scanSource.h
GEN_C		= expr_scan.c expr_scanSource.c

###############################################################################

include ../config.mk

###############################################################################

# Create your parser
all: $(MAIN)

# Run the test suite
test:
	 @for f in test.ok.*; 				\
	  do 						\
	     echo; echo "test $$f";			\
	     if	./$(MAIN) $$f ; 			\
	     then echo "    passed";		 	\
	     else echo "    FAILED";			\
		  exit 1; 				\
	     fi;					\
	  done
	 @for f in test.err.*; 				\
	  do 						\
	     echo; echo "test $$f";			\
	     if	./$(MAIN) $$f ; 			\
	     then echo "     FAILED" ;	 		\
		  exit 1; 				\
	     else echo "     passed";			\
	     fi;					\
	  done

###############################################################################

# Generate the scanner
expr_scan.c: expr.rex
	rex -cdis -y expr.rex
	rm -f expr_scanDrv.c

# These files are generated by REX too:
expr_scan.h: 	   expr_scan.c
expr_scanSource.h: expr_scan.c
expr_scanSource.c: expr_scan.c

###############################################################################

include ../common.mk

###############################################################################
