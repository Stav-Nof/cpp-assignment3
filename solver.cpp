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
    
 return *temp;
}
solver::RealVariable& solver::operator+(double num, RealVariable& x){
    return x+num;
}
solver::RealVariable& solver::RealVariable::operator==(double num){
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c - num; 
    temp->_pow = this->_pow;
    if(temp->_a == 0 && temp->_b == 0 && temp->_c !=0){
        throw std::runtime_error("ERR");
    }
    if(temp->_pow == 2 && num < 0){
        throw std::runtime_error("ERR");
    }
    return *temp;
    
}
solver::RealVariable& solver::RealVariable::operator==(RealVariable& other){
    
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a-other._a;
    temp->_b = this->_b-other._b;
    temp->_c = this->_c-other._c;
    temp->_pow = this->_pow;
    
    
   return *temp;
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
solver::RealVariable& solver::RealVariable::operator/(double num){
    
    if(num == 0){
        throw std::runtime_error("ERR");
    }
    RealVariable *temp = new RealVariable();
    temp->_a = this->_a/num;
    temp->_b = this->_b/num;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    
   
    return *temp;
}
solver::RealVariable& solver::RealVariable::operator/(RealVariable& other){

    RealVariable *temp = new RealVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    if(other._a == 0 || other._b == 0 || other._c == 0){
          throw std::runtime_error("ERR");
    }
    if(temp->_pow == other._pow){
        temp->_b /= other._b;
        temp->_pow -= other._pow;
    }
    if(temp->_pow == 2 && other._pow == 1){
        temp->_a = 0;
        temp->_b /= other._b;
        temp->_pow -= other._pow;

    }
    if(temp->_pow == 2 && other._pow == 0){
        temp->_b /= other._c;
    }
    return *temp;

}



////////////////////////////////////////////////////////////////////

solver::ComplexVariable::ComplexVariable(){
    _a = 0;
    _b = 1;
    _c = 0;
    _pow = 1;
}
solver::ComplexVariable& solver::ComplexVariable::operator*(double num){
    ComplexVariable *temp = new ComplexVariable();
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
solver::ComplexVariable& solver::ComplexVariable::operator*(ComplexVariable& other){
    ComplexVariable *temp = new ComplexVariable();
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
solver::ComplexVariable& solver::operator*(double num, ComplexVariable& x){
    return x*num;
}
solver::ComplexVariable& solver::ComplexVariable::operator-(double num){
    ComplexVariable *temp = new ComplexVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c - num;
    temp->_pow = this->_pow;
    return *temp;
}

solver::ComplexVariable& solver::ComplexVariable::operator-(ComplexVariable& other){
    ComplexVariable *temp = new ComplexVariable();
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

solver::ComplexVariable& solver::ComplexVariable::operator+(double num){
    ComplexVariable *temp = new ComplexVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c + num;
    temp->_pow = this->_pow;
    
  return *temp;
}
solver::ComplexVariable& solver::ComplexVariable::operator+(ComplexVariable& other){
    ComplexVariable *temp = new ComplexVariable();
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
    
 return *temp;
}
solver::ComplexVariable& solver::operator+(double num, ComplexVariable& x){
    return x+num;
}
solver::ComplexVariable& solver::ComplexVariable::operator==(double num){
    ComplexVariable *temp = new ComplexVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c - num; 
    temp->_pow = this->_pow;
    if(temp->_a == 0 && temp->_b == 0 && temp->_c !=0){
        throw std::runtime_error("ERR");
    }
    if(temp->_pow == 2 && num < 0){
        throw std::runtime_error("ERR");
    }
    return *temp;
    
}
solver::ComplexVariable& solver::ComplexVariable::operator==(ComplexVariable& other){
    
    ComplexVariable *temp = new ComplexVariable();
    temp->_a = this->_a-other._a;
    temp->_b = this->_b-other._b;
    temp->_c = this->_c-other._c;
    temp->_pow = this->_pow;
    
    
   return *temp;
}

solver::ComplexVariable& solver::ComplexVariable::operator^(double num){
    ComplexVariable *temp = new ComplexVariable();
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
solver::ComplexVariable& solver::ComplexVariable::operator/(double num){
    
    if(num == 0){
        throw std::runtime_error("ERR");
    }
    ComplexVariable *temp = new ComplexVariable();
    temp->_a = this->_a/num;
    temp->_b = this->_b/num;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    
   
    return *temp;
}
solver::ComplexVariable& solver::ComplexVariable::operator/(ComplexVariable& other){

    ComplexVariable *temp = new ComplexVariable();
    temp->_a = this->_a;
    temp->_b = this->_b;
    temp->_c = this->_c;
    temp->_pow = this->_pow;
    if(other._a == 0 || other._b == 0 || other._c == 0){
          throw std::runtime_error("ERR");
    }
    if(temp->_pow == other._pow){
        temp->_b /= other._b;
        temp->_pow -= other._pow;
    }
    if(temp->_pow == 2 && other._pow == 1){
        temp->_a = 0;
        temp->_b /= other._b;
        temp->_pow -= other._pow;

    }
    if(temp->_pow == 2 && other._pow == 0){
        temp->_b /= other._c;
    }
    return *temp;

}

double solver::solve(RealVariable& x){
    if (x._a != 0) return -x._b/(2*x._a) + std::sqrt(x._b*x._b-4*x._a*x._c)/(2*x._a);
    if (x._b != 0) return -x._c/x._b;
    if (x._c != 0) throw "xation without solution";
    return 0;
}
 std::complex<double> solver::solve(ComplexVariable& x){
    if (x._a != 0){
        std::complex<double> ans ;
        double temp = -x._b/(2*x._a) + std::sqrt(x._b*x._b-4*x._a*x._c)/(2*x._a);
        ans = (temp,0);
        return ans;
    }
    if (x._b != 0){
        std::complex<double> ans ;
        double temp = -x._c/x._b;
        ans = (temp,0);
        return ans;
    }
    if (x._c != 0) throw "xation without solution";
    return std::complex<double>(0,0);
}