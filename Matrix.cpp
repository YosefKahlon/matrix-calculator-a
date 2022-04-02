//
// Created by 97252 on 4/1/2022.
//


#include "Matrix.hpp"
#include "vector"
#include "stdexcept"

using namespace std;
using namespace zich;


Matrix::Matrix(const std::vector<double> &matrix, int n, int m) {
    this->matrix = matrix;
    this->row = n;
    this->col = m;


}


Matrix::~Matrix() {
    return;
}


//Six operators (+ ,+= , +(unary) , - , -(unary) , - )

Matrix Matrix::operator+(const Matrix &other) {
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }

    int length = this->col * this->row;
    for (int i = 0; i < length; ++i) {
        this->matrix[(unsigned long) i] = this->matrix[(unsigned long) i] + other.matrix[(unsigned long) i];
    }
    return Matrix(this->matrix, this->row, this->col);
}


Matrix Matrix::operator+=(const Matrix &other) {
    return other;
}

Matrix Matrix::operator++() {
    vector<double> newMatrix;
    return Matrix(newMatrix, this->row, this->col);;
}

Matrix Matrix::operator-(const Matrix &other) {

    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }
    return other;
}

Matrix Matrix::operator--() {
    vector<double> newMatrix;
    return Matrix(newMatrix, this->row, this->col);;
}


Matrix Matrix::operator-=(const Matrix &other) {
    if (other.row != other.col) {
        throw invalid_argument("row not equals to col");
    }
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }
    return other;
}


//------------------Six ratio operators(<,>,==,!= ,>= , <= )---------------------------
bool Matrix::operator<(const Matrix &other) {
    if (other.row != other.col) {
        throw invalid_argument("row not equals to col");
    }
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }
    return true;
}

bool Matrix::operator>(const Matrix &other) {
    if (other.row != other.col) {
        throw invalid_argument("row not equals to col");
    }
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }
    return true;
}

bool Matrix::operator==(const Matrix &other) {
    if (other.row != other.col) {
        throw invalid_argument("row not equals to col");
    }
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            if (this->matrix[(unsigned long)(this->col*i + j)] != other.matrix[(unsigned long)(other.col *i + j)] ) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &other) {
    if (other.row != other.col) {
        throw invalid_argument("row not equals to col");
    }
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }
    return true;
}

bool Matrix::operator>=(const Matrix &other) {
    if (other.row != other.col) {
        throw invalid_argument("row not equals to col");
    }
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }
    return true;
}

bool Matrix::operator<=(const Matrix &other) {
    if (other.row != other.col) {
        throw invalid_argument("row not equals to col");
    }
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }
    return true;
}



Matrix Matrix::operator*(const Matrix &other) {
    if (this->row != other.row || this->col != other.col) {
        throw invalid_argument("row or col no equal to real");
    }

    return Matrix(this->matrix, this->row, this->col);

}


Matrix zich::operator*(double num, Matrix &other) {
    return num * other;
}


Matrix zich::operator-(Matrix &matrix1) {
    if (matrix1.row  != matrix1.col) {
        throw invalid_argument("row or col no equal to real");
    }

    return -1 * matrix1;
}



// -------------------- output --------------------
ostream &zich::operator<<(ostream &os, const Matrix &matrix1) {
    for (int i = 0; i < matrix1.row; ++i) {
        os << "[ ";
        for (int j = 0; j < matrix1.col; ++j) {
            unsigned int index = (unsigned int) (matrix1.col * i + j);
            os << matrix1.matrix.at(index) << " ";
        }
        os << "]\n";
    }


    return os;
}

iostream &zich::operator>>(iostream &os, const Matrix &matrix1) {
    return os;
}

Matrix zich::operator*=(Matrix &other ,double num) {
    return Matrix(other.matrix, 0, 0);
}




