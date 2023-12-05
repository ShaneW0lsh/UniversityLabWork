#include "Kolomychenko_Daniil_231_329_lab53.h"

void lab53::init_array(int* arr, int size)
{
    for (int i = 0; i < size; ++i) arr[i] = 0;
}

lab53::TridiagonalMatrix::TridiagonalMatrix(int size)
    : size(size)
{
    data = new int[size];
    upper_diagonal = new int[size - 1];
    lower_diagonal = new int[size - 1];
    init_array(data, size);
    init_array(upper_diagonal, size - 1);
    init_array(lower_diagonal, size - 1);
}

lab53::TridiagonalMatrix::~TridiagonalMatrix()
{
    delete[] data;
    delete[] upper_diagonal;
    delete[] lower_diagonal;
}

void lab53::TridiagonalMatrix::input()
{
    std::cin >> *this;
}

void lab53::TridiagonalMatrix::print() const
{
    std::cout << *this;
}

int lab53::TridiagonalMatrix::tr() const
{
    int trace = 0;
    for (int i = 0; i < size; ++i)
        trace += data[i];

    return trace;
}

std::ostream& lab53::operator<<(std::ostream& os, const TridiagonalMatrix& matrix)
{
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            if (i == j)
                os << matrix.data[i] << ' ';
            else if (i == j + 1)
                os << matrix.lower_diagonal[j] << ' ';
            else if (i == j - 1)
                os << matrix.upper_diagonal[i] << ' ';
            else
                os << "0 ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& lab53::operator>>(std::istream& is, TridiagonalMatrix& matrix)
{
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            if (i == j)
                is >> matrix.data[i];
            else if (i - j == 1)
                is >> matrix.lower_diagonal[j];
            else if (j - i == 1)
                is >> matrix.upper_diagonal[i];
        }
    }
    return is;
}

lab53::TridiagonalMatrix lab53::TridiagonalMatrix::operator+(const TridiagonalMatrix& other) const
{
    TridiagonalMatrix result(size);

    for (int i = 0; i < size; ++i)
        result.data[i] = this->data[i] + other.data[i];

    for (int i = 0; i < size - 1; ++i)
        result.upper_diagonal[i] = this->upper_diagonal[i] + other.upper_diagonal[i];

    for (int i = 0; i < size - 1; ++i)
        result.lower_diagonal[i] = this->lower_diagonal[i] + other.lower_diagonal[i];

    return result;
}

lab53::TridiagonalMatrix lab53::TridiagonalMatrix::operator-(const TridiagonalMatrix& other) const
{
    TridiagonalMatrix result(size);

    for (int i = 0; i < size; ++i)
        result.data[i] = this->data[i] - other.data[i];

    for (int i = 0; i < size - 1; ++i)
        result.upper_diagonal[i] = this->upper_diagonal[i] - other.upper_diagonal[i];

    for (int i = 0; i < size - 1; ++i)
        result.lower_diagonal[i] = this->lower_diagonal[i] - other.lower_diagonal[i];

    return result;
}

lab53::TridiagonalMatrix lab53::TridiagonalMatrix::operator-()
{
    TridiagonalMatrix result(size);

    for (int i = 0; i < size; ++i)
        result.data[i] = data[i] * -1;

    for (int i = 0; i < size - 1; ++i)
        result.upper_diagonal[i] = upper_diagonal[i] * -1;

    for (int i = 0; i < size - 1; ++i)
        result.lower_diagonal[i] = lower_diagonal[i] * -1;

    return result;
}

void lab53::TridiagonalMatrix::operator+=(const TridiagonalMatrix& other)
{
    if (size != other.size) {
        std::cout << "Not valid operation, these matrices are of different size!\n";
        return;
    }

    for (int i = 0; i < size; ++i)
        data[i] += other.data[i];
    for (int i = 0; i < size - 1; ++i)
        upper_diagonal[i] += other.upper_diagonal[i];
    for (int i = 0; i < size - 1; ++i)
        lower_diagonal[i] += other.lower_diagonal[i];
}

void lab53::TridiagonalMatrix::operator-=(const TridiagonalMatrix& other)
{
    if (size != other.size) {
        std::cout << "Not valid operation, these matrices are of different size!\n";
        return;
    }

    for (int i = 0; i < size; ++i)
        data[i] -= other.data[i];
    for (int i = 0; i < size - 1; ++i)
        upper_diagonal[i] -= other.upper_diagonal[i];
    for (int i = 0; i < size - 1; ++i)
        lower_diagonal[i] -= other.lower_diagonal[i];
}

lab52::Matrix lab53::TridiagonalMatrix::operator*(const TridiagonalMatrix& other) const
{
    if (size != other.size) {
        std::cout << "Not valid operation, these matrices need to be the same size!\n";
        return lab52::Matrix(0, 0);
    }

    lab52::Matrix result(size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int sum = 0;
            for (int k = 0; k < size; ++k) {
                sum += get(i, k) * other.get(k, j);
            }
            result.elements[i * size + j] = sum;
        }
    }
    return result;
}

lab53::TridiagonalMatrix lab53::TridiagonalMatrix::operator*(const int num)
{
    TridiagonalMatrix result(size);

    for (int i = 0; i < size; ++i)
        result.data[i] = data[i] * num;
    for (int i = 0; i < size - 1; ++i)
        result.lower_diagonal[i] = lower_diagonal[i] * num;
    for (int i = 0; i < size - 1; ++i)
        result.upper_diagonal[i] = upper_diagonal[i] * num;

    return result;
}

int lab53::TridiagonalMatrix::get(int row, int col) const
{
    if (row == col)
        return data[row];
    else if (col == row + 1)
        return upper_diagonal[row];
    else if (row == col + 1)
        return lower_diagonal[col];
    else
        return 0;
}

void lab53::TridiagonalMatrix::set(int row, int col, int value)
{
    if (row == col)
        data[row] = value;
    else if (col == row + 1)
        upper_diagonal[row] = value;
    else if (row == col + 1)
        lower_diagonal[col] = value;
}

int lab53::TridiagonalMatrix::get_size() const
{
    return size;
}

void lab53::launch()
{
    TridiagonalMatrix m1(4), m2(4);
    std::cout << "Enter first matrix:\n";
    std::cin >> m1;
    std::cout << "enter second matrix:\n";
    std::cin >> m2;

    std::cout << '\n';
    std::cout << "first matrix:\n" << m1 << std::endl
        << "second matrix:\n" << m2 << std::endl;

    std::cout << "sum of those two matrices:\n";
    std::cout << m1 + m2 << std::endl;

    std::cout << "m1 multiplied by 3:\n";
    std::cout << m1 * 3 << std::endl;
    std::cout << std::endl;
    m1 += m2;
    std::cout << m1 << std::endl;
}
/*
1 4 3 4 1 2 3 4 1 3
5 3 7 8 2 9 1 8 6 6
*/
