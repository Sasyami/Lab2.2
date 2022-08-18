//
// Created by User on 14.08.2022.
//

#ifndef LAB2PRJ_FLOATQUADMATRIXPOLINTERFACE_HPP
#define LAB2PRJ_FLOATQUADMATRIXPOLINTERFACE_HPP
#include "InterfacePol.hpp"
#include "QuadMatrix.hpp"
class FloatQuadMatrixPolInterface:public InterfacePol {
private:
    Polynomial<QuadMatrix<float>> *pol;

public:
    FloatQuadMatrixPolInterface() {
        auto* FloatSeq = new ArraySequence<float>();
        auto* MatrixFloatSeq = new ArraySequence<QuadMatrix<float>>();
        int size;
        int quantity;
        float element;
        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        getline(std::cin, element_str);
        quantity = stoi(element_str);
        if (quantity<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert size of side"<<std::endl;
        getline(std::cin, element_str);
        size = stoi(element_str);
        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<quantity;i++){
            std::cout<<"Matrix "<<i<<std::endl;
            for (int j = 0;j<size*size;j++){
                getline(std::cin, element_str);
                element = stof(element_str);
                FloatSeq->Append(element);
            }

            MatrixFloatSeq->Append(QuadMatrix<float>(FloatSeq,size));
            delete FloatSeq;
            FloatSeq = new ArraySequence<float>();



        }
        pol = new Polynomial<QuadMatrix<float>>(MatrixFloatSeq);
        delete FloatSeq;
        delete MatrixFloatSeq;
    }

    ~FloatQuadMatrixPolInterface() override {
        delete pol;
    }
    void PrintPol() const override{
        print_matrix(pol->Get(0));




        for (int j = 1;j<pol->GetSize();j++) {
            std::cout<<"\n";
            for (int i = 0;i<pol->Get(0).GetSizeOfSide()/2;i++){
                std::cout<<" ";
            }
            std::cout<<"+\n";
            std::cout<<"\n";
            print_matrix(pol->Get(j));

            for (int i = 0;i<pol->Get(0).GetSizeOfSide()/2;i++){
                std::cout<<" ";
            }
            std::cout<<"x^"<<j;
            std::cout<<"\n";


        }
    }
    void AddPol() override{
        auto* FloatSeq = new ArraySequence<float>();
        auto* MatrixFloatSeq = new ArraySequence<QuadMatrix<float>>();

        int quantity;
        float element;
        size_t size = pol->Get(0).GetSizeOfSide();

        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        getline(std::cin, element_str);
        quantity = stoi(element_str);
        if (quantity<1){
            throw IndexOutOfRange(WrongInput);
        }


        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<quantity;i++){
            std::cout<<"Matrix "<<i<<std::endl;
            for (int j = 0;j<size*size;j++){
                getline(std::cin, element_str);
                element = stof(element_str);
                FloatSeq->Append(element);
            }

            MatrixFloatSeq->Append(QuadMatrix<float>(FloatSeq,size));
            delete FloatSeq;
            FloatSeq = new ArraySequence<float>();



        }
        Polynomial<QuadMatrix<float>>pol_support(MatrixFloatSeq);
        pol -> operator=(pol->operator+(pol_support));

