#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// aim -> WAP in C for Lagranges Interpolation

int main(int argc , char *argv[]){
     printf("\n\tLAGRANGES INTERPOLATION\t\n");
    float x[100] , y[100] , a = 0.00 , s = 1.00 , t = 1.00 , k = 0.00;
    int n , i , j;
    printf("\nenter the number of terms of the table : ");
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; i++){
        printf("x[%d] : " , i);
        scanf("%f" , &x[i]);
        printf("y[%d] : " , i);
        scanf("%f" , &y[i]);
    }
    printf("\nenter the value of 'x' to find the respective value of 'y' : ");
    scanf("%f" , &a);
    for (int i = 0 ; i < n ; i++){
        s = 1.00;
        t = 1.00;
        for (int j = 0 ; j < n ; j++){
            if (j != i){
                s = s * (a - x[j]);
                t = t * (x[i] - x[j]);
            }
        }
        k = k + ((s / t) * y[i]);
    }
    printf("\nrespective value of 'y' is %f at 'x' = %f\n" , a , k);
    printf("\n(x , y) : (%f , %f)" , a , k);
    return 0;
}