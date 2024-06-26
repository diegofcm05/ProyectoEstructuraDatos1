#include "ArrayStack.h"

//Constructor
ArrayStack::ArrayStack()
{
	capacidad = 1000;
	array = new Object* [capacidad];
	size = 0;
}

//Destructor
ArrayStack::~ArrayStack()
{
	for (int i = 0; i < size; i++)
	{
		delete array[i];
	}

	delete[] array;
}


//Metodo push (inserta un elemento dentro del stack)
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

//Metodo pop (Quita el elemento mas proximo a salir del stack)
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

//Mira el top del stack, es decir, el ultimo elemento que se inserto
Object* ArrayStack::top()
{
	if (size) {
		return array[size - 1];
	}
	else
		cout << "No hay nada en el stack. Esta vacio y no hay tope." << endl;
		return NULL;
}

//Verifica si la lista esta vacia
bool ArrayStack::isEmpty()
{
	if (size) {
		return false;
	}
	else
		return true;
}

//Limpia el stack, borrando todos los elementos
void ArrayStack::clear()
{
	for (int i = 0; i < size; i++)
	{
		delete array[i];
	}
	size = 0;

}

//Imprime todos los elementos
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
