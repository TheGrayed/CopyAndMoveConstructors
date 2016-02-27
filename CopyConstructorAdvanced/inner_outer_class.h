#pragma once
#include <string>
using namespace std;

#define DEFAULT_INNER_DATA 20

class inner_class
{
private:
	int data_;

public:
	static int constructor_counter_;
	static string constructor_message_;

	inner_class();
	inner_class(const inner_class&);
	void set_data(int);
	int get_data();
};

class  outer_class
{
private:
	inner_class inner_data_obj_;
public:
	static int constructor_counter_;
	static string constructor_message_;

	outer_class();
	inner_class get_inner_data();
	inner_class& get_inner_data_ref();
};

void outer_class_parameter_function(outer_class);
outer_class& outer_class_copy_and_return_ref_function(outer_class);
void run_inner_outer_class_tests();