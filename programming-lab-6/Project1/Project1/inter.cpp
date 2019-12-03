#include "inter.h"

Quaternion::Quaternion() :
	w{0.0},
	x{0.0},
	y{0.0},
	z{0.0}
{

}

Quaternion::Quaternion(double _w, double _x, double _y, double _z)
{
	w = _w; x = _x; y = _y; z = _z;
}

Quaternion::Quaternion(double _w, MyVector3 v)
{
	w = _w; x = v.x; y = v.y; z = v.z;
}

std::string Quaternion::ToString()
{
     return "(" + std::to_string(w) + "g3" + "," + std::to_string(x) + "g3" + "i," + std::to_string(y) + "g3" "j," + std::to_string(z) + "g3" + "k)";
}

double Quaternion::Modulus()
{
	return sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::Normalise()
{
	double m = w * w + x * x + y * y + z * z;
	if (m > 0.001)
	{
		m = sqrt(m);
		return Quaternion(w / m, x / m, y / m, z / m);
	}
	else
	{
		return Quaternion(1, 0, 0, 0);
	}
}

Quaternion Quaternion::Conjugate()
{
	return Quaternion(w, -x, -y, -z);
}

void Quaternion::FromAxisAngle(MyVector3 axis, double angleRadian)
{
	double m = axis.length();
	if (m > 0.0001)
	{
		double ca = cos(angleRadian / 2);
		double sa = sin(angleRadian / 2);
		x = axis.x / m * sa;
		y = axis.y / m * sa;
		z = axis.z / m * sa;
		w = ca;
	}
	else
	{
		w = 1; x = 0; y = 0; z = 0;
	}
}

Quaternion Quaternion::Multiply(Quaternion _q)
{
	double nw = _q.w * w - _q.x * x - _q.y * y - _q.z * z;
	double nx = _q.w * x + _q.x * w + _q.y * z - _q.z * y;
	double ny = _q.w * y + _q.y * w + _q.z * x - _q.x * z;
	double nz = _q.w * z + _q.z * w + _q.x * y - _q.y * x;
	return Quaternion(nw, nx, ny, nz);
}

Quaternion Quaternion::Copy()
{
	return Quaternion(x, y, z, w);
}

MyVector3 Quaternion::Rotate(MyVector3 pt, int _angle)
{
	Quaternion axis, rotate;
	axis = Normalise();
	double angleRad = 3.14 / 180 * _angle;
	rotate = Quaternion(cos(angleRad / 2), sin(angleRad / 2) * axis.x, sin(angleRad / 2) * axis.y, sin(angleRad / 2) * axis.z);
	Quaternion conjugate = rotate.Conjugate();
	Quaternion qNode = Quaternion(0, pt.x, pt.y, pt.z);
	qNode = rotate * qNode * conjugate;
	return MyVector3(qNode.x, qNode.y, qNode.z);
}

Quaternion Quaternion::operator+(Quaternion q1, Quaternion q2)
{
	return Quaternion(q1.w + q2.w, q1.x + q2.x, q1.y + q2.y, q1.z + q2.z);
}

Quaternion Quaternion::operator-(Quaternion q1)
{
	return Quaternion(-q1.w, -q1.x, -q1.y, -q1.z);
}

Quaternion Quaternion::operator-(Quaternion q1, Quaternion q2)
{
	return Quaternion(q1.w - q2.w, q1.x - q2.x, q1.y - q2.y, q1.z - q2.z);
}

Quaternion Quaternion::operator*(Quaternion q1, double s)
{
	return  Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

Quaternion Quaternion::operator*(Quaternion q1, float s)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

Quaternion Quaternion::operator *(Quaternion q1, int s)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

Quaternion Quaternion::operator *(double s, Quaternion q1)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

Quaternion Quaternion::operator *(float s, Quaternion q1)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

Quaternion Quaternion::operator *(int s, Quaternion q1)
{
	return Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);
}

Quaternion Quaternion::operator *(Quaternion q1)
{
	double nw = w * q1.w - x * q1.x - y * q1.y - z * q1.z;
	double nx = w * q1.x + x * q1.w + y * q1.z - z * q1.y;
	double ny = w * q1.y + y * q1.w + z * q1.x - x * q1.z;
	double nz = w * q1.z + z * q1.w + x * q1.y - y * q1.x;
	return Quaternion(nw, nx, ny, nz);
}