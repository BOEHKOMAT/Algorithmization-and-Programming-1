#include<stdio.h>
#include<stdarg.h>

int min(int m, ...)
{
	va_list ap;
	va_start(ap, m);
	int arr[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = va_arg(ap, int);
	}
	int min = arr[0];
	for (int i = 0; i < m; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	va_end(ap);
	return min;
}

int main(void)
{
	printf("First min num: %i \n", min(5, 1, 7, -3, -2, 4));
	printf("Second min num: %i \n", min(10, 2, 5, 4, 5, 2, 6, 1, 8, 9, 1));
	printf("Third min num: %i \n", min(-12, 1, 6, 7, -3, 9, 5, 3, -5, 8, 2, -4, 4));
}