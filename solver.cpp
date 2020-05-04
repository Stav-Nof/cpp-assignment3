#include <iostream>
#include <complex>
#include <stdexcept>
#include "solver.hpp"

solver::RealVariable::RealVariable(){
    _a = _b = _c = _flag = 0;
}

solver::RealVariable& solver::RealVariable::operator*(double num){
    if (this->_flag == 1){
        this->_flag = 0;
        this->_a *= num;
    }
    else {
        if (this->_b == 0) this->_b = 1;
        this->_b *= num;
    }
    return *this;
}
solver::RealVariable& solver::RealVariable::operator-(double num){
    this->_c -= num;
    return *this;
}
solver::RealVariable& solver::RealVariable::operator+(double num){//
    this->_c += num;
    return *this;
}
solver::RealVariable& solver::RealVariable::operator+(RealVariable& other){//
    this->_a += other._a;
    this->_b += other._b;
    this->_c += other._c;
    return *this;
}
solver::RealVariable& solver::RealVariable::operator-(RealVariable& other){//
    this->_a -= other._a;
    this->_b -= other._b;
    this->_c -= other._c;
    return *this;
}
solver::RealVariable& solver::RealVariable::operator==(double num){
    this->_c -= num;
    return *this;
}
solver::RealVariable& solver::RealVariable::operator==(RealVariable& other){//
    this->_a -= other._a;
    this->_b -= other._b;
    this->_c -= other._c;
    return *this;
}
solver::RealVariable& solver::RealVariable::operator^(double num){
    if(num > 2 || num < 0) throw "OUT OF RANGE !";
    if(num == 0) this->_c = 1;
    if(num == 1 && this->_b != 0) this->_b = 1;
    else if(num == 2){
        this->_flag = 1;
        this->_a = 1;
    }
    return *this;
}
solver::RealVariable& solver::RealVariable::operator/(double num){//
    
    if(num == 0){
        throw std::runtime_error("Math error: Attempted to divide by zero\n");
    }
    this->_a /= num;
    this->_b /= num;
    this->_c /= num;
    return *this;
}
solver::RealVariable& solver::operator*(double num, RealVariable& x){//
    if (x._flag == 1){
        x._flag = 0;
        x._a *= num;
    }
    else {
        if (x._b == 0) x._b = 1;
        x._b *= num;
    }
    return x;
}
solver::RealVariable& solver::operator+(double num, RealVariable& x){//
    x._c += num;
    return x;
}

////////////////////////////////////////////////////////////////////


solver::ComplexVariable& solver::ComplexVariable::operator*(double num){
    this->_a *= num;
    this->_b *= num;
    this->_c *= num; 
    return *this;
}
solver::ComplexVariable& solver::ComplexVariable::operator-(double num){
    this->_c -= num;
    return *this;
}
solver::ComplexVariable& solver::ComplexVariable::operator+(double num){
    this->_c += num;
    return *this;
}
solver::ComplexVariable& solver::ComplexVariable::operator+(ComplexVariable& other){
    this->_a += other._a;
    this->_b += other._b;
    this->_c += other._c;
    return *this;
}
solver::ComplexVariable& solver::ComplexVariable::operator+(std::complex<double> other){
    return *this;
}
solver::ComplexVariable& solver::ComplexVariable::operator-(ComplexVariable& other){
    return *this;
}
solver::ComplexVariable& solver::ComplexVariable::operator==(double num){
    return *this;
}
solver::ComplexVariable& solver::ComplexVariable::operator==(ComplexVariable& other){
    return *this;
}
solver::ComplexVariable& solver::ComplexVariable::operator^(double num){
    return *this;
}
solver::ComplexVariable& solver::ComplexVariable::operator/(double num){
    return *this;
}
solver::ComplexVariable& solver::operator*(double num, ComplexVariable& x){
    return x;
}
solver::ComplexVariable& solver::operator+(double num, ComplexVariable& x){
    return x;
}

 double solver::solve(RealVariable& x){
    double ans = 0;
    std::cout << x._a << ", " << x._b << ", " << x._c << std::endl;
    if (x._a == 0){
        ans = (x._c * -1)/x._b;
    }
    x._a = 0;
    x._b = 0;
    x._c = 0;
    return ans;
 }
 std::complex<double> solver::solve(ComplexVariable& x){
    std::complex<double> temp(0,0);
    return temp;
}