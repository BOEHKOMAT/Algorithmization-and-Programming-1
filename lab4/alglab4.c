#include<stdio.h>
#include<cs50.h>
#include<time.h>
void pmas(int E[], int e)
{
    for(int i = 0; i < e; i++)
    {
        printf("|%i|", E[i]);
    }
    printf("\n");
}

void del(int E[], int e, int d)
{
    for(int i = 0; i < e; i++)
    {
        if(i >= d)
            {
                E[i] = E[i+1];
            }
    }
}

void equal(int A[], int B[], int s)
{
    for(int i = 0 ; i < s ; i++)
    {
        B[i] = A[i];
    }
    printf("\n");
}

int main(void)
{
    srand(time(NULL));
    int x, x1, i;
    printf("Choose size of array: ");
    scanf("%i", &x);
    int M[x];
    int N[x-1];
    
    for(i = 0; i < x; i++)
        {
            M[i] = rand()%20;
        }
    pmas(M,x);
    
    printf("Choose array element to remove it: ");
    scanf("%i",&x1);
    
    del(M,x,x1);
    equal(M,N,x-1);
    pmas(M,x-1);
    
    printf("|%i|", M[0]);
    for(i = 1 ; i < x ; i++)
    {
        if(M[i] == 0)
            {
                continue;
            }
        else if(M[i] % 2 != 0)
            {
                printf("|%i|", M[i]);
            }
        else
            {
                printf("|%i|", M[i]);
                M[i+1] = M[i-1] + 2;
                printf("|%i|", M[i+1]);
                for(int j = i + 1 ; j < x - 1 ; j++)
                {
                    printf("|%i|", N[j]);
                }
                break;
            }
    }
    printf("\n");
}
