#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000;
static const int LOG = 20;

vector<int> tree[MAXN + 1];
int up[MAXN + 1][LOG];
int depth[MAXN + 1];

void dfs(int v, int p)
{
    up[v][0] = p;

    for (int to : tree[v])
    {
        if (to == p) continue;
        depth[to] = depth[v] + 1;
        dfs(to, v);
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    int diff = depth[a] - depth[b];

    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i))
            a = up[a][i];

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[a][i] != 0 && up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        tree[i].clear();

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    depth[1] = 0;
    dfs(1, 0);

    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n; i++)
            up[i][j] = up[ up[i][j - 1] ][j - 1];

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        int c = lca(a, b);

        int dist = depth[a] + depth[b] - 2 * depth[c];
        cout << dist << "\n";
    }

    return 0;
}
