#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "quicksort.h"
#include "mergesort.h"
#include "introsort.h"

void arrayFilling(int* array, int size, double preSortPercentages)
{
	if (preSortPercentages != 101)	//zmienna ta wykorzystywana jest po to, aby posortowac wstepnie tablice owrotnie. Nastpnie taka tablica trafia do algorytmu sortowania
	{
		for (int i = 0; i < size * preSortPercentages * 0.01; i++)
		{
			array[i] = i;
		}

		for (int i = size * preSortPercentages * 0.01; i < size; i++)
		{
			array[i] = (std::rand()) + size * preSortPercentages * 0.01;
		}
	}

	else
	{
		for (int i = size - 1; i >= 0; i--)
		{
			array[i] = size - i;
		}
	} 
}

int timeAveraging(int* times, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += times[i];
	}
	return (sum / 100);
}

int main()
{
	int averageTime;
	double preSortPercentagesArray[8] = { 0, 25, 50, 75, 95, 99, 99.7, 101 };	//ostatni element tablicy jest wykorzystywany jako zmienna
	int sizeArray[5] = { 10000, 50000, 100000, 500000, 1000000 };

	srand(time(NULL));

	for (int k = 0; k < 5; k++)
	{

		for (int z = 0; z < 8; z++)
		{
			int* timesArray = new int[100];

			for (int i = 0; i < 100; i++)
			{
				int* array = new int[sizeArray[k]];
				arrayFilling(array, sizeArray[k], preSortPercentagesArray[z]);

				auto t1 = std::chrono::high_resolution_clock::now();
				//quickSort(array, 0, sizeArray[k] - 1);
				//mergeSort(array, 0, sizeArray[k] - 1);	//wybor algorytmu sortowania
				introSort(array, sizeArray[k]);
				auto t2 = std::chrono::high_resolution_clock::now();

				auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
				timesArray[i] = duration;

				delete[] array;
				array = nullptr;
			}

			averageTime = timeAveraging(timesArray, 100);

			if(z != 7)
				std::cout << "Usredniony czas [mikrosekundy]:" << averageTime << " dla " << sizeArray[k] << " elementowej tablicy, wstepnie posortowanej w " << preSortPercentagesArray[z] << "%." << std::endl;
			else
				std::cout << "Usredniony czas [mikrosekundy]:" << averageTime << " dla " << sizeArray[k] << " elementowej tablicy, wstepnie posortowanej od tylu." << std::endl;

			delete[] timesArray;
			timesArray = nullptr;
		}
	}

	return 0;
}