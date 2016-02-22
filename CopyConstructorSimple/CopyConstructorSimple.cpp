// Main function and entry point
// 

#include "stdafx.h"
#include "simple_copyable_class.h"
#include <iostream>
using namespace std;


void my_function(simple_copyable_class);

int main()
{
	simple_copyable_class x;					//Parameterless constructor is called.
	cin.get();

	my_function(x);								//Causes a copy constructor call for the parameter inside function.
	cin.get();

    return 0;
}

void my_function(simple_copyable_class c)		//Copy constructor is called for c, while parameterless is not.
{
}