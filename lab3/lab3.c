#include <stdio.h>
#include <math.h>
#define M_PI 3.1415926

int main(void)
{
    long long f = 1;
    long double SN = 0, SE = 0, n = 0;
    double y;
    float x = 0.1, e = 2.71, x1 = 0.09, epsilon = 0.0001;
       
    for(int c = 0; c<25; c++)
    {
        if(x < 1)
            {
                printf("X=%.2f\t", x);
            }
        else
            {
                printf("\t");
            }
        f *= c;
        if(f == 0)
            {
                f = 1;
            }
        SN = ((cos(n * M_PI / 4)) / f) * pow(x1,n);
        printf("SN=%.20Lf\t", SN);
        SE = ((cos(n * M_PI / 4)) / f) * pow(x1,n);
        if(SE>epsilon)
            {   
                printf("SE=%.4Lf\t", SE);
            }
        else
            {
                printf("\t\t");
            }
        y = pow(e,x * cos(M_PI / 4)) * cos(x * sin(M_PI / 4));
        if(x < 1)
            {
                printf("Y=%.5f\n", y);
            }
        else
            printf("\n");
        x += 0.09;
    }
}