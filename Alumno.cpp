#include "Alumno.h"

//Constructor vacio de alumno
Alumno::Alumno()
{


}

//Constructor de alumno que recibe dos strings (nombre, cuenta)
Alumno::Alumno(string nombre, string NC) 
{
	name = nombre;
	numCuenta = NC;
}

//Destructor de alumno
Alumno::~Alumno()
{

}

//Metodo toString de Alumno
string Alumno::toString()
{
	string x = "Alumno - Nombre: " + name + " / Cuenta: " + numCuenta;
	return x;
}


//Metodo que compara dos alumnos
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


//Getters y Setters de nombre y cuenta
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



