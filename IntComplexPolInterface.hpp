//
// Created by User on 11.08.2022.
//

#ifndef LAB2PRJ_INTCOMLPEXPOLINTERFACE_HPP
#define LAB2PRJ_INTCOMLPEXPOLINTERFACE_HPP
#include "InterfacePol.hpp"
#include "ComplexNumbers.hpp"
class IntComplexPolInterface:public InterfacePol {
private:
    Polynomial<ComplexNumber<int>> *pol;

public:
    IntComplexPolInterface() {
        std::cout << "Insert how many elements" << std::endl;
        auto *IntComplexSeq = new ArraySequence<ComplexNumber<int>>();
        int size;
        int element_a,element_b;
        std::string element_str;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size < 1) {
            throw IndexOutOfRange(WrongInput);
        }
        std::cout << "Insert elements one by one" << std::endl;


        for (int i = 0;i<size;i++){
            std::cout<<"Insert real part"<<std::endl;
            getline(std::cin, element_str);
            element_a = stoi(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stoi(element_str);
            IntComplexSeq->Append(ComplexNumber<int>(element_a,element_b));

        }
        pol = new Polynomial<ComplexNumber<int>>(IntComplexSeq);
        delete IntComplexSeq;
    }

    ~IntComplexPolInterface() override {
        delete pol;
    }
public:
    void PrintPol() const override{
        print_complex(pol->Get(0));
        for (int i = 1;i<pol->GetSize();i++){
            std::cout<<" + ";
            print_complex(pol->Get(i));
            std::cout<<"x^"<<i;
        }
        std::cout<<"\n";
    }
    void AddPol() override{
        std::cout << "Insert how many elements" << std::endl;
        auto *IntComplexSeq = new ArraySequence<ComplexNumber<int>>();
        int size;
        int element_a,element_b;
        std::string element_str;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size < 1) {
            throw IndexOutOfRange(WrongInput);
        }
        std::cout << "Insert elements one by one" << std::endl;


        for (int i = 0;i<size;i++){
            std::cout<<"Insert real part"<<std::endl;
            getline(std::cin, element_str);
            element_a = stoi(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stoi(element_str);
            IntComplexSeq->Append(ComplexNumber<int>(element_a,element_b));

        }
        Polynomial<ComplexNumber<int>>pol_new(IntComplexSeq);
        pol->operator=(pol->operator+(pol_new));
        delete IntComplexSeq;
    }
    void SubstractPol() override{
        std::cout << "Insert how many elements" << std::endl;
        auto *IntComplexSeq = new ArraySequence<ComplexNumber<int>>();
        int size;
        int element_a,element_b;
        std::string element_str;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size < 1) {
            throw IndexOutOfRange(WrongInput);
        }
        std::cout << "Insert elements one by one" << std::endl;


        for (int i = 0;i<size;i++){
            std::cout<<"Insert real part"<<std::endl;
            getline(std::cin, element_str);
            element_a = stoi(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stoi(element_str);
            IntComplexSeq->Append(ComplexNumber<int>(element_a,element_b));

        }
        Polynomial<ComplexNumber<int>>pol_new(IntComplexSeq);
        pol->operator=(pol->operator-(pol_new));
        delete IntComplexSeq;
    }
    void MultiplyByPol() override{
        std::cout << "Insert how many elements" << std::endl;
        auto *IntComplexSeq = new ArraySequence<ComplexNumber<int>>();
        int size;
        int element_a,element_b;
        std::string element_str;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size < 1) {
            throw IndexOutOfRange(WrongInput);
        }
        std::cout << "Insert elements one by one" << std::endl;


        for (int i = 0;i<size;i++){
            std::cout<<"Insert real part"<<std::endl;
            getline(std::cin, element_str);
            element_a = stoi(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stoi(element_str);
            IntComplexSeq->Append(ComplexNumber<int>(element_a,element_b));

        }
        Polynomial<ComplexNumber<int>>pol_new(IntComplexSeq);
        pol->operator=(pol->operator*(pol_new));
        delete IntComplexSeq;
    }
    void ConcatenatedFromPol() override{
        std::cout << "Insert how many elements" << std::endl;
        auto *IntComplexSeq = new ArraySequence<ComplexNumber<int>>();
        int size;
        int element_a,element_b;
        std::string element_str;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size < 1) {
            throw IndexOutOfRange(WrongInput);
        }
        std::cout << "Insert elements one by one" << std::endl;


        for (int i = 0;i<size;i++){
            std::cout<<"Insert real part"<<std::endl;
            getline(std::cin, element_str);
            element_a = stoi(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stoi(element_str);
            IntComplexSeq->Append(ComplexNumber<int>(element_a,element_b));

        }
        Polynomial<ComplexNumber<int>>pol_new(IntComplexSeq);
        pol->operator=(pol->operator()(pol_new));
        delete IntComplexSeq;
    }
    void MultiplyByNumber() override{
        std::string element_str;
        std::cout<<"Insert number"<<std::endl;


        int element;

        getline(std::cin, element_str);
        element = stoi(element_str);

        pol->operator=(pol->operator*(ComplexNumber(element,0)));


    }
    void ShowValue() override{
        std::string element_str;
        std::cout<<"Insert number"<<std::endl;


        int element_a,element_b;
        std::cout<<"Insert real part"<<std::endl;
        getline(std::cin, element_str);
        element_a = stoi(element_str);
        std::cout<<"Insert imaginary part"<<std::endl;
        getline(std::cin, element_str);
        element_b = stoi(element_str);
        print_complex(pol->operator()(ComplexNumber(element_a,element_b)));

    }

};
#endif //LAB2PRJ_INTCOMLPEXPOLINTERFACE_HPP



