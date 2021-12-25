//
// Created by ShkulevMaksim on 21.11.2021.
//

#ifndef COURSEPROJECT_SMATRIX_H
#define COURSEPROJECT_SMATRIX_H

#include <list>
#include <string>
class MyException: public std::exception
{
    std::string    m_msg;
public:
    explicit MyException( const char* msg ) :m_msg( msg ) {}
    [[nodiscard]] const char* what() const override { return m_msg.c_str(); }
};


typedef struct matrix_element{           //Структура элемента матрицы
    int pos_y,pos_x, value;
} matrix_element;


class SMatrix {
private:
    int size_y;  //Размеры матрицы
    int size_x;

    std::list<matrix_element> matrix;  //список элементов

public:
    SMatrix(); //Конструктор
    SMatrix(int y,int x,const std::list<int>& elements); //Разные виды конструктора с параметрами (либо пустая матрица y на x либо замоленная)
    SMatrix(int y,int x);
    SMatrix(SMatrix & matrix_copy);  //Конструктор копий
    ~SMatrix(); //Деструктор

    SMatrix& operator = (const SMatrix& mat);  //Переопределенные операторы присваивания, сложения/разности двух матриц, умножения матриц, умножения матрицы на число и числа на матрицу
    SMatrix operator + (const SMatrix& mat);
    SMatrix operator - (const SMatrix& mat);
    SMatrix operator * (const SMatrix& mat);
    SMatrix operator * (int num);
    friend SMatrix operator * (int num,SMatrix& mat);  //Нельзя использовать этот оператор как член класса, т.к. он уже не бинарный

    SMatrix operator + (int num); //Добавление числа к матрице
    friend SMatrix operator + (int num,SMatrix& mat);


    SMatrix& operator += (int num); //Операторы накопления (действуют только на ненулевые элементы)
    SMatrix& operator -= (int num);
    SMatrix& operator *= (int num);

    SMatrix& operator ++ (); //Увеличения каждого элемента матрицы
    const SMatrix operator ++ (int);
    SMatrix& operator -- (); //Уменьшение на 1 в префиксной/постфиксной форме
    const SMatrix operator -- (int);


    int operator() (int y, int x) const; //Взятие по координатам для чтения
    int &operator() (int y, int x); //Взятие по координатам для записи + создание нового элемента в матрице

    void print() const; //Вывод на экран

    int** toArray() const;//Приведение к базовому типу


    bool operator<(const SMatrix &rhs) const; //Операторы сравнения размеров матриц.
    bool operator>(const SMatrix &rhs) const;
    bool operator<=(const SMatrix &rhs) const;
    bool operator>=(const SMatrix &rhs) const;
    [[nodiscard]] bool sameSize(const SMatrix& mat) const;

    bool operator==(const SMatrix &rhs) const; //Операторы сравнения
    bool operator!=(const SMatrix &rhs) const;

    SMatrix& transpose(); //Транспонирование

    [[nodiscard]] int getSizeY() const; //Геттеры
    [[nodiscard]] int getSizeX() const;
};


#endif //COURSEPROJECT_SMATRIX_H
