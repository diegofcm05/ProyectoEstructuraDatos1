#include "Simbolo.h"
#include <iostream>
Simbolo::Simbolo()
{
	
}

Simbolo::Simbolo(char newSymbol)
{
	simb = newSymbol;
}

Simbolo::~Simbolo()
{

}

string Simbolo::toString()
{
	string abc;
	abc += "Simbolo - ";
	abc += simb;
	return abc;
}

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

char Simbolo::getSimbolo()
{
	return simb;
}

void Simbolo::setSimbolo(char newSimb)
{
	simb = newSimb;
}

