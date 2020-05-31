#pragma once
#include "Shape.h"
#include <iostream>
template <typename T>
class Rectangle :
	public Shape
{
	T x, y;
	T hight, width;

public:
	Rectangle(T x0, T y0, T hight0, T width0);
	double Area()const;
	double Perimetr()const;
	T* Coordinates();
	double Volume()const;
	Rectangle& operator=(Rectangle& r);
	std::ostream& print(std::ostream& out);
	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, Rectangle<T>& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Rectangle<T>& c);
};
template <typename T>
Rectangle<T>::Rectangle(T x0, T y0, T hight0, T width0)
{
	x = x0;
	y = y0;
	hight = hight0;
	width = width0;
}
template <typename T>
double Rectangle<T>::Area()const
{
	return width * hight;
}
template <typename T>
double Rectangle<T>::Perimetr()const
{
	return 2 * (width + hight);
}
template <typename T>
T* Rectangle<T>::Coordinates()
{
	T* coordinates = new T[8];
	coordinates[0] = x;
	coordinates[1] = y;
	coordinates[2] = x + width;
	coordinates[3] = y;
	coordinates[4] = x + width;
	coordinates[5] = y - hight;
	coordinates[6] = x;
	coordinates[7] = y - hight;
	return coordinates;
}

template<typename T>
inline double Rectangle<T>::Volume() const
{
	return 0.0;
}

template<typename T>
inline Rectangle<T>& Rectangle<T>::operator=(Rectangle& r)
{
	x = r.x;
	y = r.y;
	hight = r.hight;
	width = r.width;
	return *this;
}

template<typename T>
inline std::ostream& Rectangle<T>::print(std::ostream& out)
{
	out << *this;
	return out;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Rectangle<T>& c)
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
inline std::istream& operator>>(std::istream& in, Rectangle<T>& c)
{
	std::cout << "Enter first point: ";
	in >> c.x >> c.y;
	std::cout << "Enter hight";
	in >> c.hight;
	std::cout << "Enter width: ";
	in >> c.width;
	return in;
}
