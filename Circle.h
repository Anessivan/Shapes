#pragma once
#include "Shape.h"
#include <iostream>

template <typename T>
class Circle : public Shape
{
	T rad;
	T x, y;
public:
	Circle();
	Circle(T xconstr, T yconstr, T radius);
	double Area()const;
	double Perimetr()const;
	T* GetCenter()const;
	T GetRad();
	double Volume()const;
	Circle& operator=(Circle& c);
	std::ostream& print(std::ostream& out);
	template<typename T>
	friend std::ostream& operator<< (std::ostream& out, Circle& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Circle& c);
};

template<typename T>
inline Circle<T>::Circle()
{
	rad = 0;
	x = 0; 
	y = 0;
}

template <typename T>
Circle<T>::Circle(T xconstr, T yconstr, T radius) : Shape()
{
	rad = radius;
	x = xconstr;
	y = yconstr;
}


template <typename T>
double Circle<T>::Area() const
{
	return 3.14 * rad * rad;
}

template <typename T>
double Circle<T>::Perimetr()const
{
	return 2 * 3.14 * rad;
}

template <typename T>
T* Circle<T>::GetCenter()const
{
	double* res = new T[2];
	res[0] = x;
	res[1] = y;
	return res;
}

template<typename T>
inline T Circle<T>::GetRad()
{
	return rad;
}

template<typename T>
inline double Circle<T>::Volume() const
{
	return 0.0;
}

template<typename T>
inline Circle<T>& Circle<T>::operator=(Circle& c)
{
	rad = c.rad;
	x = c.x;
	y = c.y;
	return *this;
}

template<typename T>
inline std::ostream& Circle<T>::print(std::ostream& out)
{
	out << *this;
	return out;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Circle<T>& c)
{
	out << "Centre: " << c.GetCenter()[0] << " "<< c.GetCenter()[1] << " Radius" << c.GetRad();
	return out;
}

template<typename T>
inline std::istream& operator>>(std::istream& in, Circle<T>& c)
{
	std::cout << " Enter radius: ";
	in >> c.rad;
	std::cout << " Enter center";
	in >> c.x >> c.y;
	return in;
}
