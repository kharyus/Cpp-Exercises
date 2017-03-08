#include <iostream>
#include "Python.h"

extern "C"
{
    // A function adding two integers and returning the result
    /*static PyObject* pytest_addInt(PyObject* self, PyObject *args)
    {
        return args;
    }*/

    static PyObject *spam_system(PyObject *self, PyObject *args)
    {
        const char *command;
        int sts;

        if (!PyArg_ParseTuple(args, "s", &command))
            return NULL;
        sts = system(command);
        return PyLong_FromLong(sts);
    }
}
