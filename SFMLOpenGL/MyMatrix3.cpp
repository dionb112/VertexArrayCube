/// <summary>
/// @author Dion Buckley
/// @date Feb 2017
/// Time taken: 5 hours roughly
/// No Known Bugs

#include "MyMatrix3.h"

/// <summary>
/// default constructor
/// assigns 9 matrix parts to 0
/// </summary>
MyMatrix3::MyMatrix3():
	m11{ 0.0 },
	m12{ 0.0 },
	m13{ 0.0 },
	m21{ 0.0 },
	m22{ 0.0 },
	m23{ 0.0 },
	m31{ 0.0 },
	m32{ 0.0 },
	m33{ 0.0 }
{
}
/// <summary>
/// overload constructor which takes 9 doubles and assings them to the 9 matrix parts
/// </summary>
/// <param name="a11"></param>
/// <param name="a12"></param>
/// <param name="a13"></param>
/// <param name="a21"></param>
/// <param name="a22"></param>
/// <param name="a23"></param>
/// <param name="a31"></param>
/// <param name="a32"></param>
/// <param name="a33"></param>
MyMatrix3::MyMatrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) :
	m11{ a11 },
	m12{ a12 },
	m13{ a13 },
	m21{ a21 },
	m22{ a22 },
	m23{ a23 },
	m31{ a31 },
	m32{ a32 },
	m33{ a33 }
{
}
/// <summary>
/// overload constructor which takes three 3D vector arguements and assigns the 9 matrix parts to the correct vector parts
/// </summary>
/// <param name="row1"></param>
/// <param name="row2"></param>
/// <param name="row3"></param>
MyMatrix3::MyMatrix3(MyVector3D row1, MyVector3D row2, MyVector3D row3) :
	m11{ row1.X() },
	m12{ row1.Y() },
	m13{ row1.Z() },
	m21{ row2.X() },
	m22{ row2.Y() },
	m23{ row2.Z() },
	m31{ row3.X() },
	m32{ row3.Y() },
	m33{ row3.Z() }
{
}

