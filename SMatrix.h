//
// Created by mksh2 on 21.11.2021.
//

#ifndef COURSEPROJECT_SMATRIX_H
#define COURSEPROJECT_SMATRIX_H

#include <list>

typedef struct matrix_element{
    int pos_x, pos_y, value;
} matrix_element;


class SMatrix {
private:
    int size_x;
    int size_y;
    std::list<matrix_element> matrix;

public:
    SMatrix();
    SMatrix(int x,int y,const std::list<int>& elements);
    SMatrix(SMatrix & matrix_copy);
    void print();

};


#endif //COURSEPROJECT_SMATRIX_H
