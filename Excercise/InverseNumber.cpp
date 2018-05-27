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

// merge���������arr[l...mid]��arr[mid+1...r]����Ļ�����, arr[l...r]���������Ը���
long long __merge(int arr[], int l, int mid, int r) {

	int *aux = new int[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	// ��ʼ���������Ը��� res = 0
	long long res = 0;
	// ��ʼ����iָ����벿�ֵ���ʼ����λ��l��jָ���Ұ벿����ʼ����λ��mid+1
	int j = l, k = mid + 1;
	for (int i = l; i <= r; i++) {
		if (j > mid) { // �����벿��Ԫ���Ѿ�ȫ���������
			arr[i] = aux[k - l];
			k++;
		}
		else if (k > r) { // ����Ұ벿��Ԫ���Ѿ�ȫ���������
			arr[i] = aux[j - l];
			j++;
		}
		else if (aux[j - l] <= aux[k - l]) { // ��벿����ָԪ�� <= �Ұ벿����ָԪ��
			arr[i] = aux[j - l];
			j++;
		}
		else { // �Ұ벿����ָԪ�� < ��벿����ָԪ��
			arr[i] = aux[k - l];
			k++;
			// ��ʱ, ��Ϊ�Ұ벿��k��ָ��Ԫ��С
			// ���Ԫ�غ���벿�ֵ�����δ�����Ԫ�ض���������������
			// ��벿�ִ�ʱδ�����Ԫ�ظ���Ϊ mid - j + 1
			res += (long long)(mid - j + 1);
		}
	}

	delete[] aux;

	return res;
}

// ��arr[l..r]��Χ���������Ը���
// ˼��: �鲢������Ż��ɷ��������������Ե��㷨? :)
long long __inversionCount(int arr[], int l, int r) {

	if (l >= r)
		return 0;

	int mid = l + (r - l) / 2;

	// ��� arr[l...mid] ��Χ��������
	long long res1 = __inversionCount(arr, l, mid);
	// ��� arr[mid+1...r] ��Χ��������
	long long res2 = __inversionCount(arr, mid + 1, r);

	return res1 + res2 + __merge(arr, l, mid, r);
}

// �ݹ���arr���������Ը���
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

