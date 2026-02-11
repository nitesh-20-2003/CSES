#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<array<int,2>> dp;

void dfs(int u, int p) {
    long long base = 0;

    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        base += dp[v][0];
    }

    // u is matched with its parent
    dp[u][1] = base;

    // u is not matched with its parent
    long long best = base;

    for (int v : g[u]) {
        if (v == p) continue;
        long long cand = base - dp[v][0] + dp[v][1] + 1;
        best = max(best, cand);
    }

    dp[u][0] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    g.assign(n + 1, {});
    dp.assign(n + 1, {0, 0});

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    cout << dp[1][0] << "\n";
}
