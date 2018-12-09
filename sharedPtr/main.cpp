#include "smartPtr.h"
#include "person.h"
#include <iostream>

void testInit()
{
	UniquePtr<Person> p(new Person);
	p->setName("Moshe");
	p->print();
}

void testContent()
{
	UniquePtr<Person> p(new Person);
	p->print();
	Person person("Sari", 111, 22);
	*p = person;
	p->print();
}


int main()
{
	std::cout << "Hi!" << std::endl << std::endl;
	testInit();
	std::cout << std::endl;
	testContent();
	std::cout << std::endl;
	return 0;
}
