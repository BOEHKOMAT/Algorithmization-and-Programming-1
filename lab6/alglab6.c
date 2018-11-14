#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define DL 255

void word(char sentence[],int i)
{
    if(isalpha(sentence[i]) || isblank(sentence[i]) || ispunct(sentence[i]))
        {
            printf("%c", sentence[i]);
        }
}

void number(char sentence[], int i)
{
    if(isdigit(sentence[i]))
        {
            printf("%c", sentence[i]);
        }
}

int main(void)
{
    char sentence[DL];
    printf("Enter the text:");
    fgets(sentence, DL, stdin);
    int length = strlen(sentence);
    for(int i = 0 ; i < length-1 ; i++)
    {
        word(sentence,i);
    }
    printf(" ");
    for(int i = 0 ; i < length-1 ; i++)
    {
        number(sentence,i);
    }
    printf("\n");
}