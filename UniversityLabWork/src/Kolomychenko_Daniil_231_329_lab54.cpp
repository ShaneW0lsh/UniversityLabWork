#include <iostream>
#include <cmath>

class Position {
public:
    Position(int x = 0, int y = 0) : x(x), y(y) {}

    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

private:
    int x;
    int y;
};

class Circle : public Position {
public:
    Circle(int x, int y, int radius) : Position(x, y), radius(radius) {}

    double getPerimeter() const {
        return 2 * 3.14 * radius;
    }

    double getArea() const {
        return 3.14 * radius * radius;
    }

private:
    int radius;
};

class Square : public Position {
public:
    Square(int x, int y, int side) : Position(x, y), side(side) {}

    double getPerimeter() const {
        return 4 * side;
    }

    double getArea() const {
        return side * side;
    }

private:
    int side;
};

class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare(int x, int y, int radius) : Circle(x, y, radius), Square(x, y, radius * 2) {}

    double getPerimeter() const {
        return Square::getPerimeter();
    }

    double getArea() const {
        return Square::getArea();
    }
};

void lab54() {
    Circle circle(0, 0, 5);
    std::cout << "Circle Perimeter: " << circle.getPerimeter() << std::endl;
    std::cout << "Circle Area: " << circle.getArea() << std::endl;

    Square square(0, 0, 5);
    std::cout << "Square Perimeter: " << square.getPerimeter() << std::endl;
    std::cout << "Square Area: " << square.getArea() << std::endl;

    CircleInSquare circleInSquare(0, 0, 5);
    std::cout << "Circle in Square Perimeter: " << circleInSquare.getPerimeter() << std::endl;
    std::cout << "Circle in Square Area: " << circleInSquare.getArea() << std::endl;
}