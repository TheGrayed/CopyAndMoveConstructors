#include "stdafx.h"
#include "simple_copyable_class.h"
#include <iostream>
using namespace std;

simple_copyable_class::simple_copyable_class()
{
	cout << endl << "Parameterless Constructor" << endl;
}

//Some other signatures are valid for copy constructor as well. Like (simple_copyable_class&) or (simple_copyable_class&, int = 10) which differ in being called or not in some special cases.
simple_copyable_class::simple_copyable_class(const simple_copyable_class & source) 
{
	cout << endl << "Copy Constructor" << endl;
}
