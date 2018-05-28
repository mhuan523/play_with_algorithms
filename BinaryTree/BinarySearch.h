#pragma once

template<typename T>
int binarySearchRecursive(T arr[], int n, T key) {
	int l = 0, r = n - 1;
	//在[l...r]区间中寻找key
	while (l <= r)
	{
		int mid = (r - l) / 2 + l;
		if (key == arr[mid])
			return mid;
		else if (key > arr[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

template<typename T>
int __binarySearchIterative(T arr[], int l, int r, T key) {
	if (l > r)
		return -1;
	int mid = (r - l) / 2 + l;
	if (arr[mid] == key)
		return mid;
	else if (arr[mid] > key)
		__binarySearchIterative(arr, mid + 1, r, key);
	else
		__binarySearchIterative(arr, l, mid - 1, key);
}


template<typename T>
int binarySearchIterative(T arr[], int n, T key) {
	return __binarySearchIterative(arr, 0, n - 1, key);
}

