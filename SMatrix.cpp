//
// Created by mksh2 on 21.11.2021.
//

#include "SMatrix.h"
#include <iostream>


SMatrix::SMatrix(): size_x(0),size_y(0){}

SMatrix::SMatrix(int x, int y, const std::list<int>& numbers):size_x(x),size_y(y) {
    matrix_element element;
    int i=0;
    int j=0;
    for(const int n:numbers){
        element.pos_x=i;
        element.pos_y=j;
        element.value=n;
        matrix.push_back(element);

        if(i == size_x-1){
            i=0;
            j++;
        }
        i++;
    }
}

void SMatrix::print() {
   for(std::list<matrix_element>::const_iterator it=matrix.begin(); it!=matrix.end();++it){
       if(it->pos_x == size_x-1) std::cout<<std::endl;
       std::cout<<it->value<<"\t";

   }
}

SMatrix::SMatrix(SMatrix &matrix_copy) {
    size_x=matrix_copy.size_x;
    size_y=matrix_copy.size_y;
    matrix= matrix_copy.matrix;
}

