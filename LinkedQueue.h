#pragma once
#include "TDACola.h"
#include "NodoAlumno.h"
class LinkedQueue : public TDACola
{
private:
	NodoAlumno* head;
	NodoAlumno* tail;
	int size;

public:
	LinkedQueue();
	~LinkedQueue();

	void queue(Alumno*);
	Alumno* dequeue();
	void peek();
	bool vacia();
	void anula();
	void imprimir();
};
