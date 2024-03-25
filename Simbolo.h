#pragma once
#include "Object.h"

class Simbolo : public Object
{
	char simb;

public:

	Simbolo();
	Simbolo(char);
	~Simbolo();

	string toString();
	bool equals(Object* otroObj);

	char getSimbolo();
	void setSimbolo(char);

};

