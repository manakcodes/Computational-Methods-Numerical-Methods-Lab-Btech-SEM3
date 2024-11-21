#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) ((cos(x) - (x * exp(x))))

int main(int argc , char *argv[]){
    float x0 , x1  ,x2 , fx0 , fx1  ,fx2 , e = 0.001;
    int i = 0;
    printf("\n\tSECANT METHOD\t\n");
    printf("\nenter the value of x0 and x1 : ");
    scanf("%f %f" , &x0 , &x1);
    do{
        fx0 = f(x0);
        fx1 = f(x1);
        x2 = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);
        fx2 = f(x2);
        fx0 = fx1;
        fx1 = fx2;
        x0 = x1;
        x1 = x2;
        i++;
        printf("\niteration : %d\tvalue of the function : %f\troot :%f\t\n" , i , fx2 , x2);
    } while (fabs(fx2) >= e);
    printf("\nhence the root is : %f\n" , x2);
    return 0;
}