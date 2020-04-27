#include "doctest.h"
#include "solver.hpp"
using namespace solver;

#include <string>
using namespace std;



TEST_CASE("test RealVariable") {
    RealVariable x;
    double solution = solve(x==0);
    CHECK(solution==0);//1
    solution = solve(x*2==2);
    CHECK(solution==1);//2
    solution = solve((x^2)-36==0);
    CHECK(solution==6);//3
    solution = solve((x^2)-9==0);
    CHECK(solution==3);//4
    solution = solve((x^2)*12-x-6==0);
     CHECK(solution==0.75);//5
    solution = solve((x^2)-4*x+3==0);
     CHECK(solution==3);//6
    solution = solve((x^2)-x*6==0);
    CHECK(solution==6);//7
    solution = solve((x^2)*4-9==0);
    CHECK(solution==1.5);//8
    solution = solve((x^2)-x==0);
    CHECK(solution==1);//9
    solution = solve(-2*x==-4);
    CHECK(solution==2);//10
    solution = solve(x==1);
    CHECK(solution==1);//11
    solution = solve(x==2);
    CHECK(solution==2);//12
    solution = solve(x==3);
    CHECK(solution==3);//13
    solution = solve(x==4);
    CHECK(solution==4);//14
    solution = solve(x==5);
    CHECK(solution==5);//15
    solution = solve(x==6);
    CHECK(solution==6);//16
    solution = solve(x==7);
    CHECK(solution==7);//17
    solution = solve(x==8);
    CHECK(solution==8);//18
    solution = solve(x==9);
    CHECK(solution==9);//19
    solution = solve(x==-1);
    CHECK(solution==-1);//20
    solution = solve(x==-2);
    CHECK(solution==-2);//21
    solution = solve(x==-3);
    CHECK(solution==-3);//22
    solution = solve(x==-4);
    CHECK(solution==-4);//23
    solution = solve(x==-5);
    CHECK(solution==-5);//24
    solution = solve(x==-6);
    CHECK(solution==-6);//25
    solution = solve(x==-7);
    CHECK(solution==-7);//26
    solution = solve(x==-8);
    CHECK(solution==-8);//27
    solution = solve(x==-9);
    CHECK(solution==-9);//28
    solution = solve(2*x==2);
    CHECK(solution==1);//29
    solution = solve(2*x==-9);
    CHECK(solution==-9);//30
    solution = solve(2*x+8==0);
    CHECK(solution==-4);//31
    solution = solve(4*x+9==0);
    CHECK(solution==-2.25);//32
    solution = solve(80*x+4==0);
    CHECK(solution==-0.05);//33
    solution = solve(2*x+4==6);
    CHECK(solution==1);//34
    solution = solve(10*x==-60);
    CHECK(solution==-6);//35
    solution = solve(-4*x==-36);
    CHECK(solution==9);//36
    solution = solve(7*x==28);
    CHECK(solution==4);//37
    solution = solve((x^2)*4+ 8*x-5==0);
    CHECK(solution==0.5);//38
    solution = solve((x^2)*2==0);
    CHECK(solution==0);//39
    solution = solve(2*x==20);
    CHECK(solution==10);//40
    solution = solve(2*x==30);
    CHECK(solution==15);//41
    solution = solve(2*x==-20);
    CHECK(solution==-10);//42
    solution = solve((x^2)==25);
    CHECK(solution==5);//43
    solution = solve(2*x==40);
    CHECK(solution==20);//44
    solution = solve(2*x==50);
    CHECK(solution==25);//45
    solution = solve(2*x==62);
    CHECK(solution==31);//46
    solution = solve(2*x==48);
    CHECK(solution==24);//47
    solution = solve(2*x==70);
    CHECK(solution==35);//48
    solution = solve(2*x==9);
    CHECK(solution==4.5);//49
    solution = solve(3*x==90);
    CHECK(solution==30);//50
}


