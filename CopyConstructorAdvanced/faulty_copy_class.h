#pragma once
#include <string>

#define DEFAULT_FAULTY_DATA 10

class faulty_copy_class
{
private:
	int data_;

public:
	static int constructor_counter_;
	static std::string constructor_message_;

	faulty_copy_class();
	faulty_copy_class(const faulty_copy_class&);

	inline int get_data() { return data_; }
	inline void set_data(int d) { data_ = d; }
};

void faulty_parameter_function(faulty_copy_class parameter_obj);
void run_faulty_copyable_class_tests();