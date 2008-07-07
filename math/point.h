#pragma once
#include <math.h>
#include "vector.h"

class Point3f
{
public:
	Point3f(float aX = 0, float aY = 0, float aZ = 0)
	{
		_x = aX; _y = aY; _z = aZ;
	}

	
	Point3f(const Point3f& aP)
	{
		_x = aP._x; _y = aP._y; _z = aP._z;
	}

	
	Point3f& operator =(const Point3f& aP)
	{
		_x = aP._x; _y = aP._y; _z = aP._z;
		return *this;
	}


	Point3f& operator +=(const Vector3f& aV)
	{
		_x += aV._x; _y += aV._y; _z += aV._z;
		return *this;
	}


	Point3f& operator -=(const Vector3f& aV)
	{
		_x -= aV._x; _y -= aV._y; _z -= aV._z;
		return *this;
	}

	
	Point3f& operator *=(float aN)
	{
		_x *= aN; _y *= aN; _z *= aN;
		return *this;
	}


	Point3f& operator /=(float aN)
	{
		_x /= aN; _y /= aN; _z /= aN;
		return *this;
	}

	friend Vector3f operator +(const Point3f& aP1, const Point3f& aP2);
	friend Point3f operator +(const Point3f& aP, const Vector3f& aV);
	friend Vector3f operator -(const Point3f& aP1, const Point3f& aV);
	friend Point3f operator -(const Point3f& aP, const Vector3f& aV);
	friend Point3f operator *(const Point3f& aP, float aN);
	friend Point3f operator /(const Point3f& aP, float aN);
	friend Point3f Distance(const Point3f& aP1, const Point3f& aP2);
	friend Point3f DistanceSq(const Point3f& aP1, const Point3f& aP2);


	float _x;
	float _y;
	float _z;
};


inline Vector3f operator +(const Point3f& aP, const Point3f& aP2);
{
	return Vector3f(aP1._x + aP2._x, aP1._y + aP2._y, aP1._z + aP2._z);
}


inline Point3f operator +(const Point3f& aP, const Vector3f& aV);
{
	return Point3f(aP._x + aV._x, aP._y + aV._y, aP._z + aV._z);
}


inline Vector3f operator -(const Point3f& aP1, const Point3f& aP2);
{
	return Vector3f(aP1._x - aP2._x, aP1._y - aP2._y, aP1._z - aP2._z);
}


inline Point3f operator -(const Point3f& aP, const Vector3f& aV);
{
	return Point3f(aP._x - aV._x, aP._y - aV._y, aP._z - aV._z);
}


inline Point3f operator *(const Point3f& aP, float aN);
{
	return Point3f(aP._x * aN, aP._y * aN, aP._z * aN);
}


inline Point3f operator /(const Point3f& aP, float aN);
{
	return Point3f(aP._x / aN, aP._y / aN, aP._z / aN);
}


inline float Distance(const Point3f& aP1, const Point3f& aP2)
{
	return (aP1 - aP2).Length();
}


inline float DistanceSq(const Point3f& aP1, const Point3f& aP2)
{
	return (aP1 - aP2).LengthSq();
}

