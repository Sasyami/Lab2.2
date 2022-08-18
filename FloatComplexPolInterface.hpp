//
// Created by User on 12.08.2022.
//

#ifndef LAB2PRJ_FLOATCOMPLEXPOLINTERFACE_HPP
#define LAB2PRJ_FLOATCOMPLEXPOLINTERFACE_HPP

#include "InterfacePol.hpp"
#include "ComplexNumbers.hpp"
class FloatComplexPolInterface:public InterfacePol {
private:
    Polynomial<ComplexNumber<float>> *pol;

public:
    FloatComplexPolInterface() {
        std::cout << "Insert how many elements" << std::endl;
        auto *FloatComplexSeq = new ArraySequence<ComplexNumber<float>>();
        int size;
        float element_a,element_b;
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
            element_a = stof(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stof(element_str);
            FloatComplexSeq->Append(ComplexNumber<float>(element_a,element_b));

        }
        pol = new Polynomial<ComplexNumber<float>>(FloatComplexSeq);
        delete FloatComplexSeq;
    }

    ~FloatComplexPolInterface() override {
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
        auto *FloatComplexSeq = new ArraySequence<ComplexNumber<float>>();
        int size;
        float element_a,element_b;
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
            element_a = stof(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stof(element_str);
            FloatComplexSeq->Append(ComplexNumber<float>(element_a,element_b));

        }
        Polynomial<ComplexNumber<float>>pol_new(FloatComplexSeq);
        pol->operator=(pol->operator+(pol_new));
        delete FloatComplexSeq;
    }
    void SubstractPol() override{
        std::cout << "Insert how many elements" << std::endl;
        auto *FloatComplexSeq = new ArraySequence<ComplexNumber<float>>();
        int size;
        float element_a,element_b;
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
            element_a = stof(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stof(element_str);
            FloatComplexSeq->Append(ComplexNumber<float>(element_a,element_b));

        }
        Polynomial<ComplexNumber<float>>pol_new(FloatComplexSeq);
        pol->operator=(pol->operator-(pol_new));
        delete FloatComplexSeq;
    }
    void MultiplyByPol() override{
        std::cout << "Insert how many elements" << std::endl;
        auto *FloatComplexSeq = new ArraySequence<ComplexNumber<float>>();
        int size;
        float element_a,element_b;
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
            element_a = stof(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stof(element_str);
            FloatComplexSeq->Append(ComplexNumber<float>(element_a,element_b));

        }
        Polynomial<ComplexNumber<float>>pol_new(FloatComplexSeq);
        pol->operator=(pol->operator*(pol_new));
        delete FloatComplexSeq;
    }
    void ConcatenatedFromPol() override{
        std::cout << "Insert how many elements" << std::endl;
        auto *FloatComplexSeq = new ArraySequence<ComplexNumber<float>>();
        int size;
        float element_a,element_b;
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
            element_a = stof(element_str);
            std::cout<<"Insert imaginary part"<<std::endl;
            getline(std::cin, element_str);
            element_b = stof(element_str);
            FloatComplexSeq->Append(ComplexNumber<float>(element_a,element_b));

        }
        Polynomial<ComplexNumber<float>>pol_new(FloatComplexSeq);
        pol->operator=(pol->operator()(pol_new));
        delete FloatComplexSeq;
    }
    void MultiplyByNumber() override{
        std::string element_str;
        std::cout<<"Insert number"<<std::endl;


        float element;

        getline(std::cin, element_str);
        element = stof(element_str);

        pol->operator=(pol->operator*(ComplexNumber(element,element-element)));


    }
    void ShowValue() override{
        std::string element_str;
        std::cout<<"Insert number"<<std::endl;


        float element_a,element_b;
        std::cout<<"Insert real part"<<std::endl;
        getline(std::cin, element_str);
        element_a = stof(element_str);
        std::cout<<"Insert imaginary part"<<std::endl;
        getline(std::cin, element_str);
        element_b = stof(element_str);
        print_complex(pol->operator()(ComplexNumber(element_a,element_b)));

    }

};
#endif //LAB2PRJ_FLOATCOMPLEXPOLINTERFACE_HPP
