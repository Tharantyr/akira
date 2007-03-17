using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using Akira.Maths;

namespace Akira.UnitTests
{
    [TestFixture]
    public class Vector3Tests
    {
        [Test]
        public void testProperties()
        {
            Vector3 vec = new Vector3(1, 2, 3);

            Assert.AreEqual(1, vec.X);
            Assert.AreEqual(2, vec.Y);
            Assert.AreEqual(3, vec.Z);

            vec.set(0, 0, 0);
            Assert.AreEqual(0, vec.X);
            Assert.AreEqual(0, vec.Y);
            Assert.AreEqual(0, vec.Z);
        }

        [Test]
        public void testLength()
        {
            Vector3 vec = new Vector3(1, 1, 1);

            Assert.AreEqual(Math.Sqrt(3), vec.Length);

            vec.set(0, 0, 0);
            Assert.AreEqual(0, vec.Length);

            vec.set(-1, -1, -1);
            Assert.AreEqual(Math.Sqrt(3), vec.Length);

            vec.set(0, 0, 0);
            Assert.AreEqual(0, vec.LengthSq);

            vec.set(1, 1, 1);
            Assert.AreEqual(3, vec.LengthSq);
        }

        [Test]
        public void testStaticCreation()
        {
            Assert.AreEqual(new Vector3(0, 0, 0), Vector3.zero());
            Assert.AreEqual(new Vector3(1, 1, 1), Vector3.unit());
        }

        [Test]
        public void testOperators()
        {
            Vector3 v1 = new Vector3(1, 1, 1);
            Vector3 v2 = new Vector3(2, 2, 2);
            
            //Test operator +
            Assert.AreEqual(new Vector3(3, 3, 3), v1 + v2);

            //Test operator -
            Assert.AreEqual(new Vector3(1, 1, 1), v2 - v1);

            //Test operator *
            Assert.AreEqual(new Vector3(4, 4, 4), v2 * 2);
            Assert.AreEqual(new Vector3(4, 4, 4), 2 * v2);
            Assert.AreEqual(new Vector3(2, 2, 2), v1 * v2);

            //Test operator /
            Assert.AreEqual(new Vector3(1, 1, 1), v2 / 2);

            //Test operator ==
            Assert.IsFalse(v1 == v2);
            Assert.IsTrue(v1 == new Vector3(1, 1, 1));
            Assert.IsTrue(v1 != v2);
            Assert.IsFalse(v1 != new Vector3(1, 1, 1));
        }

        [Test]
        public void testDotProduct()
        {
            Vector3 v1 = new Vector3(0, 0, 0);
            Vector3 v2 = new Vector3(1, 1, 1);

            Assert.AreEqual(0, Vector3.dot(v1, v2));
            v1.set(2, 2, 2);
            Assert.AreEqual(6, Vector3.dot(v1, v2));
        }

        [Test]
        public void testCrossProduct()
        {
            Assert.IsTrue(false, "Not implemented");
        }

        [Test]
        public void testNormal()
        {
            Vector3 v = new Vector3(1, 1, 1);

            Assert.AreEqual(new Vector3(1 / Math.Sqrt(3), 1 / Math.Sqrt(3), 1 / Math.Sqrt(3)), v.Normal);
            v.normalize();
            Assert.AreEqual(v.Normal, v);
        }
    }
}
