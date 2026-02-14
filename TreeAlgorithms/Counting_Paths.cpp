#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 200005;
const int LOG = 20;

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
long long cnt[MAXN];
int parent[MAXN];
int n, m;

void dfs_lca(int u, int p) {
    parent[u] = p;
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[ up[u][i-1] ][i-1];
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs_lca(v, u);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++) {
        if (diff & (1 << i))
            a = up[a][i];
    }

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return parent[a];
}

void dfs_accumulate(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_accumulate(v, u);
        cnt[u] += cnt[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        cnt[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    depth[1] = 0;
    dfs_lca(1, 0);

    while (m--) {
        int a, b;
        cin >> a >> b;

        int L = lca(a, b);

        cnt[a] += 1;
        cnt[b] += 1;
        cnt[L] -= 1;

        if (parent[L] != 0)
            cnt[parent[L]] -= 1;
    }

    dfs_accumulate(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}
