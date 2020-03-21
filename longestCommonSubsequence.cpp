#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int* first;
int* second;

int func(int N, int M) {
    int** dp = new int* [N + 1];

    for (int i = 0; i <= N; i++) {
        int* temp = new int[M + 1];
        for (int j = 0; j <= M; j++) {

            if (i == 0 || j == 0) temp[j] = 0;

            else if (first[N - i] == second[M - j]) {
                temp[j] = 1 + dp[i - 1][j - 1];
            }

            else {
                temp[j] = max(dp[i - 1][j], temp[j - 1]);
            }
        }
        dp[i] = temp;
    }

    return dp[N][M];
}

int main() {
    int N, M;
    cin >> N >> M;
    first = new int[N];
    second = new int[M];
    for (int i = 0; i < N; i++) {
        cin >> first[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> second[i];
    }
    cout << func(N, M) << endl;
    return 0;
}
