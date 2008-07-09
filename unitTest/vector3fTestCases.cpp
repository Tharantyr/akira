#include "vector.h"
#include<boost/test/unit_test.hpp>
using namespace boost::unit_test;

void TestConstructors()
{
	Vector3f v1(1.0f, 0.0f, -1.0f);

	BOOST_CHECK_EQUAL(v1._x, 1.0f);
	BOOST_CHECK_EQUAL(v1._y, 0.0f);
	BOOST_CHECK_EQUAL(v1._z, -1.0f);

	Vector3f v2(v1);

	BOOST_CHECK_EQUAL(v2._x, 1.0f);
	BOOST_CHECK_EQUAL(v2._y, 0.0f);
	BOOST_CHECK_EQUAL(v2._z, -1.0f);
}


void TestInternalFunctions()
{
	//Test Length
	Vector3f v(1.0f, 1.0f, 1.0f);
	BOOST_CHECK_EQUAL(v.Length(), sqrt(3.0f));
	
	//Test Length Sqaured
	BOOST_CHECK_EQUAL(v.LengthSq(), 3.0f);

	Vector3f v1(2.0f, 3.0f, 4.0f);
	v1.Normalize();
	BOOST_CHECK_EQUAL(v1.LengthSq(), 1.0f);
}


void TestInternalOperators()
{
	//Test = operator
	Vector3f v(0, 0, 0);
	Vector3f v1(1, 2, 3);
	v = v1;

	BOOST_CHECK_EQUAL(v._x, v1._x);
	BOOST_CHECK_EQUAL(v._y, v1._y);
	BOOST_CHECK_EQUAL(v._z, v1._z);

	//Test += operator
	v += v1;
	BOOST_CHECK_EQUAL(v._x, 2);
	BOOST_CHECK_EQUAL(v._y, 4);
	BOOST_CHECK_EQUAL(v._z, 6);

	//Test -= operator
	v -= v1;
	BOOST_CHECK_EQUAL(v._x, 1);
	BOOST_CHECK_EQUAL(v._y, 2);
	BOOST_CHECK_EQUAL(v._z, 3);

	//Test *= operator
	v *= 2;
	BOOST_CHECK_EQUAL(v._x, 2);
	BOOST_CHECK_EQUAL(v._y, 4);
	BOOST_CHECK_EQUAL(v._z, 6);

	//Test /= operator
	v /= 2;
	BOOST_CHECK_EQUAL(v._x, 1);
	BOOST_CHECK_EQUAL(v._y, 2);
	BOOST_CHECK_EQUAL(v._z, 3);

	//Test == operator
	BOOST_CHECK_EQUAL(v == Vector3f(1, 2, 3), true);
}


void TestExternalFunctions()
{
	//Test Dot function
	Vector3f v1(1, 2, 3);
	Vector3f v2(2, 3, 4);

	BOOST_CHECK_EQUAL(Dot(v1, v2), 1 * 2 + 2 * 3 + 3 * 4); 
	
	//Test Cross function
	Vector3f v3(0, 0, 0);
	v3 = Cross(v1, v2);	
	BOOST_CHECK_EQUAL(v3._x, 2 * 4 - 3 * 3);
	BOOST_CHECK_EQUAL(v3._y, 1 * 4 - 2 * 3);
	BOOST_CHECK_EQUAL(v3._z, 1 * 3 - 2 * 2);

	//Test Normalize function
	v3 = Normalize(v1);
	BOOST_CHECK_EQUAL(v3.Length() - 1 < EPSILON, true);

	//Test Make frame function
	MakeFrame(v1, v2, v3);

	//Test Distance
	BOOST_CHECK_EQUAL(Distance(v1, v2), (v1 - v2).Length());
	//Test DistanceSq
	BOOST_CHECK_EQUAL(DistanceSq(v1, v2), (v1 - v2).LengthSq());
}


void TestExternalOperators()
{
	Vector3f v1(1, 2, 3);
	Vector3f v2(2, 3, 4);
	Vector3f v3(0, 0, 0);

	//Test + operator
	v3 = v1 + v2;
	BOOST_CHECK_EQUAL(v3 == Vector3f(3, 5, 7), true);

	//Test - operator
	v3 = v1 - v2;
	BOOST_CHECK_EQUAL(v3 == Vector3f(-1, -1, -1), true);

	//Test * operator
	//Test / operator
}


void Vector3TestCases()
{
	TestConstructors();
	TestInternalFunctions();
	TestInternalOperators();
	TestExternalFunctions();
	TestExternalOperators();

}