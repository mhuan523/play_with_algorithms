#include"SortTestHelper.h"
#include"Student.h"

template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		//寻找[i, n)中的最小值
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}

int main() {
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	//selectionSort(arr, n);
	//SortTestHelper::printArray(arr, n);

	Student d[4] = { {"D", 90}, {"C", 100}, {"B", 95}, {"A", 95} };
	selectionSort(d, 4);
	SortTestHelper::printArray(d, 4);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);

	delete[] arr;
	system("pause");
	return 0;
}