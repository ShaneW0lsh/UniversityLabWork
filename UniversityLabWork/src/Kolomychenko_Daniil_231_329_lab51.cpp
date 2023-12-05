#include "Kolomychenko_Daniil_231_329_lab51.h"

void lab51::launch()
{
    Matrix m1(3, 3, new double[]
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    });
    Matrix m2(3, 1, new double[]
    {
        16,
        2,
        2,
    });
    std::cout << m1.trace() << '\n';
    std::cout << "Multiplication:\n";
    m1.mult(m2).print();
}

template<typename T>
void lab51::init_array(T* arr, int size, T value)
{
    for (int i = 0; i < size; ++i)
        arr[i] = value;
}

lab51::Matrix::Matrix(int rows, int columns)
    : rows(rows), columns(columns)
{
    elements = new double[rows * columns];
    init_array<double>(elements, rows * columns, 0.0);
}

lab51::Matrix::Matrix(int rows, int columns, double* elements)
    : rows(rows), columns(columns), elements(elements)
{
}

lab51::Matrix::Matrix(const Matrix& other)
    : rows(other.rows), columns(other.columns)
{
    elements = new double[rows * columns];
    for (int i = 0; i < rows * columns; ++i)
        elements[i] = other.elements[i];
}

lab51::Matrix::~Matrix()
{
    delete[] elements;
}

lab51::Matrix lab51::Matrix::sum(const Matrix& other) const
{
    Matrix result(rows, columns);
    for (int i = 0; i < rows * columns; ++i)
        result.elements[i] = elements[i] + other.elements[i];
    return result;
}

lab51::Matrix lab51::Matrix::mult(const Matrix& other) const
{
    if (columns != other.rows) {
        std::cout << "Number of columns in the first matrix must be equal to the number of rows in the second matrix!\n";
        return Matrix(0, 0);
    }

    Matrix result(rows, other.columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.columns; ++j) {
            double sum = 0;
            for (int k = 0; k < columns; ++k) {
                sum += elements[i * columns + k] * other.elements[k * other.columns + j];
            }
            result.elements[i * other.columns + j] = sum;
        }
    }

    return result;
}

double lab51::Matrix::trace() const
{
    double trace_value = 0;
    for (int i = 0; i < rows; ++i) {
        trace_value += elements[i * columns + i];
    }
    return trace_value;
}

double lab51::Matrix::determinant() const
{
    if (!this->is_square()) {
        std::cout << "This is not a square matrix!\n";
        return NULL;
    }

    if (get_size() == 1) return *elements;

    double result = 0.0;
    for (int i = 0; i < get_size(); ++i) {
        if (i % 2 == 0)
            result += elements[i] * minor(0, i).determinant();
        else
            result -= elements[i] * minor(0, i).determinant();
    }

    return result;
}

lab51::Matrix lab51::Matrix::minor(int row, int col) const
{
    int minor_size = get_size() - 1;
    Matrix result(minor_size, minor_size);

    int minor_row = 0, minor_col = 0;
    for (int i = 0; i < get_size(); ++i) {
        if (i == row) continue;
        for (int j = 0; j < get_size(); ++j) {
            if (j == col) continue;
            result.elements[minor_row * minor_size + minor_col]
                = elements[i * get_size() + j];
            ++minor_col;
        }
        minor_col = 0;
        ++minor_row;
    }

    return result;
}

void lab51::Matrix::mult_by_num(double num)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            elements[i * columns + j] *= num;
        }
    }
}

void lab51::Matrix::input()
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> elements[i * columns + j];
        }
    }
}

void lab51::Matrix::print() const
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << elements[i * columns + j] << ' ';
        }
        std::cout << std::endl;
    }
}

int lab51::Matrix::get_columns() const { return columns; }

int lab51::Matrix::get_rows() const { return rows; }

double lab51::Matrix::get_element(int i, int j) const
{
    return elements[i * columns + j];
}

bool lab51::Matrix::is_square() const { return rows == columns; }

int lab51::Matrix::get_size() const
{
    if (is_square())
        return rows;
    else {
        std::cout << "Not a square!\n";
        return NULL;
    }
}

bool lab51::Matrix::equals(Matrix& other)
{
    if (rows != other.rows or columns != other.columns)
        return false;
    for (int i = 0; i < other.columns * other.rows; ++i)
        if (elements[i] != other.elements[i])
            return false;
    return true;
}