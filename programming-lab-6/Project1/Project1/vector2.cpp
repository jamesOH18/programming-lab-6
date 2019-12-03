#include "vector2.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Default constructor set all 3 values to zero
/// </summary>
MyVector2::MyVector2() :
	x{ 0.0 },
	y{ 0.0 }
	
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector2::~MyVector2()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and separated by commas</returns>
std::string MyVector2::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "]";
	return output;
}

MyVector2::MyVector2(float t_x, float t_y)
{
	x = t_x;
	y = t_y;
}

MyVector2 MyVector2::operator+(const MyVector2 t_right) const
{
	return MyVector2(x + t_right.x, y + t_right.y);
}

MyVector2 MyVector2::operator-(const MyVector2 t_right) const
{
	return MyVector2(x - t_right.x, y - t_right.y);
}

float MyVector2::operator*(MyVector2 V2)
{
	return (x * V2.x + y * V2.y);
}

MyVector2 MyVector2::operator*(float k)
{
	return  MyVector2(x * (float)k, y * (float)k);
}

MyVector2 MyVector2::operator*(int k)
{
	return MyVector2(x * (int)k, y * (int)k)
}





MyVector2 MyVector2::operator-()
{
	return MyVector2(-x, -y);
}


float MyVector2::length() const
{
	float length = (x * x) + (y * y);
	float lengthsqrt = sqrt(length);
	return lengthsqrt;
}

float MyVector2::lengthSquared() const
{
	float lengthsquared = (x * x) + (y * y);
	return lengthsquared;
}

void MyVector2::normalise()
{
	MyVector2 normalise{ x, y};

	x = x / normalise.length();
	y = y / normalise.length();
	
}





