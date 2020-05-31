#pragma once
#include "Shape.h"
#include <iostream>
template <typename T>
class Dot : public Shape
{
	T x, y;
public: 
	Dot(T xconstr, T yconstr);
	T* GetCoordinates();
	double Volume()const;
	double Area()const;
	double Perimetr()const;
	std::ostream& print(std::ostream& out);
	Dot& operator=(Dot& d);
	template<typename T>
	friend std::ostream& operator<< (std::ostream& out, Dot& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Dot& c);
};

template <typename T>
Dot<T>::Dot(T xconstr, T yconstr)
{
	x = xconstr;
	y = yconstr;
}
template <typename T>
T* Dot<T>::GetCoordinates()
{
	T* coordinates = new T[2];
	coordinates[0] = x;
	coordinates[1] = y;
	return coordinates;
}

template<typename T>
inline double Dot<T>::Volume() const
{
	return 0.0;
}

template<typename T>
inline double Dot<T>::Area() const
{
	return 0.0;
}

template<typename T>
inline double Dot<T>::Perimetr() const
{
	return 0.0;
}

template<typename T>
inline std::ostream& Dot<T>::print(std::ostream& out)
{
	out <<*this;
	return out;
}

template<typename T>
inline Dot<T>& Dot<T>::operator=(Dot& d)
{
	x = d.x;
	y = d.y;
	return *this;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Dot<T>& c)
{
	out << "Point: " << c.GetCoordinates()[0] << c.GetCoordinates()[1];
	return out;
}

template<typename T>
inline std::istream& operator>>(std::istream& in, Dot<T>& c)
{
	in >> c.x >> c.y;
	return in;
}
