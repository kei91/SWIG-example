// startpy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Python.h"
#include <conio.h>
#include "../A/A.h"
#include "../sample/sample.h"

enum func
{
	tryInteger = 0,
	tryVoid,
	tryA
};

void pythonFunc(int iType, int iValue)
{
	Py_Initialize();

	PyObject *pName = NULL, *pModule = NULL, *pDict = NULL, *pFunc = NULL, *pArgs = NULL, *pValue = NULL;
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.insert(0, \"..\\sample\")");
	
	pName = PyUnicode_FromString("test");
	pModule = PyImport_Import(pName);
	pDict = PyModule_GetDict(pModule);
	pArgs = PyTuple_New(1);

	switch(iType)
	{
		case tryInteger:
		{
			pFunc = PyDict_GetItemString(pDict, "test");
			pValue = Py_BuildValue("i", iValue);
		}
		break;

		case tryVoid:
		{
			pFunc = PyDict_GetItemString(pDict, "testVoid");

			A a;
			a.SetI(iValue);
			void *pointer = (void *)&a;

			PyObject *pCapsule = PyCapsule_New(pointer, "testVoid.pointer", NULL);
			pValue = Py_BuildValue("O", pCapsule);
		}
		break;

		case tryA:
		{
			pFunc = PyDict_GetItemString(pDict, "testA");

			A a;
			a.SetI(iValue);
			void *pointer = (void *)&a;

			PyObject *pCapsule = PyCapsule_New(pointer, "testA.pointer", NULL);
			pValue = Py_BuildValue("O", pCapsule);
		}
		break;
	}

	PyTuple_SetItem(pArgs, 0, pValue);
	PyObject* pResult = PyObject_CallObject(pFunc, pArgs);
	PyErr_Print();
	Py_Finalize();
}

int _tmain(int argc, _TCHAR* argv[])
{
	pythonFunc(tryA, 7);
	_getch();
	return 0;
}
