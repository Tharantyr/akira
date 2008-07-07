#pragma once
#include <math.h>

#define EPSILON 0.0000000001

class Vector3f
{
public:
	Vector3f(float aX, float aY, float aZ)
	{
		_x = aX;
		_y = aY;
		_z = aZ;
	}

	
	Vector3f(const Vector3f& aV)
	{
		_x = aV._x;
		_y = aV._y;
		_z = aV._z;
	}


	float Length() const
	{
		return sqrt(_x * _x + _y * _y + _z * _z);
	}


	float LengthSq() const
	{
		return _x * _x + _y * _y + _z * _z;
	}


	Vector3f& Normalize()
	{
		float m = Length();

		_x /= m;
		_y /= m;
		_z /= m;

		return *this;
	}

	Vector3f& operator =(const Vector3f aV)
	{
		_x = aV._x; _y = aV._y; _z = aV._z;
		return *this;
	}


	Vector3f& operator +=(const Vector3f aV)
	{
		_x += aV._x; _y += aV._y; _z += aV._z;
		return *this;
	}


	Vector3f& operator -=(const Vector3f aV)
	{
		_x -= aV._x; _y -= aV._y; _z -= aV._z;
		return *this;
	}


	Vector3f& operator *=(float aN)
	{
		_x *= aN; _y *= aN; _z *= aN;
		return *this;
	}


	Vector3f& operator /=(float aN)
	{
		_x /= aN; _y /= aN; _z /= aN;
		return *this;
	}

	bool operator ==(const Vector3f &aV)
	{
		return	fabs(_x - aV._x) < EPSILON && 
				fabs(_y - aV._y) < EPSILON && 
				fabs(_z - aV._z) < EPSILON;
	}


	friend float Dot(const Vector3f &aV1, const Vector3f& aV2);
	friend Vector3f Cross(const Vector3f& aV1, const Vector3f& aV2);

	friend Vector3f operator +(const Vector3f& aV1, const Vector3f& aV2);
	friend Vector3f operator -(const Vector3f& aV1, const Vector3f& aV2);
	friend Vector3f operator *(const Vector3f& aV, float aN);
	friend Vector3f operator *(float aN, const Vector3f& aV);
	friend Vector3f operator /(const Vector3f& aV, float aN);
	friend Vector3f Normalize(const Vector3f &aV);
	friend void MakeFrame(const Vector3f& aV1, Vector3f &aV2, Vector3f &aV3);

	float _x;
	float _y;
	float _z;
};


inline float Dot(const Vector3f &aV1, const Vector3f& aV2)
{
	return aV1._x * aV2._x + aV1._y * aV2._y + aV1._z * aV2._z;
}


inline Vector3f Cross(const Vector3f& aV1, const Vector3f& aV2)
{
	return Vector3f(
		aV1._y * aV2._z - aV1._z * aV2._y,
		aV1._x * aV2._z - aV1._z * aV2._x,
		aV1._x * aV2._y - aV1._y * aV2._x
		);		
}


inline Vector3f operator +(const Vector3f& aV1, const Vector3f& aV2)
{
	return Vector3f(aV1._x + aV2._x, aV1._y + aV2._y, aV1._z + aV2._z);
}


inline Vector3f operator -(const Vector3f& aV1, const Vector3f& aV2)
{
	return Vector3f(aV1._x - aV2._x, aV1._y - aV2._y, aV1._z - aV2._z);
}


inline Vector3f operator *(const Vector3f& aV, float aN)
{
	return Vector3f(aV._x * aN, aV._y * aN, aV._z * aN);
}


inline Vector3f operator *(float aN, const Vector3f& aV)
{
	return Vector3f(aV._x * aN, aV._y * aN, aV._z * aN);
}


inline Vector3f operator /(Vector3f const& aV, float aN)
{
	return Vector3f(aV._x / aN, aV._y / aN, aV._z / aN);
}


inline Vector3f Normalize(const Vector3f& aV)
{
	return aV / aV.Length();
}


inline void MakeFrame(const Vector3f& aV1, Vector3f& aV2, Vector3f& aV3)
{
	if (fabs(aV1._x) > fabs(aV1._y))
	{
		float invLen = 1.0f / sqrt(aV1._x * aV1._x + aV1._z * aV1._z);
		aV2 = Vector3f(-aV1._z * invLen, 0.0f, aV1._x * invLen);
	}
	else
	{
		float invLen = 1.0f / sqrt(aV1._y * aV1._y + aV1._z * aV1._z);
		aV2 = Vector3f(0.0f, aV1._z * invLen, -aV1._y * invLen);
	}

	aV3 = Cross(aV1, aV2);
}


inline float Distance(const Vector3f& aV1, const Vector3f& aV2)
{
	return (aV1 - aV2).Length();
}


inline float DistanceSq(const Vector3f& aV1, const Vector3f& aV2)
{
	return (aV1 - aV2).LengthSq();
}





