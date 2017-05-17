###############################################################################
# Project:  COCKTAIL training
# Descr:    DFA (deterministic finite automaton)
# Kind:     Makefile
# Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
# $Id: Makefile,v 1.5 2013/04/17 12:45:05 vollmer Exp $
###############################################################################

# The executable to produce:
MAIN		= dea

# Source files
SRC_H		=        accept.h state.h
SRC_C		= main.c accept.c state$(SOLUTION).c

###############################################################################

include ../config.mk

###############################################################################

# Create your DEA
all: $(MAIN)

# Run the test suite
test:
	 - ./$(MAIN) n.ne+n
	 - ./$(MAIN) n.n
	 - ./$(MAIN) +n.n

###############################################################################

include ../common.mk

###############################################################################
