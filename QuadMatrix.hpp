//
// Created by User on 30.05.2022.
//

#ifndef LAB2PRJ_QUADMATRIX_HPP
#define LAB2PRJ_QUADMATRIX_HPP
#include <iostream>
#include "Sequence.hpp"
#include "MatrixError.hpp"
#include "ArraySequence.hpp"
#include <cmath>

template <typename T> class QuadMatrix{
private:
    size_t size_of_side;
    Sequence<T>* matrix;
public:
    QuadMatrix(){
        size_of_side = 0;
        matrix = new ArraySequence<T>();
    }
    QuadMatrix(T* array,size_t sizeof_side){
        size_of_side = sizeof_side;
        matrix = new ArraySequence<T>(array,sizeof_side*sizeof_side);
    }
    QuadMatrix(Sequence<T>* seq,size_t sizeof_side){

        if (seq->GetLength()<sizeof_side*sizeof_side){
            throw MatrixError(WrongMatrix);
        }

        size_of_side = sizeof_side;
        matrix = new ArraySequence(*seq);
    }
    QuadMatrix(const QuadMatrix& Matrix){
        size_of_side = Matrix.GetSizeOfSide();
        matrix = new ArraySequence<T>(*(Matrix.matrix));
    }

    ~QuadMatrix() = default;
public:
    T operator()(size_t i,size_t j) const{
        return matrix->Get(i*size_of_side+j);
    }

    QuadMatrix<T> operator+(const QuadMatrix<T>& Matrix){
        if (size_of_side!= Matrix.size_of_side){
            throw MatrixError(WrongSize);
        }

        QuadMatrix<T> new_matrix;


        for (int i = 0;i<size_of_side;i++){
            for (int j = 0;j<size_of_side;j++){

                (new_matrix.matrix)->Append(this->operator()(i,j)+Matrix.operator()(i,j));


            }


        }
        new_matrix.size_of_side = Matrix.size_of_side;


        return new_matrix;
    }
    QuadMatrix<T> operator-(const QuadMatrix<T>& Matrix){
        if (size_of_side!= Matrix.size_of_side){
            throw MatrixError(WrongSize);
        }

        QuadMatrix<T> new_matrix;


        for (int i = 0;i<size_of_side;i++){
            for (int j = 0;j<size_of_side;j++){

                (new_matrix.matrix)->Append(this->operator()(i,j)-Matrix.operator()(i,j));


            }


        }
        new_matrix.size_of_side = Matrix.size_of_side;
        return new_matrix;
    }
    QuadMatrix<T>& operator= (const QuadMatrix<T>& Matrix){
        int i,j;

        for (i = 0;i<Matrix.size_of_side;i++){
            for (j = 0;j<Matrix.size_of_side;j++) {
                if (i*Matrix.size_of_side+j>=size_of_side*size_of_side){
                    matrix->Append(Matrix.operator()(i, j));
                }else {
                    matrix->Set(Matrix.operator()(i, j), i*Matrix.size_of_side + j);
                }
            }
        }

        size_of_side = Matrix.GetSizeOfSide();

        return *this;

    }
    QuadMatrix<T> operator* (const QuadMatrix<T>& Matrix){
        int i,j;
        if (size_of_side!= Matrix.GetSizeOfSide()){
            throw MatrixError(WrongSize);
        }
        T element;
        QuadMatrix<T> new_matrix(Matrix);
        for (i = 0;i<Matrix.size_of_side;i++){
            for (j = 0;j<Matrix.size_of_side;j++) {
                element = Matrix(0,j)*(this->operator()(i,0));
                for (size_t k = 1;k<Matrix.GetSizeOfSide();k++){
                    element = element+Matrix(k,j)*(this->operator()(i,k));
                }
                new_matrix.Set(element,i,j);
            }
        }
        return new_matrix;

    }
    QuadMatrix<T> operator* (int number){
        int i,j,k;

        T element;
        QuadMatrix<T> new_matrix(*this);
        for (i = 0;i<size_of_side;i++){
            for (j = 0;j<size_of_side;j++) {
                element = this->operator()(i,j) *number;
                new_matrix.Set(element,i,j);
            }
        }
        return new_matrix;

    }
    QuadMatrix<T> operator* (float number){
        int i,j,k;

        T element;
        QuadMatrix<T> new_matrix(*this);
        for (i = 0;i<size_of_side;i++){
            for (j = 0;j<size_of_side;j++) {
                element = this->operator()(i,j) *number;
                new_matrix.Set(element,i,j);
            }
        }
        return new_matrix;

    }

public:
    void Set(T item,size_t row,size_t column){
        matrix->Set(item,row*size_of_side+column);
    }
public:
    size_t GetSizeOfSide() const{
        return size_of_side;
    }

    T norm(){
        T element;
        T max_element = this->operator()(0, 0);
        for (int j =0;j<size_of_side;j++) {
            element = this->operator()(0, j);
            for (int i = 1;i<size_of_side;i++){
                element = element+abs(this->operator()(i,j));
            }
            if (element>max_element){
                max_element = element;
            }
        }
        return max_element;

    }
    void swap_rows(size_t row1,size_t row2){
        if ((row1>=size_of_side)||(row2>=size_of_side)){
            throw MatrixError(MatrixWrongInput);
        }
        T element;
        for (int j = 0;j<size_of_side;j++){
            element = this->operator()(row1,j);
            this->Set( this->operator()(row2,j),row1,j);
            this->Set(element,row2,j);
        }
    }
    void swap_columns(size_t column1,size_t column2){
        if ((column1>=size_of_side)||(column2>=size_of_side)){
            throw MatrixError(MatrixWrongInput);
        }
        T element;
        for (int j = 0;j<size_of_side;j++){
            element = this->operator()(j,column1);
            this->Set( this->operator()(j,column2),j,column1);
            this->Set(element,j,column2);
        }
    }
    void mult_row(int number,size_t row){
        if (row>=size_of_side){
            throw MatrixError(MatrixWrongInput);
        }
        for (size_t j = 0;j<size_of_side;j++){
            this->Set(number*this->operator()(row,j),row,j);
        }
    }
    void mult_row(float number,size_t row){
        if (row>=size_of_side){
            throw MatrixError(MatrixWrongInput);
        }
        for (size_t j = 0;j<size_of_side;j++){
            this->Set(number*this->operator()(row,j),row,j);
        }
    }
    void mult_column(int number,size_t column){
        if (column>=size_of_side){
            throw MatrixError(MatrixWrongInput);
        }
        for (size_t i = 0;i<size_of_side;i++){
            this->Set(number*this->operator()(i,column),i,column);
        }
    }
    void mult_column(float number,size_t column){
        if (column>=size_of_side){
            throw MatrixError(MatrixWrongInput);
        }
        for (size_t i = 0;i<size_of_side;i++){
            this->Set(number*this->operator()(i,column),i,column);
        }
    }
    void add_multiplied_row(size_t to,size_t from,int number){
        if ((to>=size_of_side)||(from>=size_of_side)){
            throw MatrixError(MatrixWrongInput);
        }
        for (int j = 0;j<size_of_side;j++){

            this->Set(this->operator()(from,j)*number+this->operator()(to,j),to,j);


        }
    }
    void add_multiplied_row(size_t to,size_t from,float number){
        if ((to>=size_of_side)||(from>=size_of_side)){
            throw MatrixError(MatrixWrongInput);
        }
        for (int j = 0;j<size_of_side;j++){

            this->Set(this->operator()(from,j)*number+this->operator()(to,j),to,j);


        }
    }
    void add_multiplied_column(size_t to,size_t from,int number){
        if ((to>=size_of_side)||(from>=size_of_side)){
            throw MatrixError(MatrixWrongInput);
        }
        for (int i = 0;i<size_of_side;i++){

            this->Set(this->operator()(i,from)*number+this->operator()(i,to),i,to);


        }
    }
    void add_multiplied_column(size_t to,size_t from,float number){
        if ((to>=size_of_side)||(from>=size_of_side)){
            throw MatrixError(MatrixWrongInput);
        }
        for (int i = 0;i<size_of_side;i++){

            this->Set(this->operator()(i,from)*number+this->operator()(i,to),i,to);


        }
    }
    void PrintRow(size_t j){
        if (j>=size_of_side){
            throw MatrixError(MatrixWrongInput);
        }
        for (int i = 0;i<=size_of_side;i++){
            std::cout<<this->operator()(j,i);
        }
    }
    template <class U>
    friend std::ostream& operator<<(std::ostream &stream,const QuadMatrix<U>& Matrix);


};
template <class U>
std::ostream& operator<<(std::ostream &stream,const QuadMatrix<U>& Matrix){
    stream <<"( ";
    for (int j = 0; j < Matrix.GetSizeOfSide(); j++){
        stream << Matrix(0, j) << " ";
    }
    for (int i = 1; i < Matrix.GetSizeOfSide(); i++){
        stream << "| " ;
        for (int j = 0; j < Matrix.GetSizeOfSide(); j++){
            stream << Matrix(i, j) << " ";
        }

    }
    stream <<")";
    return stream;

}
template <typename T>
void print_matrix(QuadMatrix<T> a){
    for (int i = 0;i<a.GetSizeOfSide();i++){
        for (int j = 0;j<a.GetSizeOfSide();j++){
            std::cout << a(i,j)<<" ";
        }
        std::cout << " " << std::endl;
    }
}
#endif //LAB2PRJ_QUADMATRIX_HPP

