#include "sharePtr.h"
#include "Person.h"
#include <iostream>

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

