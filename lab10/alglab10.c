#include <stdio.h>
#include <cs50.h>
#include <time.h>

int **CreateMatrix(int *rows, int *cols)
{
    int **arr;
    arr = (int**)malloc(*(rows)*sizeof(int*));
    for(int i = 0 ; i < *rows ; i++)
    {
        arr[i]=(int*)malloc(*(cols)*sizeof(int));
    }
    return arr;
}

void FillMatrix(int **arr, int *rows, int *cols)
{
    for(int i = 0 ; i < *rows ; i++)
    {
        for(int j = 0 ; j < *cols ; j++)
        {
            arr[i][j] = rand()%10;
        }
    }
}

void PrintMatrix(int **arr, int *rows, int *cols)
{
    for(int i = 0 ; i < *rows ; i++)
    {
        for(int j = 0 ; j < *cols ; j++)
        {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
}

void DeleteRow(int **arr, int d, int *rows, int *cols)
{
    free(arr[d]);
    arr[d] = NULL;
    for(int i = 0 ; i < *rows ; i++)
    {
        if(i == d)
            continue;
        for(int j = 0 ; j < *cols ; j++)
        {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int rows, cols;
    
    srand(time(NULL));
    
    printf("Enter count of rows: ");
    scanf("%i",&rows);
    
    printf("Enter count of columns: ");
    scanf("%i",&cols);
    
    int **arr; 
    arr = CreateMatrix(&rows,&cols);
    FillMatrix(arr,&rows,&cols);
    PrintMatrix(arr,&rows,&cols);
    
    int del_row;
    printf("Choose row to delete: ");
    scanf("%i",&del_row);
    DeleteRow(arr,del_row,&rows,&cols);
    
    for(int i = 0 ; i < rows ; i++)
    {
        free(arr[i]);
    }
    free(arr);
}
