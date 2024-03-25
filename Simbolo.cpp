#include "Simbolo.h"
#include <iostream>

//Constructor vacio
Simbolo::Simbolo()
{

}

//Constructor que recibira el caracter que se almacenara
Simbolo::Simbolo(char newSymbol)
{
	simb = newSymbol;
}

//Destructor
Simbolo::~Simbolo()
{

}

//Metodo toString, imprime el simbolo, es decir, el caracter
string Simbolo::toString()
{
	string abc;
	abc += "Simbolo - ";
	abc += simb;
	return abc;
}

//Metodo comparador, revisa si los caracteres son iguales o no
bool Simbolo::equals(Object* otroObj)
{
	if (dynamic_cast<Simbolo*>(otroObj)) {
		Simbolo* OtroSimbolo = dynamic_cast<Simbolo*>(otroObj);
		if (OtroSimbolo != nullptr) {
			if (OtroSimbolo->simb == this->simb) {
				return true;
			}
		}
	}
	return false;
}


//Setters y getters
char Simbolo::getSimbolo()
{
	return simb;
}

void Simbolo::setSimbolo(char newSimb)
{
	simb = newSimb;
}

