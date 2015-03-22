/*
INPUT: Function f, endpoint values a, b, tolerance TOL, maximum iterations NMAX
CONDITIONS: a < b, either f(a) < 0 and f(b) > 0 or f(a) > 0 and f(b) < 0
OUTPUT: value which differs from a root of f(x)=0 by less than TOL

N ← 1
While N ≤ NMAX # limit iterations to prevent infinite loop
  c ← (a + b)/2 # new midpoint
  If f(c) = 0 or (b – a)/2 < TOL then # solution found
    Output(c)
    Stop
  EndIf
  N ← N + 1 # increment step counter
  If sign(f(c)) = sign(f(a)) then a ← c else b ← c # new interval
EndWhile
Output("Method failed.") # max number of steps exceeded
*/

#include <stdio.h>
#include <cmath>
//#include <stdlib.h>

#define DEBUG


int sign(double x) {
    return x > 0;
}


double f(double x) {
        return x*3 + 5;
}

double g (double x) {
        return x*x + 7*x - 200;
}

double find_root_by_bisection (
        double (*f)(double), double x1,
        double x2, double TOL
        ){
    const int NMAX = 100;
    int i;
    for (i = 0; i < NMAX; i++) {

        double vx1 = (*f)(x1);
        double vx2 = (*f)(x2);
        double xnew = (x1 + x2)/2.0;
        double vnew = (*f)(xnew);
    #ifdef DEBUG
                printf ("f(%lf) == %lf, f(%lf) == %lf\n ", x1, vx1, x2, vx2);
    #endif
        if (std::abs(vnew) < TOL) {
           // printf("Test %lf", abs(vnew));
            break;

        }
        if (sign(vnew) == sign(vx1)) x1 = xnew;
        else x2 = xnew;

    } // for
        return (x1 + x2)/2.0;
}


int main()
{
    double (*pF)(double);
    pF = f;
    printf("Function F (2) == %lf\n", (*pF)(2.0));

    pF = g;
    printf("Funciton G (2) == %lf\n", (*pF)(2.0));

    double xroot = find_root_by_bisection(f, -10, 10, 0.001);
    printf ("f (%lf) = %lf\n", xroot, f(xroot));

    return 0;
}
