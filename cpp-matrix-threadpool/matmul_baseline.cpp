//
//  matmul_baseline.cpp
//  cpp-matrix-threadpool
//
//  Created by MEDLAO on 21/02/2026.
//

#include "matmul_baseline.hpp"

Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.getColumns();
    Matrix C(A.getRows(), B.getColumns());
    for (int i = 0; i < A.getRows(); i++) {
        for (int j = 0; j< B.getColumns(); j++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += A.accessMatrix(i, k) * B.accessMatrix(k, j);
            }
            C.accessMatrix(i, j) = sum;
        }
    }
    return C;
}

/*For each row i of A
 For each column j of B
  Initialize sum = 0
  For each k in shared dimension
   sum += A(i,k) * B(k,j)
  Store sum in C(i,j)*/
