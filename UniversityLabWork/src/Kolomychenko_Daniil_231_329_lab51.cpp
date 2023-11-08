#include "Kolomychenko_Daniil_231_329_lab51.h"

void lab51::launch() {
    Matrix m(3, 3);
    double* el = new double[9]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix m2(3, 3, el);
}

lab51::Matrix::Matrix(int rows, int columns)
    :rows(rows), columns(columns), size(rows)
{
    elements = new double[rows * columns];
    for (int i = 0; i < rows * columns; ++i) elements[i] = 0.0;
    std::cout << "First constructor did link\n";
}

lab51::Matrix::Matrix(int rows, int columns, double* elements)
    :rows(rows), columns(columns), elements(elements), size(rows) {
    std::cout << "Second constructor did link\n";
}

lab51::Matrix::~Matrix() {
    delete[] elements;
}

lab51::Matrix lab51::Matrix::sum(const Matrix& other) {
    Matrix result(rows, columns);
    for (int i = 0; i < rows * columns; ++i)
        result.elements[i] = elements[i] + other.elements[i];
    return result;
}

// rewrite
void lab51::Matrix::mult(const Matrix* other) {
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

double lab51::Matrix::trace() const {
    double traceValue = 0;
    for (int i = 0; i < rows; ++i) {
        traceValue += elements[i * columns + i];
    }
    return traceValue;
}


double& lab51::Matrix::at(int i, int j) {
    return elements[i * size + j];
}


void lab51::Matrix::swapRows(int row1, int row2) {
    for (int i = 0; i < size; ++i) {
        double temp = at(row1, i);
        at(row1, i) = at(row2, i);
        at(row2, i) = temp;
    }
}

// Function to calculate determinant using Gaussian elimination (LU decomposition)
double lab51::Matrix::determinant() const {
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


void lab51::Matrix::mult_by_num(double num) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            elements[i * columns + j] *= num;
        }
    }
}


void lab51::Matrix::input() {
    std::cout << "Enter matrix elements:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> elements[i * columns + j];
        }
    }
}


void lab51::Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << elements[i * columns + j] << ' ';
        }
        std::cout << std::endl;
    }
}


int lab51::Matrix::get_columns() {
    return columns;
}

int lab51::Matrix::get_rows() {
    return rows;
}

double lab51::Matrix::get_element(int i, int j) {
    return elements[i * columns + j];
}
