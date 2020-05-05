#include <iostream>
#include <complex>
#include <stdexcept>
#include "solver.hpp"

solver::RealVariable::RealVariable(){
    _a = 0;
    _b = 1;
    _c = 0;
    _pow = 1;
}

solver::RealVariable& solver::RealVariable::operator*(double num){
  
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    if(temp->_pow == 2){
        temp->_a *= num;
    }
    else{
        temp->_b *= num ;
    }

    return *temp;
}
solver::RealVariable& solver::RealVariable::operator*(RealVariable& other){
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    if(temp->_pow >= 2 && other._pow >= 2){
        throw "out of range";
    }
    else{
        temp->_a *= other._a;
        temp->_b *= other._b;
        temp->_c *= other._c;
    }
    return *temp;
}
solver::RealVariable& solver::operator*(double num, RealVariable& x){
    return x*num;
}
solver::RealVariable& solver::RealVariable::operator-(double num){
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c - num;
    temp->_pow = this->_pow;
    return *temp;
}

solver::RealVariable& solver::RealVariable::operator-(RealVariable& other){
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    if(temp->_pow == other._pow && temp->_pow == 2){
        temp->_a -= other._a;
      
    }
    if(other._pow == 1){
         temp->_b -= other._b;
    }
    else{ 
        temp->_a += other._a;
        temp->_b += other._b;
        temp->_c -= other._c;
    }
    return *temp;
}
solver::RealVariable& solver::operator-(double num, RealVariable& x){
    return x-num;
}
solver::RealVariable& solver::RealVariable::operator+(double num){
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c + num;
    temp->_pow = this->_pow;
    
  return *temp;
}
solver::RealVariable& solver::RealVariable::operator+(RealVariable& other){
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c ;
    temp->_pow = this->_pow;
     if(temp->_pow == other._pow && temp->_pow == 2){
        temp->_a += other._a;
      
    }
    if(other._pow == 1){
         temp->_b += other._b;
    }
    else{
        temp->_a += other._a;
        temp->_b += other._b;
        temp->_c += other._c;
    }
    
 return *this;
}
solver::RealVariable& solver::operator+(double num, RealVariable& x){
    return x+num;
}
solver::RealVariable& solver::RealVariable::operator==(double num){
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c - num; 
    return *temp;
    
}
solver::RealVariable& solver::RealVariable::operator==(RealVariable& other){
     RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    *(temp)-other;
   return *this;
}
solver::RealVariable& solver::operator==(double num,RealVariable& x){
    return x==num;

}
solver::RealVariable& solver::RealVariable::operator^(double num){
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    if(num > 2 || num < 0) throw "OUT OF RANGE !";
    if(num == 0){
        temp->_a = 0;
        temp->_b = 0;
        temp->_c = 1;
        temp->_pow = 0;
    }
    if(num == 1){
        return *temp;
    }   
        temp->_a = 1;
        temp->_b = 0;
        temp->_pow = 2;
    
    return *temp;
}
solver::RealVariable& solver::RealVariable::operator/(double num){//
    
    if(num == 0){
        throw std::runtime_error("Math error: Attempted to divide by zero\n");
    }
     RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    if(temp->_pow == 2){
        temp->_a /= num; 
    }
    if(temp->_pow == 1){
        temp->_b /= num;
    }
    temp->_c /= num;
   
    return *temp;
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

  double solver::solve(RealVariable& equ){
        if (equ._a == 0){
            return -equ._c/equ._b;
        }
        return -equ._b/2 + std::sqrt(equ._b*equ._b-4*equ._a*equ._c)/2;
    };
 std::complex<double> solver::solve(ComplexVariable& x){
    std::complex<double> temp(0,0);
    return temp;
}