TEST_CASE("test imaginary"){
    ComplexVariable y;
    std::complex<double> solution = solve(y+5i == 2*y+3i);
    CHECK(solution==(0,2));//1
    solution = solve(y+6i == 2*y+3i);
    CHECK(solution==(0,3i));//2
    solution = solve(y+7i == 2*y+3i);
    CHECK(solution==(0,4i));//3
    solution = solve(y+8i == 2*y+3i);
    CHECK(solution==(0,5i));//4
    solution = solve(y+8i == 2*y+4i);
    CHECK(solution==(0,4i));//5
    solution = solve(y+4i == 2*y+8i);
    CHECK(solution==(0,4i));//6
    solution = solve(y+10i == 2*y+5i);
    CHECK(solution==(0,5i));//7
    solution = solve(y+10i == 2*y+5i);
    CHECK(solution==(0,5i));//8
    solution = solve(y+11i == 2*y+5i);
    CHECK(solution==(0,6i));//9
    solution = solve(y+12i == 2*y+5i);
    CHECK(solution==(0,7i));//10
    solution = solve(y+13i == 2*y+5i);
    CHECK(solution==(0,8i));//11
    solution = solve(y+14i == 2*y+5i);
    CHECK(solution==(0,9i));//12
    solution = solve(y+15i == 2*y+5i);
    CHECK(solution==(0,10i));//13
    solution = solve(y+16i == 2*y+5i);
      CHECK(solution==(0,11i));//14
      solution = solve(y+17i == 2*y+5i);
      CHECK(solution==(0,12i));//15
      solution = solve(y+18i == 2*y+5i);
      CHECK(solution==(0,13i));//16
      solution = solve(y+19i == 2*y+5i);
      CHECK(solution==(0,14i));//17
      solution = solve(y+20i == 2*y+5i);
      CHECK(solution==(0,15i));//18
      solution = solve(y+21i == 2*y+5i);
      CHECK(solution==(0,16i));//19
      solution = solve(y+21i == 2*y+5i);
      CHECK(solution==(0,16i));//19
      solution = solve(y+21i == 2*y+5i);
      CHECK(solution==(0,16i));//19
      solution = solve(y+21i == 2*y+5i);
      CHECK(solution==(0,16i));//19
      solution = solve(y+21i == 2*y+5i);
      CHECK(solution==(0,16i));//20
      solution = solve(y+22i == 2*y+5i);
      CHECK(solution==(0,17i));//21
      solution = solve(y+23i == 2*y+5i);
      CHECK(solution==(0,18i));//22
      solution = solve(y+24i == 2*y+5i);
      CHECK(solution==(0,19i));//23
      solution = solve(y+25i == 2*y+5i);
      CHECK(solution==(0,20i));//24
      solution = solve(y+26i == 2*y+5i);
      CHECK(solution==(0,21i));//25
      solution = solve(y+27i == 2*y+5i);
      CHECK(solution==(0,22i));//26
      solution = solve(y+28i == 2*y+5i);
      CHECK(solution==(0,23i));//27
      solution = solve(y+29i == 2*y+5i);
      CHECK(solution==(0,24i));//28
      solution = solve(y+30i == 2*y+5i);
      CHECK(solution==(0,25i));//29
      solution = solve(y+31i == 2*y+5i);
      CHECK(solution==(0,26i));//30
      solution = solve(y+32i == 2*y+5i);
      CHECK(solution==(0,27i));//31
      solution = solve(y+33i == 2*y+5i);
      CHECK(solution==(0,28i));//32
      solution = solve(y+34i == 2*y+5i);
      CHECK(solution==(0,29i));//33
      solution = solve(y+35i == 2*y+5i);
      CHECK(solution==(0,30i));//34
      solution = solve(y+36i == 2*y+5i);
      CHECK(solution==(0,31i));//35
      solution = solve(y+37i == 2*y+5i);
      CHECK(solution==(0,32i));//36
      solution = solve(y+38i == 2*y+5i);
      CHECK(solution==(0,33i));//37
      solution = solve(y+39i == 2*y+5i);
      CHECK(solution==(0,34i));//38
      solution = solve(y+40i == 2*y+5i);
      CHECK(solution==(0,35i));//39
      solution = solve(y+41i == 2*y+5i);
      CHECK(solution==(0,36i));//40
      solution = solve(y+42i == 2*y+5i);
      CHECK(solution==(0,37i));//41
      solution = solve(y+43i == 2*y+5i);
      CHECK(solution==(0,38i));//42
      solution = solve(y+44i == 2*y+5i);
      CHECK(solution==(0,39i));//43
      solution = solve(y+45i == 2*y+5i);
      CHECK(solution==(0,40i));//44
      solution = solve(y+46i == 2*y+5i);
      CHECK(solution==(0,41i));//45
      solution = solve(y+47i == 2*y+5i);
      CHECK(solution==(0,42i));//46
      solution = solve(y+48i == 2*y+5i);
      CHECK(solution==(0,43i));//47
      solution = solve(y+49i == 2*y+5i);
      CHECK(solution==(0,44i));//448
      solution = solve(y+50i == 2*y+5i);
      CHECK(solution==(0,45i));//49
      solution = solve(y+51i == 2*y+5i);
      CHECK(solution==(0,46i));//50

}

