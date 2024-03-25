#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
	this->array = new Alumno * [1000];
	for (int i = 0; i < 1000; i++) {
		array[i] = nullptr;
	}
	this->capacidad = 1000;

	this->head = 0;
	this->tail = 0;
}

ArrayQueue::~ArrayQueue()
{
	for (int i = 0; i < capacidad; i++) {
		if (array[i] != nullptr) {
			delete array[i];
		}
	}
	delete array;
}

//Funcion encolar: mete un alumno a la cola
void ArrayQueue::queue(Alumno* alm)
{
	//Evaluamos que no este llena.
	if (tail == head - 1 || (tail == capacidad - 1 && head == 0)) {
		cout << "La cola esta llena!!!" << endl;
	}
	else {
		array[tail] = alm;
		//Si esta al final del array que le de vuelta para no salirse.
		if (tail == capacidad - 1) {
			tail = 0;
		}
		//Si no que solo avance
		else {
			tail++;
		}
		cout << "Alumno ingresado exitosamente!" << endl;
	}
}

//Funcion desencolar: quita un alumno de la cola
Alumno* ArrayQueue::dequeue()
{
	//Evaluamos que no este vacia
	if (!vacia()) {
		Alumno* temporal = array[head];
		//Si ya es la ultima casilla que le de vuelta al array
		if (head == capacidad - 1) {
			head = 0;
		}
		//Si no solo avanza.
		else {
			head++;
		}
		return temporal;
	}
	else {
		cout << "La cola no tiene elementos!!!" << endl;
		return nullptr;
	}
}

//Mira el elemento proximo a salir, o el frente de la cola
void ArrayQueue::peek()
{
	if (!vacia())
		cout << "El elemento a la cabeza de la cola es: " << array[head]->toString() << endl;
	else
		cout << "La cola esta vacia" << endl;
}

//Revisa si la cola esta vacia
bool ArrayQueue::vacia()
{
	//La cola esta hecha tal que tail apunte a la primera casilla vacia del array ciclico, solo apunta a head si no hay nada mas en el array.
	bool vacia = (head == tail) ? true : false;
	return vacia;
}

//Borra todos los elementos de la cola
void ArrayQueue::anula()
{
	//Borra el array
	for (int i = 0; i < capacidad; i++) {
		if (array[i] != nullptr) {
			delete array[i];
		}
	}
	delete array;

	//crea otro de nuevo
	this->array = new Alumno * [1000];
	for (int i = 0; i < 1000; i++) {
		array[i] = nullptr;
	}

	head, tail = 0;
}

//Imprime todos los elementos actuales de la cola
void ArrayQueue::imprimir()
{
	if (!vacia()) {
		int actual = head;
		int cc = 1;
		//Imprimimos desde la cabeza hasta el ultimo elemento.
		while (actual != tail) {
			cout << cc << ".)" << array[actual]->toString() << endl;
			//Si llega al final del array que le de vuelta.
			if (actual == capacidad)
				actual = 0;
			else
				actual++;
			cc++;
		}
	}
	else {
		cout << "La cola esta vacia!!!" << endl;
	}
}

