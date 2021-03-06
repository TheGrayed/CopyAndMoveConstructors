#include "stdafx.h"
#include "inner_outer_class.h"
#include "utility.h"
#include <iostream>
using namespace std;

int inner_class::constructor_counter_ = 0;
string inner_class::constructor_message_ = string("No message is set for inner_class yet.");

int outer_class::constructor_counter_ = 0;
string outer_class::constructor_message_ = string("No message is set for outer_class yet.");

inner_class::inner_class()
{
	constructor_counter_++;
	cout << endl << "inner_class constructor #" << constructor_counter_ << " : PARAMETERLESS constructor." << endl << "Message: " << constructor_message_ << endl
		<< "data_ : " << data_ << " => " << DEFAULT_INNER_DATA << "\t" << "address of this: " << this << endl;
	data_ = DEFAULT_INNER_DATA;
}

inner_class::inner_class(const inner_class& source)
{
	constructor_counter_++;
	cout << endl << "inner_class constructor #" << constructor_counter_ << " : COPY constructor." << endl << "Message: " << constructor_message_ << endl
		<< "data_: " << data_ << " => " << source.data_ + 1 << '\t' << "address of this: " << this << endl << "address of source: " << &source << endl;
	data_ = source.data_ + 1;
}

void inner_class::set_data(int data)
{
	data_ = data;
}

int inner_class::get_data()
{
	return data_;
}

outer_class::outer_class()
{
	constructor_counter_++;
	cout << endl << "outer_class constructor #" << constructor_counter_ << " : PARAMETERLESS constructor." << endl << "Message: " << constructor_message_ << endl
		<< "address of this: " << this << endl;
}

inner_class outer_class::get_inner_data()
{
	return inner_data_obj_;
}

inner_class & outer_class::get_inner_data_ref()
{
	return inner_data_obj_;
}

void outer_class_parameter_function(outer_class parameter_obj)
{
	cout << endl << "outer_class_parameter_FUNCTION called." << endl << "parameter_obj.inner_data_obj_.data_: " << parameter_obj.get_inner_data_ref().get_data()
		<< endl << "the address of parameter_obj is: " << &parameter_obj << endl << "and the address of parameter_obj.inner_data_obj_ is: " << &parameter_obj.get_inner_data_ref() << endl;
}

outer_class & outer_class_copy_and_return_ref_function(outer_class parameter_obj)
{
	cout << endl << "outer_class_copy_and_return_ref_FUNCTION called." << endl << "parameter_obj.inner_data_obj_.data_: " << parameter_obj.get_inner_data_ref().get_data()
		<< endl << "the address of parameter_obj is: " << &parameter_obj << endl << "and the address of parameter_obj.inner_data_obj_ is: " << &parameter_obj.get_inner_data_ref() << endl;

	return parameter_obj;
}

void run_inner_outer_class_tests()
{
	//Copy constructor for parameters and their object members.

	//Declaring an object containing another aboject.
	outer_class::constructor_message_ = "Declaring argument_obj without assignment. (Outer constructor #1: Parameterless)";		//WILL be printed.
	inner_class::constructor_message_ = "Declaring argument_obj of outer_class type causes its inner_data_obj_ to be constructed as well. (Inner constructor #1: Parameterless)";
	//WILL be printed.
	outer_class argument_obj;
	cout << "The address of argument_obj.inner_data_object_ is: " << &argument_obj.get_inner_data_ref() << endl;
	mark_test_case_end();

	outer_class::constructor_message_ = "Passing argument_obj to outer_class_parameter_function. This message is not printed since copy constructor is generated by compiler and doesn't print constructor_message_."; //WILL NOT be printed.
	//Copy constructor of outer_class is left to be generated by compiler so that it's default behavior regarding inner_data_obj_ could be examined and therefor doens't print any massage.
	inner_class::constructor_message_ = "Passing argument_obj of outer_class type to function causes copy constructor call for inner_data_obj_. (Inner constructor #2: Copy)";
	//Since an object of outer_class is being passed to function, COMPILER GENERATED COPY CONSTRUCTOR FOR outer_class CALLS COPY CONSTRUCTOR FOR ITS inner_data_obj_.
	outer_class_parameter_function(argument_obj);
	mark_test_case_end();

	outer_class::constructor_message_ = "Declaring to_be_assigned and assigning a reference to it. This message is not printed since copy constructor is generated by compiler and doesn't print constructor_message_.";
	//WILL NOT be printed.
	//Again copy constructor of outer_class is left to be generated by compiler and therefor it will not print any message.
	inner_class::constructor_message_ = "Passing argument_obj of outer_class type to function causes copy constructor call for inner_data_obj_. (Inner constructor #3: Copy)";
	//Since an object of outer_class is being passed to function, compiler generated copy constructor for outer_class calls copy constructor for its inner_data_obj_.
	outer_class& to_be_assigned = outer_class_copy_and_return_ref_function(argument_obj);
	//The function returns a reference so no copy is done by returning from function, and since to_be_assigned is assigned by reference no copy is done by assignment as well.
	cout << endl << "The data_ inside to_be_assigned's inner_data_obj_: " << to_be_assigned.get_inner_data_ref().get_data() << endl << "the address of to_be_assigned.inner_data_obj_ is: "
		<< &to_be_assigned.get_inner_data_ref() << endl;
	mark_test_case_end();

	inner_class::constructor_message_ = "Returning an object of inner_class type by value (to_be_assigned.get_inner_data()) causes copy constructor to be called. (Inner constructor #4: Copy)";
	//WILL be printed.
	to_be_assigned.get_inner_data();
	//The to_be_assigned.inner_data_obj_ os coppied (by copy constructor) to the return value of the get_inner_data().
	mark_test_case_end();

}
