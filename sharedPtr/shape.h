#include "sharePtr.h"
#include "Person.h"

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}
    virtual double getArea() const = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : m_w(w), m_h(h) {}
    virtual ~Rectangle() {}
    virtual double getArea() const { return m_w * m_h; }
private:
    double m_w, m_h;
};

Rectangle* rectPt( new Rectangle(22.2, 11.1) );
Shape* shapePt(rectPt); // Compiles and works well

SharedPtr<Rectangle> rectSPt( new Rectangle(22.2, 11.1) );
SharedPtr<Shape> shapeSPt(rectSPt); // Will not compile, but should

SharedPtr<Person> personSpt( new Person("Kyle") );
SharedPtr<Shape> shapeSPt(personSpt); // Should never compile
