#include <stdio.h>
#include <math.h>


int main()
{
    int m, n, R1, R2, R3;
    printf("Enter m\n");
    scanf("%i",&m);
    printf("Enter n\n");
    scanf("%i",&n);
    
    R1 = m - ++n;
    R2 = ++m>--n;
    R3 = --n<++m;
    
    printf("Result1:%i\nResult2:%i\nResult3:%i\n", R1, R2, R3);
    
    return 0;
}
