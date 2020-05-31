#include <iostream>
#include "Circle.h"
#include "Conteiner.h"
#include "Cube.h"
#include "Dot.h"
#include "Elipse.h"
#include "Line.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Square.h"
#include "Trapeze.h"
#include "Triangle.h"
#include <conio.h>

int main()
{
	Circle<double> circle(5, 0, 3);
	Cube<int> cube(1, 1, 1, 1);
	Dot<int> dot(1, 1);
	Elipse<int> elips(1, 1, 1, 1);
	Line<int> line(11, 1, 2, 22);
	Parallelogram<int> par(1, 1, 2, 3, 4);
	Rectangle<int> rectangle(1, 1, 3, 5);
	Square<int> square(1, 1, 3);
	Trapeze<int> trap(1, 1, 2, 3, 1, 2);
	Triangle<int> triangle(1, 1, 2, 2, 3, 3);
	Conteiner c;
	c.PushBack(circle);
	c.PushBack(cube);
	c.PushBack(dot);
	c.PushBack(elips);
	c.PushBack(line);
	c.PushBack(par);
	c.PushBack(rectangle);
	c.PushBack(square);
	c.PushBack(trap);
	c.PushBack(triangle);
	std::cout << c;
	c.Show(5);
	c.DeleteElem(5);
	std::cout << std::endl << std::endl;
	std::cout << c;
	_getch();
}