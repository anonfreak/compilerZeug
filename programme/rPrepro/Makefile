##############################################################################
## Project:	Cocktail Reuse Library
## Descr:	Support for tools built by CoCoLab
## Author:	Dr. Juergen Vollmer <vollmer@cocolab.de>
## Makefile,v 1.1 2001/04/05 13:11:37 vollmer draft
##############################################################################

SRC_H	=
SRC_C	= rPrepro.c
SRC	= rPrepro.scan rPrepro.pars $(SRC_H) $(SRC_C) Makefile

GEN_H	= rPrepro_scan.h rPrepro_pars.h rPrepro_scanSource.h
GEN_C	= rPrepro_scan.c rPrepro_pars.c rPrepro_scanSource.c
GEN	= rPrepro.rex rPrepro_scan.rpp rPrepro_pars.lrk

MAIN	= rPrepro

###################################################
include ../config.mk
###################################################

CFLAGS = -UYYDEBUG

# Create your parser
all: $(MAIN)

rPrepro_pars.lrk rPrepro_scan.rpp: rPrepro.pars
	lpp -cxzjW rPrepro.pars

rPrepro_pars.c rPrepro_pars.h:   rPrepro_pars.lrk
	lark -scdiw rPrepro_pars.lrk

rPrepro.rex: rPrepro.scan rPrepro_scan.rpp
	rpp < rPrepro.scan rPrepro_scan.rpp > rPrepro.rex

rPrepro_scan.h: rPrepro_scan.c
rPrepro_scan.c rPrepro_scanSource.c rPrepro_scanSource.h: rPrepro.rex
	@echo expect two warnings
	rex -cdis rPrepro.rex
	rm -f rPrepro_scanDrv.c

###############################################################################
include ../common.mk
###############################################################################
