#include <iostream>
#include "shape.h"


int main()
{
	std::cout << "Shape.h file\n";
	
	Rectangle* rectPt( new Rectangle(22.2, 11.1) );
	Shape* shapePt(rectPt); // Compiles and works well
	std::cout << shapePt->getArea() << std::endl;

	SharedPtr<Rectangle> rectSPt( new Rectangle(22.2, 11.1) );
	SharedPtr<Shape> shapeSPt(rectSPt); // Will not compile, but should
	std::cout << shapeSPt->getArea() << std::endl;

	//SharedPtr<Person> personSpt( new Person("Kyle",11111,22) );
	//SharedPtr<Shape> shapeSPt(personSpt); // Should never compile
	
	return 0;
}
