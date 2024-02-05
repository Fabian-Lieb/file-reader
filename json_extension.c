#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>

static PyObject* read_json(PyObject* self, PyObject* args) {
    const char *filename;
    FILE *fp;
    char buffer[65536]; // 64KB Buffer
    size_t read_size;
    json_error_t error;
    json_t *root;

    if (!PyArg_ParseTuple(args, "s", &filename)) {
        PyErr_SetString(PyExc_TypeError, "Argument must be a string");
        return NULL;
    }

    fp = fopen(filename, "r");
    if (!fp) {
        PyErr_SetString(PyExc_IOError, "Failed to open file");
        return NULL;
    }

    read_size = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    root = json_loadb(buffer, read_size, 0, &error);
    if (!root) {
        PyErr_SetString(PyExc_ValueError, "Failed to parse JSON");
        return NULL;
    }

    return Py_BuildValue("s", json_dumps(root, JSON_COMPACT));
}

static PyMethodDef module_methods[] = {
    {"read_json", read_json, METH_VARARGS, "Read a JSON file and return its contents as a string."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef json_module = {
    PyModuleDef_HEAD_INIT,
    "json_extension",
    NULL,
    -1,
    module_methods
};

PyMODINIT_FUNC PyInit_json_extension(void) {
    return PyModule_Create(&json_module);
}