/// <summary>
/// default destructor
/// </summary>
MyMatrix3::~MyMatrix3()
{
}
/// <summary>
/// function which converts what's in the matrix data members to a string so they can be outputted to screen
/// </summary>
/// <returns></returns>
std::string MyMatrix3::toString()
{
	char tmpbuf[512];
	sprintf_s(tmpbuf, "{ [ %g, %g, %g ] [ %g, %g, %g ] [ %g, %g, %g ] }", m11, m12, m13, m21, m22, m23, m31, m32, m33);
	return tmpbuf;

	
}
/// <summary>
/// function which adds two 3D matrices
/// </summary>
/// <param name="other"> second matrix</param>
/// <returns> result after addition</returns>
MyMatrix3 MyMatrix3::operator+(const MyMatrix3 other) const
{
	MyMatrix3 result {	m11 + other.m11, m12 + other.m12, m13 + other.m13,
						m21 + other.m21, m22 + other.m22, m23 + other.m23,
						m31 + other.m31, m32 + other.m32, m33 + other.m33 };
	return result;
}
/// <summary>
/// function which subtracts two 3D matrices
/// </summary>
/// <param name="other"> second matrix</param>
/// <returns> result after subtraction</returns>
MyMatrix3 MyMatrix3::operator-(const MyMatrix3 other) const
{
	MyMatrix3 result {	m11 - other.m11, m12 - other.m12, m13 - other.m13,
						m21 - other.m21, m22 - other.m22, m23 - other.m23,
						m31 - other.m31, m32 - other.m32, m33 - other.m33 };
	return result;
}
/// <summary>
/// function which multiplies two 3D matrices
/// </summary>
/// <param name="other"> second matrix</param>
/// <returns> result after multiplication</returns>
MyMatrix3 MyMatrix3::operator*(const MyMatrix3 other) const
{
	MyMatrix3 result {	
		m11 * other.m11 + m12 * other.m21 + m13 * other.m31,
		m11 * other.m12 + m12 * other.m22 + m13 * other.m32,
		m11 * other.m13 + m12 * other.m23 + m13 * other.m33,
		m21 * other.m11 + m22 * other.m21 + m23 * other.m31,
		m21 * other.m12 + m22 * other.m22 + m23 * other.m32,
		m21 * other.m13 + m22 * other.m23 + m23 * other.m33,
		m31 * other.m11 + m32 * other.m21 + m33 * other.m31,
		m31 * other.m12 + m32 * other.m22 + m33 * other.m32,
		m31 * other.m13 + m32 * other.m23 + m33 * other.m33 };
	return result;
}
/// <summary>
/// function which multiplies a matrix and a vector
/// </summary>
/// <param name="vector"> the vector</param>
/// <returns> result after multiplication</returns>
MyVector3D MyMatrix3::operator*(const MyVector3D vector) const
{
	MyVector3D result{
		m11 * vector.X() + m12 * vector.Y() + m13 * vector.Z(),
		m21 * vector.X() + m22 * vector.Y() + m23 * vector.Z(),
		m31 * vector.X() + m32 * vector.Y() + m33 * vector.Z() };

	return result;
}
/// <summary>
/// function which multiplies a matrix by a scalar number
/// </summary>
/// <param name="scalar"> scalar</param>
/// <returns> result after multiplication</returns>
MyMatrix3 MyMatrix3::operator*(const double scalar) const
{
	MyMatrix3 result{
		m11 * scalar, m12 * scalar, m13 * scalar,
		m21 * scalar, m22 * scalar, m23 * scalar,
		m31 * scalar, m32 * scalar, m33 * scalar };
	return result;
}
/// <summary>
/// function which gives the transpose of a matrix (flipped rows and collums)
/// </summary>
/// <returns> result after transposition</returns>
MyMatrix3 MyMatrix3::transpose() const
{
	MyMatrix3 result{
		m11, m21, m31,
		m12, m22, m32,
		m13, m23, m33 };
	return result;
}
/// <summary>
/// function which gives the determinant of a 3x3 matrix
/// </summary>
/// <returns>det</returns>
double MyMatrix3::determinant() const
{
	double result = 0;
	result = (m11*(m22*m33 - m32 * m23) - m21 * (m33 * m12 - m32 * m13) + m31 * (m23 * m12 - m22 * m13));
	return result;
}
/// <summary>
/// function which gets the inverse of a 3x3 matrix, using the formula below.
/// </summary>
/// <returns>inverse</returns>
MyMatrix3 MyMatrix3::inverse() const
{
	if (determinant() == 0)
		return MyMatrix3();
	else
	{
		MyMatrix3 toDet{ m11, m12, m13, m21, m22, m23, m31, m32, m33 };
		double det = 0;
		det = toDet.determinant();
		MyMatrix3 inverse
		{ m33 * m22 - m32 * m23, m32 * m13 - m33 * m12, m23 * m12 - m22 * m13,
			m31 * m23 - m33 * m21, m33 * m11 - m31 * m13, m21 * m13 - m23 * m11,
			m32 * m21 - m31 * m22, m31 * m12 - m32 * m11, m22 * m11 - m21 * m12 };
		inverse = inverse * (1 / det);
		return inverse;
	}
	
}
/// <summary>
/// function which gets the matrix parts based on what row they are in.
/// </summary>
/// <param name="row">takes in an int which tells which row to check</param>
/// <returns> the three parts in that row</returns>
MyVector3D MyMatrix3::row(int row) const
{	
	MyVector3D result{};
	if (row == 0)
	{
		result = { m11, m12, m13 };
	}
	else if (row == 1)
	{
		result = { m21, m22, m23 };
	}
	else if (row == 2)
	{
		result = { m31, m32, m33 };
	}
	return result;
}
/// <summary>
/// function which gets the matrix parts based on what collumn they are in.
/// </summary>
/// <param name="row">takes in an int which tells which coolumn to check</param>
/// <returns> the three parts in that collumn</returns>
MyVector3D MyMatrix3::column(int col) const
{
	MyVector3D result{};
	if (col == 0)
	{
		result = { m11, m21, m31 };
	}
	else if (col == 1)
	{
		result = { m12, m22, m32 };
	}
	else if (col == 2)
	{
		result = { m13, m23, m33 };
	}
	return result;
}
/// <summary>
/// function which compares two matrices, checking if all they're parts are equal.
/// </summary>
/// <param name="other">second matrix</param>
/// <returns> true if the same false otherwise</returns>
bool MyMatrix3::operator==(const MyMatrix3 other) const
{
	return{ m11 == other.m11 && m12 == other.m12 && m13 == other.m13 && m21 == other.m21 && m22 == other.m22 && m23 == other.m23 && m31 == other.m31 && m32 == other.m32 && m33 == other.m33 };
}
/// <summary>
/// function which compares two matrices, checking if all they're parts are not equal.
/// </summary>
/// <param name="other">second matrix</param>
/// <returns> true if not equal false otherwise</returns>
bool MyMatrix3::operator!=(const MyMatrix3 other) const
{
	return{ m11 != other.m11 && m12 != other.m12 && m13 != other.m13 && m21 != other.m21 && m22 != other.m22 && m23 != other.m23 && m31 != other.m31 && m32 != other.m32 && m33 != other.m33 };
}
/// <summary>
/// function which creates a standard clockwise rotation matrix (3x3)around the Z axis based on an angle taken in, in radians but converted to degrees
/// it can be then used to rotate 3D vectors with a Z of 1
/// </summary>
/// <param name="angleRadians">angle in rads</param>
/// <returns>standard Rotation 3x3 matrix</returns>
MyMatrix3 MyMatrix3::rotationZ(double angleRadians)
{
	MyMatrix3 standardRotation
	{	cos(angleRadians), sin(angleRadians), 0,
		-sin(angleRadians),  cos(angleRadians), 0,
		0, 0, 1	};
	return standardRotation;
}
/// <summary>
/// function which creates a standard clockwise rotation matrix (3x3)around the Y axis based on an angle taken in, in radians but converted to degrees
/// it can be then used to rotate 3D vectors with a Z of 1
/// </summary>
/// <param name="angleRadians">angle in rads</param>
/// <returns>standard Rotation 3x3 matrix</returns>
MyMatrix3 MyMatrix3::rotationY(double angleRadians)
{
	MyMatrix3 standardRotation
	{	cos(angleRadians), 0, (sin(angleRadians)*-1),
		0, 1, 0,
		sin(angleRadians), 0, cos(angleRadians) };
	return standardRotation;
}
/// <summary>
/// function which creates a standard clockwise rotation matrix (3x3)around the X axis around an angle taken in, in radians but converted to degrees
/// it can be then used to rotate 3D vectors with a Z of 1
/// </summary>
/// <param name="angleRadians">angle in rads</param>
/// <returns>standard Rotation 3x3 matrix</returns>
MyMatrix3 MyMatrix3::rotationX(double angleRadians)
{
	MyMatrix3 standardRotation
	{	1, 0, 0,
		0, cos(angleRadians), sin(angleRadians),
		0, (sin(angleRadians)*-1), cos(angleRadians) };
	return standardRotation;
}
/// <summary>
/// function which creates a 3x3 standard translation matrix. Which can be used to transform by position 2d vector or 3d vector with z of 1
/// </summary>
/// <param name="displacement"> vector to move by</param>
/// <returns>standard matrix for trans</returns>
MyMatrix3 MyMatrix3::translation(MyVector3D displacement)
{
	MyMatrix3 standardTranslation{ 1,0,displacement.X(),0,1,displacement.Y(),0,0,1 };
	return standardTranslation;
}
/// <summary>
/// function which creates a 3x3 standard scaling matrix. Which can be used to transform by scale 2d vector or 3d vector with z of 1
/// </summary>
/// <param name="scalingFactor"> vector to scale by</param>
/// <returns>standard matrix for scale</returns>
MyMatrix3 MyMatrix3::scale(double scalingFactor)
{
	MyMatrix3 standardScale{ scalingFactor, 0, 0, 0, scalingFactor, 0, 0, 0 ,scalingFactor };
	return standardScale;
}

MyVector3D operator*(const MyVector3D vector, const MyMatrix3 matrix)
{
	return MyVector3D{ matrix.column(0).dot(vector), matrix.column(1).dot(vector), matrix.column(2).dot(vector) };
}
