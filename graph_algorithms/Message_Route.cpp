#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

void solve() {
    int n, m;
    cin >> n >> m;
    graph.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    vector<int> parent(n + 1, -1);
    vector<int> dist(n + 1, -1);

    q.push(1);
    dist[1] = 1; 

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neigh : graph[node]) {
            if (dist[neigh] == -1) {
                dist[neigh] = dist[node] + 1;
                parent[neigh] = node;
                q.push(neigh);
            }
        }
    }

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << dist[n] << "\n";
    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());
    for (int x : path) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
