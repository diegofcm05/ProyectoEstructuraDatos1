#pragma once
#include <iostream>
#include "TDAPila.h"
#include "Object.h"
#include "Simbolo.h"

class ArrayStack : public TDAPila
{
public:
	ArrayStack();
	~ArrayStack();
	void push(Object*);
    Object* pop();
	Object* top();
	bool isEmpty();
	void clear();
	void print();


protected:
	Object** array;
	int capacidad;
};

