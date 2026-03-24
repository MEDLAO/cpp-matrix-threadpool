//
//  matmul_threadpool.cpp
//  cpp-matrix-threadpool
//
//  Created by MEDLAO on 23/03/2026.
//

#include "Matrix.hpp"
#include "matmul_threadpool.hpp"
#include "ThreadPool.hpp"


Matrix multiply_threadpool(const Matrix& A, const Matrix& B)
{
    if (A.getColumns() != B.getRows()) {
        throw std::invalid_argument("A.getColumns() must be equal to B.getRows()");
    }
}
