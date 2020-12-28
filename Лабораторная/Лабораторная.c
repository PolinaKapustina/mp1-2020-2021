#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      
#include <time.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include "inttypes.h"
#include "memory.h"
#include <locale.h>
#define SIZE_T 10

struct testInfo
{
	int64_t compareCount, swapCount;
	int isCorrect;
};
typedef struct testInfo testInfo;

static void _radix_(double* arr, double* buffer, int64_t len)
{
	size_t i = len - 1;
	size_t pos = 0;

	for (; i > 0 && buffer[i] < 0; i--, pos++)
	{
		arr[pos] = buffer[i];
	}

	for (size_t j = 0; j <= i; j++, pos++)
	{
		arr[pos] = buffer[j];
	}
}

testInfo radixSort(double* const array, size_t cp)
{
	const int countValues = (1 << 8);

	testInfo radix;
	size_t counts[sizeof(double)][(1 << 8)];
	double* tempArray;
	double* buf;

	memset(counts, 0, sizeof(double) * countValues * sizeof(size_t));

	radix.compareCount = radix.swapCount = 0;

	for (size_t i = 0; i < sizeof(double); i++)
	{
		for (size_t j = 0; j < cp; j++)
		{
			int val = *((uint8_t*)&array[j] + i);
			counts[i][val]++;
		}
	}

	for (size_t i = 0; i < sizeof(double); i++)
	{
		size_t sum = 0;
		for (int j = 0; j < countValues; j++)
		{
			size_t temp = counts[i][j];
			counts[i][j] = sum;
			sum += temp;
		}
	}

	tempArray = (double*)malloc(sizeof(double) * cp);
	buf = (double*)malloc(sizeof(double) * cp);

	memcpy(tempArray, array, sizeof(double) * cp);
	for (size_t i = 0; i < sizeof(double); i++)
	{
		double* temp;

		for (size_t j = 0; j < cp; j++)
		{
			int val = *((uint8_t*)&tempArray[j] + i);
			buf[counts[i][val]] = tempArray[j];
			counts[i][val]++;

			radix.swapCount++;
		}

		temp = tempArray;
		tempArray = buf;
		buf = temp;
	}

	_radix_(array, tempArray, cp);
	radix.swapCount += cp;
	free(tempArray);
	free(buf);
	return radix;
}

double massiv(double* array, int l)
{
	for (int i = 0; i < l; i++)
	{
		array[i] = rand();
		array[i] = (array[i] * 0.00001 + rand());
		if ((rand() % 2) == 1)
			array[i] = 0 - array[i];
	}
}

testInfo bubble_sort(double* a, const size)
{
	testInfo bubble;
	bubble.compareCount = bubble.swapCount = 0;
	for (int i = 0; i < size - 1; i++)
	{
		int flag = 0;
		for (int j = size - 2; j > i - 1; j--)
		{
			if (a[j] > a[j + 1])
			{
				double tmp;
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				bubble.swapCount++;
				flag = 1;
			}
			bubble.compareCount++;
		}
		if (flag == 0)
		{
			return bubble;
			break;
		}
	}
}

testInfo comb_sort(double* a, const size)
{
	testInfo comb;
	comb.compareCount = comb.swapCount = 0;
	double factor = 1.2473309;
	int step = size - 1;
	while (step >= 1) {
		for (int i = 0; i + step < size; i++)
		{
			if (a[i] > a[i + 1])
			{
				double tmp;
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				comb.swapCount++;
			}
			comb.compareCount++;
		}
		step /= factor;
	}

	int b = 1;
	while (b == 1) {
		b = 0;
		for (int j = 0; j + 1 < size; j++)
		{
			if (a[j] > a[j + 1])
			{
				double tmp;
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				b = 1;
				comb.swapCount++;
			}
			comb.compareCount++;
		}

	}
	return comb;
}

testInfo mergeSort(double* a, int l, int r)
{
	testInfo merge;
	merge.compareCount = merge.swapCount = 0;
	if (l == r) return merge;
	int mid = (l + r) / 2;
	merge.swapCount += mergeSort(a, l, mid).swapCount;
	merge.swapCount += mergeSort(a, mid + 1, r).swapCount;
	int i = l;
	int j = mid + 1;
	float* tmp = (float*)malloc(r * sizeof(int));
	for (int step = 0; step < r - l + 1; step++)
	{
		if ((a[i] > a[j]))
			merge.swapCount++;
		if ((j > r) || ((i <= mid) && (a[i] <= a[j])))
		{
			tmp[step] = a[i];
			i++;
		}
		else
		{
			tmp[step] = a[j];
			j++;
		}
		merge.compareCount++;
	}
	for (int step = 0; step < r - l + 1; step++)
	{
		a[l + step] = tmp[step]; 
		merge.compareCount++;
	} 
	for (int step = 0; step < r - l + 1; step++)
	return merge;
}


void main()
{
	setlocale(LC_ALL, "Rus");

	testInfo chet [100];
	testInfo sum;
	sum.compareCount = 0;
	sum.swapCount = 0;
	int64_t swap[100], compare[100];

	int zero = 1;
	int N = SIZE_T;
	double mass[SIZE_T];
	double* p;
	p = mass;
	int i;
	int per = 0;
	testInfo flow;
	srand(time(NULL));
	printf("%d", N);
	while (zero != 0)
	{
		/*printf(" �������� ���� �� ������� ���� � ������� ��� ����� � �������. \n \n ");
		printf(" ���� \n 1. ������ ������ ������� \n 2. ������� ������ �� ����� \n 3. ������� ���������� ���������� � �������. ������ n= %d", N);
		printf(" \n 4. ��������� ������ ���������� ���������� \n 5. ������������� ������ ����������� ���������. \n 6. ������������� ������ ����������� ��������� \n ");
		printf("7. ������������� ������ ����������� �����������. \n 8. ������������� ������ ����������� �������� \n 0. �����\n");*/
		scanf("%d", &zero);
		if (zero == 1)
		{
			for (i = 0; i < N; i++)
			{
				scanf("%lf", &mass[i]);
			}
		}
		if (zero == 2)
		{
			for (i = 0; i < N; i++)
			{
				printf("%lf", mass[i]);
				printf("  ");
			}
		}
		if (zero == 3)
		{
			scanf("%d", &N);
		}
		if (zero == 4)
		{
			for (i = 0; i < N; i++)
			{
				mass[i] = rand();
				mass[i] = (mass[i] * 0.00001 + rand());
				if ((rand() % 2) == 1)
					mass[i] = 0 - mass[i];
			}
		}
		if (zero == 5)
		{
			flow = bubble_sort(p, N);
			printf("����� ������������ %" PRId64 "\n", flow.swapCount);
			printf("����� ��������� %" PRId64 "\n", flow.compareCount);
		}
		if (zero == 6)
		{
			flow = comb_sort(p, N);
			printf("����� ������������ %" PRId64 "\n", flow.swapCount);
			printf("����� ��������� %" PRId64 "\n", flow.compareCount);
		}
		if (zero == 7)
		{
			flow = radixSort(mass, N);
			printf("����� ������������ %" PRId64 "\n", flow.swapCount);
			printf("����� ��������� %" PRId64 "\n", flow.compareCount);
		}

		if (zero == 8)
		{
			flow = mergeSort(p, 0, N - 1);
			printf("����� ������������ %" PRId64 "\n", flow.swapCount);
			printf("����� ��������� %" PRId64 "\n", flow.compareCount);
		}
	}
	return 0;
}