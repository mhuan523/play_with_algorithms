#include"SortTestHelper.h"
#include"MergeSort.h"


template<typename T>
void __quickSort3Ways(T arr[], int l, int r)
{
	/*if (l >= r)
	return;*/
	if (r - l <= 15)
	{
		insertionSort(arr, l, r);
		return;
	}
	//partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	int lt = l;		//arr[l+1...lt] < v
	int gt = r + 1; //arr[gt...r] > v
	int i = l + 1;	//arr[lt+1...i) == v
	while (i < gt)
	{
		if (arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else {
			i++;
		}
	}
	swap(arr[l], arr[lt]);
	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);

}

template<typename T>
void quickSort3Ways(T arr[], int n)
{
	srand(time(NULL));
	__quickSort3Ways(arr, 0, n - 1);
}


template<typename T>
int __partition2(T arr[], int l, int r)
{
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	//arr[l+1...i) <= v; arr(j...r] >= v
	int i = l + 1, j = r;
	while (true)
	{
		while (i <= r && arr[i] < v)
		{
			i++;
		}
		while (j >= l + 1 && arr[j] > v)
		{
			j--;
		}
		if (i > j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}


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
	int p = __partition2(arr, l, r);
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
	int* arr3 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 ways", quickSort3Ways, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	int swapTimes = 10;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyArray(arr1, n);
	arr3 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 ways", quickSort3Ways, arr3, n);

	
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	system("pause");
	return 0;

}