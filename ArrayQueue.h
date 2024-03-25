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

	//Funcion encolar: mete un alumno a la cola
	void queue(Alumno*);
	//Funcion desencolar: quita un alumno de la cola
	Alumno* dequeue();
	//Mira el elemento proximo a salir, o el frente de la cola
	void peek();
	//Revisa si la cola esta vacia
	bool vacia();
	//Borra todos los elementos de la cola
	void anula();
	//Imprime todos los elementos actuales de la cola
	void imprimir();
};

