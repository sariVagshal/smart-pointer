#include "Person.h"
#include <iostream> //cout
#include <cstring> //strcpy
using std::cout;
using std::endl;


Person::Person():ID(0), age(0)
{
	strcpy(fullName, "---");
}

Person::Person(const char* name, unsigned int id, unsigned char agePeople):ID(id), age(agePeople)
{
	strcpy(fullName, name);
}

Person::~Person()
{}
	
	
void Person::setName(const char * name)
{
	strcpy(fullName, name);
}

void Person::setID(unsigned int id)
{
	ID = id;
}

void Person::setAge(unsigned char agePeople)
{
	age = agePeople;
}
	
const char * Person::getName() const
{
	return fullName;
}

unsigned int Person::getID() const
{
	return ID;
}

unsigned char Person::getAge() const
{
	return age;
}
	
	
	
#ifdef TESTING
bool Person::checkFrees(size_t arr[], size_t size)
{
	int a = 9;
	++a;
	return true;
}
void Person::print() const
{
	cout<<"=> PERSON details:"<<endl;
	cout<<"full name:	"<<fullName<<endl;
	cout<<"ID:	"<<ID<<endl;
	cout<<"age:	"<<(int)age<<endl;
}
#endif
