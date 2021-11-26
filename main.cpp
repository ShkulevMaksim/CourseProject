#include <iostream>
#include "SMatrix.h"
#include <list>

int main() {
    std::list<int> num1 ={1,0,0,0,0,
                         0,1,0,0,0,
                         0,0,1,0,0,
                         0,0,0,1,0,
                         0,0,0,0,1};

    std::list<int> num2 ={0,0,0,0,1,
                          0,0,0,1,0,
                          0,0,1,0,0,
                          0,1,0,0,0,
                          1,0,0,0,1};
    SMatrix mat1(5,5,num1);
    SMatrix mat2 (5,5,num2);
    SMatrix mat3;
    mat3=mat2+mat1;
    mat3.print();
    std::cin.get();
    return 0;
}
