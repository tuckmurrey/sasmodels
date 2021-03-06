"""
Convert models to and from sasview.
"""
from __future__ import print_function

from os.path import join as joinpath, abspath, dirname
import math
import warnings
import json

# List of models which SasView versions don't contain the explicit 'scale' argument.
# When converting such a model, please update this list.
MODELS_WITHOUT_SCALE = [
    'teubner_strey',
    'broad_peak',
    'two_lorentzian',
    "two_power_law",
    'gel_fit',
    'gauss_lorentz_gel',
    'be_polyelectrolyte',
    'correlation_length',
    'fractal_core_shell',
    'binary_hard_sphere',
    'raspberry'
]

# List of models which SasView versions don't contain the explicit 'background' argument.
# When converting such a model, please update this list.
MODELS_WITHOUT_BACKGROUND = [
    'guinier',
]

MODELS_WITHOUT_VOLFRACTION = [
    'fractal',
    'vesicle',
    'multilayer_vesicle',
]


# Convert new style names for polydispersity info to old style names
PD_DOT = [
    ("", ""),
    ("_pd", ".width"),
    ("_pd_n", ".npts"),
    ("_pd_nsigma", ".nsigmas"),
    ("_pd_type", ".type"),
    ]

CONVERSION_TABLE = None

def _read_conversion_table():
    global CONVERSION_TABLE
    if CONVERSION_TABLE is None:
        path = joinpath(dirname(abspath(__file__)), "convert.json")
        with open(path) as fid:
            CONVERSION_TABLE = json_load_byteified(fid)

def json_load_byteified(file_handle):
    return _byteify(
        json.load(file_handle, object_hook=_byteify),
        ignore_dicts=True
    )

def _byteify(data, ignore_dicts = False):
    # if this is a unicode string, return its string representation
    if isinstance(data, unicode):
        return data.encode('utf-8')
    # if this is a list of values, return list of byteified values
    if isinstance(data, list):
        return [ _byteify(item, ignore_dicts=True) for item in data ]
    # if this is a dictionary, return dictionary of byteified keys and values
    # but only if we haven't already byteified it
    if isinstance(data, dict) and not ignore_dicts:
        return dict((_byteify(key, ignore_dicts=True),
                     _byteify(value, ignore_dicts=True))
                    for key, value in data.items())
    # if it's anything else, return it in its original form
    return data


def _convert_pars(pars, mapping):
    """
    Rename the parameters and any associated polydispersity attributes.
    """
    newpars = pars.copy()
    for new, old in mapping.items():
        if old == new: continue
        for pd, dot in PD_DOT:
            if old+dot in newpars:
                if new is not None:
                    newpars[new+pd] = pars[old+dot]
                del newpars[old+dot]
    return newpars

def _rescale_sld(pars):
    """
    rescale all sld parameters in the new model definition by 1e6 so the
    numbers are nicer.  Relies on the fact that all sld parameters in the
    new model definition end with sld.
    """
    return dict((p, (v*1e6 if p.endswith('sld')
                     else v*1e-15 if 'ndensity' in p
                     else v))
                for p, v in pars.items())

def convert_model(name, pars):
    """
    Convert model from old style parameter names to new style.
    """
    _, _ = name, pars # lint
    raise NotImplementedError
    # need to load all new models in order to determine old=>new
    # model name mapping

def _unscale(par, scale):
    return [pk*scale for pk in par] if isinstance(par, list) else par*scale

def _unscale_sld(pars):
    """
    rescale all sld parameters in the new model definition by 1e6 so the
    numbers are nicer.  Relies on the fact that all sld parameters in the
    new model definition end with sld.
    """
    return dict((p, (_unscale(v,1e-6) if p.startswith('sld') or p.endswith('sld')
                     else _unscale(v,1e15) if 'ndensity' in p
                     else v))
                for p, v in pars.items())

def _remove_pd(pars, key, name):
    """
    Remove polydispersity from the parameter list.

    Note: operates in place
    """
    # Bumps style parameter names
    pd = pars.pop(key+".width", 0.0)
    pd_n = pars.pop(key+".npts", 0)
    if pd != 0.0 and pd_n != 0:
        warnings.warn("parameter %s not polydisperse in sasview %s"%(key, name))
    pars.pop(key+".nsigmas", None)
    pars.pop(key+".type", None)
    return pars

def _revert_pars(pars, mapping):
    """
    Rename the parameters and any associated polydispersity attributes.
    """
    newpars = pars.copy()

    for new, old in mapping.items():
        for pd, dot in PD_DOT:
            if old and old+pd == new+dot:
                continue
            if new+pd in newpars:
                if old is not None:
                    newpars[old+dot] = pars[new+pd]
                del newpars[new+pd]
    for k in list(newpars.keys()):
        for pd, dot in PD_DOT[1:]:  # skip "" => ""
            if k.endswith(pd):
                newpars[k[:-len(pd)]+dot] = newpars[k]
                del newpars[k]
    return newpars

def revert_name(model_info):
    _read_conversion_table()
    oldname, oldpars = CONVERSION_TABLE.get(model_info.id, [None, {}])
    return oldname

def _get_translation_table(model_info):
    _read_conversion_table()
    _, translation = CONVERSION_TABLE.get(model_info.id, [None, {}])
    translation = translation.copy()
    for p in model_info.parameters.kernel_parameters:
        if p.length > 1:
            newid = p.id
            oldid = translation.get(p.id, p.id)
            translation.pop(newid, None)
            for k in range(1, p.length+1):
                if newid+str(k) not in translation:
                    translation[newid+str(k)] = oldid+str(k)
    # Remove control parameter from the result
    if model_info.control:
        translation[model_info.control] = None
    return translation

