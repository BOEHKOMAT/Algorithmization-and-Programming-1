#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    int m,n,Result;
    printf("Enter m\n");
    m = GetInt();
    printf("Enter n\n");
    n = GetInt();
    Result = m-(++n);
    printf("%d\n", Result);
    if(++m>--n)
        printf("True\n");
    else
        printf("False\n");
    if(--n<++m)
        printf("True\n");
    else
        printf("False\n");    
    return 0;    
}