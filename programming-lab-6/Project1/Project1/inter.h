#pragma once
#include <string.h>
#include "vector3.h"



	class Quaternion
	{
	public:
		double x, y, z, w;

		Quaternion();
	
		Quaternion(double _w, double _x, double _y, double _z);
	
		Quaternion(double _w, MyVector3 v);
		
		std::string ToString();
		
		double Modulus();
		
		Quaternion Normalise();

		Quaternion Conjugate();
	
		void FromAxisAngle(MyVector3 axis, double angleRadian);
		
		Quaternion Multiply(Quaternion _q);
		
		Quaternion Copy();
		
		MyVector3 Rotate(MyVector3 pt, int _angle);
		
		// Multiplying q1 with q2 is meaning of doing q2 firstly then q1
		static Quaternion operator +(Quaternion q1, Quaternion q2);
		
		Quaternion operator -(Quaternion q1);
		
		static Quaternion operator -(Quaternion q1, Quaternion q2);
	
		
		static Quaternion operator *(Quaternion q1, double s);
	
		static Quaternion operator *(Quaternion q1, float s);
	
		static Quaternion operator *(Quaternion q1, int s);
		
		static Quaternion operator *(double s, Quaternion q1);
		
		static Quaternion operator *(float s, Quaternion q1);
		
		static Quaternion operator *(int s, Quaternion q1);
		
		Quaternion operator *(Quaternion q1);
		
	};
