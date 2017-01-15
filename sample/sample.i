%module sample

%{
#include "sample.h"
%}

%typemap(in) void* 
{
	$1 = (void *)PyCapsule_GetPointer($input, "testVoid.pointer");
}

%typemap(in) A* 
{
	$1 = (A *)PyCapsule_GetPointer($input, "testA.pointer");
}

%include "sample.h"
