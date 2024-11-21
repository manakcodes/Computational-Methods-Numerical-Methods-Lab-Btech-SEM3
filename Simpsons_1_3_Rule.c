#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) ((1) / ((1) + (x * x)))

// aim -> WAP in C for Simpsons's 1/3 Rule

int main(int argc , char *argv[]){
    float a , b , fa , fb , h , k , m , integ = 0.00;
    int i , n;
    printf("\n\tSIMPSON'S 1/3 RULE\t\n");
    printf("\nenter the lower - limit of the integral (a) : ");
    scanf("%f" , &a);
    printf("\nenter the upper - limit of the integral (b) : ");
    scanf("%f" , &b);
    printf("\nenter the number of sub - intervals (n) : ");
    scanf("%d" , &n);
    if (n % 2 != 0){
        printf("\ninvalid number of sub - intervals\n");
        return -1;
    }
    h = ((b - a) / n);
    fa = f(a);
    fb = f(b);
    m = fa + fb;
    for (int i = 1 ; i <= n - 1 ; i++){
        k = a + i * h;
        if (i % 2 == 0){
            m = m + 2 * f(k);
        }
        else{
            m = m + 4 * f(k);
        }
    }
    integ = ((h / 3) * (m));
    printf("\nrequired value of integral (simpsons 1/3 rule) : \n%f\n" , integ);
    return 0;
}