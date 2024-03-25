#pragma once
#include "TDAPila.h"
#include <iostream>
#include "Nodo.h"
using namespace std;

class LinkedStack : public TDAPila
{
	Nodo* tope = nullptr;
public:
	LinkedStack();
	void push(Object*);
	Object* pop();
	Object* top();
	bool isEmpty();
	void clear();
	void print();
};

