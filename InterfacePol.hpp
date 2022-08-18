//
// Created by User on 05.08.2022.
//

#ifndef LAB2PRJ_INTERFACEPOL_HPP
#define LAB2PRJ_INTERFACEPOL_HPP
#include "QuadMatrix.hpp"
#include "Polynomial.hpp"
#include "ComplexNumbers.hpp"
class InterfacePol{
public:

    virtual ~InterfacePol() = default;
    virtual void PrintPol() const = 0;
    virtual void AddPol() = 0;
    virtual void SubstractPol() = 0;
    virtual void MultiplyByPol() = 0;
    virtual void ConcatenatedFromPol() = 0;
    virtual void MultiplyByNumber() = 0;
    virtual void ShowValue() = 0;
};

#endif //LAB2PRJ_INTERFACEPOL_HPP
