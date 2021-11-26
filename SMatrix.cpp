//
// Created by mksh2 on 21.11.2021.
//

#include "SMatrix.h"
#include <iostream>
#include <stdexcept>


SMatrix::SMatrix(): size_x(0),size_y(0){}

SMatrix::SMatrix(int x, int y, const std::list<int>& numbers):size_x(x),size_y(y) {
        matrix_element element;
        int i=0;
        int j=0;
            for(auto it=numbers.begin(); it!=numbers.end();++it){
                if(*it!=0){
                    element.pos_x=i;
                    element.pos_y=j;
                    element.value=*it;
                    matrix.push_back(element);

                }
                i++;
                if(i>=(size_x)){
                    i=0;
                    j++;
                }

            }

}



SMatrix::SMatrix(SMatrix &matrix_copy) {
    size_x=matrix_copy.size_x;
    size_y=matrix_copy.size_y;
    matrix= matrix_copy.matrix;
}

SMatrix::~SMatrix() = default;


void SMatrix::print() {
    auto it=matrix.begin();
    for (int j = 0; j < size_y; ++j) {
        for (int i=0;i<size_x; ++i){
           if( (it->pos_x==i) && (it->pos_y==j)){
               std::cout<<it->value<<"\t";
               ++it;
           }
           else {  std::cout<<"0\t";}
        }
        std::cout<<std::endl;
    }
}

SMatrix &SMatrix::operator=(const SMatrix& m2) {
    size_x = m2.size_x;
    size_y = m2.size_y;
    matrix=m2.matrix;
    return *this ;
}

SMatrix &SMatrix::operator+(SMatrix &mat) {
    std::list<matrix_element>::iterator it_1;
    if(size_x == mat.size_x && size_y == mat.size_y){
        auto it1=matrix.begin();
        auto it2=mat.matrix.begin();
        for (int j = 0; j < size_y; ++j) {
            for (int i=0;i<size_x; ++i){
                if(i==it1->pos_x && j == it1->pos_y && it2->pos_x!=i && it2->pos_y!=j){
                    it1++;
                    continue;
                }
                if(i==it1->pos_x && j == it1->pos_y && it2->pos_x==i && it2->pos_y==j){
                    it1->value+=it2->value;
                    it1++;
                    it2++;
                    continue;
                }
                if(i!=it1->pos_x && j != it1->pos_y && it2->pos_x==i && it2->pos_y==j){
                    matrix.insert(it1,*it2);
                    it2++;
                    continue;
                }




            }
        }

    }
    return *this;
}







