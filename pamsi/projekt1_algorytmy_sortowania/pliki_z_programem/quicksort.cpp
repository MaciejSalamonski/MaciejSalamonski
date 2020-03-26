#include "quicksort.h"

int pivot(int* array, int left, int right)
{
	int x = array[(left + right) / 2];
	int i = left, j = right, u;
	while (true)
	{
		while (array[j] > x)
			j--;
		while (array[i] < x)
			i++;
		if (i < j)
		{
			u = array[i];
			array[i] = array[j];
			array[j] = u;
			i++;
			j--;
		}
		else
			return j;
	}
}

void quickSort(int* array, int left, int right)
{
	int p;
	if (left < right)
	{
		p = pivot(array, left, right);
		quickSort(array, left, p);
		quickSort(array, p + 1, right);
	}
}