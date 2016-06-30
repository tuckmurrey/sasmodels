///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double RSHMODE,  double THETA_1,  double R1,
           double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
           double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
           double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
           double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
           double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
           double R_1,  double R_2);
double Fq( double q,  double RSHMODE,  double THETA_1,  double R1,
           double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
           double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
           double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
           double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
           double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
           double R_1,  double R_2);
double form_volume(  double RSHMODE,  double THETA_1,  double R1,
                     double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                     double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                     double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                     double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                     double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                     double R_1,  double R_2);
double Iqxy( double qx, double qy, double RSHMODE, double THETA_1, double R1,
             double THETA_2, double R2, double T_SH, double T_C, double ETA_SH, double ETA_C,
             double ETA_SOL, double _PSI, double SIGMA, double KAPPA, double Q,
             double BIG_THETA_1, double BIG_THETA_2, double DELTA_1, double DELTA_2,
             double D_1, double D_2, double DIF_ETA_SH, double DIF_ETA_C, double GAMMA,
             double _THETA, double _PHI, double PSI, double R_SH, double R_1, double R_2);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// help variables:
double J1xdivx ( double x )
{
    if ( fabs(x) <= 1.0e-4 )
    {
        return 0.5 - sas_pow_2(x)/16.0 + sas_pow_4(x)/384.0-sas_pow_6(
                   x)/18432. + sas_pow_8(x)/1474560.;
    }
    else
    {
        return sas_J1(x)/x;
    }
}
double J1divQQ ( double x,  double RSHMODE,  double THETA_1,  double R1,
                 double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                 double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                 double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                 double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                 double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                 double R_1,  double R_2)
{
    if ( PSI <= 1.0e-3 )
    {
        return x / (4.0*Q*Q) + ( ( sas_pow_3(x)/-16.0 - x/12.0 ) / 2.0*Q*Q + x/
                                 (6.0*Q*Q) ) * PSI*PSI;
    }
    else
    {
        return sas_J1(x*sin(PSI))/(Q*Q*sin(2.0*PSI));
    }
}
/* Note functions with ** in the description need to be integrated over z */
// (1a) Flat-capped sphere of radius R_SH (r in formulae): real part  **
double inner_sphere_real ( double z,  double RSHMODE,  double THETA_1,
                           double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                           double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                           double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                           double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                           double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                           double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u;
    u = Q*sqrt(R_SH*R_SH - z*z)*sin(PSI);
    temp = 2.0*M_PI*DIF_ETA_SH*(R_SH*R_SH - z*z)*J1xdivx(u);
    result = cos(Q*z*cos(PSI))*temp;
    return result;
}
// (1b) Flat-capped sphere of radius R_SH: imaginary part **
double inner_sphere_imag ( double z,  double RSHMODE,  double THETA_1,
                           double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                           double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                           double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                           double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                           double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                           double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u;
    u = Q*sqrt(R_SH*R_SH - z*z)*sin(PSI);
    temp =  2.0*M_PI*DIF_ETA_SH*(R_SH*R_SH - z*z)*J1xdivx(u);
    result = sin(Q*z*cos(PSI))*temp;
    return result;
}
// (2a) Flat-capped sphere of radius R_SH + T_SH (r+tsh in formulae): real part **
double outer_sphere_real ( double z,  double RSHMODE,  double THETA_1,
                           double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                           double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                           double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                           double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                           double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                           double R_SH,  double R_1,  double R_2 )
{
    double radius, temp, result, u;
    radius = R_SH + T_SH;
    u = Q*sqrt(radius*radius-z*z)*sin(PSI);
    temp = 2.0*M_PI*DIF_ETA_SH*(radius*radius - z*z)*J1xdivx(u);
    result = cos(Q*z*cos(PSI))*temp;
    return result;
}
// (2b) Flat-capped sphere of radius R_SH + T_SH (r+tsh in formulae): imaginary part **
double outer_sphere_imag ( double z,  double RSHMODE,  double THETA_1,
                           double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                           double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                           double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                           double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                           double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                           double R_SH,  double R_1,  double R_2 )
{
    double radius, temp, result, u;
    radius = R_SH + T_SH;
    u = Q*sqrt(radius*radius-z*z)*sin(PSI);
    temp = 2.0*M_PI*DIF_ETA_SH*(radius*radius - z*z)*J1xdivx(u);
    result = sin(Q*z*cos(PSI))*temp;
    return result;
}
// (3a) Cylindrical cap (right): real part
double cap_right_real ( double RSHMODE,  double THETA_1,  double R1,
                        double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                        double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                        double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                        double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                        double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                        double R_1,  double R_2 )
{
    double a, b, result, u;
    u = Q*R_SH*sin(THETA_1);
    a = Q*R_SH*cos(THETA_1)*cos(PSI);
    b = Q*(R_SH + T_SH)*cos(BIG_THETA_1)*cos(PSI);
    result = (-1.0)*DIF_ETA_SH*4.0*M_PI*R_SH*sin(THETA_1)*J1divQQ(u, RSHMODE,
             THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA,
             Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2)*(sin(a) - sin(b));
    return result;
//	sasfit_out ( "Other: %lf\n", 0.1e1 / Q * R_SH * sin(THETA_1) / 0.4e1 + ((-pow(Q, 0.3e1) * pow(R_SH, 0.3e1) * pow(sin(THETA_1), 0.3e1) / 0.16e2 - Q * R_SH * sin(THETA_1) / 0.12e2) * pow(Q, -0.2e1) / 0.2e1 + 0.1e1 / Q * R_SH * sin(THETA_1) / 0.6e1) * PSI * PSI );
}
// (3b) Cylindrical cap (right): imaginary part
double cap_right_imag ( double RSHMODE,  double THETA_1,  double R1,
                        double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                        double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                        double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                        double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                        double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                        double R_1,  double R_2 )
{
    double a, b, result, u;
    u = Q*R_SH*sin(THETA_1);
    a = Q*R_SH*cos(THETA_1)*cos(PSI);
    b = Q*(R_SH + T_SH)*cos(BIG_THETA_1)*cos(PSI);
    result = DIF_ETA_SH*4.0*M_PI*R_SH*sin(THETA_1)*J1divQQ(u, RSHMODE, THETA_1, R1,
             THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q,
             BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2)*(cos(a) - cos(b));
    return result;
}
// (4a) Cylindrical cap (left): real part
double cap_left_real ( double RSHMODE,  double THETA_1,  double R1,
                       double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                       double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                       double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                       double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                       double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                       double R_1,  double R_2 )
{
    double a, b, result, u;
    u = Q*R_SH*sin(THETA_2);
    a = (-1.0)*Q*(R_SH+T_SH)*cos(BIG_THETA_2)*cos(PSI);
    b = -(1.0)*Q*R_SH*cos(THETA_2)*cos(PSI);
    result = (-1.0)*DIF_ETA_SH*4.0*M_PI*R_SH*sin(THETA_2)*J1divQQ(u, RSHMODE,
             THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA,
             Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2)*(sin(a) - sin(b));
    return result;
}
// (4b) Cylindrical cap (left): imaginary part
double cap_left_imag ( double RSHMODE,  double THETA_1,  double R1,
                       double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                       double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                       double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                       double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                       double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                       double R_1,  double R_2 )
{
    double a, b, result, u;
    u = Q*R_SH*sin(THETA_2);
    a = (-1.0)*Q*(R_SH+T_SH)*cos(BIG_THETA_2)*cos(PSI);
    b = -(1.0)*Q*R_SH*cos(THETA_2)*cos(PSI);
    result = DIF_ETA_SH*4.0*M_PI*R_SH*sin(THETA_2)*J1divQQ(u, RSHMODE, THETA_1, R1,
             THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q,
             BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2)*(cos(a) - cos(b));
    return result;
}
// (5a) Domain cylindrical cap (right): real part
double dom_cap_right_real ( double RSHMODE,  double THETA_1,  double R1,
                            double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                            double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                            double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                            double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                            double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                            double R_1,  double R_2 )
{
    double a,b,result, u;
    u = Q*R_SH*cos(THETA_1);
    a = Q*((R_SH+T_SH)*cos(BIG_THETA_1) - T_C)*cos(PSI);
    b = Q*(R_SH+T_SH)*cos(BIG_THETA_1)*cos(PSI);
    result = (-1.0)*DIF_ETA_C*4.0*M_PI*R_SH*sin(THETA_1)*J1divQQ(u, RSHMODE,
             THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA,
             Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2)*(sin(a) - sin(b));
    return result;
}
// (5b) Domain cylindrical cap (right): imaginary part
double dom_cap_right_imag ( double RSHMODE,  double THETA_1,  double R1,
                            double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                            double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                            double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                            double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                            double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                            double R_1,  double R_2 )
{
    double a, b, result, u;
    u = Q*R_SH*cos(THETA_1);
    a = Q*((R_SH+T_SH)*cos(BIG_THETA_1) - T_C)*cos(PSI);
    b = Q*(R_SH+T_SH)*cos(BIG_THETA_1)*cos(PSI);
    result = DIF_ETA_C*4.0*M_PI*R_SH*sin(THETA_1)*J1divQQ(u, RSHMODE, THETA_1, R1,
             THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q,
             BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2)*(cos(a) - cos(b));
    return result;
}
// (6a) Domain cylindrical cap (left): real part
double dom_cap_left_real ( double RSHMODE,  double THETA_1,  double R1,
                           double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                           double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                           double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                           double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                           double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                           double R_1,  double R_2 )
{
    double a, b, result, u;
    u = Q*R_SH*cos(THETA_2);
    a = (-1.0)*Q*(R_SH*T_SH)*cos(BIG_THETA_2)*cos(PSI);
    b = (-1.0)*Q*((R_SH+T_SH)*cos(BIG_THETA_2)+T_C)*cos(PSI);
    result = (-1.0)*DIF_ETA_C*4.0*R_SH*sin(THETA_2)*M_PI*J1divQQ(u, RSHMODE,
             THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA,
             Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2)*(sin(a) - sin(b));
    return result;
}
// (6b) Domain cylindrical cap (left): imaginary part
double dom_cap_left_imag ( double RSHMODE,  double THETA_1,  double R1,
                           double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                           double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                           double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                           double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                           double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                           double R_1,  double R_2 )
{
    double a, b, result, u;
    u = Q*R_SH*cos(THETA_2);
    a = (-1.0)*Q*(R_SH*T_SH)*cos(BIG_THETA_2)*cos(PSI);
    b = (-1.0)*Q*((R_SH+T_SH)*cos(BIG_THETA_2)+T_C)*cos(PSI);
    result = DIF_ETA_C*4.0*M_PI*R_SH*sin(THETA_2)*J1divQQ(u, RSHMODE, THETA_1, R1,
             THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q,
             BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2)*(cos(a) - cos(b));
    return result;
}
// (7a) Domain outer curved cap (right): real part **
double outer_curve_right_real ( double z,  double RSHMODE,  double THETA_1,
                                double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                                double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                                double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                                double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                                double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                                double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u, Z;
    Z = fabs(z);
    u = Q*sqrt(R_1*R_1 - (Z-D_1)*(Z-D_1))*sin(PSI);
    temp =  2.0*M_PI*DIF_ETA_C*(R_1*R_1 - (Z-D_1)*(Z-D_1))*J1xdivx(u);
    result = cos(Q*z*cos(PSI))*temp;
    return result;
}
// (7b) Domain outer curved cap (right): imaginary part **
double outer_curve_right_imag ( double z,  double RSHMODE,  double THETA_1,
                                double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                                double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                                double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                                double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                                double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                                double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u, Z;
    Z = fabs(z);
    u = Q*sqrt(R_1*R_1 - (Z-D_1)*(Z-D_1))*sin(PSI);
    temp =  2.0*M_PI*DIF_ETA_C*(R_1*R_1 - (Z-D_1)*(Z-D_1))*J1xdivx(u);
    result = sin(Q*z*cos(PSI))*temp;
    return result;
}
// (8a) Domain outer curved cap (left): real part **
double outer_curve_left_real ( double z,  double RSHMODE,  double THETA_1,
                               double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                               double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                               double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                               double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                               double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                               double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u, Z;
    Z = fabs(z);
    u = Q*sqrt(R_2*R_2 - (Z-D_2)*(Z-D_2))*sin(PSI);
    temp =  2.0*M_PI*DIF_ETA_C*(R_1*R_1 - (Z-D_2)*(Z-D_2))*J1xdivx(u);
    result = cos(Q*z*cos(PSI))*temp;
    return result;
}
// (8b) Domain outer curved cap (left): imaginary part **
double outer_curve_left_imag ( double z,  double RSHMODE,  double THETA_1,
                               double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                               double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                               double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                               double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                               double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                               double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u, Z;
    Z = fabs(z);
    u = Q*sqrt(R_2*R_2 - (Z-D_2)*(Z-D_2))*sin(PSI);
    temp =  2.0*M_PI*DIF_ETA_C*(R_2*R_2 - (Z-D_2)*(Z-D_2))*J1xdivx(u);
    result = sin(Q*z*cos(PSI))*temp;
    return result;
}
// (9a) Domain inner curved cap (right): real part **
double inner_curve_right_real ( double z,  double RSHMODE,  double THETA_1,
                                double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                                double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                                double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                                double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                                double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                                double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u, Z;
    Z = fabs(z);
    u = Q*sqrt(R_1*R_1 - (Z-D_1)*(Z-D_1))*sin(PSI);
    temp =  2.0*M_PI*DIF_ETA_C*(R_1*R_1 - (Z-D_1)*(Z-D_1))*J1xdivx(u);
    result = cos(Q*z*cos(PSI))*temp;
    return result;
}
// (9b) Domain inner curved cap (right): imaginary part
double inner_curve_right_imag ( double z,  double RSHMODE,  double THETA_1,
                                double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                                double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                                double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                                double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                                double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                                double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u, Z;
    Z = fabs(z);
    u = Q*sqrt(R_1*R_1 - (Z-D_1)*(Z-D_1))*sin(PSI);
    temp =  2.0*M_PI*DIF_ETA_C*(R_1*R_1 - (Z-D_1)*(Z-D_1))*J1xdivx(u);
    result = sin(Q*z*cos(PSI))*temp;
    return result;
}
// (10a) Domain inner curved cap (left): real part
double inner_curve_left_real ( double z,  double RSHMODE,  double THETA_1,
                               double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                               double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                               double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                               double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                               double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                               double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u, Z;
    Z = fabs(z);
    u = Q*sqrt(R_2*R_2 - (Z-D_2)*(Z-D_2))*sin(PSI);
    temp =  2.0*M_PI*DIF_ETA_C*(R_2*R_2 - (Z-D_2)*(Z-D_2))*J1xdivx(u);
    result = cos(Q*z*cos(PSI))*temp;
    return result;
}
// (10b) Domain inner curved cap (left): imaginary part
double inner_curve_left_imag ( double z,  double RSHMODE,  double THETA_1,
                               double R1,  double THETA_2,  double R2,  double T_SH,  double T_C,
                               double ETA_SH,  double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,
                               double KAPPA,  double Q,  double BIG_THETA_1,  double BIG_THETA_2,
                               double DELTA_1,  double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,
                               double DIF_ETA_C,  double GAMMA,  double _THETA,  double _PHI,  double PSI,
                               double R_SH,  double R_1,  double R_2 )
{
    double temp, result, u, Z;
    Z = fabs(z);
    u =Q*sqrt(R_2*R_2 - (Z-D_2)*(Z-D_2))*sin(PSI);
    temp =  2.0*M_PI*DIF_ETA_C*(R_2*R_2 - (Z-D_2)*(Z-D_2))*J1xdivx(u);
    result = sin(Q*z*cos(PSI))*temp;
    return result;
}
/* ******************************************************************************* */
double probability_new (double *x,  double RSHMODE,  double THETA_1,  double R1,
                        double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                        double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                        double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                        double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                        double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                        double R_1,  double R_2)
{
    double p, norm, u, c, LNf, theta, phi, radius;
    theta	= x[0];
    phi		= x[1];
    radius	= x[2];
    if (KAPPA < 0)
    {
        u = sqrt(-KAPPA);
        norm = sqrt(M_PI)*sas_erf(u)/u;
    }
    else if (KAPPA == 0.0)
    {
        norm = 2;
    }
    else
    {
        u = sqrt(KAPPA);
        norm = 2.0*exp(KAPPA)*gsl_sf_dawson(
                   u)/u; // maple: `assuming`([convert(int(exp(kappa*cos(theta)^2)*sin(theta), theta = 0 .. Pi), dawson)], [kappa > 0])
    }
    if (radius == 0.0)
    {
        LNf = 0.0;
    }
    else
    {
        c = 1.0/(sqrt(M_PI*2.0)*fabs(SIGMA));
        LNf = c/radius * exp(-0.5*pow(log(radius/RSHMODE)/SIGMA,2.0));
    }
    p = LNf*exp(KAPPA*sas_pow_2(cos(theta)))/(norm*2.0*M_PI);
    return p;
}
double sasfit_ff_magneticfieldalignedvesicle_new_kernel(double *x, size_t dim,
        double RSHMODE,  double THETA_1,  double R1,  double THETA_2,  double R2,
        double T_SH,  double T_C,  double ETA_SH,  double ETA_C,  double ETA_SOL,
        double _PSI,  double SIGMA,  double KAPPA,  double Q,  double BIG_THETA_1,
        double BIG_THETA_2,  double DELTA_1,  double DELTA_2,  double D_1,  double D_2,
        double DIF_ETA_SH,  double DIF_ETA_C,  double GAMMA,  double _THETA,
        double _PHI,  double PSI,  double R_SH,  double R_1,  double R_2)
{
    double res,p;
    double sasfit_ff_magneticfieldalignedvesicle_psi_zint();
    _THETA	= x[0];
    _PHI	= x[1];
    R_SH	= x[2];
    R_1 = R1*(R_SH+T_C);
    R_2 = R2*(R_SH+T_C);
    p = probability_new(x, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH,
                        ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1,
                        DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
                        R_2);
    GAMMA =	acos( sin(_PSI)*cos(_THETA) + cos(_PSI)*sin(_THETA)*cos(
                      _PHI) );	//acos( sin(_THETA) * cos(_PHI) * sin(PSI) + cos(_THETA) * cos(PSI) ); <--is this gamma correct?
    res = sin(_THETA)*p*sasfit_ff_magneticfieldalignedvesicle_psi_zint(Q, RSHMODE,
            THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA,
            Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
            GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2);
    return res;
}
int sasfit_integrate_plugin_new(sasfit_func_monte_t intKern_fct,
                                double *xl,
                                double *xu,
                                size_t dim,
                                double RSHMODE,  double THETA_1,  double R1,  double THETA_2,  double R2,
                                double T_SH,  double T_C,  double ETA_SH,  double ETA_C,  double ETA_SOL,
                                double _PSI,  double SIGMA,  double KAPPA,  double Q,  double BIG_THETA_1,
                                double BIG_THETA_2,  double DELTA_1,  double DELTA_2,  double D_1,  double D_2,
                                double DIF_ETA_SH,  double DIF_ETA_C,  double GAMMA,  double _THETA,
                                double _PHI,  double PSI,  double R_SH,  double R_1,  double R_2,
                                size_t calls,
                                double *res,
                                double *err)
{
    int status;
    static gsl_rng *r;
    static int rng_init=-1;
    gsl_monte_function F;
    gsl_monte_miser_state *s;
    if (rng_init < 0)
    {
        r = gsl_rng_alloc (gsl_rng_default);
        rng_init = 1;
    }
    s = gsl_monte_miser_alloc(dim);
    gsl_set_error_handler_off ();
    F.f = (double (*) (double*, size_t, void*)) intKern_fct;
    F.dim = dim;
    F.RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
               SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
               DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2s = RSHMODE,
                                                                           THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA,
                                                                           Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
                                                                           GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2;
    status = gsl_monte_miser_integrate( &F, xl, xu, dim, calls, r, s, res, err );
    gsl_monte_miser_free(s);
    return status;
}
/* ******************************************************************************* */
double Iq( double q, double RSHMODE,  double THETA_1,  double R1,
           double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
           double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
           double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
           double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
           double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
           double R_1,  double R_2)
{
    double res, err;
    double xl[3], xu[3];
    int status;
    Q=q;
    gsl_set_error_handler_off ();
    xl[0]=0.0;
    xl[1]=0.0;
    xl[2]=0.0;
    xu[0]=M_PI;
    xu[1]=2.0*M_PI;
    xu[2]=RSHMODE*exp(-SIGMA*SIGMA*(1.0-6.0)+sqrt(2.0*SIGMA*SIGMA*log(100.0/0.1)));
    status = sasfit_integrate_plugin_new(
                 &sasfit_ff_magneticfieldalignedvesicle_new_kernel, xl, xu, 3, RSHMODE, THETA_1,
                 R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q,
                 BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
                 GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2, sasfit_eps_get_iter_4_mc(), &res,
                 &err );
//	sasfit_out( "Q=%lf, Int=%lf, Err/Int=%lf Rmax=%lf\n", Q, res, err/res, xu[2]);
    return res;
}
/* ******************************************************************************* */
double sasfit_ff_magneticfieldalignedvesicle_psi_zint( double q,
        double RSHMODE,  double THETA_1,  double R1,  double THETA_2,  double R2,
        double T_SH,  double T_C,  double ETA_SH,  double ETA_C,  double ETA_SOL,
        double _PSI,  double SIGMA,  double KAPPA,  double Q,  double BIG_THETA_1,
        double BIG_THETA_2,  double DELTA_1,  double DELTA_2,  double D_1,  double D_2,
        double DIF_ETA_SH,  double DIF_ETA_C,  double GAMMA,  double _THETA,
        double _PHI,  double PSI,  double R_SH,  double R_1,  double R_2 )
{
    double	r1a, r1b, r2a, r2b, r7a, r7b, r8a, r8b, r9a, r9b, r10a, r10b,
            real_amp, imag_amp,
            intensity;
    DIF_ETA_SH	= ( ETA_SH - ETA_SOL );
    DIF_ETA_C	= ( ETA_C - ETA_SOL );
//	Q = q;
//	GAMMA = acos( sin(PSI)*cos(_THETA) + cos(PSI)*sin(_THETA)*cos(_PHI) );
    PSI = GAMMA;
    BIG_THETA_1	= asin((R_SH*sin(THETA_1))/(R_SH+T_SH));
    BIG_THETA_2	= asin((R_SH*sin(THETA_2))/(R_SH+T_SH));
    DELTA_1		= ( BIG_THETA_1 - asin(R_SH*sin(THETA_1)/R_1) );
    DELTA_2		= ( BIG_THETA_2 - asin(R_SH*sin(THETA_2)/R_2) );
// Define D_1:
    if ( R_1 > ((R_SH+T_SH)*sin(BIG_THETA_1)) && R_1 < (R_SH+T_SH) )
    {
        D_1	= ( sqrt( R_1*R_1 + (R_SH+T_SH)*(R_SH+T_SH) - 2.0*R_1*(R_SH+T_SH)*cos(
                          DELTA_1) ) );
    }
    else if ( R_1 > (R_SH+T_SH) )
    {
        D_1	= ( (-1.0)*sqrt( R_1*R_1 + (R_SH+T_SH)*(R_SH+T_SH) - 2.0*R_1*
                             (R_SH+T_SH)*cos(DELTA_1) ) );
    }
    else
    {
    }
// Define D_2:
    if ( R_2 > ((R_SH+T_SH)*sin(BIG_THETA_2)) && R_2 < (R_SH+T_SH) )
    {
        D_2	= ( sqrt( R_2*R_2 + (R_SH+T_SH)*(R_SH+T_SH) - 2.0*R_2*(R_SH+T_SH)*cos(
                          DELTA_2) ) );
    }
    else if ( R_2 > (R_SH+T_SH) )
    {
        D_2	= ( (-1.0)*sqrt( R_2*R_2 + (R_SH+T_SH)*(R_SH+T_SH) - 2.0*R_2*
                             (R_SH+T_SH)*cos(DELTA_2) ) );
    }
    else
    {
    }
// Perform the integrations over z:
    r1a  = sasfit_integrate( (-1.0)*R_SH*cos(THETA_2), R_SH*cos(THETA_1),
                             inner_sphere_real, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C,
                             ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1,
                             D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2 );
//	sasfit_out("r1a: %lf\n", r1a);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    if ((R_SH*cos(THETA_2)) == (R_SH*cos(THETA_1)))
    {
        r1b = 0.0;
    }
    else
    {
        r1b  = sasfit_integrate( (-1.0)*R_SH*cos(THETA_2), R_SH*cos(THETA_1),
                                 inner_sphere_imag, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C,
                                 ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1,
                                 D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2 );
    }
//	sasfit_out("r1b: %lf\n", r1b);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    r2a  = sasfit_integrate( (-1.0)*(R_SH+T_SH)*cos(BIG_THETA_2),
                             (R_SH+T_SH)*cos(BIG_THETA_1), outer_sphere_real, RSHMODE, THETA_1, R1, THETA_2,
                             R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1,
                             BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA,
                             _PHI, PSI, R_SH, R_1, R_2 );
