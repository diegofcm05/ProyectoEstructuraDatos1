#pragma once
#include "Object.h"

class Alumno : public Object
{
	
	string name;
	string numCuenta;


public:
	Alumno();
	Alumno(string, string);
	~Alumno();

	string toString();
	bool equals(Object* otroObj);

	string getNombre();
	void setNombre(string);

	string getCuenta();
	void setCuenta(string);


};

