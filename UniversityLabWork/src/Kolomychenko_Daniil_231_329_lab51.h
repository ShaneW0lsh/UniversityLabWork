#pragma once
#include <iostream>

namespace lab51 {
    void launch();

    template<typename T>
    void init_array(T* arr, int size, T value = 0);

    class Matrix {
    private:
        int rows;
        int columns;
        double* elements;
    public:
        Matrix(int rows, int columns);
        Matrix(int rows, int columns, double* elements);
        Matrix(const Matrix& other);
        ~Matrix();

        Matrix sum(const Matrix& other) const;
        Matrix mult(const Matrix& other) const;
        Matrix minor(int row, int col) const;
        double trace() const;
        double determinant() const;
        void mult_by_num(double num);
        void input();
        void print() const;
        int get_columns() const;
        int get_rows() const;
        double get_element(int i, int j) const;
        bool is_square() const;
        int get_size() const;
        bool equals(Matrix& other);
    };
}