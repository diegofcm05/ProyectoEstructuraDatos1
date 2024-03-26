#include "Nodo.h"

//Constructor vacio
Nodo::Nodo()
{
	siguiente = nullptr;
	anterior = nullptr;
	dato = nullptr;
}

//Constructor que recibe un objeto
Nodo::Nodo(Object* Dato)
{
	siguiente = nullptr;
	anterior = nullptr;
	dato = Dato;
}

//Destructor
Nodo::~Nodo()
{
	if (dato) {
		delete dato;
	}
	if (siguiente)
		delete siguiente;
}
//Funcion para obtener el siguiente nodo
Nodo* Nodo::getSiguiente()
{
	return siguiente;
}
//Funcion para obtener el Nodo Anterior
Nodo* Nodo::getAnterior()
{
	return anterior;
}
//Funcion para establecer el nuevo dato contenido en el Nodo
void Nodo::setDato(Object* Dato)
{
	dato = Dato;
}
Object* Nodo::getDato()
{
	return dato;
}
//Funcion para establecer el Nodo siguiente
void Nodo::setSiguiente(Nodo* Siguiente)
{
	siguiente = Siguiente;
}
//Funcion para establecer el Nodo anterior
void Nodo::setAnterior(Nodo* Anterior)
{
	anterior = Anterior;
}