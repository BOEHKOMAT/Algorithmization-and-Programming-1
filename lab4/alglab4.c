#include<stdio.h>
#include<cs50.h>
#include<time.h>

void pmas(int *E, int e)
{
    for(int i = 0; i < e; i++)
    {
        printf("|%i|", E[i]);
    }
    printf("\n");
}

void del(int *M, int e, int d)
{
    for(int i = 0; i < e; i++)
    {
        if(i >= d)
            {
                M[i] = M[i+1];
            }
    }
}

void add(int *M, int *N, int length)
{
    N[0] = M[0];
    for(int i = 1 ; i < length ; i++)
    {
        if(M[i] == 0 || M[i] % 2 != 0)
        {
            N[i] = M[i];
        }    
        else
        {
            N[i]=M[i];
            N[i+1] = M[i-1]+2;
            for(int j = i+2 ; j < length+1; j++)
            {
                N[j] = M[j-1];
            }
            break;
        }
    }
}

int main(void)
{
    srand(time(NULL));
    int x, x1, i;
    do
    {
        printf("Choose size of array: ");
        scanf("%i", &x); 
    }
    while(x < 0);
    int M[x];
    int N[x];
    
    for(i = 0; i < x; i++)
        {
            M[i] = rand()%20;
        }
    pmas(M,x);
    
    do
    {
        printf("Choose array element to remove it: ");
        scanf("%i",&x1);
    }
    while(x < 0);
    del(M,x,x1);
    pmas(M,x-1);
    add(M,N,x);
    pmas(N,x);
}
