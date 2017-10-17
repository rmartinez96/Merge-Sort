// Raul Martinez
// raul.martinez01@utrgv.edu

#include <iostream>
#include <string>
#include "linkedList.h"
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;


//Pick a pivot (try just the first item for example).  Partition the array items in the range from index s to index e by
//moving all items smaller than the pivot to the left of the pivot,
//and all items large to the right, with the pivot in between.  Return the index of the pivot item after this partitioning.
//To ensure a good average case run time regardless of input order, how should you choose the pivot?
template <class T>
unsigned partition(T * A, int s, int e)
{
	int i = s, j = e;
	int tmp;
	int pivot = A[(s + e) / 2];

	while (i <= j)
	{
		while (A[i] < pivot)
			i++;
		while (A[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
			j--;
		}
	}
	return i;
}

template <class T>
void quickSort(T * A, int start, int end)
{
	if( start < end )
	{
		int p=partition(A, start, end);
		quickSort(A, start, p - 1);
		quickSort(A, p+1, end);
	}
}

int main()
{
	unsigned size = 10000000;

	//part 1:  implement a merge sort for a doubly linked list class
	linkedList<unsigned> numbers;
	for (int i = 0; i < size; i++)
		numbers.push_back(rand() + rand()*pow(2, 15));



	clock_t startTime = clock();
	numbers.mergeSort();
	clock_t endTime = clock();

	//numbers.display();

	cout << "Merge sort took: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;

	//part 2: implement a quick sort to sort an array.
	unsigned * A = new unsigned[size];
	for (int i = 0; i < size; i++)
		A[i] = rand() + rand()*pow(2, 15);  //test also with: A[i] = i;

	startTime = clock();
	quickSort(A, 0, size - 1);
	endTime = clock();

	//for (int i = 0; i < size; i++)
		//cout << A[i] << endl;


	cout << "Quick sort took: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;

	return 0;
}