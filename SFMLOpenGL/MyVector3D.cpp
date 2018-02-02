/// <summary>
/// @author Dion Buckley
/// @date Dec 2016
/// Time taken: 5 hours roughly
/// No Known Bugs

/// </summary>
/// 
#include "MyVector3D.h"
#define PI 3.14159265

/// <summary>
/// Default constructor which results in a zero vector
/// </summary>
MyVector3D::MyVector3D():
	m_x{ 0.0 },
	m_y{ 0.0 },
	m_z{ 0.0 }
{
}

/// <summary>
/// construct 3D vector using 3 double values x, y and z
/// </summary>
/// <param name="x">x component</param>
/// <param name="y">y component</param>
/// <param name="z">z component</param>
MyVector3D::MyVector3D(double x, double y, double z):
	m_x{ x },
	m_y{ y },
	m_z{ z }
{	
}

MyVector3D::MyVector3D(sf::Vector3f sfVector) :
	m_x(static_cast<double>(sfVector.x)),
	m_y(static_cast<double>(sfVector.y)),
	m_z(static_cast<double>(sfVector.z))
{
}

MyVector3D::MyVector3D(sf::Vector3i sfVector) :
	m_x(static_cast<double>(sfVector.x)),
	m_y(static_cast<double>(sfVector.y)),
	m_z(static_cast<double>(sfVector.z))
{
}

MyVector3D::MyVector3D(sf::Vector2i sfVector) :
	m_x(static_cast<double>(sfVector.x)),
	m_y(static_cast<double>(sfVector.y)),
	m_z(0.0)
{
}

MyVector3D::MyVector3D(sf::Vector2f sfVector) :
	m_x(static_cast<double>(sfVector.x)),
	m_y(static_cast<double>(sfVector.y)),
	m_z(0.0)
{
}

MyVector3D::MyVector3D(sf::Vector2u sfVector) :
	m_x(static_cast<double>(sfVector.x)),
	m_y(static_cast<double>(sfVector.y)),
	m_z(0.0)
{
}

/// <summary>
/// default destructor
/// </summary>
MyVector3D::~MyVector3D()
{
}

/// <summary>
/// create string for vector in form (x,y,z). Using sprintf with formating specifiers of g 
/// </summary>
/// <returns></returns>
std::string MyVector3D::toString()
{
	char tmpbuf[256];
	sprintf_s(tmpbuf, "[ %g, %g, %g ]", m_x, m_y, m_z);
	return tmpbuf;
}

double MyVector3D::X() const
{
	return m_x;
}

double MyVector3D::Y() const
{
	return m_y;
}

double MyVector3D::Z() const
{
	return m_z;
}

/// <summary>
/// overload for addition operation between two vectors.
/// adds the x, y and z component of each together and returns the sum in a new vector
/// original vectors stay the same
/// </summary>
/// <param name="right">second vector</param>
/// <returns>sum of two vectors</returns>
MyVector3D MyVector3D::operator+(const MyVector3D right) const
{
	return MyVector3D(m_x + right.m_x, m_y + right.m_y, m_z + right.m_z);
}

/// <summary>
/// overload for subtraction operation between two vectors.
/// subtracts the x, y and z component of each, and returns the result in a new vector
/// original vectors stay the same
/// </summary>
/// <param name="right">second vector</param>
/// <returns>subtraction of two vectors</returns>
MyVector3D MyVector3D::operator-(const MyVector3D right) const
{
	return MyVector3D(m_x - right.m_x, m_y - right.m_y, m_z - right.m_z);
}

/// <summary>
/// overload for multiplication of a vector by a scalar
/// multiplies each component by the double scalar
/// </summary>
/// <param name="scalar">The scalar in use</param>
/// <returns>multiplied value</returns>
MyVector3D MyVector3D::operator*(const double scalar) const
{
	return MyVector3D(m_x * scalar, m_y * scalar, m_z* scalar);
}

/// <summary>
/// overload for division operation using a double value
/// </summary>
/// <param name="divisor">The divisor in use</param>
/// <returns>value after diviion or null vector if user uses 0 as divisor, to stop crash</returns>
MyVector3D MyVector3D::operator/(const double divisor) const
{
	std::string error = "Error. Cannot divide by 0!"; // find out if i can implement this somehow
	if (divisor != 0) // stopping division by 0
	{
		return MyVector3D(m_x / divisor, m_y / divisor, m_z / divisor);
	}
	return MyVector3D();
}

/// <summary>
/// overload for plus equals operation. Vector coming in is constant
/// </summary>
/// <param name="right">second vector</param>
/// <returns>essentially the sum of the two vectors</returns>
MyVector3D MyVector3D::operator+=(const MyVector3D right)
{
	m_x += right.m_x;
	m_y += right.m_y;
	m_z += right.m_z;
	return MyVector3D(m_x, m_y, m_z);
}

/// <summary>
/// overload for minus equals operation. Vector coming in is constant
/// </summary>
/// <param name="right">second vector</param>
/// <returns>The subtraced value of the two vectors</returns>
MyVector3D MyVector3D::operator-=(const MyVector3D right)
{
	m_x -= right.m_x;
	m_y -= right.m_y;
	m_z -= right.m_z;
	return MyVector3D(m_x, m_y, m_z);
}

