#include "Alumno.h"

Alumno::Alumno()
{


}

Alumno::Alumno(string nombre, string NC) 
{
	name = nombre;
	numCuenta = NC;
}


Alumno::~Alumno()
{

}


string Alumno::toString()
{
	string x = "Alumno - Nombre: " + name + " / Cuenta: " + numCuenta;
	return x;
}



bool Alumno::equals(Object* otroObj)
{
	if (dynamic_cast<Alumno*>(otroObj)) {
		Alumno* OtroAlumno = dynamic_cast<Alumno*>(otroObj);
		if (OtroAlumno != nullptr) {	
			if (OtroAlumno->numCuenta == this->numCuenta) {
				return true;
			}
		}
	}
	return false;
}

string Alumno::getNombre()
{
	return name;
}

void Alumno::setNombre(string newName)
{
	name = newName;
}

string Alumno::getCuenta()
{
	return numCuenta;
}

void Alumno::setCuenta(string newCuenta)
{
	numCuenta = newCuenta;
}



