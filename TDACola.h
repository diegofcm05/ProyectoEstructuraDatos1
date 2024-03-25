#pragma once
#include "Alumno.h"
#include <iostream>

using namespace std;
class TDACola
{

public:
	virtual void queue(Alumno*);
	virtual Alumno* dequeue();
	virtual void peek();
	virtual bool vacia();
	virtual void anula();
	virtual void imprimir();

	TDACola();
	~TDACola();
};


