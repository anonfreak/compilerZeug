###############################################################################
# Project:  COCKTAIL training
# Descr:    AST implemented in JAVA
# Kind:     Makefile
# Author:   Prof. Dr. Juergen Vollmer <vollmer@dhbw-karlsruhe.de>
# $Id: Makefile,v 1.6 2015/03/31 14:57:07 vollmer Exp $
###############################################################################

J_MAIN	= Main$(SOLUTION)

###############################################################################

include ../config.mk

SOLUTION_SUFFIX = Solution

# ACHTUNG:  java-1_7_0-openjdk-devel  muss installiert sein!!

CLASSES		= BinaryExpr EXPR IntConst UnaryExpr CondExpr EXPRS Exprs NoExprs Main
SRC		= $(addsuffix $(SOLUTION).java,  $(CLASSES))
JAVA_OBJS	= $(addsuffix $(SOLUTION).class, $(CLASSES))

###############################################################################

# Create your parser
all: $(J_MAIN)

$(J_MAIN): $(JAVA_OBJS)
	echo "#!/bin/sh"      >  $(J_MAIN)
	echo "java $(J_MAIN)" >> $(J_MAIN)
	chmod a+x $(J_MAIN)

test:	$(J_MAIN)
	$(J_MAIN)

clean::
	rm -f Main MainSolution *~ $(JAVA_OBJS)

###############################################################################

include ../common.mk

###############################################################################
