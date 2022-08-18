//
// Created by User on 11.08.2022.
//

#ifndef LAB2PRJ_MENUERROR_HPP
#define LAB2PRJ_MENUERROR_HPP
#include <iostream>
#define NoInterface 0
#define WrongMenuInput 1
class MenuError: std::exception{
private:
    static const char* MenuErrorMsg (int msg){

        if (msg == NoInterface){

            auto string = "No interface no work\n";
            return string;
        }
        if (msg == WrongMenuInput){

            auto string = "You typed something wrong\n";
            return string;
        }

        auto string = "Something wrong, i can feel it(Maybe the error code?)\n";
        return string;

    }

public:

    explicit MenuError(int msg):exception(){
        std::cout<<MenuError::MenuErrorMsg(msg)<<std::endl;
    }
};
#endif //LAB2PRJ_MENUERROR_HPP
