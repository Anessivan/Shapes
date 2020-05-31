#pragma once
#include "Shape.h"
#include <iostream>
template <typename T>
class Cube : public Shape
{
	T x, y, z;
	T reb;
public:
	Cube(T xconstr, T yconstr, T zconstr, T rebconstr);
	Cube(Cube& c);
	double Area()const;
	double Perimetr()const;
	double Volume()const;
	T* Coordinates();
	Cube& operator=(Cube& c);
	std::ostream& print(std::ostream& out);
	template<typename T>
	friend std::ostream& operator<< (std::ostream& out, Cube& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Cube& c);
};

template<typename T>
inline Cube<T>::Cube(T xconstr, T yconstr, T zconstr, T rebconstr)
{
	x = xconstr;
	y = yconstr;
	z = zconstr;
	reb = rebconstr;
}

template<typename T>
inline Cube<T>::Cube(Cube& c)
{
	x = c.x;
	y = c.y;
	z = c.z;
	reb = c.reb;
}

template<typename T>
inline double Cube<T>::Area()const
{
	return reb * reb;
}

template<typename T>
inline double Cube<T>::Perimetr()const
{
	return 4 * reb;
}

template<typename T>
inline double Cube<T>::Volume() const
{
	return reb * reb * reb;
}

template<typename T>
inline T* Cube<T>::Coordinates()
{
	T* data = new T[24];
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = x + reb;
	data[4] = y;
	data[5] = z;
	data[6] = x + reb;
	data[7] = y + reb;
	data[8] = z;
	data[9] = x;
	data[10] = y + reb;
	data[11] = z;
	data[12] = x;
	data[13] = y;
	data[14] = z - reb;
	data[15] = x + reb;
	data[16] = y;
	data[17] = z - reb;
	data[18] = x + reb;
	data[19] = y + reb;
	data[20] = z - reb;
	data[21] = x;
	data[22] = y + reb;
	data[23] = z - reb;
	return data;
}

template<typename T>
inline Cube<T>& Cube<T>::operator=(Cube& c)
{
	x = c.x;
	y = c.y;
	z = c.z;
	reb = c.reb;
	return *this;
}

template<typename T>
inline std::ostream& Cube<T>::print(std::ostream& out)
{
	out << *this;
	return out;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, Cube<T>& c)
{
	T* data = new T[24];
	data = c.Coordinates();
	for (int i = 0; i < 24; i++)
	{
		if (i % 3 == 0) out << std::endl << "Point: ";
		out << data[i] << " ";
	}
	return out;
}
template <typename T>
std::istream& operator>> (std::istream& in, Cube<T>& c)
{
	for (int i = 0; i < 24; i++)
	{
		if (i % 3 == 0)  std::cout<< std::endl << "Point: ";
		in >> c.data[i];
	}
	return in;
}

