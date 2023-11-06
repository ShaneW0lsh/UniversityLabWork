#include <iostream>

class TridiagonalMatrix {
private:
    int size;
    int* data;
    int* upper_diagonal;
    int* lower_diagonal;

    void init_array(int* arr, int size, int default_value = 0) {
        for (int i = 0; i < size; ++i)
            arr[i] = default_value;
    }

public:
    TridiagonalMatrix(int size) : size(size) {
        data = new int[size];
        upper_diagonal = new int[size - 1];
        lower_diagonal = new int[size - 1];
        init_array(data, size);
        init_array(upper_diagonal, size - 1);
        init_array(lower_diagonal, size - 1);
    }

    ~TridiagonalMatrix() {
        delete[] data;
        delete[] upper_diagonal;
        delete[] lower_diagonal;
    }

    void input() { std::cin >> *this; }

    void print() const { std::cout << *this; }

    int tr() const {
        int trace = 0;
        for (int i = 0; i < size; ++i)
            trace += data[i];

        return trace;
    }

    friend std::ostream& operator<<(std::ostream& os, const TridiagonalMatrix& matrix) {
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

    friend std::istream& operator>>(std::istream& is, TridiagonalMatrix& matrix) {
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

    TridiagonalMatrix operator+(TridiagonalMatrix& other) {
        TridiagonalMatrix result(size);

        for (int i = 0; i < size; ++i)
            result.data[i] = this->data[i] + other.data[i];

        for (int i = 0; i < size-1; ++i)
            result.upper_diagonal[i] = this->upper_diagonal[i] + other.upper_diagonal[i];

        for (int i = 0; i < size-1; ++i)
            result.lower_diagonal[i] = this->lower_diagonal[i] + other.lower_diagonal[i];

        return result;
    }

    TridiagonalMatrix operator-(TridiagonalMatrix& other) {
        TridiagonalMatrix result(size);

        for (int i = 0; i < size; ++i)
            result.data[i] = this->data[i] - other.data[i];

        for (int i = 0; i < size - 1; ++i)
            result.upper_diagonal[i] = this->upper_diagonal[i] - other.upper_diagonal[i];

        for (int i = 0; i < size - 1; ++i)
            result.lower_diagonal[i] = this->lower_diagonal[i] - other.lower_diagonal[i];

        return result;
    }

    TridiagonalMatrix operator-() {
        TridiagonalMatrix result(size);

        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] * -1;

        for (int i = 0; i < size - 1; ++i)
            result.upper_diagonal[i] = upper_diagonal[i] * -1;

        for (int i = 0; i < size - 1; ++i)
            result.lower_diagonal[i] = lower_diagonal[i] * -1;

        return result;
    }
};
/*
            TODO:
            доделать умножение матриц, код снизу.
*/
void lab53() {
    TridiagonalMatrix m1(4), m2(4);
    std::cout << "Enter first matrix:\n";
    std::cin >> m1;
    std::cout << "Enter second matrix:\n";
    std::cin >> m2;
    std::cout << '\n';
    std::cout << "First matrix:\n" << m1 << std::endl 
        << "Second matrix:\n" << m2 << std::endl;
    std::cout << "Sum of those two matrices:\n";
    std::cout << m1 + m2 << std::endl;
    std::cout << m1 - m2 << std::endl;

    std::cout << -(m1 + m2) << std::endl;
}
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