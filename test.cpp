#include <stdio.h>
#include <iostream>
#include <string>

template<typename T>
class SquareMatrixBase {
public:
    SquareMatrixBase();
    virtual ~SquareMatrixBase();
protected:
    void invert(std::size_t matrixSize);
};

template<typename T, std::size_t n>
class SquareMatrix: private SquareMatrixBase<T> {
public:
    SquareMatrix(T init_num);
    ~SquareMatrix();
    void invert();
private:
    using SquareMatrixBase<T>::invert;
    T num;
};

template<typename T>
SquareMatrixBase<T>::SquareMatrixBase()
{
}

template<typename T>
SquareMatrixBase<T>::~SquareMatrixBase()
{
}

template<typename T>
void SquareMatrixBase<T>::invert(std::size_t matrixSize)
{
    printf("n = %ld\n", matrixSize);
}

template<typename T, std::size_t n>
SquareMatrix<T, n>::SquareMatrix(T init_num): num(init_num)
{
}

template<typename T, std::size_t n>
SquareMatrix<T, n>::~SquareMatrix()
{
}

template<typename T, std::size_t n>
void SquareMatrix<T, n>::invert()
{
    this->invert(n);
}

int main()
{
    SquareMatrix<double, 5> sm1(5.0);
    sm1.invert();
    SquareMatrix<double, 10> sm2(5.0);
    sm2.invert();
}
