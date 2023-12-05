#pragma once
#include <iostream>
#include "Kolomychenko_Daniil_231_329_lab52.h"

namespace lab53 {

    void init_array(int* arr, int size);

    class TridiagonalMatrix {
    private:
        int size;
        int* data;
        int* upper_diagonal;
        int* lower_diagonal;

    public:
        TridiagonalMatrix(int size);
        ~TridiagonalMatrix();

        void input();
        void print() const;
        int tr() const;

        friend std::ostream& operator<<(std::ostream& os, const TridiagonalMatrix& matrix);
        friend std::istream& operator>>(std::istream& is, TridiagonalMatrix& matrix);
        TridiagonalMatrix operator+(const TridiagonalMatrix& other) const;
        TridiagonalMatrix operator-(const TridiagonalMatrix& other) const;
        TridiagonalMatrix operator*(const int num);
        lab52::Matrix operator*(const TridiagonalMatrix& other) const;
        TridiagonalMatrix operator-();
        void operator+=(const TridiagonalMatrix& other);
        void operator-=(const TridiagonalMatrix& other);

        int get(int row, int col) const;
        void set(int row, int col, int value);

        int get_size() const;
    };
    void launch();
}