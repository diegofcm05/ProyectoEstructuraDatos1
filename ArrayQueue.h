#pragma once
#include "TDACola.h"
class ArrayQueue : public TDACola
{
private:
	Alumno** array;
	int capacidad;

	int head;
	int tail;

public:
	ArrayQueue();
	~ArrayQueue();

	void queue(Alumno*);
	Alumno* dequeue();
	void peek();
	bool vacia();
	void anula();
	void imprimir();
};

