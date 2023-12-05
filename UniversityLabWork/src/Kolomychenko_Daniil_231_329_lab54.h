#pragma once
#include <iostream>
#include <cmath>

namespace lab54 {
    class Position {
    public:
        Position(int x = 0, int y = 0);

        void setPosition(int x, int y);

        int getX() const;

        int getY() const;

    private:
        int x;
        int y;
    };

    class Circle : public virtual Position {
    public:
        Circle(int x, int y, int radius);

        double getPerimeter() const;

        double getArea() const;

    private:
        int radius;
    };

    class Square : public virtual Position {
    public:
        Square(int x, int y, int side);

        double getPerimeter() const;

        double getArea() const;

    private:
        int side;
    };

    class CircleInSquare : public Circle, public Square {
    public:
        CircleInSquare(int x, int y, int radius);
    };

    void launch();
}