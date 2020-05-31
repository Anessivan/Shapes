#pragma once
#include "Shape.h"
#include <iostream>
template <typename T>
class Trapeze :
	public Shape
{
	T x0, y0, x1, y1;
	T topwidth;
	T downwidth;
public:
	Trapeze(T x0constr, T y0constr, T x1constr, T y1constr, T topwidth, T downwidth);
	double Area()const;
	double Perimetr()const;
	double Volume()const;
	Trapeze& operator=(Trapeze& t);
	T* Coordinates();
	std::ostream& print(std::ostream& out);
	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, Trapeze<T>& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Trapeze<T>& c);
};
template <typename T>
Trapeze<T>::Trapeze(T x0constr, T y0constr, T x1constr, T y1constr, T topwidthconstr, T downwidthconstr)
{
	x0 = x0constr;
	y0 = y0constr;
	x1 = x1constr;
	y1 = y1constr;
	topwidth = topwidthconstr;
	downwidth = downwidthconstr;
}
template <typename T>
double Trapeze<T>::Area()const
{
	double h = y0 - y1;
	return h * (topwidth + downwidth) / 2;
}
template <typename T>
double Trapeze<T>::Perimetr()const
{
	double h = abs(y0 - y1);
	double a = abs(x0 - x1);
	double b = abs(x1 + downwidth - x0 - topwidth);
	double d = sqrt(a * a + h * h);
	double d2 = sqrt(b * b + h * h);
	return topwidth + downwidth + d + d2;
}
template<typename T>
inline double Trapeze<T>::Volume() const
{
	return 0.0;
}
template<typename T>
inline Trapeze<T>& Trapeze<T>::operator=(Trapeze& t)
{
	x0 = t.x0;
	y0 = t.y0;
	x1 = t.x1;
	y1 = t.y1;
	topwidth = t.topwidth;
	downwidth = t.downwidth;
	return *this;
}
template <typename T>
T* Trapeze<T>::Coordinates()
{
	T* coordinates = new T[8];
	coordinates[0] = x0;
	coordinates[1] = y0;
	coordinates[2] = x1;
	coordinates[3] = y1;
	coordinates[4] = x1 + downwidth;
	coordinates[5] = y1;
	coordinates[6] = x0 + topwidth;
	coordinates[7] = y0;
	return coordinates;
}

template<typename T>
inline std::ostream& Trapeze<T>::print(std::ostream& out)
{
	out << *this;
	return out;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Trapeze<T>& c)
{
	T* data = new T[8];
	data = c.Coordinates();
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
			out << "point: ";
		out << data[i] << " ";
	}
	return out;
}

template<typename T>
inline std::istream& operator>>(std::istream& in, Trapeze<T>& c)
{
	std::cout << "Enter first point: ";
	in >> c.x0 >> c.y0;
	std::cout << " enter second point: ";
	in >> c.x1 >> c.y1;
	std::cout << " Enter top width: ";
	in >> c.topwidth;
	std::cout << " Enter down width: ";
	in >> c.downwidth;
	return in;
}
