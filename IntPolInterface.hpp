//
// Created by User on 09.08.2022.
//

#ifndef LAB2PRJ_INTPOLINTERFACE_HPP
#define LAB2PRJ_INTPOLINTERFACE_HPP
#include "InterfacePol.hpp"
class IntPolInterface:public InterfacePol{
private:
    Polynomial<int>* pol;

public:
    IntPolInterface(){
        std::cout<<"Insert how many elements"<<std::endl;
        auto* IntSeq = new ArraySequence<int>();
        int size;
        int element;
        std::string element_str;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stoi(element_str);
            IntSeq->Append(element);

        }
        pol = new Polynomial<int>(IntSeq);
        delete IntSeq;
    }
    ~IntPolInterface() override{
        delete pol;
    }
public:
    void PrintPol() const override{
        std::cout<<pol->Get(0);
        for (int i = 1;i<pol->GetSize();i++){
            std::cout<<" + "<<pol->Get(i)<<"x^"<<i;
        }
        std::cout<<"\n";
    }
    void AddPol() override{
        std::cout<<"Insert how many elements"<<std::endl;
        auto* IntSeq = new ArraySequence<int>();
        int size;
        int element;
        std::string element_str;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stoi(element_str);
            IntSeq->Append(element);

        }
        Polynomial<int> pol_support(IntSeq);
        pol->operator=(pol->operator+(pol_support));
        delete IntSeq;
    }
    void SubstractPol() override{
        std::cout<<"Insert how many elements"<<std::endl;
        auto* IntSeq = new ArraySequence<int>();
        int size;
        std::string element_str;
        int element;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stoi(element_str);
            IntSeq->Append(element);

        }
        Polynomial<int> pol_support(IntSeq);
        pol->operator=(pol->operator-(pol_support));
        delete IntSeq;
    }

    void MultiplyByPol() override{
        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        auto* IntSeq = new ArraySequence<int>();
        int size;
        int element;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stoi(element_str);
            IntSeq->Append(element);

        }
        Polynomial<int> pol_support(IntSeq);
        pol->operator=(pol->operator*(pol_support));
        delete IntSeq;
    }
    void ConcatenatedFromPol() override{
        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        auto* IntSeq = new ArraySequence<int>();
        int size;
        int element;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stoi(element_str);
            IntSeq->Append(element);

        }
        Polynomial<int> pol_support(IntSeq);
        pol->operator=(pol->operator()(pol_support));
        delete IntSeq;
    }
    void MultiplyByNumber() override{
        std::string element_str;
        std::cout<<"Insert number"<<std::endl;


        int element;
        getline(std::cin, element_str);
        element = stoi(element_str);



        pol->operator=(pol->operator*(element));

    }
    void ShowValue() override{
        std::string element_str;
        std::cout<<"Insert number"<<std::endl;


        int element;
        getline(std::cin, element_str);
        element = stoi(element_str);



        std::cout<<pol->operator()(element)<<std::endl;
    };

};
#endif //LAB2PRJ_INTPOLINTERFACE_HPP
