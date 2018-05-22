#include"SortTestHelper.h"
#include"SelectionSort.h"

template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n ; i++) {
		//寻找arr[i]合适的插入位置
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			/*if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;*/
			swap(arr[j], arr[j - 1]);
		}
	}
	return;
}

template<typename T>
void insertionSortAdvanced(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		T e = arr[i];
		int j = i;
		for (; j > 0 && arr[j-1] > e; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}

int main() {
	int n = 10000;
	//int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
	int *arr2 = SortTestHelper::copyArray(arr, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	SortTestHelper::testSort("Advanced Insertion Sort", insertionSortAdvanced, arr2, n);

	delete[] arr;
	delete[] arr2;
	system("pause");
	return 0;
}