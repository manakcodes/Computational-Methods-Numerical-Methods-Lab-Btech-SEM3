#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) ((1) / ((1) + (x * x)))

// aim -> WAP in C for Trapezoidal Rule

/*

aim -> 
WAP in C for Trapezoidal Rule

formula -> 
h = ((b - a) / n)
h = height of intervals
b = upperLimit of integral
a = lowerLimit of integral
n = number of sub intervals

I = integral of function f(x) from lowerLimit (a) to uperLimit (b)
I = (h / 2) * (f(a) + f(b) + (2 * sum of f(xi) from i = 1 to i <= n - 1))

I = (h / 2) * (f(a) + f(b) + (2 * (sigma f(xi) [i = 1 ; i <= n - 1])))

theory ->
the trapezoidal rule is a numerical method to approximate the definite integral 
of a function , it works by dividing the interval of integration into smaller 
subintervals , approximating the area under the curve as a series of trapezoids 
and summing their areas

formula used ->
h = ((b - a) / n)
h -> height of interval
b -> upper limit of integral
a -> lower limit of intergral
n -> no of intervals

"you can take any number of n for trapezoidal rule"

I = integral of function f(x) from lowerLimit (a) to upperLimit (b)
let number of sub intervals = n be 5
then we calculate 6 values from x0 to x5 like x0 , x1 , x2 , x3 , x4 , x5 , x6

we calculate the following terms

for values of x                 value of func y = f(x)

x0 = a + h                      y0 = (fx0)
x1 = x0 + h                     y1 = f(x1)
x2 = x1 + h                     y2 = f(x2)
x3 = x2 + h                     y3 = f(x3)
x4 = x3 + h                     y4 = f(x4)
x5 = x4 + h                     y5 = f(x5)

now h = ((b - a) / n)

now we calculate the integral as -> 
    I = (h / 2) * (y0 + y5 + 2 * (y1 + y2 + y3 + y4))

PSEUDOCODE -> 

    define  float -> a , b , fa , fb , h , k , m , integ
    a = lowerLimit of integral
    b = upperLimit of integral
    fa = f(a) = value of function at a
    fb = f(b) = value of function at b
    h = height of interval
    k = x0 , x1......xn
    m = sum of terms
    integ = final expression
    
*/

int main(int argc , char *argv[]){
    float a , b , fa , fb , h , k  ,m , integ = 0.00;
    int i , n;
    printf("\n\tTRAPEZOIDAL RULE\t\n");
    printf("\nenter the lower - limit of the integral (a) : ");
    scanf("%f" , &a);
    printf("\nenter the upper - limit of the integral (b) : ");
    scanf("%f" , &b);
    printf("\nenter the number of sub - intervals (n) : ");
    scanf("%d" , &n);
    h = ((b - a) / n);
    fa = (fa);
    fb = (fb);
    m = f(a) + f(b);
    for (int i = 1 ; i <= n - 1 ; i++){
        k = a + i * h;
        m = m + 2 * f(k);
    }
    integ = ((h / 2) * m);
    printf("\nrequired value of integration (trapezoidal rule) : \n%f\n" , integ);
    return 0;
}