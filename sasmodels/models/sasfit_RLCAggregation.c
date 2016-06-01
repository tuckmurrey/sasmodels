///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* src/sasfit_ff/sasfit_ff_RLCAggregation.c
*
* Copyright (c) 2008-2009, Paul Scherrer Institute (PSI)
*
* This file is part of SASfit.
*
* SASfit is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* SASfit is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with SASfit.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*   Ingo Bressler (ingo@cs.tu-berlin.de)
*/
double Iq( double q,
	double RG,
	double D,
	double I0)
{
double C[5], SQ;
int i;
C[0] = 1.0;
C[1] = 8./3./D;
C[2] = 3.13;
C[3] = -2.58;
C[4] = 0.95;
SQ = 0.0;
for (i=0; i < 5 ;i++)
{
SQ = SQ+C[i]*pow(q*RG,2.0*i);
}
SQ = pow(SQ, -D/8.);
if (RG == 0)
{
return 1.0;
} else {
return I0*SQ;
}
}
double Iqxy( double qx, double qy,
	double RG,
	double D,
	double I0)
{
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, RG, D, I0);
}