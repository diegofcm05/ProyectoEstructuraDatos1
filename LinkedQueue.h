#pragma once
#include "TDACola.h"
#include "NodoAlumno.h"
class LinkedQueue : public TDACola
{
private:
	//Nodo representando la cabeza de la cola
	NodoAlumno* head;
	//Nodo representando el final de la cola
	NodoAlumno* tail;
	//Tamano de la cola
	int size;

public:
	//Constructor
	LinkedQueue();
	//Destructor
	~LinkedQueue();

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
