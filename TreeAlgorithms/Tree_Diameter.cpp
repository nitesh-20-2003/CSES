#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;

pair<int,int> bfs(int src) {
    queue<int> q;
    vector<int> dist(tree.size(), -1);

    q.push(src);
    dist[src] = 0;

    int far = src;

    while(!q.empty()) {
        int u = q.front(); 
        q.pop();

        far = u;

        for(int v : tree[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return {far, dist[far]};
}

void solve() {
    int n;
    cin >> n;

    tree.assign(n + 1, {});

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // 1st bfs
    auto p1 = bfs(1);

    // 2nd bfs from farthest node
    auto p2 = bfs(p1.first);

    cout << p2.second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
