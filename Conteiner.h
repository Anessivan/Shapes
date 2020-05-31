#pragma once
#include "Shape.h"
#include <iostream>
class Conteiner
{
	Shape** data;
	unsigned int size;
	unsigned int maxsize;
public:
	Conteiner();
	Conteiner(Conteiner& c);
	friend std::ostream& operator<< (std::ostream& out, Conteiner& c);
	void DeleteElem(int index);
	void PushBack(Shape& s);
	void Show(int index);
	Conteiner& operator= (Conteiner& c);
};

