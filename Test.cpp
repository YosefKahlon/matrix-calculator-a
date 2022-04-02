//
// Created by 97252 on 4/2/2022.
//
#include "Matrix.hpp"
#include "vector"
#include "doctest.h"

using namespace std;
using namespace zich;

TEST_CASE ("ez case ") {
    vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2, 1, 2, 3};
    Matrix matrix(identity, 3, 3);
    Matrix matrix2(identity2, 4, 3);


    CHECK_THROWS(matrix + matrix2);
    CHECK_THROWS(matrix - matrix2);

}

TEST_CASE ("COMPERE OPERATOR ") {
    vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix matrix(identity, 3, 3);
    Matrix matrix2(identity2, 3, 3);

            CHECK_FALSE( matrix < matrix);
            CHECK_FALSE(matrix > matrix);
            CHECK_FALSE((matrix + matrix) < matrix);
            CHECK_FALSE((matrix - matrix) > matrix);



    //CHECK_UNARY

}

