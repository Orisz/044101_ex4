#include "Person.h"


//************************************************************************************************************
//* Function name : Person::Person
//* Description   : constructor of the class person initialize all the parameters
//* Parameters    : int id - the id of the new person
//*					char* name - the name of the new person
//* Return value  : None.
//************************************************************************************************************

Person::Person(int id, char* name) :
	id_(id)
{
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}

//************************************************************************************************************
//* Function name : Person::~Person
//* Description   : distructor of the class person, delete the memory of the name
//* Parameters    : None.
//* Return value  : None.
//************************************************************************************************************

Person::~Person()
{
	delete []name_;
}

//************************************************************************************************************
//* Function name : Person::getID
//* Description   : the function return the id of the person
//* Parameters    : None.
//* Return value  : int - the id of the person
//************************************************************************************************************

int Person::getID()
{
	return id_;
}

//************************************************************************************************************
//* Function name : Person::getName
//* Description   : the function return copy of the name of the person
//* Parameters    : None.
//* Return value  : char* - the name of the person
//************************************************************************************************************

char* Person::getName()
{
	char* copy_name = new char[strlen(name_) + 1];
	strcpy(copy_name, name_);
	return copy_name;
}
