#include<stdio.h>
#include<cs50.h>
#include<time.h>
void printmat(int A[100][100], int *a, int *b)
{
    for(int i = 0 ; i < *a ; i++)
    {
        for(int j = 0 ; j < *b ; j++)
        {
            A[i][j] = rand()%90+10;
            printf("%i ", A[i][j]);
        }
        printf("\n");
    }
}

void check_max_min(int A[100][100], int r, int c)
{
    int max[r];
    int index = 0;
    int check;
    for(int i = 0 ; i < r ; i++)
    {
        max[i] = A[i][0];
        index = 0;
        for(int j = 0 ; j < c ; j++)
        {
            if(A[i][j] > max[i])
                {
                    max[i] = A[i][j];
                    index = j;
                }
        }
        //printf("|%i|", max[i]);
        //printf("|%i|", index);
        check = 1;
        for(int k = 0; k < r ; k++)
        {
            if(max[i] < A[k][index])
                {
                    check++;
                    //printf("%i", check);
                }
                
        } 
        //printf("\t");
        if(check == r)
            printf("{%i}", max[i]);
    }
}

void check_min_max(int A[100][100], int r, int c)
{
    int max[c];
    int index = 0;
    int check;
    for(int i = 0 ; i < c ; i++)
    {
        max[i] = A[0][i];
        index = 0;
        for(int j = 0 ; j < r ; j++)
        {
            if(A[j][i] > max[i])
                {
                    max[i] = A[j][i];
                    index = j;
                }
        }
        //printf("|%i|", max[i]);
        //printf("|%i|", index);
        check = 1;
        for(int k = 0; k < c ; k++)
        {
            if(max[i] < A[index][k])
                {
                    check++;
                    //printf("%i", check);
                }
                
        } 
        //printf("\t");
        if(check == c)
            printf("{%i}", max[i]);
    }
}

int main(void)
{
    int a;
    printf("Enter count of raws:");
    scanf("%i",&a);
    int b;
    printf("Enter count of colums:");
    scanf("%i",&b);
    int arr[a][b];
    srand(time(NULL));
    
    printmat(arr,&a,&b);
    printf("Sadle point(s): ");
    check_max_min(arr,a,b);
    check_min_max(arr,a,b);
    printf("\n");
}
