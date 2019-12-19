#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string.h>
using namespace std;

class Person
{
public:
	Person(int id, char* name);
	~Person();

	int getID();
	char* getName();

protected:
	int id_;
	char* name_;
};

#endif
