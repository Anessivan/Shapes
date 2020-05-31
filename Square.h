#pragma once
#include "Shape.h"
#include <iostream>
template <typename T>
class Square :
	public Shape
{
	T x, y;
	T hight;

public:
	Square(T x0, T y0, T hight0);
	double Area()const;
	double Perimetr()const;
	T* Coordinates();
	Square& operator=(Square& s);
	double Volume()const;
	std::ostream& print(std::ostream& out);
	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, Square<T>& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Square<T>& c);
};

template <typename T>
Square<T>::Square(T x0, T y0, T hight0)
{
	x = x0;
	y = y0;
	hight = hight0;
}
template <typename T>
double Square<T>::Area()const
{
	return hight * hight;
}
template <typename T>
double Square<T>::Perimetr()const
{
	return 4 * hight;
}
template <typename T>
T* Square<T>::Coordinates()
{
	T* coordinates = new T[8];
	coordinates[0] = x;
	coordinates[1] = y;
	coordinates[2] = x + hight;
	coordinates[3] = y;
	coordinates[4] = x + hight;
	coordinates[5] = y - hight;
	coordinates[6] = x;
	coordinates[7] = y - hight;
	return coordinates;
}

template<typename T>
inline Square<T>& Square<T>::operator=(Square& s)
{
	x = s.x;
	y = s.y;
	hight = s.hight;
	return *this;
}

template<typename T>
inline double Square<T>::Volume() const
{
	return 0.0;
}

template<typename T>
inline std::ostream& Square<T>::print(std::ostream& out)
{
	out << *this;
	return out;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Square<T>& c)
{
	T* data = new T[8];
	data = c.Coordinates();
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
			out << "point: ";
		out << data[i] << " ";
	}
	delete[] data;
	return out;
}

template<typename T>
inline std::istream& operator>>(std::istream& in, Square<T>& c)
{
	std::cout << " Enter first point: ";
	in >> c.x >> c.y;
	std::cout << "Enter hight ";
	in >> c.hight;
	return in;
}