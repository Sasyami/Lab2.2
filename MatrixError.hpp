//
// Created by User on 20.06.2022.
//

#ifndef LAB2PRJ_MATRIXERROR_HPP
#define LAB2PRJ_MATRIXERROR_HPP
#include <iostream>
#define WrongSize 0
#define MatrixWrongInput 1
#define WrongMatrix 2
class MatrixError: std::exception{
private:
    static const char* MatrixErrorMsg (int msg){

        if (msg == WrongSize){

            auto string = "Size of some matrix is wrong\n";
            return string;
        }
        if (msg == MatrixWrongInput){

            auto string = "Input is wrong\n";
            return string;
        }
        if (msg == WrongMatrix){

            auto string = "Matrix is wrong\n";
            return string;
        }
        auto string = "Something wrong, i can feel it(Maybe the error code?)\n";
        return string;

    }

public:

    explicit MatrixError(int msg):exception(){
        std::cout<<MatrixError::MatrixErrorMsg(msg)<<std::endl;
    }
};
#endif //LAB2PRJ_MATRIXERROR_HPP

