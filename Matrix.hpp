//
// Created by 97252 on 4/1/2022.
//

#ifndef MATRIX_CALCULATOR_A_MATRIX_HPP
#define MATRIX_CALCULATOR_A_MATRIX_HPP

#include "vector"
#include "iostream"

using namespace std;
namespace zich {

    class Matrix {

    private:
        std::vector<double> matrix;
        int row;
        int col;
    public:
        //constructor
        Matrix(const std::vector<double> &matrix, int n, int m);

        //destructor
        ~Matrix();

        Matrix operator+(const Matrix &other);

        Matrix operator+=(const Matrix &other);

        Matrix operator++();

        Matrix operator-(const Matrix &other);

        Matrix operator--();

        Matrix operator-=(const Matrix &other);


        bool operator>(const Matrix &other);

        bool operator<(const Matrix &other);

        bool operator==(const Matrix &other);

        bool operator!=(const Matrix &other);

        bool operator>=(const Matrix &other);

        bool operator<=(const Matrix &other);

        // this * other
        Matrix operator*(const Matrix &other);

        friend Matrix operator-(Matrix &matrix1);

        friend Matrix operator*(double num, Matrix &other);

        friend Matrix operator*=(Matrix &other, double num);

        //output
        friend ostream &operator<<(ostream &os, const Matrix &matrix1);

        //input
        friend iostream &operator>>(iostream &os, const Matrix &matrix1);


    };


}
#endif //MATRIX_CALCULATOR_A_MATRIX_HPP
