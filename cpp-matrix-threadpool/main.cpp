//
//  main.cpp
//  cpp-matrix-threadpool
//
//  Created by MEDLAO on 15/02/2026.
//

#include <iostream>
#include "Matrix.hpp"
#include "matmul_baseline.hpp"


int main(int argc, const char * argv[]) {
    
    try {
        Matrix A(3, 4);
        
        // Creating the values
        A.accessMatrix(2, 1) = 1.0;
        A.accessMatrix(1, 3) = 7.0;
        
        // Reading the values
        std::cout << A.accessMatrix(2, 1) << std::endl;
        std::cout << A.accessMatrix(1, 3) << std::endl;
        
        const Matrix B(2, 3);
        std::cout << B.accessMatrix(0, 0) << std::endl;
        
        // B.accessMatrix(0, 0) = 10.0;
        
        // Test multiplication
        Matrix C(3, 3);
        Matrix D(2, 4);
        
        // C first row
        C.accessMatrix(0,0) = 1;
        C.accessMatrix(0,1) = 2;
        
        // C second row
        C.accessMatrix(1,0) = 3;
        C.accessMatrix(1,1) = 4;

        // C third row
        C.accessMatrix(2,0) = 5;
        C.accessMatrix(2,1) = 6;

        // D first row
        D.accessMatrix(0,0) = 7;
        D.accessMatrix(0,1) = 8;
        D.accessMatrix(0,2) = 9;
        D.accessMatrix(0,3) = 10;

        // D second row
        D.accessMatrix(1,0) = 11;
        D.accessMatrix(1,1) = 12;
        D.accessMatrix(1,2) = 13;
        D.accessMatrix(1,3) = 14;

        
        Matrix E = multiply(C, D);
        
        for (int i = 0; i < C.getRows(); i++) {
            std::cout << "[ ";
            for (int j = 0; j < D.getColumns(); j++) {
                std::cout << E.accessMatrix(i, j) << " ";
            }
            std::cout << "]" << std::endl;
        }
        
        std::cout << "cpp-matrix-threadpool project started\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}
