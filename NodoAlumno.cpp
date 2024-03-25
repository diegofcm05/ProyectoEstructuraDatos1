#include "NodoAlumno.h"

NodoAlumno::NodoAlumno()
{
}

NodoAlumno::NodoAlumno(Alumno* dato)
{
	this->dato = dato;
	this->anterior = nullptr;
	this->siguiente = nullptr;
}

NodoAlumno::~NodoAlumno()
{
	delete this->dato;
}

NodoAlumno* NodoAlumno::getAnterior()
{
	return this->anterior;
}

NodoAlumno* NodoAlumno::getSiguiente()
{
	return this->siguiente;
}

Alumno* NodoAlumno::getDato()
{
	return this->dato;
}

void NodoAlumno::setAnterior(NodoAlumno* nuevo)
{
	this->anterior = nuevo;
}

void NodoAlumno::setSiguiente(NodoAlumno* nuevo)
{
	this->siguiente = nuevo;
}

