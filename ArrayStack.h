#pragma once
#include <iostream>
#include "TDAPila.h"
#include "Object.h"
#include "Simbolo.h"

class ArrayStack : public TDAPila
{
public:
	//Constructor
	ArrayStack();
	//Destructor
	~ArrayStack();

	//Metodo push (inserta un elemento dentro del stack)
	void push(Object*);
	//Metodo pop (Quita el elemento mas proximo a salir del stack)
    Object* pop();
	//Mira el top del stack, es decir, el ultimo elemento que se inserto
	Object* top();
	//Verifica si la lista esta vacia
	bool isEmpty();
	//Limpia el stack, borrando todos los elementos
	void clear();
	//Imprime todos los elementos
	void print();


protected:
	Object** array;
	int capacidad;
};

