#include "Kolomychenko_Daniil_231_329_lab54.h"

lab54::Position::Position(int x, int y)
    : x(x), y(y)
{
}

void lab54::Position::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

int lab54::Position::getX() const
{
    return x;
}

int lab54::Position::getY() const
{
    return y;
}

lab54::Circle::Circle(int x, int y, int radius)
    : Position(x, y), radius(radius)
{
}

double lab54::Circle::getPerimeter() const
{
    return 2 * 3.14 * radius;
}

double lab54::Circle::getArea() const
{
    return 3.14 * radius * radius;
}

lab54::Square::Square(int x, int y, int side)
    : Position(x, y), side(side)
{
}

double lab54::Square::getPerimeter() const
{
    return 4 * side;
}

double lab54::Square::getArea() const
{
    return side * side;
}

lab54::CircleInSquare::CircleInSquare(int x, int y, int radius)
    : Circle(x, y, radius), Square(x, y, radius * 2)
{
}


void lab54::launch()
{
    Circle circle(0, 0, 5);
    std::cout << "Circle Perimeter: " << circle.getPerimeter() << std::endl;
    std::cout << "Circle Area: " << circle.getArea() << std::endl;

    Square square(0, 0, 5);
    std::cout << "Square Perimeter: " << square.getPerimeter() << std::endl;
    std::cout << "Square Area: " << square.getArea() << std::endl;

    CircleInSquare circleInSquare(0, 0, 5);
    std::cout << "Circle in Square Perimeter: " << circleInSquare.Square::getPerimeter() << std::endl;
    std::cout << "Circle in Square Area: " << circleInSquare.Square::getArea() << std::endl;
}