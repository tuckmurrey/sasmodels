
static double
f_constant(double q, double r, double sld)
{
  const double bes = sph_j1c(q * r);
  const double vol = M_4PI_3 * cube(r);
  return sld * vol * bes;
}

double
form_volume(double core_radius, double n, double thickness[]);
double
form_volume(double core_radius, double n, double thickness[])
{
  double r = core_radius;
  for (int i=0; i < n; i++) {
    r += thickness[i];
  }
  return M_4PI_3 * cube(r);
}

double
Iq(double q, double core_sld, double core_radius,
   double solvent_sld, double num_shells, double sld[], double thickness[]);
double
Iq(double q, double core_sld, double core_radius,
   double solvent_sld, double num_shells, double sld[], double thickness[])
{
  const int n = (int)ceil(num_shells);
  double f, r, last_sld;
  r = core_radius;
  last_sld = core_sld;
  f = 0.;
  for (int i=0; i<n; i++) {
    f += M_4PI_3 * cube(r) * (sld[i] - last_sld) * sph_j1c(q*r);
    last_sld = sld[i];
    r += thickness[i];
  }
  f += M_4PI_3 * cube(r) * (solvent_sld - last_sld) * sph_j1c(q*r);
  return f * f * 1.0e-4;
}
