#ifndef __PERSON_H__
#define __PERSON_H__
#include <cstddef>


class Person
{
public:
	Person();
	Person(const char*, unsigned int, unsigned char);
	~Person();
	
	void setName(const char *);
	void setID(unsigned int);
	void setAge(unsigned char);
	
	const char * getName() const;
	unsigned int getID() const;
	unsigned char getAge() const;
	
#ifdef TESTING
	static bool checkFrees(size_t arr[], size_t size);
	void print() const;
#endif
private:
	char fullName[32];
	unsigned int ID;
	unsigned char age;
};



#endif /*__PERSON_H__*/
