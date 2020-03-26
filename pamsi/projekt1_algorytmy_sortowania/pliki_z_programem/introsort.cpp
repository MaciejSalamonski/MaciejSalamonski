#include <cmath>
#include "introsort.h"
#include "quicksort.h"

 void maxHeapify(int* array, int heapSize, int index)
 {
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

	if (left < heapSize && array[left] > array[index])
		largest = left;
	else
		largest = index;

	if (right < heapSize && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		int temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;

		maxHeapify(array, heapSize, largest);
	}
}

 void heapSort(int* array, int count)
 {
	int heapSize = count;

	for (int p = (heapSize - 1) / 2; p >= 0; --p)
		maxHeapify(array, heapSize, p);

	for (int i = count - 1; i > 0; --i)
	{
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;

		--heapSize;
		maxHeapify(array, heapSize, 0);
	}
}

 void introSort(int* array, int count)
 {
	 int partitionSize = pivot(array, 0, count - 1);

	if (partitionSize > (2 * log(count)))
	{
		heapSort(array, count);
	}
	else
	{
		quickSort(array, 0, count - 1);

	}
}