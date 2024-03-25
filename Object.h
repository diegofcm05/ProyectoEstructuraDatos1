#pragma once
#include <string>
using namespace std;

class Object
{
public:
	Object();
	~Object();
	virtual string toString()=0;
	virtual bool equals(Object* otroObj) = 0;
};

