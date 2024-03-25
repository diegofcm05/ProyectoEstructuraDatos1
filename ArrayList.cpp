#include "ArrayList.h"
#include "Alumno.h"


ArrayList::ArrayList()
{
	this->size = 0;
	this->capacidad = 1000; //se puede evaluar como incializar y aumentar
	this->array = new Object * [capacidad];
	for (size_t i = 0; i < capacidad; i++)
	{
		this->array[i] = nullptr;
	}
}

ArrayList::~ArrayList()
{

	for (int i = 0; i < size; i++)
	{
		if (array[i] != nullptr)
			delete array[i];
	}

	delete[] array;
}

bool ArrayList::inserta(Object* dato, int position)
{
	position--;

	if (position >= 0 && position <= this->size) {

		for (int i = size - 1; i >= position; i--)
		{
			array[i + 1] = array[i];
		}
		array[position] = dato;
		this->size++;
		return true;
	}
	return false;
}

bool ArrayList::suprime(int position)
{
	position--;

	if (position >= 0 && position < size) {

		for (int i = position; i < size - 1; i++)
		{
			array[i] = array[i + 1];
		}
		array[size - 1] = nullptr;
		this->size--;
		return true;
	}
	return false;
}

void ArrayList::anula()
{
	for (int i = 0; i < size; i++)
	{
		delete array[i];
		array[i] = nullptr;
	}
	size = 0;
}

Object* ArrayList::recupera(int position)
{
	position--;
	if (position >= 0 && position < size) {
		if (dynamic_cast<Alumno*>(array[position])) {
			return dynamic_cast<Alumno*>(array[position]);
		}
	}
	return nullptr;
}

Object* ArrayList::anterior(int position)
{
	position--;
	if (position > 0 && position < size) {
		if (dynamic_cast<Alumno*>(array[position])) {
			return dynamic_cast<Alumno*>(array[position - 1]);
		}
	}

	return nullptr;
}

Object* ArrayList::siguiente(int position)
{
	position--;
	if (position >= 0 && position < size - 1)
	{
		if (dynamic_cast<Alumno*>(array[position])) {
			return dynamic_cast<Alumno*>(array[position + 1]);
		}
	}
	return nullptr;
}

void ArrayList::imprime_lista()
{
	for (int i = 0; i < size; i++)
	{
		if (dynamic_cast<Alumno*>(array[i]))
			cout << (i + 1) << ". " << dynamic_cast<Alumno*>(array[i])->toString() << endl;
		else
			cout << "El objeto en pos " << i << " no es Alumno" << endl;


	}
}

int ArrayList::busca(Object* dato)
{
	for (size_t i = 0; i < size; i++)
	{
		if (dynamic_cast<Alumno*>(array[i])) {
			if (array[i]->equals(dato)) {

				return i + 1;
			}
		}
	}
	cout << "No se encontro ningun elemento con ese numero de cuenta en la lista" << endl;
	return 0;
}

bool ArrayList::vacia()
{
	if (this->size == 0) {
		return true;
	}
	return false;
}
