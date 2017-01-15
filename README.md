# SWIG-example
This is a simple example of using SWIG. It covers two topics:
<ul>
  <li> Wrapping C++ class "sample" in Python.</li>
  <li> Calling Python script with wrapped class from C++.</li>
</ul>

<p>For more information about project setting, look <a href="http://www.matthiaskauer.com/2013/08/tutorial-mixing-c-and-python-on-windows-with-swig-and-visual-studio-express-2012/"> here</a>.<p>
Class sample (/sample/sample.h) contains three functions that we want call from Python script:
 <ul>
  <li> <code>print_infoA(A *a)</code></li>
  <li> <code>print_infoVoid(void *a)</code></li>
  <li> <code>print_info(int i)</code></li>
</ul>

<p>First function takes pointer to class A (/A/A.h).</p>
<p>For first two we have to put these lines in sample.i:</p>
<p> <code> %typemap(in) void* {	$1 = (void *)PyCapsule_GetPointer($input, "testVoid.pointer"); } </code> </p>
<p> <code> %typemap(in) A* { $1 = (A *)PyCapsule_GetPointer($input, "testA.pointer"); } </code> </p>
<p>After that we can call function that takes <code> void* </code> or <code> A* </code> parameters.</p>

<p>Test Python script placed in /sample/test.py.</p>
<p>/startpy/startpy.cpp contains function <code> pythonFunc </code> that calls test.py.</p>
