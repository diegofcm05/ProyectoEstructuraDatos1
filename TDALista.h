#pragma once
#include "Object.h"

#include <iostream>
using namespace std;

class TDALista
{

public:
	//inserta el dato en la posicion indicada
	virtual bool inserta(Object* dato, int position) = 0;
	//quita el dato de la posicion indicada en el paramentro de la lista
	virtual bool suprime(int position) = 0;
	//borra todos los elementos de la lista
	virtual void anula() = 0;
	//retorna el objeto almacenado en la posicion indicada
	virtual Object* recupera(int position) = 0;
	//retorna el objkecto almacenado en la posicion anterior a la indiciada
	virtual Object* anterior(int position) = 0;
	//retorna el objkecto almacenado en la posicion siguiente a la indiciada
	virtual Object* siguiente(int position) = 0;
	//imprime los objetos de la lista
	virtual void imprime_lista() = 0;
	//retorna la posicion donde se ubica el dato indicado en el prametro
	virtual int busca(Object* dato) = 0;
	//retorna verdadero si la lista esta vacia
	virtual bool vacia() = 0;

	int getSize();

protected:
	int size;
};

