#include "LinkedStack.h"

LinkedStack::LinkedStack()
{
}

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

Object* LinkedStack::pop()
{
	if (size > 0) {
		Nodo* top = tope;
		tope = tope->getAnterior();
		tope->setSiguiente(nullptr);
		top->setAnterior(nullptr);
		size--;
		return top->getDato();
	}
	else
		return NULL;
}

Object* LinkedStack::top()
{
	if (size > 0)
		return tope->getDato();
	else
		return NULL;
}

bool LinkedStack::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}

void LinkedStack::clear()
{
	if (size > 0)
		delete tope;
	size = 0;
}

void LinkedStack::print()
{
	Nodo* temp = tope;
	while (temp != nullptr) {
		cout << temp->getDato()->toString() << (temp->getAnterior() != nullptr ? ", " : " ");
		temp = temp->getAnterior();
	}
	cout << endl;
}

