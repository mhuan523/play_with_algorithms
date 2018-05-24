#pragma once

template<typename T>
void insertionSort(T arr[], int l, int r)
{
	for (int i = l + 1; i <= r; i++) {
		int j = i;
		T e = arr[i];
		for (; j > l && arr[j - 1] > e; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
}