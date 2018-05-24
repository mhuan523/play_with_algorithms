#include"SortTestHelper.h"
#include"MergeSort.h"


//对arr[l...r]进行partition操作
//返回p，使得arr[l...p-1] < arr[p]，arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r)
{
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	//arr[l+1...j] < v; arr[j+1...i) > v
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			swap(arr[++j], arr[i]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}


template<typename T>
void __quickSort(T arr[], int l, int r)
{
	/*if (l >= r)
		return;*/
	if (r - l <= 15)
	{
		insertionSort(arr, l, r);
		return;
	}
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}


template<typename T>
void quickSort(T arr[], int n)
{
	srand(time(NULL));
	__quickSort(arr, 0, n - 1);
}


int main() {
	int n = 1000000;
	cout << "Test for Random Array, size = " << n << ", random range [0," << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	int swapTimes = 10;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	int *arr3 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	int *arr4 = SortTestHelper::copyArray(arr3, n);

	SortTestHelper::testSort("Insertion Sort", mergeSort, arr3, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr4, n);

	delete[] arr1;
	delete[] arr2;

	delete[] arr3;
	delete[] arr4;

	system("pause");
	return 0;

}