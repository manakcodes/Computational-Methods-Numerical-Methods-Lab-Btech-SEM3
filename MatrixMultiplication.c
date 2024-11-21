#include<stdio.h>
#include<stdlib.h>


int main(int argc , char *argv[]){
    int rows1 = 0;
    int cols1 = 0;
    printf("\nenter the rows and cols of MATRIX 1 : ");
    scanf("%d %d" , &rows1 , &cols1);
    int rows2 = 0;
    int cols2 = 0;
    printf("\nenter the rows and cols or MATRIX 2 : ");
    scanf("%d %d" , &rows2 , &cols2);
    if (cols1 != rows2){
        printf("\nthe MATRIX cannot be multiplied\n");
        printf("\ncols of MATRIX 1 != rows of marix 2\n");
        printf("\nonly m x n and n x p matrix can be multiplied\n");
        printf("\nthe resultant would be of n x p\n");
        return -1;
    }
    printf("\nyou chose to multiply MATRIX 1 : %d x %d\nwith MATRIX 2 : %d x %d\n" , rows1 , cols1 , rows2 , cols2);
    printf("the resultant matrix would be of order %d x %d\n\n" , rows1 , cols2);
    int **arr1 = (int **)(malloc(rows1 * sizeof(int *)));
    for (int i = 0 ; i < rows1 ; i++){
        arr1[i] = (int *)(malloc(cols1 * sizeof(int *)));
    }
    int **arr2 = (int **)(malloc(rows2 * sizeof(int *)));
    for (int i = 0 ; i < rows2 ; i++){
        arr2[i] = (int *)(malloc(cols2 * sizeof(int *)));
    }
    printf("\nenter the elements of MATRIX 1 below : \n");
    for (int i = 0 ; i < rows1 ; i++){
        for (int j = 0 ; j < cols1 ; j++){
            scanf("%d" , &arr1[i][j]);
        }
    }
    printf("\nenter the elements of MATRIX 2 below : \n");
    for (int i = 0 ; i < rows2 ; i++){
        for (int j = 0 ; j < cols2 ; j++){
            scanf("%d" , &arr2[i][j]);
        }
    }
    printf("\nMATRIX 1 : \n");
    for (int i = 0 ; i < rows1 ; i++){
        printf("\n");
        for (int j = 0 ; j < cols1 ; j++){
            printf("%d\t" , arr1[i][j]);
        }
    }
    printf("\nMATRIX 2 : \n");
    for (int i = 0 ; i < rows2 ; i++){
        printf("\n");
        for (int j = 0 ; j < cols2 ; j++){
            printf("%d\t" , arr2[i][j]);
        }
    }
    int **res = (int **)(malloc(rows1 * sizeof(int *)));
    for (int i = 0 ; i < rows1 ; i++){
        res[i] = (int *)(malloc(cols2 * sizeof(int *)));
    }
    for (int i = 0 ; i < rows1 ; i++){
        for (int j = 0 ; j < cols2 ; j++){
            res[i][j] = 0;
            for (int k = 0 ; k < cols1 ; k++){
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("\nproduct of MATRIX 1 and MATRIX 2 : \n");
    for (int i = 0 ; i < rows1 ; i++){
        printf("\n");
        for (int j = 0 ; j < cols2 ; j++){
            printf("%d\t" , res[i][j]);
        }
    }
    for (int i = 0 ; i < rows1 ; i++) {
        free(arr1[i]);
    }
    free(arr1);

    for (int i = 0 ; i < rows2 ; i++) {
        free(arr2[i]);
    }
    free(arr2);

    for (int i = 0 ; i < rows1 ; i++) {
        free(res[i]);
    }
    free(res);
    return 0;
}