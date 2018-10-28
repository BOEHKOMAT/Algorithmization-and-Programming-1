#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int a;
    printf("Enter count of raws:");
    scanf("%i",&a);
    int b;
    printf("Enter count of colums:\n");
    scanf("%i",&b);
    int arr[a][b], max[2][a], min[2][b], maxi[2][b], mini[2][a];
    int c, d;
    for(c = 0 ; c < a ; c++)
    {
        for(d = 0 ; d < b ; d++)
        {
            arr[c][d]=rand()%9000+1000;
            printf("|%i|", arr[c][d]);
        }
        printf("\n");
    }
    printf("\n");
    for(c = 0 ; c < a ; c++)
    {
        max[0][c] = arr[c][0];
        max[1][c] = 0;
        for(d = 0 ; d < b ; d++)
        {
            if(arr[c][d] > max[0][c])
                {
                    max[0][c] = arr[c][d];  //max in raws
                    max[1][c] = c;
                }
        }
    }
    for(d = 0 ; d < b ; d++)
    {
        min[0][d] = arr[0][d];
        min[1][d] = 0;
        for(c = 0 ; c < a ; c++)
        {
            if(arr[c][d] < min[0][d])
                {
                    min[0][d] = arr[c][d];  //min in columns
                    min[1][d] = c;
                }
        }
    }
    
    
    for(c = 0 ; c < b  ; c++)
    {
        for(d = 0 ; d < b ; d++)
        {
            if((max[0][c] == min[0][d]) && (max[1][c] == min[1][c]))    //find out a sadle point
                {
                    printf("\n|%i|\n", max[0][c]);
                }
        }
    }
    
   /* for(c = 0 ; c < a ; c++)
        {
            printf("|%i|", max[0][c]);
            printf("|%i|", max[1][c]);
        }
        printf("\n");
    for(d = 0 ; d < b ; d++)
        {
            printf("|%i|", min[0][d]);
            printf("|%i|", min[1][d]);
        }
        printf("\n");*/
    
    for(d = 0 ; d < b ; d++)
    {
        maxi[0][d] = arr[0][d];
        maxi[1][d] = 0;
        for(c = 0 ; c < a ; c++)
        {
            if(arr[c][d] > maxi[0][d])
                {
                    maxi[0][d] = arr[c][d];  //max in columns
                    maxi[1][d] = d;
                }
        }
    }
    for(c = 0 ; c < a ; c++)
    {
        mini[0][c] = arr[c][0];
        mini[1][c] = 0;
        for(d = 0 ; d < b ; d++)
        {
            if(arr[c][d] < mini[0][c])
                {
                    mini[0][c] = arr[c][d];  //min in raws
                    mini[1][c] = d;
                }
        }
    }
    
   /* for(c = 0 ; c < a ; c++)
        {
            printf("|%i|", mini[0][c]);
            printf("|%i|", mini[1][c]);
        }
        printf("\n");
    for(d = 0 ; d < b ; d++)
        {
            printf("|%i|", maxi[0][d]);
            printf("|%i|", maxi[1][d]);
        }
        printf("\n");*/
    
    for(d = 0 ; d < b  ; d++)
    {
        for(c = 0 ; c < a ; c++)
        {
            if((maxi[0][d] == mini[0][c]) && (maxi[1][d] == mini[1][c]))    //find out a sadle point
                {
                    printf("\n|%i|\n", maxi[0][d]);
                }
        }
    }
}