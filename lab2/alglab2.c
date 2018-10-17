#include <stdio.h>
#include <math.h>

int main()
{
     float a;
     int n = 0;
     float s = 0;
     for(n = 0 ; ; n++)
     {
         a = 1/pow(2,n)+1/pow(3,n);
         s+=a;
         if(a > 0.0001)
            printf("%f\n", a);
         else
            break;
     }
     printf("Sum is:%f\n", s-a);
     return 0;
}