/// <summary>
/// overload for equality operator. If all components are equal then true
/// </summary>
/// <param name="right">2nd vector</param>
/// <returns>true if vectors are equal, false if not</returns>
bool MyVector3D::operator==(const MyVector3D right) const
{
	return (m_x == right.m_x && m_y == right.m_y && m_z == right.m_z);
}

/// <summary>
/// overload for inequality operator. If all components are not equal to their counterparts then true
/// </summary>
/// <param name="right">2nd vector</param>
/// <returns>true if vectors are not equal, false otherwise</returns>
bool MyVector3D::operator!=(const MyVector3D right) const
{
	return (m_x != right.m_x && m_y != right.m_y && m_z != right.m_z);
}

/// <summary>
/// overload operator for uniary negative
/// </summary>
/// <returns>that vectors negative</returns>
MyVector3D MyVector3D::operator-()
{
	return MyVector3D(-m_x, -m_y, -m_z);
}

/// <summary>
/// negate the x component for when ball bounces off side cushions
/// </summary>
void MyVector3D::reverseX()
{
	m_x = -m_x;
}

/// <summary>
/// negate the y component for when ball bounces off top or bottom cushions
/// </summary>
void MyVector3D::reverseY()
{
	m_y = -m_y;
}

/// <summary>
/// Calculate length of a vector using maths formula ( sq root of components squared )
/// </summary>
/// <returns>length</returns>
double MyVector3D::length() const
{
	const double result = std::sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
	return result;
}

/// <summary>
/// Calculate length squared of a vector using maths formula (all components squared and added together )
/// </summary>
/// <returns>length squared</returns>
double MyVector3D::lengthSquared() const
{
	const double result = pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2);
	return result;
}

/// <summary>
/// calculate the dot product of two vectors using the each vectos components multiplied by their corresponding componenets
/// </summary>
/// <param name="other">second vector</param>
/// <returns> dot product </returns>
double MyVector3D::dot(const MyVector3D other) const
{
	const double result = ((m_x * other.m_x) + (m_y * other.m_y) + (m_z * other.m_z));
	return result;
}

/// <summary>
/// calculate the cross product of two vectors using the below maths formula.
/// this formula is derived from the fact that the cross product is really the determinant of a 3x3 matrix
/// then using the method of cofactors the fomaula below can be derived
/// </summary>
/// <param name="other"> second vector </param>
/// <returns> cross product </returns>
MyVector3D MyVector3D::crossProduct(const MyVector3D other) const
{
	MyVector3D result{ m_y * other.m_z - m_z * other.m_y, m_z * other.m_x - m_x * other.m_z, m_x * other.m_y - m_y * other.m_x };
	return result;
}

/// <summary>
/// function to calculate the angle between two 3D vectors in degrees
/// first get's the dot product of the two vectors then gets the length of each vector.
/// Then uses the maths of cos-1 of the dot product over the lengths multiplied. 
/// Finally multiplied by 180 and divided by PI to change from radians to degrees
/// </summary>
/// <param name="other">second vector</param>
/// <returns> angle between the two vectors</returns>
double MyVector3D::angleBetween(const MyVector3D other) const
{
	MyVector3D vectorA(m_x, m_y, m_z);
	MyVector3D vectorB(other.m_x, other.m_y, other.m_z);
	const double dot = vectorA.dot(vectorB);
	const double lengthA = vectorA.length();
	const double lengthB = vectorB.length();
	double cosAngleBetween = 0;
	double angleBetween = 0;

	cosAngleBetween = dot / (lengthA *lengthB);
	// the 180 / pi is the formula for converting from radians to degrees
	angleBetween = acos(cosAngleBetween) * 180 / PI;
	return angleBetween;
}

/// <summary>
/// function to creqate a normal vector using the current vector
/// </summary>
/// <returns>new vector with a length of one</returns>
MyVector3D MyVector3D::unit() const
{
	double x = 0;
	double y = 0;
	double z = 0;
	double vectorLength = length();
	if (vectorLength != 0) //to stop division of 0
	{
		x = m_x / vectorLength;
		y = m_y / vectorLength;
		z = m_z / vectorLength;
	}
	return MyVector3D(x, y, z);
}

/// <summary>
/// function to change a vectors length to 1
/// No new vector is created here
/// </summary>
void MyVector3D::normalise()
{
	double vectorLength = length();
	if (vectorLength != 0) //to stop division of 0
	{
		m_x = m_x / vectorLength;
		m_y = m_y / vectorLength;
		m_z = m_z / vectorLength;
	}
}

/// <summary>
///  projection of one vector onto the current vector
/// </summary>
/// <param name="other">vector to project</param>
/// <returns>projection parralell to current</returns>
MyVector3D MyVector3D::projection(const MyVector3D other) const
{
	double lenghtSq = lengthSquared();
	double dotProduct = dot(other);
	double scale = 1.0; // default for null vector involvement
	if (lenghtSq != 0)
	{
		scale = dotProduct / lenghtSq;
	}

	return this->operator*(scale);
}

/// <summary>
/// perpendicular component of vector relative to current vector
/// defined as orignal - projection
/// </summary>
/// <param name="other">vector to project/reject</param>
/// <returns>rejection perpendiucular to current</returns>
MyVector3D MyVector3D::rejection(const MyVector3D other) const
{
	return other - projection(other);
}
