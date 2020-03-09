#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int** adj, int n, int src, bool* visited) {
	cout << src << endl;
	visited[src] = true;
	for (int i = 0; i < n; i++) {
		if (i == src) {
			continue;
		}
		if (adj[src][i] == 1) {
			if (!visited[i]) {
				dfs(adj, n, i, visited);
			}
		}
	}
}
int main() {
	int n = 0, e = 0;
	cin >> n >> e;
	int** adj = new int* [n];
	for (int i = 0; i < n; i++) {
		adj[i] = new int[n];
		for (int j = 0; j < n; j++) {
			adj[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++) {
		int f = 0, s = 0;
		cin >> f >> s;
		adj[f][s] = 1;
		adj[s][f] = 1;
	}

	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	dfs(adj, n, 0, visited);

	return 0;
}