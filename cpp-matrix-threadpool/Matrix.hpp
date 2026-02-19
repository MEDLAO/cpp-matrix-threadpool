//
//  Matrix.hpp
//  cpp-matrix-threadpool
//
//  Created by MEDLAO on 17/02/2026.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <vector>

class Matrix {
private:
    int rows;
    int columns;
    std::vector<double> data;
    
public:
    Matrix(int r, int c);
    
    int getRows() const;
    int getColumns() const;
    
    double& accessMatrix(int row, int col);  // for modifying
    double accessMatrix(int row, int col) const; // for reading
    
};

#endif /* Matrix_hpp */