//	sasfit_out("r2a: %lf\n", r2a);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    if (((R_SH+T_SH)*cos(BIG_THETA_2)) == ((R_SH+T_SH)*cos(BIG_THETA_1)))
    {
        r2b = 0.0;
    }
    else
    {
        r2b  = sasfit_integrate( (-1)*(R_SH+T_SH)*cos(BIG_THETA_2),
                                 (R_SH+T_SH)*cos(BIG_THETA_1), outer_sphere_imag, RSHMODE, THETA_1, R1, THETA_2,
                                 R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1,
                                 BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA,
                                 _PHI, PSI, R_SH, R_1, R_2 );
    }
//	sasfit_out("r2b: %lf\n", r2b);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
//	sasfit_out ("r3a: %lf\n", cap_right_real(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2));
//	sasfit_out ("r3b: %lf\n", cap_right_imag(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2));
//	sasfit_out ("r4a: %lf\n", cap_left_real(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2));
//	sasfit_out ("r4b: %lf\n", cap_left_imag(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2));
//	sasfit_out ("r5a: %lf\n", dom_cap_right_real(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2));
//	sasfit_out ("r5b: %lf\n", dom_cap_right_imag(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2));
//	sasfit_out ("r6a: %lf\n", dom_cap_left_real(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2));
//	sasfit_out ("r6b: %lf\n", dom_cap_left_imag(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2));
    r7a  = sasfit_integrate( (R_SH+T_SH)*cos(BIG_THETA_1), R_1 + D_1,
                             outer_curve_right_real, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH,
                             ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1,
                             DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
                             R_2 );
