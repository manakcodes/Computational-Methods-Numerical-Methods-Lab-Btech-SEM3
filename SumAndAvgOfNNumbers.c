#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc , char *argv[]){
    printf("\n\tSUM AND AVERAGE OF N NUMBERS ENTERED BY THE USER\t\n");
    int n = 0;
    float data = 0;
    float sum = 0.00;
    float avg = 0.00;
    printf("\nhow many numbers you want to enter : ");
    scanf("%d" , &n);
    printf("\nenter numbers below : \n");
    for (int i = 0 ; i < n ; i++){
        printf("\nenter numer [%d] : " , i + 1);
        scanf("%f" , &data);
        sum += data;
    }
    printf("sum : %f\navg :%f\n\n" , sum , sum / n);
    return 0;
}