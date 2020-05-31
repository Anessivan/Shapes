#pragma once
#include "Shape.h"
#include <iostream>
template <typename T>
class Elipse :
	public Shape
{
	T x, y;
	T rad1;
	T rad2;
public:
	Elipse(T xconstr, T yconstr, T rad1constr, T rad2constr);
	double Area()const;
	double Perimetr()const;
	double Volume()const;
	T* Centre();
	T* GetRad();
	Elipse& operator= (Elipse& e);
	std::ostream& print(std::ostream& out);
	template<typename T>
	friend std::ostream& operator<< (std::ostream& out, Elipse& c);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Elipse& c);
};

template<typename T>
inline Elipse<T>::Elipse(T xconstr, T yconstr, T rad1constr, T rad2constr)
{
	x = xconstr;
	y = yconstr;
	rad1 = rad1constr;
	rad2 = rad2constr;
}

template<typename T>
inline double Elipse<T>::Area()const
{
	return 3.14 * rad1 * rad2;
}

template<typename T>
inline double Elipse<T>::Perimetr()const
{
	return 3.14 * (rad1 + rad2);
}

template<typename T>
inline double Elipse<T>::Volume() const
{
	return 0.0;
}

template<typename T>
inline T* Elipse<T>::Centre()
{
	T* coordinates = new T[2];
	coordinates[0] = x;
	coordinates[1] = y;
	return coordinates;
}

template<typename T>
inline T* Elipse<T>::GetRad()
{
	T* data = new T[2];
	data[0] = rad1;
	data[1] = rad2;
	return data;
}

template<typename T>
inline Elipse<T>& Elipse<T>::operator=(Elipse& e)
{
	x = e.x;
	y = e.y;
	rad1 = e.rad1;
	rad2 = e.rad2;
	return *this;
}

template<typename T>
inline std::ostream& Elipse<T>::print(std::ostream& out)
{
	out << *this;
	return out;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out, Elipse<T>& c)
{
	out << "rad1 = " << c.GetRad()[0] << " rad2 = " << c.GetRad()[1] << "center: " << c.Centre()[0] << " " << c.Centre()[1];
	return out;
}

template<typename T>
inline std::istream& operator>>(std::istream& in, Elipse<T>& c)
{
	std::cout << "Enter rad1 ";
	in >> c.rad1;
	std::cout << "Enter rad2";
	in >> c.rad2;
	std::cout << "Enter center";
	in >> c.x >> c.y;
	return in;
}
