#pragma once
#include "Nodo.h"
#include "Object.h"
#include "NodoAlumno.h"
class TDAPila
{
public:
	int size = 0;
	NodoAlumno* inicio;
	NodoAlumno* final;
	//Metodo push (inserta un elemento dentro del stack)
	virtual void push(Object*) = 0;
	//Metodo pop (Quita el elemento mas proximo a salir del stack)
	virtual Object* pop() = 0;
	//Mira el top del stack, es decir, el ultimo elemento que se inserto
	virtual Object* top() = 0;
	//Verifica si la lista esta vacia
	virtual bool isEmpty() = 0;
	//Limpia el stack, borrando todos los elementos
	virtual void clear() = 0;
	//Imprime todos los elementos
	virtual void print() = 0;
};


