//
// Created by User on 16.08.2022.
//

#ifndef LAB2PRJ_TEST_HPP
#define LAB2PRJ_TEST_HPP

#include "Polynomial.hpp"
#include "PolyError.hpp"
template <class T>
void print(const Polynomial<T>& pol) {
    if (pol.GetSize()<1){
        throw PolyError(WrongSize);
    }
    std::cout<<pol.Get(0);
    for (int i = 1;i<pol.GetSize();i++){
        std::cout<<" + "<<pol.Get(i)<<"x^"<<i;
    }
}
template <class T>
class Test{
private:
    Polynomial<T> pol1;
    Polynomial<T> pol2;

public:
    Test() = delete;
    Test(Polynomial<T>& polynomial1, Polynomial<T>& polynomial2){
        pol1 = polynomial1;
        pol2 = polynomial2;

    }
    void PolynomialoperationsTest(T value){
        std::cout<<"Adding"<<std::endl;
        auto pol = pol1+pol2;
        print(pol);
        std::cout<<"\n";
        std::cout<<"Substracting"<<std::endl;
        pol = pol1-pol2;
        print(pol);
        std::cout<<"\n";

        std::cout<<"Multiplying"<<std::endl;
        pol = pol1*pol2;
        print(pol);
        std::cout<<"\n";
        std::cout<<"Concatenating"<<std::endl;
        pol = pol1(pol2);
        print(pol);
        std::cout<<"\n";
        std::cout<<"Multiplying by"<<value<<std::endl;
        pol = pol1*value;
        print(pol);
        std::cout<<"\n";
        std::cout<<"Polynom 1 of "<<value<<std::endl;
        std::cout<<pol1(value)<<std::endl;

        std::cout<<"\n";

    }
    void ZeroOperationsTest(T zero){
        auto pol_zero = pol1-pol1;
        std::cout<<"Checking operations with zero polynomial\n";
        std::cout<<"Zero polynomial\n";
        print(pol_zero);
        std::cout<<"\n";
        std::cout<<"Non zero polynomial\n";
        print(pol1);
        std::cout<<"\n";
        std::cout<<"Adding zero polynomial\n";
        auto pol = pol1+pol_zero;
        print(pol);
        std::cout<<"\n";
        std::cout<<"Substracting zero polynomial\n";
        pol=pol1-pol_zero;
        print(pol);
        std::cout<<"\n";
        std::cout<<"Multiplying zero polynomial\n";
        pol = pol1*pol_zero;
        print(pol);
        std::cout<<"\n";
        std::cout<<"Concatenating zero polynomial\n";
        pol = pol1(pol_zero);
        print(pol);
        std::cout<<"\n";
        std::cout<<"Multiplying by zero\n";
        pol = pol1*zero;
        print(pol);
        std::cout<<"\n";
        std::cout<<"Value of zero\n";
        std::cout<<pol1(zero);

        std::cout<<"\n";
    }
    void Exceptions(){
        auto pol = pol1;

        try{
            Polynomial<T> pol_empty;
            pol = pol1+pol_empty;
        }catch(PolyError& e){
            std::cout<<"Adding Empty polynom failed\n";
        }
        try{
            Polynomial<T> pol_empty;
            pol = pol1-pol_empty;
        }catch(PolyError& e){
            std::cout<<"Substracting Empty polynom failed\n";
        }
        try{
            Polynomial<T> pol_empty;
            pol = pol1*pol_empty;
        }catch(PolyError& e){
            std::cout<<"Multiplying by Empty polynom failed\n";
        }
        try{
            Polynomial<T> pol_empty;
            pol = pol1(pol_empty);
        }catch(PolyError& e){
            std::cout<<"Concatenating from Empty polynom failed\n";
        }
        try{
            Polynomial<T> pol_empty;
            pol = pol_empty*pol1.Get(0);
        }catch(PolyError& e){
            std::cout<<"Multiplying Empty polynom by number failed\n";
        }
        try{
            Polynomial<T> pol_empty;
            std::cout<<pol_empty(pol1.Get(0));
        }catch(PolyError& e){
            std::cout<<"Showing value of Empty polynom failed\n";
        }

    }
    void print_pols(){
        std::cout<<"Polynomial 1 \n";
        print(pol1);
        std::cout<<"\n";
        std::cout<<"Polynomial 2 \n";
        print(pol2);
        std::cout<<"\n";
    }
};
#endif //LAB2PRJ_TEST_HPP
