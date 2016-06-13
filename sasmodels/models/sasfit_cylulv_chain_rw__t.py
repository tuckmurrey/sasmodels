r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by cylulv_chain_rw__t

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "cylulv_chain_rw__t"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "N", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_cylulv_chain_rw__t.c" ]

demo = dict(
	N = 10.0)
