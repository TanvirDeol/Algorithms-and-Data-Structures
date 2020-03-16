#include <bits/stdc++.h>
using namespace std;

int getSum(int* bitTree, int index) {
	int sum = 0;
	while (index > 0) {
		sum += bitTree[index];
		index -= index & (-index);
	}
	return sum;
}


void update(int* bitTree, int sz, int index, int val) {
	index++;
	while (index <= sz) {
		bitTree[index] += val;
		index += index & (-index);
	}
}


int* construct(int* arr, int sz) {

	int* bitTree = new int[sz + 1];
	for (int i = 1; i <= sz; i++) {
		bitTree[i] = 0;
	}

	for (int i = 0; i < sz; i++) {
		update(bitTree, sz, i, arr[i]);
	}

	return bitTree;
}


int main() {
	int n = 0; cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		int inp = 0; cin >> inp;
		arr[i] = inp;
	}


	int* bitTree = construct(arr, n);

	//for (int i = 1; i <= n; i++) {
	//	cout << bitTree[i] << " ";
	//}cout << endl;
	cout << getSum(bitTree, 9) - getSum(bitTree, 5 - 1) << endl;

	return 0;
}