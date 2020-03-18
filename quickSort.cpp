#include <bits/stdc++.h>
using namespace std;

//swaps two indexes of an array
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int part(int* arr, int low, int high) {
	//the items in the array are compared to the pivot
	int pivot = arr[high];
	int i = (low - 1);
	//goes through array, if an item is < pivot
	//it is swapped with index of i. 
	for (int j = low; j <= high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	//returns partition index to repeat process recusively
	return (i + 1);
}
void quickSort(int* arr, int low, int high) {
	//two pointer approach, the low increments,
	//and the high decrements until they meet
	if (low < high) {
		//partitions the array once
		int p = part(arr, low, high);
		//divides the array into partitions and repeats the process
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}


int main() {
	//collect input
	int N = 0; cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		int inp; cin >> inp;
		arr[i] = inp;
	}
	quickSort(arr, 0, N - 1);
	//print array
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}cout << endl;
	return 0;
}
