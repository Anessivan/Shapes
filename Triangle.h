#pragma once
#include "Shape.h"
#include <iostream>
template <typename T>
class Triangle :
	public Shape
{
	T x0, y0, x1, y1, x2, y2;
public:
	Triangle(T x0, T y0, T x1, T y1, T x2constr, T y2constr);
	double Area()const;
	double Perimetr()const;
	double Volume()const;
	T* Coordinates();
	Triangle& operator=(Triangle& t);
	std::ostream& print(std::ostream& out);
	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, Triangle<T>& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Triangle<T>& c);
};
template <typename T>
Triangle<T>::Triangle(T x0constr, T y0constr, T x1constr, T y1constr, T x2constr, T y2constr)
{
	x0 = x0constr;
	y0 = y0constr;
	x1 = x1constr;
	y1 = y1constr;
	x2 = x2constr;
	y2 = y2constr;
}
template <typename T>
double Triangle<T>::Area()const
{
	double Ger, p = Perimetr() / 2;
	double a = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
	double b = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	double c = sqrt(pow(x2 - x0, 2) + pow(y2 - y0, 2));
	Ger = p * (p - a) * (p - b) * (p - c);
	return sqrt(Ger);
}
template <typename T>
double Triangle<T>::Perimetr()const
{
	double a, b, c;
	a = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
	b = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	c = sqrt(pow(x2 - x0, 2) + pow(y2 - y0, 2));
	return a + b + c;
}
template<typename T>
inline double Triangle<T>::Volume() const
{
	return 0.0;
}
template <typename T>
T* Triangle<T>::Coordinates()
{
	T* coordinates = new T[6];
	coordinates[0] = x0;
	coordinates[1] = y0;
	coordinates[2] = x1;
	coordinates[3] = y1;
	coordinates[4] = x2;
	coordinates[5] = y2;
	return coordinates;
}

template<typename T>
inline Triangle<T>& Triangle<T>::operator=(Triangle& t)
{
	x0 = t.x0;
	y0 = t.y0;
	x1 = t.x1;
	y1 = t.y1;
	x2 = t.x2;
	y2 = t.y2;
	return *this;
}

template<typename T>
inline std::ostream& Triangle<T>::print(std::ostream& out)
{
	out << *this;
	return out;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Triangle<T>& c)
{
	out << "First point: " << c.x0 << " " << c.y0 << " Second point: " << c.x1 << " " << c.y1 << " Third point: " << c.x2 << " " << c.y2;
	return out;
}

template<typename T>
inline std::istream& operator>>(std::istream& in, Triangle<T>& c)
{
	std::cout << "Enter first point: ";
	in >> c.x0 >> c.y0;
	std::cout << " Enter second point: ";
	in >> c.x1 >> c.y1;
	std::cout << " Enter third point: ";
	in >> c.x2 >> c.y2;
	return in;
}
