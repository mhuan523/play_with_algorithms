#include"SortTestHelper.h"
#include"InsertionSort.h"

template<typename T>
void insertionSort(T arr[], int l, int r)
{
	for (int i = l + 1; i <= r; i++) {
		int j = i;
		T e = arr[i];
		for (; j > l && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}


//将arr[l...mid]和arr[mid + 1...r]进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}

//递归使用归并排序，对arr[l...r]进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r)
{
	/*if (l >= r)
		return;*/
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if (arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n - 1);
}

template<typename T>
void mergeSortBU(T arr[], int n)
{
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i + sz< n; i += sz + sz)
		{
			//对arr[i...i+sz -1]和arr[i+sz...i+2*sz-1]进行归并
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n-1));
		}
	}
}

int main() {
	int n = 50000;
	cout << "Test for Random Array, size = " << n << ", random range [0," << n << "]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSortAdvanced, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	int swapTimes = 0;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	int *arr3 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	int *arr4 = SortTestHelper::copyArray(arr3, n);

	SortTestHelper::testSort("Insertion Sort", insertionSortAdvanced, arr3, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr4, n);

	delete[] arr1;
	delete[] arr2;

	delete[] arr3;
	delete[] arr4;

	system("pause");
	return 0;

}