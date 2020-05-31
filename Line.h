#pragma once
#include "Shape.h"
#include <iostream>
template <typename T>
class Line :
	public Shape
{
	T x0, y0, x1, y1;
public:
	Line(T x0constr, T y0constr, T x1constr, T y1constr);
	T* Coordinates();
	double Volume()const;
	double Area()const;
	std::ostream& print(std::ostream& out);
	double Perimetr()const;
	Line& operator=(Line& l);
	template<typename T>
	friend std::ostream& operator<< (std::ostream& out, Line<T>& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Line<T>& c);
};

template <typename T>
Line<T>::Line(T x0constr, T y0constr, T x1constr, T y1constr)
{
	x0 = x0constr;
	y0 = y0constr;
	x1 = x1constr;
	y1 = y1constr;
}

template <typename T>
T* Line<T>::Coordinates()
{
	T* coordinates = T[4];
	coordinates[0] = x0;
	coordinates[1] = y0;
	coordinates[2] = x1;
	coordinates[3] = y1;
	return coordinates;
}

template<typename T>
inline double Line<T>::Volume() const
{
	return 0.0;
}

template<typename T>
inline double Line<T>::Area() const
{
	return 0.0;
}

template<typename T>
inline std::ostream& Line<T>::print(std::ostream& out)
{
	out << *this;
	return out;
}

template<typename T>
inline double Line<T>::Perimetr() const
{
	return 0.0;
}

template<typename T>
inline Line<T>& Line<T>::operator=(Line& l)
{
	x0 = l.x0;
	y0 = l.y0;
	x1 = l.x1;
	y1 = l.y1;
	return *this;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Line<T>& c)
{
	out << "Point 1: " << c.x0 << ' ' << c.y0 << ' ' << "Point 2: " << c.x1 << ' ' << c.y1;
	return out;
}

template<typename T>
inline std::istream& operator>>(std::istream& in, Line<T>& c)
{
	std::cout << "Point 1 ";
	in >> c.x0 >> ' ' >> c.y0;
	std::cout << std::endl << "Point 2: ";
		in>> c.x1 >> c.y1;
		return in;
}
