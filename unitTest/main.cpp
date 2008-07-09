// unitTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector.h"
#include <boost/test/unit_test.hpp>
using namespace boost::unit_test;

extern void Vector3TestCases(void);


test_suite*
init_unit_test_suite(int, char* [])
{
	test_suite* suite = BOOST_TEST_SUITE("Akira Math Library Test Suite");
	
	suite->add(BOOST_TEST_CASE(&Vector3TestCases));

	return suite;
}
