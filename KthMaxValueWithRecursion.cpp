#include<iostream>

using namespace std;

// Swapping two values.
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// Partitioning the array on the basis of values at high as pivot value.
int CreatePartition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;

	// Getting index of pivot.
	for (i = low; i < high; i++)
	{
		if (a[i] > a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
	swap(&a[pivot], &a[index]);

	return index;
}

// Implementing Partition.
int Partition(int a[], int low, int high, int k)
{
	int pindex;
	if (low < high)
	{
		// Partitioning array using last element as a pivot.
		// Recursively implementing partitioning in the direction to place the pivot at (k-1)th pivot.
		pindex = CreatePartition(a, low, high);
		if (pindex == k - 1)
			return k - 1;
		else if (pindex > k - 1)
			Partition(a, low, pindex - 1, k);
		else
			Partition(a, pindex + 1, high, k);
	}
}

int main()
{
	const int n = 5;
	int  i, k, kk;

	int arr[n];
	for (i = 0; i < n; i++)
	{
		cout << "Enter element " << i + 1 << ": ";
		cin >> arr[i];
	}

	cout << "\nEnter the k for the kth latest element: ";
	cin >> k;

	kk = Partition(arr, 0, n - 1, k);

	// Printing the result.
	cout << "\nThe kth latest element: " << arr[kk];

	return 0;
}