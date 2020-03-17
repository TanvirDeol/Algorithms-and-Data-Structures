#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long


ll* dp;
ll factorial(long num) {
	if (num == 1) {
		return dp[1];
	}
	if (dp[num] != -1) return dp[num];

	return dp[num] = num * factorial(num - 1);
}

int main() {
	int T = 0; cin >> T;
	dp = new ll[1000001];
	for (int i = 0; i < 100001; i++) {
		dp[i] = -1;
	}
	dp[1] = 1;


	for (int i = 0; i < T; i++) {
		ll N = 0; cin >> N;
		cout << factorial(N) % 1000000007 << endl;
	}



	return 0;
}