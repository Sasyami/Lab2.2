//
// Created by User on 09.08.2022.
//

#ifndef LAB2PRJ_FLOATPOLINTERFACE_HPP
#define LAB2PRJ_FLOATPOLINTERFACE_HPP
#include "InterfacePol.hpp"
class FloatPolInterface:public InterfacePol{
private:
    Polynomial<float>* pol;

public:
    FloatPolInterface(){
        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        auto* FloatSeq = new ArraySequence<float>();
        int size;
        float element;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stof(element_str);
            FloatSeq->Append(element);

        }
        pol = new Polynomial<float>(FloatSeq);
        delete FloatSeq;
    }
    ~FloatPolInterface() override{
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
        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        auto* FloatSeq = new ArraySequence<float>();
        int size;
        float element;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stof(element_str);
            FloatSeq->Append(element);

        }
        Polynomial<float> pol_support(FloatSeq);
        pol->operator=(pol->operator+(pol_support));
        delete FloatSeq;
    }
    void SubstractPol() override{
        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        auto* FloatSeq = new ArraySequence<float>();
        int size;
        float element;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stof(element_str);
            FloatSeq->Append(element);

        }
        Polynomial<float> pol_support(FloatSeq);
        pol->operator=(pol->operator-(pol_support));
        delete FloatSeq;
    }

    void MultiplyByPol() override{
        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        auto* FloatSeq = new ArraySequence<float>();
        int size;
        float element;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stof(element_str);
            FloatSeq->Append(element);

        }
        Polynomial<float> pol_support(FloatSeq);
        pol->operator=(pol->operator*(pol_support));
        delete FloatSeq;
    }
    void ConcatenatedFromPol() override{
        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        auto* FloatSeq = new ArraySequence<float>();
        int size;
        float element;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<size;i++){

            getline(std::cin, element_str);
            element = stof(element_str);
            FloatSeq->Append(element);

        }
        Polynomial<float> pol_support(FloatSeq);
        pol->operator=(pol->operator()(pol_support));
        delete FloatSeq;
    }

    void MultiplyByNumber() override{
        std::string element_str;
        std::cout<<"Insert number"<<std::endl;


        float element;
        getline(std::cin, element_str);
        element = stof(element_str);



        pol->operator=(pol->operator*(element));

    }
    void ShowValue() override{
        std::string element_str;
        std::cout<<"Insert number"<<std::endl;


        float element;
        getline(std::cin, element_str);
        element = stof(element_str);



        std::cout<<pol->operator()(element)<<std::endl;
    };

};
#endif //LAB2PRJ_FLOATPOLINTERFACE_HPP
