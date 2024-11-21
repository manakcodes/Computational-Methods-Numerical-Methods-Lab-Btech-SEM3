#include <stdio.h>
#include<stdlib.h>
#define F(x, y) ((y * y - x * x) / (y * y + x * x))

void runge_kutta(double * , double * , double);

int main() {
    double x = 0, y = 1, h = 0.2;
    for (int i = 1; i <= 2; i++) {
        runge_kutta(&x, &y, h);
    }
    printf("x = %.2lf, y = %.4lf\n", x, y);
    printf("\n\n\tINFO : \n\n");
    printf("\tNAME : manak\t");
    printf("\n\tCLASS : CSE - AIML (3rd sem)\t\n");
    printf("\tROLL NO. : 04613215623\t\n");
    return 0;
}

void runge_kutta(double *x, double *y, double h) {
    double k1, k2, k3, k4;
    k1 = h * F(*x, *y);
    k2 = h * F(*x + h / 2, *y + k1 / 2);
    k3 = h * F(*x + h / 2, *y + k2 / 2);
    k4 = h * F(*x + h, *y + k3);
    
    *y = *y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    *x = *x + h;
}

