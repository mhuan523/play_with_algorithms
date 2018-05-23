#pragma once

template<typename T>
void insertionSortAdvanced(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		T e = arr[i];
		int j = i;
		for (; j > 0 && arr[j - 1] > e; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}