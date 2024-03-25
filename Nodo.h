#pragma once
#include "Object.h"
class Nodo
{
public:
	Nodo();
	Nodo(Object*);
	~Nodo();

	Nodo* getSiguiente();
	Nodo* getAnterior();
	Object* getDato();

	void setSiguiente(Nodo*);
	void setAnterior(Nodo*);
	void setDato(Object*);

protected:
	Nodo* siguiente;
	Nodo* anterior;
	Object* dato;
};

