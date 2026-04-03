//
//  main.cpp
//  cpp-matrix-threadpool
//
//  Created by MEDLAO on 15/02/2026.
//

#include <iostream>
#include <chrono>
#include "Matrix.hpp"
#include "matmul_baseline.hpp"
#include "matmul_threadpool.hpp"


void benchmark(int N) {
    // create matrices
    Matrix A(N, N);
    Matrix B(N, N);
    
    // fill
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A.accessMatrix(i, j) = 1.0;
            B.accessMatrix(i, j) = 1.0;
        }
    }
    
    // multiply and measure
    auto start = std::chrono::steady_clock::now();
    
    Matrix C = multiply(A, B);
    
    auto end = std::chrono::steady_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    // print
    std::cout << "Elpased time : N =  " << N << " | " << "time = " << duration.count() << " ms" << std::endl;
    
    /*for (int i = 0; i < N; i++) {
        std::cout << "[ ";
        for (int j = 0; j < N; j++) {
            std::cout << C.accessMatrix(i, j) << " ";
        }
        std::cout << "]" << std::endl;
    }*/
    
}

int main(int argc, const char * arcgv[]) {
    
    try {
//        Matrix A(3, 4);
        Matrix A(3, 3);
        Matrix B(3, 3);
        
        // fill with simple values
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                A.accessMatrix(i, j) = 1.0;
                B.accessMatrix(i, j) = 1.0;
            }
        }
        
        benchmark(300);
        benchmark(500);
        benchmark(800);
        benchmark(1000);
        
        // const Matrix B(2, 3);
        // std::cout << B.accessMatrix(0, 0) << std::endl;
        
        Matrix C1 = multiply(A, B);
        Matrix C2 = multiply_threadpool(A, B);

        std::cout << C1.accessMatrix(0, 0) << " "
                  << C2.accessMatrix(0, 0) << std::endl;
    
        
        std::cout << "cpp-matrix-threadpool project started\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}
