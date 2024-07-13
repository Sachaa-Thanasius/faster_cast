#define PY_SSIZE_T_CLEAN
#include "Python.h"

PyDoc_STRVAR(fastercast_cast__doc__,
             "cast($module, typ, val, /)\n"
             "--\n"
             "Cast a value to a type.\n"
             "\n");

static PyObject *
fastercast_cast(PyObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    if (nargs > 2)
    {
        PyErr_Format(PyExc_TypeError, "cast() takes 2 positional arguments but %zd were given", nargs);
        return NULL;
    }
    else if (nargs < 2)
    {
        PyErr_Format(PyExc_TypeError, "cast() missing %zd required argument(s)", 2 - nargs);
        return NULL;
    }
    PyObject *val = args[1];
    Py_INCREF(val);
    return val;
}

static PyMethodDef fastercast_methods[] = {
    {"cast", (PyCFunction)fastercast_cast, METH_FASTCALL, fastercast_cast__doc__},
    {NULL, NULL, 0, NULL} // Sentinel
};

PyDoc_STRVAR(fastercast_doc,
             "Accelerator for typing.cast.\n");

static struct PyModuleDef_Slot fastercastmodule_slots[] = {
#if PY_VERSION_HEX >= 0x030C0000
    {Py_mod_multiple_interpreters, Py_MOD_PER_INTERPRETER_GIL_SUPPORTED},
#endif
#if PY_VERSION_HEX >= 0x030D0000
    {Py_mod_gil, Py_MOD_GIL_NOT_USED},
#endif
    {0, NULL}};

static struct PyModuleDef fastercastmodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "fastercast",
    .m_doc = fastercast_doc,
    .m_methods = fastercast_methods,
    .m_slots = fastercastmodule_slots,
};

PyMODINIT_FUNC
PyInit_fastercast(void)
{
    return PyModuleDef_Init(&fastercastmodule);
}