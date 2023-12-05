#pragma once

#include <iostream>

namespace lab52 {
    template<typename T>
    void init_array(T* arr, int size, T value);

    class Matrix {
    private:
        int rows;
        int columns;

    public:
        double* elements;
        Matrix(int rows, int columns);
        Matrix(int rows, int columns, double* elements);
        Matrix(const Matrix& other);
        ~Matrix();

        Matrix sum(const Matrix& other) const;
        Matrix sum(const double* arr, int size) const; // TODO 
        Matrix mult(const Matrix& other) const;
        Matrix mult(const double* arr, int size) const; // TODO
        double trace() const;
        double determinant() const;
        Matrix minor(int row, int col) const;
        void mult_by_num(double num);
        void input();
        void input(int i, int j);
        void input(int i, int j, double* arr);
        void print() const;
        int get_columns() const;
        int get_rows() const;
        double get_element(int i, int j) const;
        int get_size() const;
        bool is_square() const;
        bool equals(Matrix& other);
    };

    void launch();
}