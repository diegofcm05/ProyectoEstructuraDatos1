#pragma once
#include "Alumno.h"
#include <iostream>

using namespace std;
class TDACola
{

public:
	//Metodos virtuales padre de Cola/Queue (son implementados en ArrayQueue y LinkedQueue)
	//Sus explicaciones tambien se encuentran ahi
	virtual void queue(Alumno*);
	virtual Alumno* dequeue();
	virtual void peek();
	virtual bool vacia();
	virtual void anula();
	virtual void imprimir();

	//Constructor y Destructor
	TDACola();
	~TDACola();
};


