#pragma once
#include "TDACola.h"
class ArrayQueue : public TDACola
{
private:
	Alumno** array;//Array que almacenara los alumnos
	int capacidad;//capacidad del array

	int head;//cabeza de la cola
	int tail;//cola o elemento final

public:
	//Constructor vacio
	ArrayQueue();
	//Destructor
	~ArrayQueue();

	
	void queue(Alumno*);
	Alumno* dequeue();
	void peek();
	bool vacia();
	void anula();
	void imprimir();
};

