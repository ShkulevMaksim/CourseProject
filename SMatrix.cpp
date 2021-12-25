//
// Created by Maksim Shkulev on 21.11.2021.
//

#include "SMatrix.h"
#include <iostream>
#include <stdexcept>



SMatrix::SMatrix(): size_x(0),size_y(0){}
SMatrix::SMatrix(int y, int x):size_x(x),size_y(y) {}

SMatrix::SMatrix(int y, int x, const std::list<int>& numbers):size_x(x),size_y(y) {
    try{
        if(numbers.size() != size_x*size_y){throw MyException("Wrong dimensions");} //Не знаю можно ли в конструкторы вставлять проверки
        int i=0;
        int j=0;
        for(auto it=numbers.begin(); it!=numbers.end();++it){
            matrix.emplace_back(j,i,*it);
            i++;
            if(i>=size_x){
                i=0;
                j++;
            }
        }
    }
    catch(...){
        throw;
    }

}


SMatrix::SMatrix(SMatrix &matrix_copy) {
    size_x=matrix_copy.size_x;
    size_y=matrix_copy.size_y;
   matrix= matrix_copy.matrix;
}

SMatrix::~SMatrix() = default; //Не стал расписывать деструктор, так как лист сам чистится




SMatrix &SMatrix::operator=(const SMatrix& m2) {
    size_x = m2.size_x;
    size_y = m2.size_y;
    matrix=m2.matrix;
    return *this ;
}


int SMatrix::operator()(int y, int x) const {
    int val=0;
    for(auto it=matrix.begin();it!=matrix.end();++it){
        if(it->pos_x==x && it->pos_y==y) {val= it->value; break;}
    }
    return val;
}


int &SMatrix::operator()(int y, int x) {

    for(auto it=matrix.begin();it!=matrix.end();++it){
        if(it->pos_x==x && it->pos_y==y) {
          return it->value;
        }
    }
    matrix.emplace_back(y,x,NULL);
    return this->operator()(y,x);     //Получается затратно, но я не смог придумать лучше решения

}



void SMatrix::print() const {
    try{
        if(size_x==0 || size_y==0){std::cout<<"Matrix is empty"<<'\n'; return;}

        for (int i=0;i<size_y; ++i) {
            for (int j = 0; j < size_x; ++j){
                std::cout<<this->operator()(i,j)<<"\t";
            }
            std::cout<<'\n';
        }
        std::cout<<'\n';
    }
    catch(const MyException& ex){
        std::cout<<"Exception is: "<<ex.what()<<'\n';
    }
}

SMatrix SMatrix::operator+(const SMatrix &mat) {
    try{
        if(!this->sameSize(mat)){throw MyException("Dimensions dont match");}
        SMatrix buffer(*this);
        for(int j=0;j<size_y;j++){
            for(int i=0;i<size_x;i++){
                buffer(i,j)+=mat(i,j);
            }
        }
        return buffer ;
    }
    catch(...){
        throw;
    }
}

SMatrix SMatrix::operator-(const SMatrix &mat) {
    try{
        if(!this->sameSize(mat)){throw MyException("Dimensions dont match");}
        SMatrix buffer(*this);
        for(int j=0;j<size_y;j++){
            for(int i=0;i<size_x;i++){
                buffer(i,j)-=mat(i,j);
            }
        }
        return buffer ;
    }
    catch(...){
        throw;
    }
}

SMatrix SMatrix::operator*(const SMatrix &mat) {
    try{if(this->size_x!=mat.size_y){throw MyException("Wrong dimensions for finding product");} //Умножение методом итераций. Затратно, но работает
        SMatrix buffer(this->size_y,mat.size_x);
        int sum =0;
        for(int i=0;i<size_y;i++){
            for(int j=0;j<mat.size_x;j++){
                sum =0;
                for(int k=0;k<size_x;k++){
                    sum+= this->operator()(i,k)*mat(k,j);
                }
                buffer(i,j)=sum;
            }
        }
        return buffer;}
    catch(...){
        throw;
    }
}

