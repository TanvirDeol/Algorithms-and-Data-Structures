#include <bits/stdc++.h>

using namespace std;

struct edge { int to, length; };

int dijkstra(const vector< vector<edge> >& graph, int source, int target) {
    vector<int> min_distance(graph.size(), INT_MAX);
    min_distance[source] = 0;
    set< pair<int, int> > active_vertices;
    active_vertices.insert({ 0,source });

    while (!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        if (where == target) return min_distance[where];
        active_vertices.erase(active_vertices.begin());
        for (auto ed : graph[where])
            if (min_distance[ed.to] > min_distance[where] + ed.length) {
                active_vertices.erase({ min_distance[ed.to], ed.to });
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert({ min_distance[ed.to], ed.to });
            }
    }
    return INT_MAX;
}

int main()
{
    int N, E, src, tar;
    cin >> N >> E >> src >> tar;

    vector<vector<edge> > graph;
    for (int i = 0; i < N; i++) {
        vector<edge> ve;
        graph.push_back(ve);
    }
    for (int i = 0; i < E; i++) {
        int st, len, dst;
        cin >> st >> len >> dst;
        edge temp; temp.length = len;
        temp.to = dst;
        graph[st].push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        cout << dijkstra(graph, src, i) << endl;
    }
}