//	sasfit_out("r7a: %lf\n", r7a);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    r7b  = sasfit_integrate( (R_SH+T_SH)*cos(BIG_THETA_1), R_1 + D_1,
                             outer_curve_right_imag, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH,
                             ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1,
                             DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
                             R_2 );
//	sasfit_out("r7b: %lf\n", r7b);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    r8a  = sasfit_integrate(  -D_2 - R_2, (-1)*(R_SH+T_SH)*cos(BIG_THETA_2),
                              outer_curve_left_real, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH,
                              ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1,
                              DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
                              R_2 );
//	sasfit_out("r8a: %lf\n", r8a);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    r8b  = sasfit_integrate( -D_2 - R_2, (-1)*(R_SH+T_SH)*cos(BIG_THETA_2),
                             outer_curve_left_imag, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH,
                             ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1,
                             DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
                             R_2 );
//	sasfit_out("r8b: %lf\n", r8b);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    r9a  = sasfit_integrate( ((R_SH+T_SH)*cos(BIG_THETA_1)) - T_C, R_1 + D_1 - T_C,
                             inner_curve_right_real, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH,
                             ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1,
                             DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
                             R_2 );
//	sasfit_out("r9a: %lf\n", r9a);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    r9b  = sasfit_integrate( ((R_SH+T_SH)*cos(BIG_THETA_1)) - T_C, R_1 + D_1 - T_C,
                             inner_curve_right_imag, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH,
                             ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1,
                             DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
                             R_2 );
