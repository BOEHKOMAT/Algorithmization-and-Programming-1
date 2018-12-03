#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define DL 256
void create_file(FILE *f,int rows)
{
    char buffer[DL];
    printf("Put %i strings in F1.txt:\n", rows);
    for(int i = 0; i < rows; i++)
    {
        fgets(buffer,DL,stdin);
        if (buffer[strlen(buffer)-1]!='\n')
        {
            buffer[strlen(buffer)]='\n';
            buffer[strlen(buffer)+1]='\0';
        }
        fputs(buffer,f);
    }
    rewind(f);
}

void print(FILE *f)
{
    int rows = 1;
    char buffer[DL];
    while(1)
    {
        fgets(buffer,DL,f);
        if(feof(f))break;
        printf("%i. %s", rows++, buffer);
    }
    rewind(f);
}

void copy(FILE *f1, FILE *f2, int n, int k)
{
    char buffer[DL];
    int i = 0;
    while (i != k)
    {
        if(i < n)
        {
            if((fgets (buffer, DL, f1))!=NULL);
            i++;
        }
        else
        {
            if((fgets (buffer, DL, f1))!=NULL)
            fputs(buffer,f2);
            i++;
        }
    }
}

int is_loud(char c)
{
    if(c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u' || c == 'y' || c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'U' || c == 'Y')
        return 1;
    else 
        return 0;
}

void check(FILE *f)
{
    int counter = 0;
    char buffer[DL] = {};
    char el[DL];
    while(1)
    {
        fgets(el,DL,f);
        if(feof(f))break;
        strcat(buffer,el);
    }
    printf("%s", buffer);
    for(int i = 0, n = strlen(buffer); i < n; i++)
            if(is_loud(buffer[i])==0 && isalpha(buffer[i]))
                    counter++;
    printf("Count of  words in F2.txt: %i\n", counter);
}

int main(int argc,char* argv[])
{
    int rows = atoi(argv[1]);

    FILE *F1, *F2;
    F1 = fopen("F1.txt","w+b");
    F2 = fopen("F2.txt","w+b");
    create_file(F1, rows);
    print(F1);
        
    int n, k;
    do
    {
        printf("Choose rows(from...to), which need to copy: ");
        scanf("%i %i", &n, &k);
    }
    while(n < 1 || k < 1);
    if(n > k){int tmp = n;n = k;k = tmp;}
    
    copy(F1, F2, n-1, k);
    print(F2);
    check(F2);
    fclose(F2);
    fclose(F1);
}
