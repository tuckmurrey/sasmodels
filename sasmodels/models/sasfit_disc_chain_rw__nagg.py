r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by disc_chain_rw__nagg

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "disc_chain_rw__nagg"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "NAGG", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_disc_chain_rw__nagg.c" ]

demo = dict(
	NAGG = 10.0)
