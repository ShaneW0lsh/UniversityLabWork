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
    /*
                TODO:
                доделать умножение матриц, код снизу.
    */
    void launch();
    /*
    1 4 3 4 1 2 3 4 1 3
    5 3 7 8 2 9 1 8 6 6
    */


    /*
        TridiagonalMatrix operator*(const TridiagonalMatrix& rhs) const {
            if (cols != rhs.rows) {
                throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix.");
            }

            TridiagonalMatrix result(rows, rhs.cols);

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < rhs.cols; ++j) {
                    int sum = 0;
                    for (int k = 0; k < cols; ++k) {
                        sum += get(i, k) * rhs.get(k, j);
                    }
                    result.set(i, j, sum);
                }
            }

            return result;
        }

        // ... (other methods and member variables)

    private:
        // ... (member variables and other private methods)

        // Get the value at a specific position in the tridiagonal matrix
        int get(int row, int col) const {
            if (row == col) {
                return data[row];
            } else if (col == row + 1) {
                return upperDiagonal[row];
            } else if (row == col + 1) {
                return lowerDiagonal[col];
            } else {
                return 0;
            }
        }

        // Set the value at a specific position in the tridiagonal matrix
        void set(int row, int col, int value) {
            if (row == col) {
                data[row] = value;
            } else if (col == row + 1) {
                upperDiagonal[row] = value;
            } else if (row == col + 1) {
                lowerDiagonal[col] = value;
            }
        }
    };
    */
}