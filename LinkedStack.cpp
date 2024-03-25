#include "LinkedStack.h"

LinkedStack::LinkedStack()
{
}

//Metodo push (inserta un elemento dentro del stack)
void LinkedStack::push(Object* nvoObjeto)
{
	Nodo* node = new Nodo(nvoObjeto);
	if (tope == nullptr)
		tope = node;
	else {
		tope->setSiguiente(node);
		node->setAnterior(tope);
		tope = tope->getSiguiente();
	}
	size++;
}

//Metodo pop (Quita el elemento mas proximo a salir del stack)
Object* LinkedStack::pop()
{
	if (size > 1) {
		Nodo* top = tope;
		tope = tope->getAnterior();
		tope->setSiguiente(nullptr);
		top->setAnterior(nullptr);
		size--;
		return top->getDato();
	}
	else if (size == 1) {

		size--;
		return tope->getDato();
	}
	else
		return NULL;
}

//Mira el top del stack, es decir, el ultimo elemento que se inserto
Object* LinkedStack::top()
{
	if (size > 0)
		return tope->getDato();
	else
		return NULL;
}

//Verifica si la lista esta vacia
bool LinkedStack::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}

//Limpia el stack, borrando todos los elementos
void LinkedStack::clear()
{
	if (size > 0)
		delete tope;
	tope = NULL;
	size = 0;
}

//Imprime todos los elementos
void LinkedStack::print()
{
	Nodo* temp = tope;
	while (temp != nullptr) {
		cout << temp->getDato()->toString() << (temp->getAnterior() != nullptr ? ", " : " ");
		temp = temp->getAnterior();
	}
	cout << endl;
}

