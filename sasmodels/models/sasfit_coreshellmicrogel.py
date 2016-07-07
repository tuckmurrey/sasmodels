r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by coreshellmicrogel

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "coreshellmicrogel"
title = " "
description = ""
category = "shape-independent"
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "W_CORE", 	"", 	10.0, 	[-inf, inf], 	"volume", 	""],
 [ "SIGMA_CORE", 	"", 	3.0, 	[-inf, inf], 	"volume", 	""],
 [ "W_SH", 	"", 	4.0, 	[-inf, inf], 	"volume", 	""],
 [ "SIGMA_SHIN", 	"", 	3.0, 	[-inf, inf], 	"volume", 	""],
 [ "D", 	"", 	3.0, 	[-inf, inf], 	"volume", 	""],
 [ "SIGMA_OUT", 	"", 	4.0, 	[-inf, inf], 	"volume", 	""],
 [ "ETA_CORE", 	"", 	3.5, 	[-inf, inf], 	"", 	""],
 [ "ETA_SHELL", 	"", 	2.5, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_coreshellmicrogel.c" ]

demo = dict(
	W_CORE = 10.0,
	SIGMA_CORE = 3.0,
	W_SH = 4.0,
	SIGMA_SHIN = 3.0,
	D = 3.0,
	SIGMA_OUT = 4.0,
	ETA_CORE = 3.5,
	ETA_SHELL = 2.5,
	ETA_SOL = 1.0,
	P0 = 0.0)
