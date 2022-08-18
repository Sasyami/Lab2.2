//
// Created by User on 10.08.2022.
//

#ifndef LAB2PRJ_MENU_HPP
#define LAB2PRJ_MENU_HPP
#include "InterfacePol.hpp"
#include "MenuError.hpp"
#include "IntPolInterface.hpp"
#include "FloatPolInterface.hpp"
#include "FloatComplexPolInterface.hpp"
#include "IntComlpexPolInterface.hpp"
#include "IntQuadMatrixPolInterface.hpp"
#include "FloatQuadMatrixPolInterface.hpp"
class Menu{
private:
    InterfacePol* interface;
public:
    Menu(){
        interface = nullptr;
    };
    explicit Menu (InterfacePol* newInterface){
        interface = newInterface;
    }

    ~Menu(){

        delete interface;

    }
    void PrintPol(){
        if(interface == nullptr){
            throw MenuError(NoInterface);
        }

        interface->PrintPol();
    }
    void AddPol(){
        if(interface == nullptr){
            throw MenuError(NoInterface);
        }
        interface->AddPol();
    }
    void SubstractPol(){
        if(interface == nullptr){
            throw MenuError(NoInterface);
        }
        interface->SubstractPol();
    }
    void MultiplyByPol(){
        if(interface == nullptr){
            throw MenuError(NoInterface);
        }
        interface->MultiplyByPol();
    }
    void ConcatenatedFromPol(){
        if(interface == nullptr){
            throw MenuError(NoInterface);
        }
        interface->ConcatenatedFromPol();
    }
    void MultiplyByNumber(){
        if(interface == nullptr){
            throw MenuError(NoInterface);
        }
        interface->MultiplyByNumber();
    }
    void ShowValue(){
        if(interface == nullptr){
            throw MenuError(NoInterface);
        }
        interface->ShowValue();
    }


};
#endif //LAB2PRJ_MENU_HPP
