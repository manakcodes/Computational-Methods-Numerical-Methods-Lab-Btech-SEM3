#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 10

int main(int argc , char *argv[]){
     printf("\n\tGAUSS ELIMINATION\t\n");
    float a[size][size] , x[size] , ratio;
    int i , j , k , n;
    printf("\nenter the number of unknowns : ");
    scanf("%d" , &n);
    printf("\nenter the MATRIX below : \n");
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n + 1 ; j++){
            printf("\na[%d][%d] : " , i + 1 , j + 1);
            scanf("%f" , &a[i][j]);
        }
    }
    for (int i = 0 ; i < n - 1 ; i++){
        if (a[i][i] == 0){
            printf("\nzero on diagonal error\n");
            return -1;
        }
        for (int j = i + 1 ; j < n ; j++){
            ratio = a[j][i] / a[i][i];
            for (int k = 0 ; k < n ; k++){
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (int i = n - 2 ; i >= 0 ; i--){
        x[i] = a[i][n];
        for (int j = i + 1 ; j < n ; j++){
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    printf("\nsolution : \n");
    for (int i = 0 ; i < n ; i++){
        printf("x[%d] : %f\n" , i + 1 , x[i]);
    }
    return 0;
}