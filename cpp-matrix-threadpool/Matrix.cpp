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
