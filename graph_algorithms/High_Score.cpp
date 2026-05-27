#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17; 

struct Edge {
    int u, v;
    long long w;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist(n + 1, -INF);
    dist[1] = 0;

    for (int i = 1; i < n; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != -INF && dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    
    for (int i = 1; i <= n; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != -INF && dist[e.u] + e.w > dist[e.v]) {
              
                dist[e.v] = INF; 
            }
        }
    }

    if (dist[n] >= INF) cout << -1 << endl;
    else cout << dist[n] << endl;

    return 0;
}