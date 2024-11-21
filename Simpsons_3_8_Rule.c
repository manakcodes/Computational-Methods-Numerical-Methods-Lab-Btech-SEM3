#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) ((1) / ((1) + (x * x)))

// aim -> WAP in C for Simpson's 3/8 Rule

int main(int argc , char *argv[]){
    float a , b , fa , fb , h , k , m , integ = 0.00;
    int i , n;
    printf("\n\tSIMPSON'S 3/8 RULE\t\n");
    printf("\nenter the lower - limit of the integral (a) : ");
    scanf("%f" , &a);
    printf("\nenter the upper - limit of the integral (b) : ");
    scanf("%f" , &b);
    printf("\nenter the number of sub - intervals (n) : ");
    scanf("%d" , &n);
    if (n % 3 != 0){
        printf("\ninvalid number of sub - intervals\n");
        return -1;
    }
    h = ((b - a) / n);
    fa = f(a);
    fb = f(b);
    m = fa + fb;
    for (int i = 1 ; i <= n - 1 ; i++){
        k = a + i * h;
        if (i % 3 == 0){
            m = m + 2 * f(k);
        }
        else{
            m = m + 3 * f(k);
        }
    }
    integ = (((3 * h) / 8) * (m));
    printf("\nrequired value of integration (simpsons's 3/8 rule) : \n%f\n" , integ);
    return 0;
}