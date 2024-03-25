#pragma once
#include "Object.h"

class Simbolo : public Object
{
	char simb;

public:
	//Constructor vacio
	Simbolo();
	//Constructor que recibira el caracter que se almacenara
	Simbolo(char);
	//Destructor
	~Simbolo();

	//Metodo toString, imprime el simbolo, es decir, el caracter
	string toString();
	//Metodo comparador, revisa si los caracteres son iguales o no
	bool equals(Object* otroObj);

	//Setters y getters
	char getSimbolo();
	void setSimbolo(char);

};

