#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int x, x1, i;
    printf("Enter x:\n");
    scanf("%i", &x);
    int M[x];
    int N[x];
    int a = 0;
    
    for(i = 0;i<x;i++)
        {
            M[i]=N[i];
            M[i] = rand()%100;
            printf("|%i|", M[i]);
        }
    
    printf("\n");
    printf("Choose array element to remove it:\n");
    scanf("%i",&x1);
    
    M[x1] = 0;
    
    for(i = 0;i<x;i++)
    {
        if(x1 != i)
            printf("|%i|", M[i]);
        else
            continue;
    }
    printf("\n");
    
    i = 0;
    printf("Array with added element followed after the first paired element:\n");
    do
    {   
        if(M[i]%2!=0)
            {
                printf("|%i|", M[i]);
                i++;
            }
        else if(M[i]%2==0&&x1==i)
            {
                a++;
                i++;
                break;
            }
        else
            { 
                N[i+1]=M[i-1]+2;
                printf("|%i|", M[i]);
                printf("|%i|", N[i+1]);
                i++;
                break;
            }
    }
    while(true);
    do
    {   
        if(a == 0)
            {
                if(x1 != i)
                {
                    printf("|%i|", M[i]);
                    i++;
                }
                else
                {
                    i++;
                    continue;
                }
            }
        else
            {
                if(M[i]%2!=0)
                    {
                        printf("|%i|", M[i]);
                        i++;
                    }
                else
                    { 
                        N[i+1]=M[i-1]+2;
                        printf("|%i|", M[i]);
                        printf("|%i|", N[i+1]);
                        i++;
                        do
                        {
                            printf("|%i|", M[i]);
                            i++;
                        }
                        while(i < x);
                        break;
                    }
            }
    }
    while(i < x);
    printf("\n");
}