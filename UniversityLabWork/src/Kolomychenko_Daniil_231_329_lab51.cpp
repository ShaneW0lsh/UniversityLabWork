#include <iostream>

static class Matrix {
private:
    int rows;
    int columns;
    int size;
    double* elements;

public:
    Matrix(int rows, int columns)
    : rows(rows), columns(columns) {
        elements = new double[rows * columns];
        size = rows;
    }

    ~Matrix() { delete[] elements; }

    void sum(const Matrix* other) {
        for (int i = 0; i < rows * columns; ++i)
            this->elements[i] += other->elements[i];
    }

    void mult(const Matrix* other) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other->columns; ++j) {
                this->elements[i * other->columns + j] = 0;
                for (int k = 0; k < columns; ++k) {
                    this->elements[i * other->columns + j] += elements[i * columns + k] 
                        * other->elements[k * other->columns + j];
                }
            }
        }
    }

    double trace() const {
        double traceValue = 0;
        for (int i = 0; i < rows; ++i) {
            traceValue += elements[i * columns + i];
        }
        return traceValue;
    }

    double& at(int i, int j) {
        return elements[i * size + j];
    }

    void swapRows(int row1, int row2) {
        for (int i = 0; i < size; ++i) {
            double temp = at(row1, i);
            at(row1, i) = at(row2, i);
            at(row2, i) = temp;
        }
    }

    // Function to calculate determinant using Gaussian elimination (LU decomposition)
    double determinant() const {
        double det = 1;
        Matrix temp(rows, columns);

        for (int i = 0; i < size * size; ++i) {
            temp.elements[i] = elements[i];
        }

        for (int i = 0; i < size - 1; ++i) {
            if (temp.at(i, i) == 0) {
                for (int j = i + 1; j < size; ++j) {
                    if (temp.at(j, i) != 0) {
                        temp.swapRows(i, j);
                        det *= -1; // Swap rows changes the sign of the determinant
                        break;
                    }
                }
            }

            if (temp.at(i, i) == 0) {
                return 0; // Matrix is singular, determinant is 0
            }

            for (int j = i + 1; j < size; ++j) {
                double ratio = temp.at(j, i) / temp.at(i, i);
                for (int k = i; k < size; ++k) {
                    temp.at(j, k) -= ratio * temp.at(i, k);
                }
            }
        }

        // Calculate determinant by multiplying diagonal elements
        for (int i = 0; i < size; ++i) {
            det *= temp.at(i, i);
        }

        return det;
    }

    void mult_by_num(double num) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                elements[i * columns + j] *= num;
            }
        }
    }

    void input() {
        std::cout << "Enter matrix elements:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cin >> elements[i * columns + j];
            }
        }
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cout << elements[i * columns + j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    int get_columns() {
        return columns;
    }

    int get_rows() {
        return rows;
    }

    double get_element(int i, int j) {
        return elements[i * columns + j];
    }
};

void lab51() {
    Matrix m(3, 3);
    m.input();

    m.print();
    std::cout << m.trace() << std::endl;
    std::cout << m.determinant() << std::endl;
}