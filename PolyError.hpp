//
// Created by User on 23.06.2022.
//

#ifndef LAB2PRJ_POLYERROR_HPP
#define LAB2PRJ_POLYERROR_HPP
#include <iostream>
#define WrongSize 0
#define PolyWrongInput 1
#define WrongPoly 2
#define WrongIndexPol 3
class PolyError: std::exception{
private:
    static const char* PolyErrorMsg (int msg){

        if (msg == WrongSize){

            auto string = "Size of some Poly is wrong\n";
            return string;
        }
        if (msg == PolyWrongInput){

            auto string = "Input is wrong\n";
            return string;
        }
        if (msg == WrongPoly){

            auto string = "Poly is wrong\n";
            return string;
        }
        if (msg == WrongIndexPol){

            auto string = "Poly is wrong\n";
            return string;
        }
        auto string = "Something wrong, i can feel it(Maybe the error code?)\n";
        return string;

    }

public:

    explicit PolyError(int msg):exception(){
        std::cout<<PolyError::PolyErrorMsg(msg)<<std::endl;
    }
};
#endif //LAB2PRJ_POLYERROR_HPP

