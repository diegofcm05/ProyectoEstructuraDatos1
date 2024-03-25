#pragma once
#include "TDALista.h"
#include "Object.h"

class ArrayList : public TDALista
{
public:
	ArrayList();
	~ArrayList();

	//inserta el dato en la posicion indicada
	virtual bool inserta(Object* dato, int position);
	//quita el dato de la posicion indicada en el paramentro de la lista
	virtual bool suprime(int position);
	//borra todos los elementos de la lista
	virtual void anula();
	//retorna el objeto almacenado en la posicion indicada
	virtual Object* recupera(int position);
	//retorna el objkecto almacenado en la posicion anterior a la indiciada
	virtual Object* anterior(int position);
	//retorna el objkecto almacenado en la posicion siguiente a la indiciada
	virtual Object* siguiente(int position);
	//imprime los objetos de la lista
	virtual void imprime_lista();
	//retorna la posicion donde se ubica el dato indicado en el prametro
	virtual int busca(Object* dato);
	//retorna verdadero si la lista esta vacia
	virtual bool vacia();

protected:
	Object** array;
	int capacidad;

};
