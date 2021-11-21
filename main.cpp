#include <iostream>
#include "SMatrix.h"
#include <list>

int main() {
    std::list<int> num ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    SMatrix mat(5,5,num);
    SMatrix mat2(mat);
    mat2.print();
    std::cin.get();
    return 0;
}
