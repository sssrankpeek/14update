#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
double find_max(double* ptr_array, int n, int K, int M);
double find_max_vnomerax(double* ptr_array, int n, int K, int L);
void main()
{
	setlocale(LC_ALL, "RUS");
	int size;
	printf("Введите размер массива > ");
	scanf("%d", &size);
	double* array = (double*)calloc(size, sizeof(double));
	full_elements(array, size);
	put_elements(array,size);
	printf("\n");
	calc_elements(array, size);
	int a, b;
	printf("\nОт какого элемента массива начать сумму? >");
	scanf("%d", &a);
	printf("\nДо какого элемента массива просчитать сумму? >");
	scanf("%d", &b);
	sum_elements(array,a,b);
	int c;
	printf("\nВведите элемент, который хотите найти >");
	scanf("%d", &c);
	printf("Индекс вашего элемента = %d", find_element(array, size, c));
	int q, r;
	printf("\nОт какого элемента массива искать максимальный? >");
	scanf("%d", &q);
	printf("\nДо какого элемента массива искать минимальный? >");
	scanf("%d", &r);
	printf("\nМаксимальный элемент в заданном интервале = %lf", find_max(array, size, q, r));
	int m, n;
	printf("\nОт какого порядкового номера элемента массива искать максимальный? >");
	scanf("%d", &m);
	printf("\nДо какого порядкового номера элемента массива искать минимальный? >");
	scanf("%d", &n);
	printf("\nМаксимальный элемент в заданном интервале = %lf", find_max_vnomerax(array, size, m, n));
}
double find_max_vnomerax(double* ptr_array, int n, int K, int L)
{
	double max = -10000;
	for (int i = K+1; i <= L+1; i++)
	{
		if (ptr_array[i] > max)
			max = ptr_array[i];
	}
	return max;
}
double* full_elements(double* ptr_array, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] = rand() % 101 - 50;
	}
	return ptr_array;
}
int put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\na[%d] = %lf", i+1, ptr_array[i]);
	}
	return 0;
}
double* calc_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 2 == 0)
		{
			ptr_array[i] = ptr_array[i] + 1;
		}
		printf("\nA[%d]= %lf", i+1, ptr_array[i]);
	}
	return ptr_array;
}
double sum_elements(double* ptr_array, int begin, int end)
{
	double sum=0;
	for (int i = begin; i <= end; i++)
	{
		sum += ptr_array[i];
	}
	printf("Сумма элементов массива: %lf", sum);
	return sum;
}
double find_max(double* ptr_array, int n, int K, int M)
{
	double max = -10000;
	for (int i = K; i <= M; i++)
	{
		if (ptr_array[i] > max)
			max = ptr_array[i];
	}
	return max;
}
int find_element(double* ptr_array, int n, double element)
{
	int position;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element)
		{
			position = i;
			return position;
		}
	}
	return -1;
}