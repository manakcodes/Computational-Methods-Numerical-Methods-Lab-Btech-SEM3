#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) ((x * x * x) - (4 * x) - (9))

int main(int argc , char *argv[]){
    float a , b , x1 , fa , fb  ,fx1 , e = 0.001;
    int i = 0;
    printf("\n\tBISECTION METHOD\t\n");
    printf("\nenter two initial guesses : ");
    scanf("%f %f" , &a , &b);
    fa = f(a);
    fb = f(b);
    if (fa * fb > 0){
        printf("\nincorrect initial guess\n");
        return -1;
    }
    else{
        do{
            x1 = ((a + b) / 2);
            fx1 = f(x1);
            if (fx1 < 0){
                a = x1;
            }
            else{
                b = x1;
            }
            i++;
            printf("\niteration : %d\tvalue of the function : %f\troot : %f\t\n" , i , x1 , fx1);
        } while (fabs(b - a) >= e);
    }
    return 0;
}