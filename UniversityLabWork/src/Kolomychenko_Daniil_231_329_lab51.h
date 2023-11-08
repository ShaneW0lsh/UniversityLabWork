#pragma once
#include <iostream>

namespace lab51 {

    class Matrix {
    private:
        int rows;
        int columns;
        int size;
        double* elements;
    public:
        Matrix(int rows, int columns);
        
        Matrix(int rows, int columns, double* elements);

        ~Matrix();

        Matrix sum(const Matrix& other);
        void mult(const Matrix* other);
        double trace() const;
        double& at(int i, int j);
        void swapRows(int row1, int row2);
        double determinant() const;
        void mult_by_num(double num);
        void input();
        void print() const;
        int get_columns();
        int get_rows();
        double get_element(int i, int j);
    };

    void launch();
}