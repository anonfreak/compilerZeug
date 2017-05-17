###############################################################################
# Project:  COCKTAIL training
# Descr:    Aufbau AST in C
# Kind:     Makefile
# Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
# $Id: Makefile,v 1.1 2010/04/26 16:39:23 vollmer draft $
###############################################################################

# The executable to produce:
MAIN		= main

# Source files
SRC_H		=                   tree$(SOLUTION).h write$(SOLUTION).h eval$(SOLUTION).h
SRC_C		= main$(SOLUTION).c tree$(SOLUTION).c write$(SOLUTION).c eval$(SOLUTION).c

###############################################################################

include ../config.mk

###############################################################################

all: $(MAIN)

# Run the test suite
test:
	 - ./$(MAIN)

###############################################################################

include ../common.mk

###############################################################################

