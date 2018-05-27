#include<iostream>
#include<ctime>
#include"SortTestHelper.h"

using namespace std;


template<typename T>
long long getInverseNumber(T arr[], int n) {
	long long res = 0;
	/*for (int i = 1; i < n; i++) {
		int j = i;
		for (; j > 0 && arr[j - 1] > arr[j]; j--) {
			res += 1;
		}
	}*/
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j])
				res += 1;
		}
	}
	return res;
}


template<typename T>
long long __merge(T arr[], int l, int mid, int r) {
	long long res = 0;
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (l > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i - l];
			i++;
		}
		else if(aux[i- l] <= aux[j - l]){
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
			res = res + (long long)(mid - i + l);
		}
	}
	delete[] aux;
	return res;
}

// merge函数求出在arr[l...mid]和arr[mid+1...r]有序的基础上, arr[l...r]的逆序数对个数
long long __merge(int arr[], int l, int mid, int r) {

	int *aux = new int[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	// 初始化逆序数对个数 res = 0
	long long res = 0;
	// 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
	int j = l, k = mid + 1;
	for (int i = l; i <= r; i++) {
		if (j > mid) { // 如果左半部分元素已经全部处理完毕
			arr[i] = aux[k - l];
			k++;
		}
		else if (k > r) { // 如果右半部分元素已经全部处理完毕
			arr[i] = aux[j - l];
			j++;
		}
		else if (aux[j - l] <= aux[k - l]) { // 左半部分所指元素 <= 右半部分所指元素
			arr[i] = aux[j - l];
			j++;
		}
		else { // 右半部分所指元素 < 左半部分所指元素
			arr[i] = aux[k - l];
			k++;
			// 此时, 因为右半部分k所指的元素小
			// 这个元素和左半部分的所有未处理的元素都构成了逆序数对
			// 左半部分此时未处理的元素个数为 mid - j + 1
			res += (long long)(mid - j + 1);
		}
	}

	delete[] aux;

	return res;
}

// 求arr[l..r]范围的逆序数对个数
// 思考: 归并排序的优化可否用于求逆序数对的算法? :)
long long __inversionCount(int arr[], int l, int r) {

	if (l >= r)
		return 0;

	int mid = l + (r - l) / 2;

	// 求出 arr[l...mid] 范围的逆序数
	long long res1 = __inversionCount(arr, l, mid);
	// 求出 arr[mid+1...r] 范围的逆序数
	long long res2 = __inversionCount(arr, mid + 1, r);

	return res1 + res2 + __merge(arr, l, mid, r);
}

// 递归求arr的逆序数对个数
long long inversionCount(int arr[], int n) {

	return __inversionCount(arr, 0, n - 1);
}


template<typename T>
long long  __getInverseNumber2(T arr[], int l, int r) {
	if (l >= r)
		return 0;
	int mid = (l + r) / 2;
	long long res1 = __getInverseNumber2(arr, l, mid);
	long long res2 = __getInverseNumber2(arr, mid + 1, r);
	return res1 + res2 + __merge(arr, l,mid, r);
}

template<typename T>
long long getInverseNumber2(T arr[], int n) {
	return __getInverseNumber2(arr, 0, n - 1);
}


int main() {
	int n = 10000;
	int* arr1 = SortTestHelper::generateNearlyOrderedArray(n, 50);
	int* arr2 = SortTestHelper::copyArray(arr1, n);
	cout << getInverseNumber(arr1, n);
	cout << endl;
	cout << getInverseNumber2(arr1, n);
	cout << endl;
	cout << inversionCount(arr2, n);
	cout << endl;

	delete[] arr1;
	system("pause");
	return 0;
}

