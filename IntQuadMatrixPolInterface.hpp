//
// Created by User on 12.08.2022.
//

#ifndef LAB2PRJ_INTQUADMATRIXPOLINTERFACE_HPP
#define LAB2PRJ_INTQUADMATRIXPOLINTERFACE_HPP
#include "InterfacePol.hpp"
#include "QuadMatrix.hpp"
class IntQuadMatrixPolInterface:public InterfacePol {
private:
    Polynomial<QuadMatrix<int>> *pol;

public:
    IntQuadMatrixPolInterface() {
        auto* IntSeq = new ArraySequence<int>();
        auto* MatrixIntSeq = new ArraySequence<QuadMatrix<int>>();
        int size;
        int quantity;
        int element;
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
                element = stoi(element_str);
                IntSeq->Append(element);
            }

            MatrixIntSeq->Append(QuadMatrix<int>(IntSeq,size));
            delete IntSeq;
            IntSeq = new ArraySequence<int>();



        }
        pol = new Polynomial<QuadMatrix<int>>(MatrixIntSeq);
        delete IntSeq;
        delete MatrixIntSeq;
    }

    ~IntQuadMatrixPolInterface() override {
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
        auto* IntSeq = new ArraySequence<int>();
        auto* MatrixIntSeq = new ArraySequence<QuadMatrix<int>>();
        size_t size = pol->Get(0).GetSizeOfSide();
        int quantity;
        int element;
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
                element = stoi(element_str);
                IntSeq->Append(element);
            }

            MatrixIntSeq->Append(QuadMatrix<int>(IntSeq,size));
            delete IntSeq;
            IntSeq = new ArraySequence<int>();



        }
        Polynomial<QuadMatrix<int>>pol_support(MatrixIntSeq);
        pol -> operator=(pol->operator+(pol_support));

        delete IntSeq;
        delete MatrixIntSeq;
    }
    void SubstractPol() override{
        auto* IntSeq = new ArraySequence<int>();
        auto* MatrixIntSeq = new ArraySequence<QuadMatrix<int>>();
        size_t size = pol->Get(0).GetSizeOfSide();
        int quantity;
        int element;
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
                element = stoi(element_str);
                IntSeq->Append(element);
            }

            MatrixIntSeq->Append(QuadMatrix<int>(IntSeq,size));
            delete IntSeq;
            IntSeq = new ArraySequence<int>();



        }
        Polynomial<QuadMatrix<int>>pol_support(MatrixIntSeq);
        pol -> operator=(pol->operator-(pol_support));

        delete IntSeq;
        delete MatrixIntSeq;
    }
    void MultiplyByPol() override{
        auto* IntSeq = new ArraySequence<int>();
        auto* MatrixIntSeq = new ArraySequence<QuadMatrix<int>>();
        size_t size = pol->Get(0).GetSizeOfSide();
        int quantity;
        int element;
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
                element = stoi(element_str);
                IntSeq->Append(element);
            }

            MatrixIntSeq->Append(QuadMatrix<int>(IntSeq,size));
            delete IntSeq;
            IntSeq = new ArraySequence<int>();



        }
        Polynomial<QuadMatrix<int>>pol_support(MatrixIntSeq);
        pol -> operator=(pol->operator*(pol_support));

        delete IntSeq;
        delete MatrixIntSeq;
    }
    void ConcatenatedFromPol() override{
        auto* IntSeq = new ArraySequence<int>();
        auto* MatrixIntSeq = new ArraySequence<QuadMatrix<int>>();
        size_t size = pol->Get(0).GetSizeOfSide();
        int quantity;
        int element;
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
                element = stoi(element_str);
                IntSeq->Append(element);
            }

            MatrixIntSeq->Append(QuadMatrix<int>(IntSeq,size));
            delete IntSeq;
            IntSeq = new ArraySequence<int>();



        }
        Polynomial<QuadMatrix<int>>pol_support(MatrixIntSeq);
        pol -> operator=(pol->operator() (pol_support));

        delete IntSeq;
        delete MatrixIntSeq;
    }
    void MultiplyByNumber() override{
        auto* IntSeq = new ArraySequence<int>();

        size_t size = pol->Get(0).GetSizeOfSide();

        int element;
        std::string element_str;


        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert element"<<std::endl;


        getline(std::cin, element_str);
        element = stoi(element_str);


        for (int j = 0;j<size*size;j++){

            IntSeq->Append(element-element);
        }

        QuadMatrix<int>Matrix(IntSeq,size);
        for (int i = 0;i<size;i++){
            Matrix.Set(element,i,i);
        }






        pol -> operator=(pol->operator*(Matrix));

        delete IntSeq;

    }
    void ShowValue() override{
        auto* IntSeq = new ArraySequence<int>();

        size_t size = pol->Get(0).GetSizeOfSide();
        int quantity;
        int element;
        std::string element_str;

        if (size<1){
            throw IndexOutOfRange(WrongInput);
        }
        std::cout<<"Insert elements one by one"<<std::endl;




        for (int j = 0;j<size*size;j++){
            getline(std::cin, element_str);
            element = stoi(element_str);
            IntSeq->Append(element);

        }
        QuadMatrix<int>Matrix(IntSeq,size);
        print_matrix(pol->operator()(Matrix));
        std::cout<<"\n";
        delete IntSeq;

    }
};
#endif //LAB2PRJ_INTQUADMATRIXPOLINTERFACE_HPP
