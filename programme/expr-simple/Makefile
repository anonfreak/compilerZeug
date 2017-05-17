###############################################################################
# Project:  COCKTAIL training
# Descr:    simple expr-parser and calculator using scanf etc.
# Kind:     Makefile
# Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
# $Id: Makefile,v 1.1 2014/04/01 13:17:00 vollmer Exp vollmer $
###############################################################################

# The executable to produce:
MAIN		= se

# Source files
SRC_H		=
SRC_C		= main$(SOLUTION).c

###############################################################################

include ../config.mk

###############################################################################

# Create your DEA
all: $(MAIN)

# Run the test suite
test:
	 - ./$(MAIN) 1 + 2
	 - ./$(MAIN) 11+22+33
	 - ./$(MAIN) foo

###############################################################################

include ../common.mk

###############################################################################
