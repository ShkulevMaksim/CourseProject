#include <iostream>
#include "SMatrix.h"
#include <list>
#include <fstream>
int main(int argc, char* argv[]) {
    try {
        if(argc != 3) throw MyException ("Wrong arguments");
        std::ifstream mat_in1;
        mat_in1.open(argv[1]);
        if(!mat_in1.is_open()) throw MyException("Can't open input file");
        if(mat_in1.peek() == std::ifstream::traits_type::eof()) throw MyException("Can't read file");
        int m1_size_y;
        mat_in1 >> m1_size_y;
        int m1_size_x;
        mat_in1 >> m1_size_x;
        int buf;
        std::list<int> numbers;
        while (mat_in1 >> buf) {
            numbers.push_back(buf);
        }
        SMatrix mat1(m1_size_y, m1_size_x, numbers);
        numbers.clear();


        std::ifstream mat_in2;
        mat_in2.open(argv[2]);
        if(!mat_in2.is_open()) throw MyException("Can't open input file");
        if(mat_in2.peek() == std::ifstream::traits_type::eof()) throw MyException("Can't read file");
        int m2_size_y;
        mat_in2 >> m2_size_y;
        int m2_size_x;
        mat_in2 >> m2_size_x;
        int buf2;
        while (mat_in2 >> buf2) {
            numbers.push_back(buf2);
        }
        SMatrix mat2(m2_size_y, m2_size_x, numbers);
        numbers.clear();
        mat_in1.close();
        mat_in2.close();

        std::cout << "Original matrices: " << '\n';
        mat1.print();
        std::cout << '\n';
        mat2.print();
        SMatrix mat3;
        std::cout << "Choose an option: " << '\n';
        std::cout << "1. Find A+B " << '\n'
                  << "2. Find A-B" << '\n'
                  << "3. Find A*B " << '\n'
                  << "4. Find A* value " << '\n'
                  << "5. Find A+ value " << '\n'
                  << "6. ++A " << '\n'
                  << "7. B++ " << '\n'
                  << "8. Compare A and B" << '\n'
                  << "9. Get Value (y,x) in A" << '\n'
                  << "10.Transpose A " << '\n'
                << "11.A to array " << '\n';


        int ans;
        std::cin >> ans;
        int v = 0;
        switch (ans) {
            case 1:{
                mat3 = mat1 + mat2;
                std::cout << "Sum of 2 matrices: " << '\n';
                mat3.print();
                break;
            }

            case 2:{
                mat3 = mat1 - mat2;
                std::cout << "Substr. of 2 matrices: " << '\n';
                mat3.print();
                break;
            }

            case 3:{
                mat3 = mat1 * mat2;
                std::cout << "Product of 2 matrices: " << '\n';
                mat3.print();
                break;
            }

            case 4:{
                std::cout << "Input value " << '\n';
                std::cin >> v;
                mat3 = mat1 * v;
                mat3.print();
                break;
            }

            case 5:{
                std::cout << "Input value " << '\n';
                std::cin >> v;
                mat3 = mat1 + v;
                mat3.print();
                std::cin.get();
                break;
            }

            case 6:{
                mat3 = ++mat1;
                mat3.print();
                break;
            }

            case 7:{
                mat3 = mat2++;
                mat3.print();
                break;
            }

            case 8:{
                if(mat1.sameSize(mat2)){
                    std::cout<<"Sizes are equal"<<'\n';
                }
                if (mat1==mat2){
                    std::cout<<"A and B are equal"<<'\n';
                }
                if (mat1<mat2){
                    std::cout<<"A is less than B"<<'\n';
                }
                if (mat1>mat2){
                    std::cout<<"A is bigger than B"<<'\n';
                }
            }


            case 9:{
                int i=0, j=0;
                std::cout << "Input y pos " << '\n';
                std::cin >> i;
                std::cout << "Input x pos " << '\n';
                std::cin >> j;
                std::cout<<mat1(i,j)<< '\n';
                break;
            }

            case 10:{
                mat3 = mat1.transpose();
                mat3.print();
                break;
            }
            case 11:{
                int** array = mat1.toArray();
                break;
            }

            default:{
                std::cout << "Not an option " << '\n';
            }

        }

    }
    catch (const MyException& ex){
        std::cout<<"Exception is: "<<ex.what()<<std::endl;
    }
    catch (const std::exception& ex){
        std::cout<<"Standard exception is: "<<ex.what()<<std::endl;
    }
    catch (...){
        std::cout<<"Unknown exception"<<std::endl;
    }
    std::cin.get();
    std::cin.get();
    return 0;
}
