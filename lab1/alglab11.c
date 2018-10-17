#include <stdio.h>
#include <math.h>

int main(void)
{
    int a = 1000;
    float b = 0.0001;
    double c;
    c = (pow(a - b,3)) - (pow(a,3) - 3 * a * pow(b,2)) / (pow(b,3) - 3 * pow(a,2) * b);
    printf("%f\n",c);
}