///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R,  double P0);
double Fq( double q,  double R,  double P0);
double form_volume(  double R,  double P0);
double Iqxy( double qx, double qy, double R, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local R, P0eters/variables
double Iq( double q, double R,  double P0)
{
// insert your code here
    return 0.0;
}
double Fq( double q,  double R,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R,  double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, P0);
}
