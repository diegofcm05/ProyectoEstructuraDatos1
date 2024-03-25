#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

LinkedQueue::~LinkedQueue()
{
	delete head;
}

void LinkedQueue::queue(Alumno* alumno)
{
	NodoAlumno* temporal = new NodoAlumno(alumno);
	//Si no esta vacia le a?ade un elemento a la par de la cola y luego hace que el nuevo se convierta en la cola.
	if (size != 0) {
		tail->setSiguiente(temporal);
		temporal->setAnterior(tail);
		tail = temporal;
	}
	//Si esta vacia el nuevo elemento es el unico y por lo tanto es la cabeza y la cola a la vez.
	else {
		head = temporal;
		tail = temporal;
	}
	size++;
	cout << "Alumno ingresado exitosamente" << endl;
}

Alumno* LinkedQueue::dequeue()
{
	if (size != 0) {
		//Si posee un unico elemento hace que la cabeza y la cola vuelvan a no apuntar a nada.
		Alumno* retornar = head->getDato();
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		//Si no, hace que la cabeza se vuelva el de la derecha a la cabeza anterior.Despega la cabeza anterior de la lista.
		else {
			head = head->getSiguiente();
			head->getAnterior()->setSiguiente(nullptr);
			head->setAnterior(nullptr);
		}
		size--;
		return retornar;
	}
	else {
		cout << "La cola esta vacia!!!" << endl;
		return nullptr;
	}
}

void LinkedQueue::peek()
{
	if (!vacia())
		cout << "El alumno al inicio de la cola es: " << head->getDato()->toString() << endl;
	else
		cout << "La cola esta vacia!!!" << endl;
}

bool LinkedQueue::vacia()
{
	bool vacia = size == 0 ? true : false;
	return vacia;
}

void LinkedQueue::anula()
{
	delete head;
	head = nullptr;
	tail = nullptr;
	size = 0;
}

void LinkedQueue::imprimir()
{
	if (vacia()) {
		cout << "La cola esta vacia!!!" << endl;
	}
	else {
		//Imprime el temporal y luego sigue al de la derecha hasta terminar con todos los elementos.
		NodoAlumno* temporal = head;
		for (int i = 1; i <= size; i++) {
			cout << i << ".)" << temporal->getDato()->toString() << endl;
			temporal = temporal->getSiguiente();
		}
	}
}