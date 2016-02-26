#include "stdafx.h"
#include "utility.h"
#include "healthy_copy_class.h"
#include <iostream>
#include <string>
using namespace std;

int healthy_copy_class::constructor_counter_ = 0;
std::string healthy_copy_class::constructor_message_ = string("No message is set for healthy_copy_class yet.");

healthy_copy_class::healthy_copy_class()
{
	constructor_counter_++;
	cout << endl << "healthy_copy_class constructor #" << constructor_counter_ << " : PARAMETERLESS constructor."<< endl << "Message: " << constructor_message_ << endl
		<< "data_ : " << data_ << " => " << DEFAULT_HEALTHY_DATA <<'\t' << "address of this: " << this << endl;
	data_ = DEFAULT_HEALTHY_DATA;
}

healthy_copy_class::healthy_copy_class(const healthy_copy_class& source)
{
	//Since copy constructor in this program is called by either assignment or function call,
	//then source should be either an arguement or an object that is being assigned to another by assignment operator,
	//and the object whose constructor is called (this) refers to either parameter or the object being assigned to.
	//One of the most famous uses of copy constructor is "deep copy" of the object,
	//where simply copying pointers and references in the class isn't sufficient, and their actual data should be copied as well.
	constructor_counter_++;
	cout << endl << "healthy_copy_class constructor #" << constructor_counter_ << " : COPY constructor." << endl << "Message: " << constructor_message_ << endl
		<< "data_: " << data_ << " => " << source.data_ << '\t' << "address of this: " << this << '\t' << "address of source: " << &source << endl;
	data_ = source.data_;	
	//As seen in faulty_copy_class, without this line, data_ of the object whose constructor is called (probably parameter or value on the left side of assignment)
	//is not assigned at all, and will have different value compared to source (probably arguement or value on the right side of assignment).
}


//At the start of parameter_obj's lifetime, the copy constructor is called with referece to argument of this function call as constructor's parameter.
void healthy_parameter_function(healthy_copy_class parameter_obj)
{
	cout << endl << "healthy_parameter_FUNCTION called. parameter_obj.data_ is: " << parameter_obj.get_data() << "\t" << "and the address of parameter_obj is: " << &parameter_obj << endl;
}


healthy_copy_class healthy_return_function()
{
	return healthy_copy_class();
}

