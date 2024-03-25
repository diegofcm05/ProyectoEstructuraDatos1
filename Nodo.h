#pragma once
#include "Object.h"
class Nodo
{
protected:
	//Apuntador al nodo siguiente del actual.
	Nodo* siguiente;
	//Apuntador al nodo anterior del actual.
	Nodo* anterior;
	//Contiene la informacion dentro del nodo
	Object* dato;
public:
	//Constructor vacio
	Nodo();
	//Constructor que recibe un objeto
	Nodo(Object*);
	//Destructor
	~Nodo();
	
	//Getters y setters de los atributos de esta clase
	Nodo* getSiguiente();
	Nodo* getAnterior();
	void setDato(Object*);
	Object* getDato();
	void setSiguiente(Nodo*);
	void setAnterior(Nodo*);
};
