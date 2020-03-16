#include <bits/stdc++.h>
using namespace std;

/*Given N steps of stairs, how many ways can you climb the stairs using 1,2 or 3 steps*/
int* dp;
int climb(int N) {
	if (N >= 0) {
		if (dp[N] > 0) return dp[N];
	}
	if (N == 0)return 1;
	else if (N < 0) return 0;

	return climb(N - 1) + climb(N - 2) + climb(N - 3);
}

int main() {
	int N = 0; cin >> N;
	dp = new int[N + 1];

	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = 0;
	}

	for (int i = 2; i <= N; i++) {
		int ans = climb(i);
		dp[i] = ans;
	}

	cout << dp[N];

	return 0;
}