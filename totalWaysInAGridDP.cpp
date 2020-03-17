#include <bits/stdc++.h>
using namespace std;
#define ll long long
//find total number of ways to go from (1,1) to (N,M) 
//with blocked squares
//where you can only move down or right
int main() {
	//collect input and initialize
	int N = 0, M = 0, B = 0;
	cin >> N >> M >> B;
	int** grid = new int* [N + 1];
	for (int i = 0; i < N + 1; i++) {
		int* temp = new int[M + 1];
		memset(temp, 0, sizeof(temp) * (M + 1));
		grid[i] = temp;
	}
	//collect blocked squares positions
	for (int i = 0; i < B; i++) {
		int k, j; cin >> k >> j;
		grid[k][j] = -1;
	}
	//if the first position is blocked, there are 0 ways
	if (grid[1][1] == -1) { cout << 0 << endl; return 0; }

	//for all grids on the first coloumn, theres only one way to reach it
	for (int i = 1; i <= M; i++) {
		if (grid[i][1] == 0) grid[i][1] = 1;
		else break;
	}
	//for all grids on the first row, theres only one way to reach it
	for (int i = 2; i <= N; i++) {
		if (grid[1][i] == 0) grid[1][i] = 1;
		else break;
	}

	//bottom up approach
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= M; j++) {
			//if current block is blocked, leave it at 0
			if (grid[i][j] == -1)continue;
			//if the block above is >0, then add the possibilities to [i][j]
			if (grid[i - 1][j] > 0) grid[i][j] = grid[i][j] + grid[i - 1][j];
			//if the block to the left is >0, then add the possibilities to [i][j]
			if (grid[i][j - 1] > 0) grid[i][j] = grid[i][j] + grid[i][j - 1];
		}
	}

	//prints[N][M] if its not blocked
	if (grid[N][M] != -1) {
		cout << grid[N][M] << endl;
	}
	else cout << 0 << endl;
	return 0;
}