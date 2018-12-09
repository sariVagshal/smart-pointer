#include "sharePtr.h"
#include "Person.h"
#include <iostream>
#include <cstddef>//NULL
#include <cstring>//strcmp


void testCtor()
{
    std::cout << ("\n\n---testCtor---") << std::endl;
    SharedPtr<Person> p(new Person("Michal", 206169740, 23));
    std::cout << "passed test ctor" << std::endl;
}

void testOperatorArrow()
{
    std::cout << ("\n\n---testOperatorArrow---") << std::endl;

    SharedPtr<Person> p(new Person("Michal", 206169740, 23));
    p->setAge(99);
    p->setName("Shimshon");
    p->setID(9876543);

    if (p->getAge() == 99)
        std::cout << "passed test operator arrow" << std::endl;
    else
        std::cout << "not passed test operator arrow" << std::endl;
}

void testOperatorStar()
{
    std::cout << ("\n\n---testOperatorStar---") << std::endl;

    SharedPtr<Person> p(new Person("Michal", 206169740, 23));
    (*p).setAge(99);
    (*p).setName("Shimshon");
    (*p).setID(9876543);

    if (p->getAge() == 99)
        std::cout << "passed test operator star" << std::endl;
    else
        std::cout << "not passed test operator star" << std::endl;
}

void testOperatorBool()
{
    std::cout << ("\n\n---testOperatorBool---") << std::endl;
    SharedPtr<Person> p(new Person("Michal", 206169740, 23));
    if(p)
    {
        std::cout << "passed test operator bool" << std::endl;
    }
    else
    {
        std::cout << "not passed test operator bool" << std::endl;
    }
}


bool func(SharedPtr<Person> p)
{
    p->setAge(24);
    return p.getCounter() == 2;
}

void testCpyCtor()
{
    std::cout << ("\n\n---testCpyCtor---") << std::endl;

    SharedPtr<Person> p(new Person("Michal", 206169740, 23));

    if(func(p))
    {
        if(p.getCounter() == 1 && p->getAge() == 24)
            std::cout << "passed test copy constructor" << std::endl;
        return;
    }
    std::cout << "not passed test copy constructor" << std::endl;
}

void testAssignmentOperator()
{
    std::cout << ("\n\n---testAssignmentOperator---") << std::endl;

    SharedPtr<Person> p(new Person("Michal", 206169740, 23));

    SharedPtr<Person> ptrArr[3];

    for (int i = 0; i < 3; ++i)
    {
        ptrArr[i] = p;
    }

    std::cout << "number of pointers : " << p.getCounter() << std::endl;

    if(p.getCounter() == 4)
    {
        std::cout << "passed test assignment operator" << std::endl;
        return;
    }
    std::cout << "not passed test assignment operator" << std::endl;
}

int main()
{
	std::cout << "Hi!\n\n";
	
	testOperatorArrow();

    testOperatorStar();

    testOperatorBool();

    testCpyCtor();

    testAssignmentOperator();
}
