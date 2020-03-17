#include <bits/stdc++.h>
using namespace std;

//Finds max subarray sum
int maxSubArray(int* arr, int N) {
	//dp array to store maximum subarray leading to index i
	int* dp = new int[N];
	dp[0] = arr[0];
	//most is the max subarray sum
	int most = dp[0];
	//bottom up dp approach
	//if previous dp[i] <0 then add arr[i] with 0, otherwise with dp[i-1]
	for (int i = 0; i < N; i++) {
		dp[i] = arr[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
		//if dp decreases the total sum, max continues with its previous subarray
		most = max(most, dp[i]);
	}
	return most;
}

int main() {
	//collect input
	int X = 0; cin >> X;
	int* arr = new int[X];
	for (int i = 0; i < X; i++) {
		int inp = 0; cin >> inp;
		arr[i] = inp;
	}
	cout << "ans:" << maxSubArray(arr, X) << endl;

	return 0;
}