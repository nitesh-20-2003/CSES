#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;

vector<long long> sub, dp, ans;

void dfs1(int u, int p)
{
    sub[u] = 1;
    dp[u] = 0;

    for(int v : graph[u])
    {
        if(v == p) continue;

        dfs1(v, u);

        sub[u] += sub[v];
        dp[u] += dp[v] + sub[v];
    }
}

void dfs2(int u, int p)
{
    for(int v : graph[u])
    {
        if(v == p) continue;

        ans[v] = ans[u] - sub[v] + (n - sub[v]);
        dfs2(v, u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    graph.assign(n + 1, {});
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    sub.assign(n + 1, 0);
    dp.assign(n + 1, 0);
    ans.assign(n + 1, 0);

    dfs1(1, 0);

    ans[1] = dp[1];

    dfs2(1, 0);

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    return 0;
}
