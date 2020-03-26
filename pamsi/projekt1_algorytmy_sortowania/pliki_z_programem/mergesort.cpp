#include "mergesort.h"

void merge(int* array, int begin, int mid, int end)
{
	int leftSize = mid - begin + 1;
	int rightSize = end - mid;

	int* left = new int[leftSize];
	int* right = new int[rightSize];

	for (int i = 0; i < leftSize; ++i) left[i] = array[begin + i];
	for (int i = 0; i < rightSize; ++i) right[i] = array[mid + 1 + i];

	int i = 0;
	int j = 0;
	int k = begin;

	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < leftSize)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < rightSize)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	delete[] left;
	delete[] right;
}

void mergeSort(int* array, int begin, int end)
{
	if (begin < end)
	{
		int mid = begin + (end - begin) / 2;

		mergeSort(array, begin, mid);
		mergeSort(array, mid + 1, end);
		merge(array, begin, mid, end);
	}
}