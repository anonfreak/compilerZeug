###############################################################################
# Project:  COCKTAIL training
# Descr:    Using MAKE
# Kind:     Makefile
# Author:   Dr. Juergen Vollmer <Juergen.Vollmer@informatik-vollmer.de>
# $Id: Makefile,v 1.11 2009/04/21 08:54:51 vollmer Exp $
###############################################################################

# The executable to produce:
MAIN		= hello

# Source files
SRC_H		=         hello2.h
SRC_C		= hello.c hello2.c
OBJ		= hello.o hello2.o

# der C-Compiler und seine Flags
CC		= gcc
X_DEBUG		= -g -Wall -pedantic
		# -g:        Debugging des Programms unterstuetzen
		# -Wall:     Gib viele Warnungen aus   GNU-spezifisch
		# -pedantic  Besondes pingelig sein    GNU-spezifisch
	        # -DDEBUG    erlaube benutzerspezifische Debugausgabe
X_CFLAGS	= -ansi $(X_DEBUG) $(CFLAGS)

# Format der Makefile-Regeln

# Zieldatei : Benoetigte Dateien
# <tab>  Kommando, das beschreibt, wie das Ziel erzeugt werden kann

# Ausfuehrung einer Regel:
# 1. Erzeuge zuerst alle "Benotigten Dateien", die auf der rechten Seite des :
#    stehen.
# 2. Das Kommando wird ausgefuehrt, wenn eine der Dateien auf der rechten
#    Seite des : neueren Datums ist wie die Datei auf der linken Seite,
#    oder  wenn es die Datei auf der linken Seit noch nicht gibt.

# Dies ist die 1. Regel im Makefile, ihr Ziel wird berechnet, wenn
# `make' keine Argument angegeben sind.
$(MAIN): $(OBJ)
	$(CC) $(X_CFLAGS) -o $(MAIN) $(OBJ)

# Das folgende wird ausgefuehrt, wenn `make clean' aufgerufen wird.
clean real-clean:
	rm -f $(OBJ) $(MAIN) $(MAIN).exe *~

# "Meta-Regeln" sind verallgemeinerte Makefile-Regeln,
# dazu werden die Dateiendungen betrachtet.
# Das folgende besagt: es Gibt Regeln fuer die Dateisuffixe .c und .o
.SUFFIXES:	.c .o

# "Meta-Regeln"
# $* ist die Variable, die den Dateinamen ohne Dateisuffix (z.B. .c)
# enthaelt.

.c.o:
	$(CC) $(X_CFLAGS) -c $*.c

# Abhaengigkeiten ohne Kommando, bedeuten:
# wenn sich "rechte Seite" aendert, dann muss auch die "linke Seite"
# neu erzeugt werden

# erzeuge Übersetzungsabhängigkeiten
depend: clean
	@ # remove "uninteressting" dependencies
	@ $(CC) $(X_CFLAGS) -MM $(SRC_C) |				\
		sed -e"s|/usr/[^ ]*||g" 				\
	            -e"s|/home/[^ ]*||g" 				\
		    -e'/^[ ]*\\[ ]*$$/d' > .depend

-include .depend

###############################################################################
# wird hier nicht benutzt

mk-sources:

delete-sources:

###############################################################################