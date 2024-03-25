#pragma once
#include <string>
using namespace std;

class Object
{
public:
	Object();
	~Object();
	//Metodo toString padre; se implementa de diferente manera en alumno y simbolo.
	virtual string toString()=0;
	//Metodo comparador padre; se implementa de diferente manera en alumno y simbolo.
	virtual bool equals(Object* otroObj) = 0;
};

