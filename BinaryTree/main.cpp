#include"BinarySearch.h"
#include<iostream>
using namespace std;


int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 20 };
	cout << binarySearchIterative(arr, sizeof(arr) / sizeof(int), 99)<<endl;
	cout << binarySearchRecursive(arr, sizeof(arr) / sizeof(int), 5)<<endl;

	system("pause");
	return 0;
}