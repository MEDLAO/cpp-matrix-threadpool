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
    
    Matrix C(A.getRows(), B.getColumns()); // result Matrix
    
    int n = A.getColumns(); // shared Dimension
    
    ThreadPool pool(4); // create worker threads
    
    for (int i = 0; i < A.getRows(); i++) {
        // create a task for row i (capture variables and copy i)
        pool.enqueue([&, i]() {
        });
        
        for (int j = 0; j < B.getColumns(); j++)
        {
            double sum = 0.0;
            
            for (int k = 0; k < n; k++)
            {
                sum += A.accessMatrix(i, k) * B.accessMatrix(k, j);
            }
            
            C.accessMatrix(i, j) = sum;
        }
        
    }
    
    return C; // return the computed matrix
}