def _trim_vectors(model_info, pars, oldpars):
    _read_conversion_table()
    _, translation = CONVERSION_TABLE.get(model_info.id, [None, {}])
    for p in model_info.parameters.kernel_parameters:
        if p.length_control is not None:
            n = int(pars[p.length_control])
            oldname = translation.get(p.id, p.id)
            for k in range(n+1, p.length+1):
                for _, old in PD_DOT:
                    oldpars.pop(oldname+str(k)+old, None)
    return oldpars

def revert_pars(model_info, pars):
    """
    Convert model from new style parameter names to old style.
    """
    if model_info.composition is not None:
        composition_type, parts = model_info.composition
        if composition_type == 'product':
            P, S = parts
            oldpars = {'scale':'scale_factor'}
            oldpars.update(_get_old_pars(P))
            oldpars.update(_get_old_pars(S))
        else:
            raise NotImplementedError("cannot convert to sasview sum")
    else:
        translation = _get_translation_table(model_info)
        oldpars = _revert_pars(_unscale_sld(pars), translation)
        oldpars = _trim_vectors(model_info, pars, oldpars)


    # Note: update compare.constrain_pars to match
    name = model_info.id
    if name in MODELS_WITHOUT_SCALE or model_info.structure_factor:
        if oldpars.pop('scale', 1.0) != 1.0:
            warnings.warn("parameter scale not used in sasview %s"%name)
    if name in MODELS_WITHOUT_BACKGROUND or model_info.structure_factor:
        if oldpars.pop('background', 0.0) != 0.0:
            warnings.warn("parameter background not used in sasview %s"%name)


    # If it is a product model P*S, then check the individual forms for special
    # cases.  Note: despite the structure factor alone not having scale or
    # background, the product model does, so this is below the test for
    # models without scale or background.
    namelist = name.split('*') if '*' in name else [name]
    for name in namelist:
        if name in MODELS_WITHOUT_VOLFRACTION:
            del oldpars['volfraction']
        if name == 'stacked_disks':
            _remove_pd(oldpars, 'n_stacking', name)
        elif name == 'pearl_necklace':
            _remove_pd(oldpars, 'num_pearls', name)
            _remove_pd(oldpars, 'thick_string', name)
        elif name == 'core_shell_parallelepiped':
            _remove_pd(oldpars, 'rimA', name)
            _remove_pd(oldpars, 'rimB', name)
            _remove_pd(oldpars, 'rimC', name)
        elif name == 'spherical_sld':
            for k in range(1, int(pars['n_shells'])+1):
                _remove_pd(oldpars, 'thick_flat'+str(k), 'thick_flat')
                _remove_pd(oldpars, 'thick_inter'+str(k), 'thick_inter')
        elif name == 'rpa':
            # convert scattering lengths from femtometers to centimeters
            for p in "L1", "L2", "L3", "L4":
                if p in oldpars: oldpars[p] *= 1e-13
            if pars['case_num'] < 2:
                for k in ("a", "b"):
                    for p in ("L", "N", "Phi", "b", "v"):
                        oldpars.pop(p+k, None)
                for k in "Kab,Kac,Kad,Kbc,Kbd".split(','):
                    oldpars.pop(k, None)
            elif pars['case_num'] < 5:
                for k in ("a",):
                    for p in ("L", "N", "Phi", "b", "v"):
                        oldpars.pop(p+k, None)
                for k in "Kab,Kac,Kad".split(','):
                    oldpars.pop(k, None)
        elif name == 'core_shell_parallelepiped':
            _remove_pd(oldpars, 'rimA', name)
        elif name in ['mono_gauss_coil','poly_gauss_coil']:
            del oldpars['i_zero']
        elif name == 'onion':
            oldpars.pop('n_shells', None)

    return oldpars

def constrain_new_to_old(model_info, pars):
    """
    Restrict parameter values to those that will match sasview.
    """
    name = model_info.id
    # Note: update convert.revert_model to match
    if name in MODELS_WITHOUT_SCALE or model_info.structure_factor:
        pars['scale'] = 1
    if name in MODELS_WITHOUT_BACKGROUND or model_info.structure_factor:
        pars['background'] = 0
    # sasview multiplies background by structure factor
    if '*' in name:
        pars['background'] = 0

    # If it is a product model P*S, then check the individual forms for special
    # cases.  Note: despite the structure factor alone not having scale or
    # background, the product model does, so this is below the test for
    # models without scale or background.
    namelist = name.split('*') if '*' in name else [name]
    for name in namelist:
        if name in MODELS_WITHOUT_VOLFRACTION:
            pars['volfraction'] = 1
        if name == 'pearl_necklace':
            pars['string_thickness_pd_n'] = 0
            pars['number_of_pearls_pd_n'] = 0
        elif name == 'line':
            pars['scale'] = 1
            pars['background'] = 0
        elif name == 'rpa':
            pars['case_num'] = int(pars['case_num'])
        elif name == 'mono_gauss_coil':
            pars['i_zero'] = 1
        elif name == 'poly_gauss_coil':
            pars['i_zero'] = 1
        elif name == 'core_multi_shell':
            pars['n'] = min(math.ceil(pars['n']), 4)
        elif name == 'spherical_sld':
            for k in range(1, 11):
                pars['thick_flat%d_pd_n'%k] = 0
                pars['thick_inter%d_pd_n'%k] = 0

