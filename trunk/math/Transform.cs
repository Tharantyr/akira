namespace Akira.Maths
{
    public Transform(Transform t)
    {
    }

    public Transform(Matrix m)
    {
    }

    static public Transform operator *(Transform m1, Transform m2)
    {
    }


    static public operator *(Transfrom m, Vector3 v)
    {
    }

    static public operator *(Transform m, Normal n)
    {
    }

    static public operator *(Transfrom m, Point3 p)
    {
    }


    public Matrix Mat
    {
        get
        {
            return _mat;
        }
        set
        {
            _mat = value;
            _invMat = Matrix.inverse(_mat);
        }
    }


    public Matrix Inv
    {
        get
        {
            return _invMat;
        }
        set
        {
            _invMat = value;
            _mat = Matrix.inverse(_invMat);
        }
    }

    Matrix _mat;
    Matrix _invMat;
}
