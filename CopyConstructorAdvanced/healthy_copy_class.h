//The purpose of this class is to test when copy constructor is called. Also it's data_ values will be compared to faulty_copy_class.
#pragma once
#include <string>
using namespace std;

#define DEFAULT_HEALTHY_DATA 5

class healthy_copy_class
{
private:
	int data_;

public:
	static int constructor_counter_;
	static string constructor_message_;

	healthy_copy_class();
	healthy_copy_class(const healthy_copy_class&);

	inline int get_data() { return data_; }
	inline void set_data(int d) { data_ = d; }
};

void healthy_parameter_function(healthy_copy_class);
healthy_copy_class healthy_return_function();
void run_healthy_copyable_class_tests();