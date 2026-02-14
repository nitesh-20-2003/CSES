#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000;
static const int LOG = 20;   // because 2^18 > 2e5

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

int lift(int v, int k)
{
    for (int i = 0; i < LOG; i++)
        if (k & (1 << i))
            v = up[v][i];
    return v;
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    // bring a and b to same depth
    a = lift(a, depth[a] - depth[b]);

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

    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        tree[p].push_back(i);
        tree[i].push_back(p);
    }

    depth[1] = 0;
    dfs(1, 0);

    //  precompute ,build binary lifting table
    for (int j = 1; j < LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[ up[i][j - 1] ][j - 1];
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}
