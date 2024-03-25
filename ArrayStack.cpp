#include "ArrayStack.h"


ArrayStack::ArrayStack()
{
	capacidad = 1000;
	array = new Object* [capacidad];
	size = 0;
}

ArrayStack::~ArrayStack()
{
	for (int i = 0; i < size; i++)
	{
		delete array[i];
	}

	delete[] array;
}

void ArrayStack::push(Object* obj)
{
	if (size < capacidad) {
		array[size] = obj;
		cout << "Objeto agregado" << endl;
		size++;
	}
	else {
		cout << "El stack esta lleno. El objeto no se agrego.";
	}
	
}

Object* ArrayStack::pop()
{
	Object* Devuelto = NULL;

	if (size) {
		Devuelto = array[size - 1];
		array[size - 1] = NULL;
		size--;
		return Devuelto;
	}
	else
	{
		cout << "No hay nada en el stack para sacar. Esta vacio." << endl;
		return NULL;
	}
	
	
}

Object* ArrayStack::top()
{
	if (size) {
		return array[size - 1];
	}
	else
		cout << "No hay nada en el stack. Esta vacio y no hay tope." << endl;
		return NULL;
}

bool ArrayStack::isEmpty()
{
	if (size) {
		return false;
	}
	else
		return true;
}

void ArrayStack::clear()
{
	for (int i = 0; i < size; i++)
	{
		delete array[i];
	}
	size = 0;

}

void ArrayStack::print()
{
	if (size < 1) {
		cout << "No hay elementos para imprimir. El stack esta vacio.\n";
	}
	else {
		cout << "Elementos de stack (en orden del que deberian salir):\n";
		for (int i = size-1; i >= 0; i--)
		{
			cout << array[i]->toString() << endl;
		}
	}
	
}
