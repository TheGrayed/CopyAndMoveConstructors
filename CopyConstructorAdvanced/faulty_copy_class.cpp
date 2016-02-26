#include "stdafx.h"
#include "utility.h"
#include "faulty_copy_class.h"
#include <iostream>
#include <string>
using namespace std;

int faulty_copy_class::constructor_counter_ = 0;
std::string faulty_copy_class::constructor_message_ = string("No message is set for faulty_copy_class yet.");

faulty_copy_class::faulty_copy_class()
{
	constructor_counter_++;
	cout << endl << "faulty_copy_class constructor #" << constructor_counter_ << " : PARAMETERLESS constructor." << endl << "Message: " << constructor_message_ << endl
		<< "data_ : " << data_ << " => " << DEFAULT_FAULTY_DATA << "\t" << "address of this: " << this << endl;
	data_ = DEFAULT_FAULTY_DATA;
}

faulty_copy_class::faulty_copy_class(const faulty_copy_class& source)
{
	constructor_counter_++;
	cout << endl << "faulty_copy_class constructor #" << constructor_counter_ << " : COPY constructor." << endl << "Message: " << constructor_message_ << endl
		<< "data_: " << data_ << " source.data_: " << source.data_ << '\t' << "address of this: " << this << '\t' << "address of source: " << &source << endl;

	//Contrary to healthy_copy_class, since data_ is not assigned here, a parameter of faulty_copy_class will not have the same data_ as the argument.
	//The same thing can be said for all the cases in healthy_copy_class tests where copy constructor was called.
}

void faulty_parameter_function(faulty_copy_class parameter_obj)
{
	//The data_ of parameter_obj will always be useless data since copy constructor does not assign argument's data_ to parameter_obj.
	cout << endl << "faulty_parameter_FUNCTION called. parameter_obj.data_ is: " << parameter_obj.get_data() << "\t" << "and the address of parameter_obj is: " << &parameter_obj << endl;
}

//This function runs the test cases for healthy_copy_class.
void run_faulty_copyable_class_tests()
{
	//Copy constructor for parameters
	faulty_copy_class::constructor_message_ = "Declaring argument_obj without assignment. (Constructor #1: Parameterless)";		//WILL be printed.
	faulty_copy_class argument_obj;
	//Causes parameterless constructor to be called.
	mark_test_case_end();

	faulty_copy_class::constructor_message_ = "Calling function with argument_obj as arguement. (Constructor #2: Copy)";		//WILL be printed.
	faulty_parameter_function(argument_obj);
	//Causes copy constructor to be called with argument_obj as argument.
	//Also since faulty_copy_class never assigns its data_ in copy constructor, the data_ of the argument_obj os not passed to parameter_obj inside the function.
	//Please note that the addresses of object whose constructor is called (parameter) matches the address of parameter inside function.
	//But at the same time it is not the same as argument whose address is printed at constructor #1.	
	mark_test_case_end();
}