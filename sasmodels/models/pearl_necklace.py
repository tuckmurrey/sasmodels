r"""
This model provides the form factor for a pearl necklace composed of two 
elements: *N* pearls (homogeneous spheres of radius *R*) freely jointed by *M* 
rods (like strings - with a total mass *Mw* = *M* \* *m*\ :sub:`r` + *N* \* *m*\
:sub:`s`, and the string segment length (or edge separation) *l* 
(= *A* - 2\ *R*)). *A* is the center-to-center pearl separation distance.

.. figure:: img/pearl_fig.jpg

    Pearl Necklace schematic

Definition
----------

The output of the scattering intensity function for the PearlNecklaceModel is 
given by (Schweins, 2004)

.. math::

    I(q)=\frac{ \text{scale} }{V} \cdot \frac{(S_{ss}(q)+S_{ff}(q)+S_{fs}(q))}
        {(M \cdot m_f + N \cdot m_s)^2} + \text{bkg}

where

.. math::

    S_{ss}(q) &= sm_s^2\psi^2(q)[\frac{N}{1-sin(qA)/qA}-\frac{N}{2}-
        \frac{1-(sin(qA)/qA)^N}{(1-sin(qA)/qA)^2}\cdot\frac{sin(qA)}{qA}] \\
    S_{ff}(q) &= sm_r^2[M\{2\Lambda(q)-(\frac{sin(ql/2)}{ql/2})\}+
        \frac{2M\beta^2(q)}{1-sin(qA)/qA}-2\beta^2(q)\cdot
        \frac{1-(sin(qA)/qA)^M}{(1-sin(qA)/qA)^2}] \\
    S_{fs}(q) &= m_r \beta (q) \cdot m_s \psi (q) \cdot 4[
        \frac{N-1}{1-sin(qA)/qA}-\frac{1-(sin(qA)/qA)^{N-1}}{(1-sin(qA)/qA)^2}
        \cdot \frac{sin(qA)}{qA}] \\
    \psi(q) &= 3 \cdot \frac{sin(qR)-(qR)\cdot cos(qR)}{(qR)^3} \\
    \Lambda(q) &= \frac{\int_0^{ql}\frac{sin(t)}{t}dt}{ql} \\
    \beta(q) &= \frac{\int_{qR}^{q(A-R)}\frac{sin(t)}{t}dt}{ql}

where the mass *m*\ :sub:`i` is (SLD\ :sub:`i` - SLD\ :sub:`solvent`) \* 
(volume of the *N* pearls/rods). *V* is the total volume of the necklace.

The 2D scattering intensity is the same as $P(q)$ above, regardless of the 
orientation of the *q* vector.

The returned value is scaled to units of |cm^-1| and the parameters of the
pearl_necklace model are the following

NB: *number_of_pearls* must be an integer.

.. figure:: img/pearl_plot.jpg

    1D plot using the default values (w/1000 data point).

REFERENCE

R Schweins and K Huber, *Particle Scattering Factor of Pearl Necklace Chains*, 
*Macromol. Symp.* 211 (2004) 25-42 2004
"""

from numpy import inf

name = "pearl_necklace"
title = "Colloidal spheres chained together with o preferential orientation"
description = """
Calculate form factor for Pearl Necklace Model
[Macromol. Symp. 2004, 211, 25-42]
Parameters:
background:background
scale: scale factor
sld: the SLD of the pearl spheres
sld_string: the SLD of the strings
sld_solvent: the SLD of the solvent
number_of_pearls: number of the pearls
radius: the radius of a pearl
edge_separation: the length of string segment; surface to surface
string_thickness: thickness (ie, diameter) of the string
"""
category = "shape:cylinder"

#             ["name", "units", default, [lower, upper], "type","description"],
parameters = [["radius", "Angstrom", 80.0, [0, inf], "volume", 
               "Mean radius of the chained spheres"],
              ["edge_separation", "Angstrom", 350.0, [0, inf], "volume", 
               "Mean separation of chained particles"],
              ["string_thickness", "Angstrom", 2.5, [0, inf], "volume", 
               "Thickness of the chain linkage"],
              ["number_of_pearls", "none", 3, [0, inf], "volume", 
               "Mean number of pearls in each necklace"],
              ["sld", "Angstrom^2", 1.0, [-inf, inf], "", 
               "Scattering length density of the chained spheres"],
              ["string_sld", "Angstrom^2", 1.0, [-inf, inf], "", 
               "Scattering length density of the chain linkage"],
              ["solvent_sld", "Angstrom^2", 6.3, [-inf, inf], "", 
               "Scattering length density of the solvent"],
              ]

source = ["lib/Si.c", "pearl_necklace.c"]

# parameters for demo
demo = dict(scale=1, background=0, radius=80.0, edge_separation=350.0,
            number_of_pearls=3, sld=1, solvent_sld=6.3, string_sld=1,
            string_thickness=2.5,
            radius_pd=.2, radius_pd_n=5,
            edge_separation_pd=25.0, edge_separation_pd_n=5,
            number_of_pearls_pd=0, number_of_pearls_pd_n=0,
            string_thickness_pd=0.2, string_thickness_pd_n=5,
           )

# For testing against the old sasview models, include the converted parameter
# names and the target sasview model name.
oldname = 'PearlNecklaceModel'
oldpars = dict(scale='scale',background='background',radius='radius',
               number_of_pearls='num_pearls', solvent_sld='sld_solv',
               string_thickness='thick_string', sld='sld_pearl',
               string_sld='sld_string', edge_separation='edge_separation')