//This function runs the test cases for healthy_copy_class.
void run_healthy_copyable_class_tests()
{
	//Copy constructor for parameters
#pragma region Copy Constructor for Parameters

	healthy_copy_class::constructor_message_ = "Declaring argument_obj without assignment. (Constructor #1: Parameterless)";		//WILL be printed.
	healthy_copy_class argument_obj;	
	//Causes parameterless constructor to be called.
	mark_test_case_end();

	healthy_copy_class::constructor_message_ = "Calling function with argument_obj as arguement. (Constructor #2: Copy)";		//WILL be printed.
	healthy_parameter_function(argument_obj);
	//Causes copy constructor to be called with argument_obj as argument.
	//Please note that the addresses of object whose constructor is called (parameter) matches the address of parameter inside function.
	//But at the same time it is not the same as argument whose address is printed at constructor #1.
	mark_test_case_end();

#pragma endregion


	//*************************************************************************************************************************************************************************************


	//Copy constructor in assignment
#pragma region Copy Constructor and Assignment

	healthy_copy_class::constructor_message_ = "Declaring an object (declare_and_assign_obj) and assigning argument_obj to it in the same line. (Constructor #3: Copy)";		//WILL be printed.
	//As is done in next line, copy constructor is also called in an assignment for the object declared in the same line
	healthy_copy_class declare_and_assign_obj = argument_obj;
	mark_test_case_end();

	healthy_copy_class::constructor_message_ = "Declaring an object (to_beassigned_obj) without assignment. (Constructor #4: Parameterless)";		//WILL be printed.
	healthy_copy_class to_be_assigned_obj;		//Again, causes parameterless constructor to be called.
	mark_test_case_end();

	healthy_copy_class::constructor_message_ = "Assigning an already declared object (arguement_obj) to another already declared object (to_be_assigned_obj). (Never printed)";
	//WILL NOT be printed therefor expect a messageless cin.get(). 
	to_be_assigned_obj = argument_obj;
	//In this case, copy constructor is not called since healthy_to_be_assigned has been declared before.
	//However this process can be customized by overloading assignment operator.
	mark_test_case_end();
#pragma endregion


	//*************************************************************************************************************************************************************************************


	//In some cases, mostly when the object being passed or assigned is a temporary object, compiler may choose not to call copy constructor.
	//Please note that some of these behaviors are not mandatory in c++ standard, and therefor may vary from compiler to compiler or based on compiler's settings.
#pragma region Some Copy Elision Cases

	healthy_copy_class::constructor_message_ = "Assigning a temporary object created by constructor to object declared in the same line (to_be_assigned_obj2). (Constructor #5: Parameterless)";
	//WILL be printed. (But only ONCE.)
	healthy_copy_class to_be_assigned_obj2 = healthy_copy_class();
	cout << "to_be_assigned_obj2 's address is: " << &to_be_assigned_obj2 << endl;
	//The most common case of copy elision.
	//Due to line 74 (Constructor #3)'s test, we expect to see 2 constructor calls, one for temporary object on the right and one for to_be_assigned_obj2.
	//But instead ONLY ONE object is created, and the parameterless constructor is called on to_be_assigned_obj2 itself.
	//Please note that the address printed in parameterless constructor matches the address of the to_be_assigned_obj2 printed afterwards.
	//In other words the compiler's copy elision rules dictate that instead of creating an object then assigning it to
	//an object that is just declared which creates a second object, ONLY ONE object should be created.
	mark_test_case_end();

	healthy_copy_class::constructor_message_ = "Passing a temporary object created by constructor as arguement. (Constructor #6: Parameterless)";		//WILL be printed. (But only ONCE.)
	healthy_parameter_function(healthy_copy_class());
	//Contrary to what was done at line 57 (Constructor #2), this line DOES NOT invoke a call to COPY constructor,
	//but instead the PARAMETER of healthy_parameter_function IS CONSTRUCTED WITH PARAMETERLESS CONSTRUCTOR.
	//Please note that the address printed in parameterless constructor matches the address of the function's parameter.
	//In other words the compiler's copy elision rules dictate that instead of creating an object then passing it to
	//function by value which creates a second object, ONLY ONE object should be created.
	mark_test_case_end();

	healthy_copy_class::constructor_message_ = "Assigning a function return value to an object declared in the same line. (Constructor #7: Parameterless)";		//WILL be printed. (But only ONCE.)
	healthy_copy_class declare_and_assign_from_func_obj = healthy_return_function();
	//Again, contrary to what was done at line 74 (Constructor #3), copy constructor is not called, but parameterless constructor is. (Inside healthy_return_function.)
	//since right value of assignment is a temporary object and is already constructed in healthy_return_function.
	//Like before compiler's copy elision rules dictate that only 1 object should be created instead of 2;
	mark_test_case_end();

	healthy_copy_class::constructor_message_ = "Passing a temporary object created by function as arguement. (Constructor #8: Parameterless)";		//WILL be printed. (But only ONCE.)
	healthy_parameter_function(healthy_return_function());
	//As a combination of 2 previous Copy Elision rules, again ONLY ONE object is created, instead of 3.
	//(1 call inside the healthy_return_function for direct constructor call, 1 call for temporary object created 
	//after returning from healthy_return_function and 1 call for healthy_parameter_function's parameter.
	//Instead all 3 are reduced to 1 object and 1 parameterless constructor call)
	mark_test_case_end();

#pragma endregion

}