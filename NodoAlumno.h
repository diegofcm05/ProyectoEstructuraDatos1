#pragma once
#include "Alumno.h"
class NodoAlumno
{
private:
	NodoAlumno* siguiente;
	NodoAlumno* anterior;
	Alumno* dato;

public:
	NodoAlumno();
	NodoAlumno(Alumno*);
	~NodoAlumno();

	NodoAlumno* getAnterior();
	NodoAlumno* getSiguiente();
	Alumno* getDato();

	void setAnterior(NodoAlumno* nuevo);
	void setSiguiente(NodoAlumno* nuevo);
};
