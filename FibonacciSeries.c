#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int IterativeFibonacci(int);
int RecursiveFibonacci(int);

int main(int argc , char *argv[]){
    int choice = 0;
    printf("\n\tFIBONACCI SERIES\t\n");
    printf("\n\nMAIN MENU\n\n");
    printf("1.Iterative Method\n2.Recursive Method\n3.EXIT\n\n");
    printf("enter choice (1 / 2 / 3) : ");
    scanf("%d" , &choice);
    if (choice != 1 && choice != 2 && choice != 3){
        printf("\ninvalid choice\n");
        return -1;
    }
    if (choice == 3){
        printf("\nEXIT\n");
        return -1;
    }
    else{
        int n = 0;
        printf("enter a number till you want to print fibonacci series for : ");
        scanf("%d" , &n);
        if (choice == 1){
            for (int i = 0 ; i <= n ; i++){
                printf("%d , " , IterativeFibonacci(i));
            }
        }
        else if (choice == 2){
            for (int i = 0 ; i <= n ; i++){
                printf("%d , " , RecursiveFibonacci(i));
            }
        }
    }
    return 0;
}


int IterativeFibonacci(int n){
    if (n <= 1){
        return n;
    }
    int firstTerm = 0;
    int secondTerm = 1;
    int nextTerm = 0;
    for (int i = 2 ; i <= n ; i++){
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
    return nextTerm;
}


int RecursiveFibonacci(int n){
    if (n <= 1){
        return 1;
    }
    return (RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2));
}