#include <iostream>
#include <complex>


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

    };

    static double solve(RealVariable x);
    static std::complex<double> solve(ComplexVariable x);


    RealVariable& operator*(double num, RealVariable& x);
    RealVariable& operator+(double num, RealVariable& x);

    ComplexVariable& operator*(double num, ComplexVariable& x);
    ComplexVariable& operator+(double num, ComplexVariable& x);
}
