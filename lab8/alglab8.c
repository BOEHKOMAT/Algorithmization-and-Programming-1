#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char surname[40];
	char name[40];
	char fathername[40];
	long long number;
	int form;
	int marks[4];
}schoolchild;

schoolchild initialization()
{
	schoolchild person;
	printf("Surname Name Fathername: "); scanf("%s%s%s", person.surname, person.name, person.fathername);
	printf("Phone number: "); scanf("%lld",&person.number);
	printf("Form:"); scanf("%i", &person.form);
	printf("Marks(math, physics, language, literature): "); scanf("%i %i %i %i", &person.marks[0], &person.marks[1], &person.marks[2], &person.marks[3]);
	return person;
}

void writing(char* fname, schoolchild *arr, int count)
{
	FILE *f;
	f = fopen(fname, "wb");
	for (int i = 0; i < count; i++)
		fwrite(&arr[i], sizeof(schoolchild), 1, f);
	fclose(f);
}

int reading(char* fname, schoolchild *arr, int count)
{
	FILE *f;
	int i = 0;
	if((f = fopen(fname, "rb")) == NULL)return -1;
	while (!feof(f) && i < count)
	{
		fread(&arr[i], sizeof(schoolchild), 1, f);
		i++;
	}
	fclose(f);
	return 1;
}

int print(char* fname, int count)
{
	schoolchild person;
	int i = 0;
	FILE *f;
	if((f = fopen(fname, "rb")) == NULL)return -1;;
	while(!feof(f) && i < count)
	{
		fread(&person, sizeof(schoolchild), 1, f);
		printf("Surname: %s | Name: %s | Fathername: %s | Phone number: %lld | Form: %i | Marks(math,physics,language,literature: %i %i %i %i\n", person.surname, person.name, person.fathername, person.number, person.form, person.marks[0], person.marks[1], person.marks[2], person.marks[3]);
		i++;
	}
	return 0;
}

int check_struct(schoolchild arr)
{
	int check = 0;
	for (int i = 0; i < 4; i++)
	{
		if (arr.marks[i] == 2)
			check++;
	}
	if (check != 0)
		return 1;
	else
		return 0;
}

int del(schoolchild *arr, int count)
{
    int counter = 0;
	FILE *f;
	f = fopen("lab8copy.txt", "wb");
	for (int i = 0; i < count; i++)
	{
		if (check_struct(arr[i]) == 0)
			fwrite(&arr[i], sizeof(schoolchild), 1, f);
        else
            counter++;
	}
	fclose(f);
	return counter;
}

void add(char* fname, int count)
{
    schoolchild object = initialization();
    schoolchild buffer[count];
    reading(fname,buffer,count);
    FILE *f;
    f = fopen(fname,"wb");
    fwrite(&object,sizeof(schoolchild),1,f);
    for(int i = 0; i < count; i++)
    fwrite(&buffer[i],sizeof(schoolchild),1,f);
    fclose(f);
}

int main(void)
{
	int count;
	do
	{
		printf("Choose count of schoolchildren: ");
		scanf("%i", &count);
	}
	while (count < 1);
	schoolchild arr[count];
	for(int i = 0; i < count; i++)
	    arr[i] = initialization();
	
	writing("lab8.txt", arr, count);
	print("lab8.txt", count);
	reading("lab8.txt",arr,count);
	
	printf("\n======================================Start process deleting schoolchildren, which have 2 from any subject======================================\n");
    int counter = del(arr,count);
    if(counter == -1)
        return 0;
    print("lab8copy.txt",count-counter);
    
    printf("\n==========================================================Add information of new object=========================================================\n");
    add("lab8copy.txt",count - counter);
    printf("\n======================================================================Adding====================================================================\n");
    print("lab8copy.txt",count - counter + 1);
}