//
// Created by User on 30.05.2022.
//

#ifndef LAB2PRJ_COMPLEXNUMBERS_HPP
#define LAB2PRJ_COMPLEXNUMBERS_HPP
#include <iostream>
template <class T>
class ComplexNumber{
private:
    T real;
    T imaginary;
public:
    T Real() const{
        return real;
    }
    T Imaginary() const{
        return imaginary;
    }
    void SetReal(T a){
        real = a;
    }
    void SetImaginary(T b){
        imaginary = b;
    }
public:
    ComplexNumber(){
        real  =0;
        imaginary = 0;
    }
    ComplexNumber(T a, T b){
        real = a;
        imaginary = b;
    }
public:
    ComplexNumber& operator=(const ComplexNumber<T>& number){
        this->SetReal(number.Real());
        imaginary = number.Imaginary();
        return *this;
    }
    ComplexNumber operator+(const ComplexNumber<T>& number){
        ComplexNumber<T> new_number;
        new_number.real = this->Real()+number.Real();
        new_number.imaginary = this->Imaginary()+number.Imaginary();
        return new_number;
    }
    ComplexNumber operator-(const ComplexNumber<T>& number){
        ComplexNumber<T> new_number;
        new_number.real = this->Real()-number.Real();
        new_number.imaginary = this->Imaginary()-number.Imaginary();
        return new_number;
    }
    ComplexNumber operator*(const ComplexNumber<T>& number){
        ComplexNumber<T> new_number;
        new_number.real = this->Real()*number.Real() - this->Imaginary()*number.Imaginary();
        new_number.imaginary = this->Real()*number.Imaginary() + this->Imaginary()*number.Real();
        return new_number;

    }
    ComplexNumber operator*(T number){
        ComplexNumber<T> new_number;
        new_number.real = this->Real()*number;
        new_number.imaginary = this->Imaginary()*number;
        return new_number;
    }
    template <class U>
    friend std::ostream& operator<<(std::ostream &out ,const ComplexNumber<U> &a);

};
template <class T>
std::ostream& operator<< (std::ostream &out, const ComplexNumber<T> &a)
{

    out << "("<<a.Real()<<" + "<<a.Imaginary()<<"i)";


    return out;
}


template <class t>
void print_complex(ComplexNumber<t> a){
    std::cout << "("<<a.Real()<<" + "<<a.Imaginary()<<"i)";
}

#endif //LAB2PRJ_COMPLEXNUMBERS_HPP

