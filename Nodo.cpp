#include "Nodo.h"

Nodo::Nodo()
{
	siguiente = NULL;
	anterior = NULL;
	dato = NULL;

}

Nodo::Nodo(Object* obje)
{

}

Nodo::~Nodo()
{
	if (dato)
		delete dato;
	if (siguiente)
		delete siguiente;
}

Nodo* Nodo::getSiguiente() {
	return siguiente;
}
Nodo* Nodo::getAnterior() {
	return anterior;
}
Object* Nodo::getDato() {
	return dato;
}

void Nodo::setSiguiente(Nodo* pNext) {
	siguiente = pNext;
}
void Nodo::setAnterior(Nodo* pPrev) {
	anterior = pPrev;
}
void Nodo::setDato(Object* Data) {
	dato = Data;
}