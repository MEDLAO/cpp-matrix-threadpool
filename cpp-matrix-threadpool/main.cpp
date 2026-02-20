//
//  main.cpp
//  cpp-matrix-threadpool
//
//  Created by MEDLAO on 15/02/2026.
//

#include <iostream>
#include "Matrix.hpp"

int main(int argc, const char * argv[]) {
    
    Matrix A(3, 4);
    
    // Creating the values
    A.accessMatrix(2, 1) = 1.0;
    A.accessMatrix(1, 4) = 7.0;
    
    // Reading the values
    std::cout << A.accessMatrix(2, 1) << std::endl;
    std::cout << A.accessMatrix(1, 4) << std::endl;
    
    const Matrix B(2, 3);
    std::cout << B.accessMatrix(0, 0) << std::endl;
    
    // B.accessMatrix(0, 0) = 10.0;
    
    std::cout << "cpp-matrix-threadpool project started\n";
    return 0;
}
