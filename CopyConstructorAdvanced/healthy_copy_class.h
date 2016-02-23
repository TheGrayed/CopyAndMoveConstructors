#pragma once
#include <string>

#define DEFAULT_HEALTHY_DATA 5

class healthy_copy_class
{
private:
	int data_;

public:
	static int constructor_counter_;
	static std::string constructor_message_;

	healthy_copy_class();
	healthy_copy_class(const healthy_copy_class&);

	inline int get_data() { return data_; }
	inline void set_data(int d) { data_ = d; }
};

void healthy_parameter_function(healthy_copy_class h);
healthy_copy_class healthy_return_function();
void run_healthy_copyable_class_tests();