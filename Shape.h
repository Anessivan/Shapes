#pragma once
#include <iostream>


class Shape
{
public:
	virtual ~Shape() {}
	virtual double Area()const = 0;
	virtual double Perimetr()const = 0;
	virtual double Volume()const = 0;
	virtual std::ostream& print(std::ostream& out) = 0;
	friend std::ostream& operator<< (std::ostream& out, Shape& c) { return c.print(out); }
};
