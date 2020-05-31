#include "Conteiner.h"

std::ostream& operator<<(std::ostream& out, Conteiner& c)
{
	for (int i = 0; i < c.size; i++)
		out << "Shape: " << *(c.data[i]) << std::endl;
	return out;
}

Conteiner::Conteiner()
{
	Shape** data = nullptr;
	size = 0;
	maxsize = 0;
}

Conteiner::Conteiner(Conteiner& c)
{
	*this = c;
}

void Conteiner::DeleteElem(int index)
{
	if (index < size)
	{
		for (int i = index; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}
}

void Conteiner::PushBack(Shape& s)
{
	if (size == maxsize)
	{
		Shape** copy = data;
		data = nullptr;
		data = new Shape*[maxsize + 5];
		maxsize = maxsize + 5;
		for (int i = 0; i < size; i++)
			data[i] = copy[i];
	}
	size++;
	data[size - 1] = &s;
}

void Conteiner::Show(int index)
{
	std::cout << *(data[index]);
}

Conteiner& Conteiner::operator=(Conteiner& c)
{
	size = c.size;
	maxsize = c.maxsize;
	if (data != nullptr)
		delete[] data;
	data = new Shape * [maxsize];
	for (int i = 0; i < size; i++)
	{
		data[i] = c.data[i];
	}
	return *this;
}
