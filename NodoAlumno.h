#pragma once
#include "Alumno.h"
class NodoAlumno
{
private:
	//Apuntador al nodo siguiente de este nodo.
	NodoAlumno* siguiente;
	//Apuntador al nodo anterior de este nodo.
	NodoAlumno* anterior;
	//Contiene el dato del nodo, en este caso, un Alumno
	Alumno* dato;

public:
	//Constructor vacio
	NodoAlumno();
	//Constructor que contiene un alumno
	NodoAlumno(Alumno*);
	//Destructor
	~NodoAlumno();

	//getters y setters de NodoAlumno
	NodoAlumno* getAnterior();
	NodoAlumno* getSiguiente();
	Alumno* getDato();

	void setAnterior(NodoAlumno* nuevo);
	void setSiguiente(NodoAlumno* nuevo);
};
