using System;
using System.Collections.Generic;
using System.Text;

namespace Akira.Maths
{
    class Matrix
    {
        public Matrix(Matrix m)
        {
            for (int i = 0; i < 4; i++
            {
                for (int j = 0; j < 4; j++)
                {
                    _mat[i][j] = m._mat[i][j];
                }
            }
        }


        public Matrix(Vector3 c1, Vector3 c2, Vector3 c3, Vector3 c4)
        {
            _mat[0][0] = c1.X;
            _mat[1][0] = c1.Y;
            _mat[2][0] = c1.Z;
            _mat[3][0] = 0;

            _mat[0][1] = c2.X;
            _mat[1][1] = c2.Y;
            _mat[2][1] = c2.Z;
            _mat[3][1] = 0;

            _mat[0][2] = c3.X;
            _mat[1][2] = c3.Y;
            _mat[2][2] = c3.Z;
            _mat[3][2] = 0;

            _mat[0][3] = c4.X;
            _mat[1][3] = c4.Y;
            _mat[2][3] = c4.Z;
            _mat[3][3] = 1;
        }

        public double[] this[int index]
        {
            get
            {
                return _mat[index];
            }
        }


        static public Matrix zero()
        {
            Vector3 vec = new Vector3(0, 0, 0);

            return new Matrix(vec, vec, vec, vec);
        }


        static public Matrix identity()
        {
            return new Matrix(new Vector3(1, 0, 0), new Vector3(0, 1, 0), new Vector3(0, 0, 1), new Vector3(0, 0, 0));
        }


        static public Matrix translate(double x, double y, double z)
        {
            return new Matrix(new Vector3(1, 0, 0), new Vector3(0, 1, 0), new Vector3(0, 0, 1), new Vector3(x, y, z));
        }


        static public Matrix rotateX(double rad)
        {
        }


        static public Matrix rotateY(double rad)
        {
        }


        static public Matrix rotateZ(double rad)
        {
        }

        static public Matrix lookAt(Vector3 look, Vector3 up)
        {
        }


        static public Vector3 operator *(Matrix m, Vector3 v)
        {
            return new Vector3(
                            m._mat[0][0] * v._X + m._mat[0][1] * v._Y + m._mat[0][2] * v.Z + m._mat[0][3],
                            m._mat[1][0] * v._X + m._mat[1][1] * v._Y + m._mat[1][2] * v.Z + m._mat[1][3],
                            m._mat[2][0] * v._X + m._mat[2][1] * v._Y + m._mat[2][2] * v.Z + m._mat[2][3]);
        }


        static public Matrix operator *(Matrix m1, Matrix m2)
        {
            return new Matrix(
                new Vector3(m1._mat[0][0] * m2._mat[0][0] + m1._mat[0][1] * m2._mat[1][0] + m1._mat[0][2] * m2._mat[2][0],
                            m1._mat[1][0] * m2._mat[0][0] + m1._mat[1][1] * m2._mat[1][0] + m1._mat[1][2] * m2._mat[2][0],
                            m1._mat[2][0] * m2._mat[0][0] + m1._mat[2][1] * m2._mat[1][0] + m1._mat[2][2] * m2._mat[2][0]),
                new Vector3(m1._mat[0][1] * m2._mat[0][1] + m1._mat[0][1] * m2._mat[1][1] + m1._mat[0][2] * m2._mat[2][1],
                            m1._mat[1][1] * m2._mat[0][1] + m1._mat[1][1] * m2._mat[1][1] + m1._mat[1][2] * m2._mat[2][1],
                            m1._mat[2][1] * m2._mat[0][1] + m1._mat[2][1] * m2._mat[1][1] + m1._mat[2][2] * m2._mat[2][1]),
                new Vector3(m1._mat[0][2] * m2._mat[0][2] + m1._mat[0][1] * m2._mat[1][2] + m1._mat[0][2] * m2._mat[2][2],
                            m1._mat[1][2] * m2._mat[0][2] + m1._mat[1][1] * m2._mat[1][2] + m1._mat[1][2] * m2._mat[2][2],
                            m1._mat[2][2] * m2._mat[0][2] + m1._mat[2][1] * m2._mat[1][2] + m1._mat[2][2] * m2._mat[2][2]),
                new Vector3(m1._mat[0][3] * m2._mat[0][3] + m1._mat[0][1] * m2._mat[1][3] + m1._mat[0][2] * m2._mat[2][3],
                            m1._mat[1][3] * m2._mat[0][3] + m1._mat[1][1] * m2._mat[1][3] + m1._mat[1][2] * m2._mat[2][3],
                            m1._mat[2][3] * m2._mat[0][3] + m1._mat[2][1] * m2._mat[1][3] + m1._mat[2][2] * m2._mat[2][3]));
        }

        static public Matrix inverse(Matrix m)
        {
        }

        protected double[,] _mat = new double[4, 4];
    }
}
