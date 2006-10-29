using System;
using System.Collections.Generic;
using System.Text;
using System.Math;

namespace Akira.Maths
{
    class Vector3
    {
        protected double _x;
        protected double _y;
        protected double _z;

        public Vector3(double x, double y, double z)
        {
            _x = x;
            _y = y;
            _z = z;
        }

        public Vector3(Vector3 vec)
        {
            _x = vec._x;
            _y = vec._y;
            _z = vec._z;
        }

        public double X
        {
            get
            {
                return _x;
            }
            set
            {
                _x = value;
            }
        }

        public double Y
        {
            get
            {
                return _y;
            }
            set
            {
                _y = value;
            }
        }

        public double Z
        {
            get
            {
                return _z;
            }
            set
            {
                _z = value;
            }
        }

        public double Length
        {
            get
            {
                return Math.Sqrt(_x * _x + _y * _y + _z * _z);
            }
        }

        public double LengthSq
        {
            get
            {
                return _x * _x + _y * _y + _z * _z;
            }
        }

        static public Vector3 zero()
        {
            return new Vector3(0, 0, 0);
        }

        static public Vector3 unit()
        {
            return new Vector3(1, 1, 1);
        }

        static public Vector3 operator +(Vector3 v1, Vector3 v2)
        {
            return new Vector3(v1._x + v2._x, v1._y + v2._y, v1._z + v2._z);
        }

        static public Vector3 operator -(Vector3 v1, Vector3 v2)
        {
            return new Vector3(v1._x - v2._x, v1._y + v2._y, v1._z + v2._z);
        }

        static public Vector3 operator *(Vector3 vec, double x)
        {
            return new Vector3(vec._x * x, vec._y * x, vec._z * x);
        }

        static public Vector3 operator *(double x, Vector3 vec)
        {
            return vec * x;
        }

        static public Vector3 operator *(Vector3 v1, Vector3 v2)
        {
            return new Vector3(v1._x * v2._x, v1._y * v2._y, v1._z * v2._z);
        }

        static public Vector3 operator /(Vector3 v1, double x)
        {
            return new Vector3(v1._x / x, v1._y / x, v1._z / x);
        }

        static public double dot(Vector3 v1, Vector3 v2)
        {
            return v1._x * v2._x + v1._y * v2._y + v1._z * v2._z;
        }

        static public Vector3 cross(Vector3 v1, Vector3 v2)
        {
        }

        Vector3 normal()
        {
            double len = Length;

            return new Vector3(_x / len, _y / len, _z / len);
        }

        Vector3 normalize()
        {
            double len = Length;

            _x /= len; _y /= len; _z /= len;

            return this;
        }
    }
}