//	sasfit_out("r9b: %lf\n", r9b);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    r10a = sasfit_integrate( -D_2 + T_C - R_2,
                             ((-1)*(R_SH+T_SH)*cos(BIG_THETA_2)) + T_C, inner_curve_left_real, RSHMODE,
                             THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA,
                             Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
                             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2 );
//	sasfit_out("r10a: %lf\n", r10a);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
    r10b = sasfit_integrate( -D_2 + T_C - R_2,
                             ((-1)*(R_SH+T_SH)*cos(BIG_THETA_2)) + T_C, inner_curve_left_imag, RSHMODE,
                             THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA,
                             Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C,
                             GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2 );
//	sasfit_out("r10b: %lf\n", r10b);
    if ( RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C, ETA_SOL, _PSI,
            SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1, D_2,
            DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1,
            R_2->errStatus ) return 0.0;
// Adding the contributions to the amplitude (real parts and imaginary parts separately): (2) - (1) - (3) - (4) + (5) + (6) + (7) + (8) - (9) - (10)
    real_amp	= r2a - r1a - cap_right_real(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH,
                  T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2,
                  DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI,
                  R_SH, R_1, R_2) - cap_left_real(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C,
                          ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2,
                          DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI,
                          R_SH, R_1, R_2) + dom_cap_right_real(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH,
                                  T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2,
                                  DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI,
                                  R_SH, R_1, R_2) + dom_cap_left_real(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH,
                                          T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2,
                                          DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI,
                                          R_SH, R_1, R_2) + r7a + r8a - r9a - r10a;
    imag_amp	= r2b - r1b - cap_right_imag(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH,
                  T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2,
                  DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI,
                  R_SH, R_1, R_2) - cap_left_imag(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C,
                          ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2,
                          DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI,
                          R_SH, R_1, R_2) + dom_cap_right_imag(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH,
                                  T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2,
                                  DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI,
                                  R_SH, R_1, R_2) + dom_cap_left_imag(RSHMODE, THETA_1, R1, THETA_2, R2, T_SH,
                                          T_C, ETA_SH, ETA_C, ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2,
                                          DELTA_1, DELTA_2, D_1, D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI,
                                          R_SH, R_1, R_2) + r7b + r8b - r9b - r10b;
