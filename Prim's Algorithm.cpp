#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
#define MOD 1000000007
const int MAX = 1e4 + 5;

bool marked[MAX];
vector <pi> adj[MAX];
int N, M;

long mod(long a, long b)
{
	return (a % b + b) % b;
}

int prim(int x) {
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	ll  mCost = 0; int y;
	pq.push({ 0,x });
	pi p;
	while (!pq.empty()) {
		p = pq.top(); pq.pop();
		x = p.second;
		if (marked[x])continue;
		mCost += p.first;
		marked[x] = 1;
		for (int i = 0; i < adj[x].size(); i++) {
			y = adj[x][i].second;
			if (!marked[y])pq.push(adj[x][i]);
		}
	}
	return mCost;
}
int main() {
	cin >> N >> M;
	int x, y; ll w;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> w;
		adj[x].push_back({ w,y });
		adj[y].push_back({ w,x });
	}
	int minCost = prim(x);
	cout << minCost << endl;
	return 0;
}