        delete FloatSeq;
        delete MatrixFloatSeq;
    }
    void SubstractPol() override{
        auto* FloatSeq = new ArraySequence<float>();
        auto* MatrixFloatSeq = new ArraySequence<QuadMatrix<float>>();

        int quantity;
        float element;
        size_t size = pol->Get(0).GetSizeOfSide();

        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        getline(std::cin, element_str);
        quantity = stoi(element_str);
        if (quantity<1){
            throw IndexOutOfRange(WrongInput);
        }

        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<quantity;i++){
            std::cout<<"Matrix "<<i<<std::endl;
            for (int j = 0;j<size*size;j++){
                getline(std::cin, element_str);
                element = stof(element_str);
                FloatSeq->Append(element);
            }

            MatrixFloatSeq->Append(QuadMatrix<float>(FloatSeq,size));
            delete FloatSeq;
            FloatSeq = new ArraySequence<float>();



        }
        Polynomial<QuadMatrix<float>>pol_support(MatrixFloatSeq);
        pol -> operator=(pol->operator-(pol_support));

        delete FloatSeq;
        delete MatrixFloatSeq;
    }
    void MultiplyByPol() override{
        auto* FloatSeq = new ArraySequence<float>();
        auto* MatrixFloatSeq = new ArraySequence<QuadMatrix<float>>();

        int quantity;
        float element;
        size_t size = pol->Get(0).GetSizeOfSide();

        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        getline(std::cin, element_str);
        quantity = stoi(element_str);
        if (quantity<1){
            throw IndexOutOfRange(WrongInput);
        }

        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<quantity;i++){
            std::cout<<"Matrix "<<i<<std::endl;
            for (int j = 0;j<size*size;j++){
                getline(std::cin, element_str);
                element = stof(element_str);
                FloatSeq->Append(element);
            }

            MatrixFloatSeq->Append(QuadMatrix<float>(FloatSeq,size));
            delete FloatSeq;
            FloatSeq = new ArraySequence<float>();



        }
        Polynomial<QuadMatrix<float>>pol_support(MatrixFloatSeq);
        pol -> operator=(pol->operator*(pol_support));

        delete FloatSeq;
        delete MatrixFloatSeq;
    }
    void ConcatenatedFromPol() override{
        auto* FloatSeq = new ArraySequence<float>();
        auto* MatrixFloatSeq = new ArraySequence<QuadMatrix<float>>();

        int quantity;
        float element;
        size_t size = pol->Get(0).GetSizeOfSide();

        std::string element_str;
        std::cout<<"Insert how many elements"<<std::endl;
        getline(std::cin, element_str);
        quantity = stoi(element_str);
        if (quantity<1){
            throw IndexOutOfRange(WrongInput);
        }

        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;


        for (int i = 0;i<quantity;i++){
            std::cout<<"Matrix "<<i<<std::endl;
            for (int j = 0;j<size*size;j++){
                getline(std::cin, element_str);
                element = stof(element_str);
                FloatSeq->Append(element);
            }

            MatrixFloatSeq->Append(QuadMatrix<float>(FloatSeq,size));
            delete FloatSeq;
            FloatSeq = new ArraySequence<float>();



        }
        Polynomial<QuadMatrix<float>>pol_support(MatrixFloatSeq);
        pol -> operator=(pol->operator() (pol_support));

        delete FloatSeq;
        delete MatrixFloatSeq;
    }
    void MultiplyByNumber() override{
        auto* FloatSeq = new ArraySequence<float>();



        float element;

        size_t size = pol->Get(0).GetSizeOfSide();


        std::string element_str;


        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert element"<<std::endl;


        getline(std::cin, element_str);
        element = stof(element_str);


        for (int j = 0;j<size*size;j++){

            FloatSeq->Append(element-element);
        }

        QuadMatrix<float>Matrix(FloatSeq,size);
        for (int i = 0;i<size;i++){
            Matrix.Set(element,i,i);
        }






        pol -> operator=(pol->operator*(Matrix));

        delete FloatSeq;

    }
    void ShowValue() override{
        auto* FloatSeq = new ArraySequence<float>();



        float element;

        size_t size = pol->Get(0).GetSizeOfSide();


        std::string element_str;

        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;




        for (int j = 0;j<size*size;j++){
            getline(std::cin, element_str);
            element = stof(element_str);
            FloatSeq->Append(element);

        }
        QuadMatrix<float>Matrix(FloatSeq,size);
        print_matrix(pol->operator()(Matrix));
        std::cout<<"\n";
        delete FloatSeq;

    }
};
#endif //LAB2PRJ_FLOATQUADMATRIXPOLINTERFACE_HPP
