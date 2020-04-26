#include <iostream>


namespace solver{
    
    class RealVariable{
        private:
        double _a;
        double _b;
        double _c;
        
        public:
        RealVariable(){
            _a = _b = _c = 0;
        }
        RealVariable& operator*(double num);
        RealVariable& operator-(double num);
        RealVariable& operator+(double num);
        RealVariable& operator+(RealVariable& other);
        RealVariable& operator-(RealVariable& other);
        RealVariable& operator==(double num);
        RealVariable& operator==(RealVariable& other);
        RealVariable& operator^(double num);
        RealVariable& operator/(double num);
        friend RealVariable& operator*(double num, RealVariable& x);
        friend RealVariable& operator+(double num, RealVariable& x);
    };
    class ComplexVariable{
        private:
        std::complex<double> _a;
        std::complex<double> _b;
        std::complex<double> _c;
        
        public:
        ComplexVariable(){
            _a = _b = _c = 0;
        }
        ComplexVariable& operator*(double num);
        ComplexVariable& operator-(double num);
        ComplexVariable& operator+(double num);
        ComplexVariable& operator+(ComplexVariable& other);
        ComplexVariable& operator+(std::complex<double> other);
        ComplexVariable& operator-(ComplexVariable& other);
        ComplexVariable& operator==(double num);
        ComplexVariable& operator==(ComplexVariable& other);
        ComplexVariable& operator^(double num);
        ComplexVariable& operator/(double num);
        friend ComplexVariable& operator*(double num, ComplexVariable& x);
        friend ComplexVariable& operator+(double num, ComplexVariable& x);
    };

    static double solve(RealVariable x);
    static ComplexVariable solve(ComplexVariable x);
    
}