//	sasfit_out ("Real amplitude: %lf \n", real_amp);
//	sasfit_out ("Imaginary amplitude: %lf \n", imag_amp);
    intensity	= (real_amp)*(real_amp) + (imag_amp)*(imag_amp);
    return intensity;
}
double Fq( double q,  double RSHMODE,  double THETA_1,  double R1,
           double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
           double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
           double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
           double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
           double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
           double R_1,  double R_2)
{
// insert your code here
    return 0.0;
}
double form_volume(  double RSHMODE,  double THETA_1,  double R1,
                     double THETA_2,  double R2,  double T_SH,  double T_C,  double ETA_SH,
                     double ETA_C,  double ETA_SOL,  double _PSI,  double SIGMA,  double KAPPA,
                     double Q,  double BIG_THETA_1,  double BIG_THETA_2,  double DELTA_1,
                     double DELTA_2,  double D_1,  double D_2,  double DIF_ETA_SH,  double DIF_ETA_C,
                     double GAMMA,  double _THETA,  double _PHI,  double PSI,  double R_SH,
                     double R_1,  double R_2)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double RSHMODE, double THETA_1, double R1,
             double THETA_2, double R2, double T_SH, double T_C, double ETA_SH, double ETA_C,
             double ETA_SOL, double _PSI, double SIGMA, double KAPPA, double Q,
             double BIG_THETA_1, double BIG_THETA_2, double DELTA_1, double DELTA_2,
             double D_1, double D_2, double DIF_ETA_SH, double DIF_ETA_C, double GAMMA,
             double _THETA, double _PHI, double PSI, double R_SH, double R_1, double R_2)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, RSHMODE, THETA_1, R1, THETA_2, R2, T_SH, T_C, ETA_SH, ETA_C,
               ETA_SOL, _PSI, SIGMA, KAPPA, Q, BIG_THETA_1, BIG_THETA_2, DELTA_1, DELTA_2, D_1,
               D_2, DIF_ETA_SH, DIF_ETA_C, GAMMA, _THETA, _PHI, PSI, R_SH, R_1, R_2);
}
