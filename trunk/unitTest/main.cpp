// unitTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <aeryn/test_runner.hpp>
#include <aeryn/is_equal.hpp>
#include <aeryn/use_name.hpp>
#include <iostream>
#include "vector.h"

extern void Vector3TestCases(void);

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace Aeryn;

	TestRunner testRunner;
	testRunner.Add("Vector3<double> tests", TestCase(USE_NAME(Vector3TestCases)));
	
	testRunner.Run();

	char i;
	std::cin >> i; 
}

