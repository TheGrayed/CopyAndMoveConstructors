#include "stdafx.h"
#include "utility.h"
#include <iostream>
#include <string>
using namespace std;

void declare_test_batch(string batch_name)
{
	cout << endl << endl << "*****************************************************************" << endl << batch_name << ": "
		<< endl << "*****************************************************************" << endl << endl;
}

void mark_test_case_end()
{
	cout << "--------------------------------------------------------------" << endl;
	cin.get();
}
