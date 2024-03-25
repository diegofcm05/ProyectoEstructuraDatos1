#pragma once
#include "Object.h"

class Alumno : public Object
{
	
	string name; //Nombre del Alumno
	string numCuenta; //Numero de Cuenta


public:
	//Constructor vacio de alumno
	Alumno(); 
	//Constructor de alumno que recibe dos strings (nombre, cuenta)
	Alumno(string, string);
	//Destructor de alumno
	~Alumno();

	//Metodo toString de Alumno
	string toString();
	//Metodo que compara dos alumnos
	bool equals(Object* otroObj);

	//Getters y Setters de nombre y cuenta
	string getNombre();
	void setNombre(string);
	string getCuenta();
	void setCuenta(string);


};

