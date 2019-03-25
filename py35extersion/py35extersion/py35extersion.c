#include <Python.h>

/*
 * Implements an example function.
 */
PyDoc_STRVAR(py35extersion_example_doc, "example(obj, number)\
\
Example function");

PyObject *py35extersion_example(PyObject *self, PyObject *args, PyObject *kwargs) {
    /* Shared references that do not need Py_DECREF before returning. */
    PyObject *obj = NULL;
    int number = 0;

    /* Parse positional and keyword arguments */
    static char* keywords[] = { "obj", "number", NULL };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "Oi", keywords, &obj, &number)) {
        return NULL;
    }

    /* Function implementation starts here */

    if (number < 0) {
        PyErr_SetObject(PyExc_ValueError, obj);
        return NULL;    /* return NULL indicates error */
    }

    Py_RETURN_NONE;
}

/*
 * List of functions to add to py35extersion in exec_py35extersion().
 */
static PyMethodDef py35extersion_functions[] = {
    { "example", (PyCFunction)py35extersion_example, METH_VARARGS | METH_KEYWORDS, py35extersion_example_doc },
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize py35extersion. May be called multiple times, so avoid
 * using static state.
 */
int exec_py35extersion(PyObject *module) {
    PyModule_AddFunctions(module, py35extersion_functions);

    PyModule_AddStringConstant(module, "__author__", "jason.li");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2019);

    return 0; /* success */
}

/*
 * Documentation for py35extersion.
 */
PyDoc_STRVAR(py35extersion_doc, "The py35extersion module");


static PyModuleDef_Slot py35extersion_slots[] = {
    { Py_mod_exec, exec_py35extersion },
    { 0, NULL }
};

static PyModuleDef py35extersion_def = {
    PyModuleDef_HEAD_INIT,
    "py35extersion",
    py35extersion_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    py35extersion_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_py35extersion() {
    return PyModuleDef_Init(&py35extersion_def);
}
