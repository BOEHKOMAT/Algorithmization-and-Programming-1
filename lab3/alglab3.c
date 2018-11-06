#include <stdio.h>
#include <math.h>
#define M_PI 3.1415926
#define EPS 0.0001

long long fact(int x)
{
    if(x == 0 || x == 1)
        {
            return 1;
        }
    else 
        {
            return x*fact(x-1);
        }
}

int main(void)
{
    double SE = 0, SE1 = 0, SN = 0, SN1 = 0, n = 0;
    double y;
    float x = 0.1, e = 2.71;
    
    for(x = 0.1; x <= 1; x += 0.09)
    {
        y = pow(e,x * cos(M_PI / 4)) * cos(x * sin(M_PI / 4));
        for(n = 0, SN = 0; n < 25; n++)
        {
            SN1 = ((cos(n * M_PI / 4)) / fact(n)) * pow(x,n);
            SN += SN1;
        }
        n = 0;
        SE = 0;
        do
        {
            SE1 = ((cos(n * M_PI / 4)) / fact(n)) * pow(x,n);
            SE += SE1;
            n++;
        }
        while(SE1 > EPS);
        printf("X=%.2f\tSN=%f\tSE=%f\tY=%f\n", x, SN, SE, y);
    }
}
