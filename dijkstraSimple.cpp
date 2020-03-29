#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int>  pi;
#define mp make_pair
#define vec vector

vec<int> dijkstra(vec<vec<pi> >adj, int src, int N) {
    priority_queue<pi> pq;
    vec<int> dist(N, INT_MAX);
    pq.push({ 0,src });
    dist[src] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        vector<pi> ::iterator i;
        for (i = adj[cur].begin(); i < adj[cur].end(); i++) {
            int n = i->first;
            int len = i->second;
            if (dist[n] > dist[cur] + len) {
                dist[n] = dist[cur] + len;
                pq.push(mp(dist[n], n));
            }
        }
    }
    return dist;
}

int main()
{
    int N, E;
    cin >> N >> E;

    vec<vec<pi> > graph;
    for (int i = 0; i < N; i++) {
        vec<pi> ve;
        graph.push_back(ve);
    }
    for (int i = 0; i < E; i++) {
        int st, len, end;
        cin >> st >> len >> end;
        graph[st].push_back({ end,len });
        graph[end].push_back({ st,len });
    }
    vec<int> res = dijkstra(graph, 0, N);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }


    return 0;
}
