#pragma once
#ifndef MYVECTOR2
#define MYVECTOR2


/// <summary>
/// james o hara
/// 

#include <iostream>
#include <SFML/Graphics.hpp>


class MyVector2
{
public:
	float x;
	float y;
	

	MyVector2();
	~MyVector2();
	std::string toString();

	MyVector2(float x, float y);//sets up x y z
	
	MyVector2 operator +(const MyVector2 t_right) const;//adds two vectors together
	MyVector2 operator -(const MyVector2 t_right) const;// subtracts two vectors from eachother
	MyVector2 operator *(MyVector2 V2);//multiplies a vector by a number
	MyVector2 operator *(float k);
	MyVector2 operator *(int k);
	MyVector2 operator -();  // this changes the vector//makes a vector a negative
	float length()const;//sets up the length
	float lengthSquared()const;//sets up the lentgh squared
	void normalise(); // vector changes and will have length 1 
	
};



#endif // !MYVECTOR3