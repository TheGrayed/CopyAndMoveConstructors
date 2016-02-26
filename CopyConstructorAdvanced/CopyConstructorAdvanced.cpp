// Main function and entry point
//

#include "stdafx.h"
#include "utility.h"
#include "healthy_copy_class.h"
#include "faulty_copy_class.h"
#include <iostream>
using namespace std;

int main()
{
	declare_test_batch("healthy_copy_class tests");

	run_healthy_copyable_class_tests();

	declare_test_batch("faulty_copy_class tests");

	run_faulty_copyable_class_tests();

	return 0;
}