bool SMatrix::sameSize(const SMatrix &mat) const {
    return (mat.size_x==size_x && mat.size_y== size_y);
}

SMatrix & SMatrix::operator++() {
    for(auto it=matrix.begin();it!=matrix.end();++it){
        it->value++;
    }
    return *this;
}

SMatrix & SMatrix::operator--() {
    for(auto it=matrix.begin();it!=matrix.end();++it){
        it->value--;
    }
    return *this;
}

const SMatrix  SMatrix::operator++(int) {
    SMatrix temp;
    for(auto it=matrix.begin();it!=matrix.end();++it){
        it->value++;
    }
    return temp;
}

const SMatrix  SMatrix::operator--(int) {
    SMatrix temp;
    for(auto it=matrix.begin();it!=matrix.end();++it){
        it->value--;
    }
    return temp;
}



SMatrix SMatrix::operator*(int num) {
    for(auto it=matrix.begin();it!=matrix.end();++it){
        it->value*=num;
    }
    return *this;
}

SMatrix operator*(int num, SMatrix &mat) {
    for(auto it=mat.matrix.begin();it!=mat.matrix.end();++it){
        it->value*=num;
    }
    return mat;
}

bool SMatrix::operator<(const SMatrix &rhs) const {
    if (size_y < rhs.size_y && size_x < rhs.size_x)
        return true;
    else
        return false;
}

bool SMatrix::operator>(const SMatrix &rhs) const {
    return rhs < *this;
}

bool SMatrix::operator<=(const SMatrix &rhs) const {
    return !(rhs < *this);
}

bool SMatrix::operator>=(const SMatrix &rhs) const {
    return !(*this < rhs);
}


bool SMatrix::operator==(const SMatrix &rhs) const {
    for (auto it=matrix.begin();it!=matrix.end();++it){
        if(it->value!=rhs(it->pos_y,it->pos_x)){
            return false;
        }
    }
    return size_y == rhs.size_y &&
           size_x == rhs.size_x ;
}

bool SMatrix::operator!=(const SMatrix &rhs) const {
    return !(rhs == *this);
}

int SMatrix::getSizeY() const {
    return size_y;
}

int SMatrix::getSizeX() const {
    return size_x;
}

SMatrix & SMatrix::transpose() {
    int t;
    for(int i = 0; i < size_y; ++i)
    {
        for(int j = i; j < size_x; ++j)
        {
            t = this->operator()(i,j);
            this->operator()(i,j) = this->operator()(j,i);
            this->operator()(j,i) = t;
        }
    }
    return *this;
}

SMatrix& SMatrix::operator+=(int num) {
     for(auto it=matrix.begin();it!=matrix.end();++it){
        it->value+=num;
    }
    return *this;
}

SMatrix & SMatrix::operator-=(int num) {
    for(auto it=matrix.begin();it!=matrix.end();++it){
        it->value-=num;
    }
    return *this;
}

SMatrix & SMatrix::operator*=(int num) {
    for(auto it=matrix.begin();it!=matrix.end();++it){
        it->value*=num;
    }
    return *this;
}

SMatrix operator+(int num, SMatrix &mat) {
    for(auto it=mat.matrix.begin();it!=mat.matrix.end();++it){
        it->value+=num;
    }
    return mat;
}

SMatrix SMatrix::operator+(int num) {
    for(auto it=matrix.begin();it!=matrix.end();++it){
        it->value+=num;
    }
    return *this;
}

int **SMatrix::toArray() const {
    int **arr= new int*[size_y];
    for(auto i=0;i<size_y;i++){
        arr[i]= new int[size_x];
        for(int j = 0; j < size_x; j++){ arr[i][j] = this->operator()(i,j); }
    }
    return arr;
}








