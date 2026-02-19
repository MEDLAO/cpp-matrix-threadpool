//
//  Matrix.cpp
//  cpp-matrix-threadpool
//
//  Created by MEDLAO on 17/02/2026.
//

#include "Matrix.hpp"


Matrix::Matrix(int r, int c) {
    rows = r;
    columns = c;
    data.resize(r * c);
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

double& Matrix::accessMatrix(int row, int col) {
    int index = row * columns + col;
    return data[index];
}

double Matrix::accessMatrix(int row, int col) const {
    int index = row * columns + col;
    return data[index];
}
