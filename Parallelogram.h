#pragma once
#include "Shape.h"
#include <iostream>
template <typename T>
class Parallelogram : public Shape
{
	T x0, y0, x1, y1;
	T width;
public:
	Parallelogram(T x0constr, T y0constr, T x1constr, T y1constr, T widthconstr);
	Parallelogram(Parallelogram& p);
	double Area()const;
	double Perimetr()const;
	double Volume()const;
	T* Coordinates();
	std::ostream& print(std::ostream& out);
	Parallelogram& operator=(Parallelogram& p);
	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, Parallelogram<T>& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Parallelogram<T>& c);
};

template<typename T>
inline Parallelogram<T>::Parallelogram(T x0constr, T y0constr, T x1constr, T y1constr, T widthconstr)
{
	x0 = x0constr;
	y0 = y0constr;
	x1 = x1constr;
	y1 = y1constr;
	width = widthconstr;
}

template<typename T>
inline Parallelogram<T>::Parallelogram(Parallelogram& p)
{
	x0 = p.x0;
	y0 = p.y0;
	x1 = p.x1;
	y1 = p.y1;
	width = p.width;
}

template<typename T>
inline double Parallelogram<T>::Area()const
{
	double h = abs(y0 - y1);
	return h * width;
}

template<typename T>
inline double Parallelogram<T>::Perimetr()const
{
	double xres = x0 - x1;
	double yres = y0 - y1;
	double a = sqrt(xres* xres + yres* yres);
	return 2* (width + a);
}

template<typename T>
inline double Parallelogram<T>::Volume() const
{
	return 0.0;
}

template<typename T>
inline T* Parallelogram<T>::Coordinates()
{
	T* coordinates = new T[8];
	coordinates[0] = x0;
	coordinates[1] = y0;
	coordinates[2] = x1;
	coordinates[3] = y1;
	coordinates[4] = x1 + width;
	coordinates[5] = y1;
	coordinates[6] = x0 + width;
	coordinates[7] = y0;
	return coordinates;
}

template<typename T>
inline std::ostream& Parallelogram<T>::print(std::ostream& out)
{
	out << *this;
	return out;
}

template<typename T>
inline Parallelogram<T>& Parallelogram<T>::operator=(Parallelogram& p)
{
	x0 = p.x0;
	y0 = p.y0;
	x1 = p.x1;
	y1 = p.y1;
	width = p.width;
	return *this;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Parallelogram<T>& c)
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
inline std::istream& operator>>(std::istream& in, Parallelogram<T>& c)
{
	std::cout << "Enter first point: ";
	in >> c.x0 >> c.y0;
	std::cout << std::endl  << "Enter second point: ";
	in >> c.x1 >> c.y1;
	std::cout << "Enter width: ";
	in >> c.width;
	return in;
}
