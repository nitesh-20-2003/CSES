#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> parent;
vector<int> visited;

int start = -1, endd = -1;

bool dfs(int node, int par)
{
    visited[node] = 1;
    parent[node] = par;

    for(int neigh : g[node])
    {
        if(neigh == par) continue;

        if(visited[neigh])
        {
            start = neigh;
            endd = node;
            return true;
        }

        if(!visited[neigh])
        {
            if(dfs(neigh, node))
                return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    g.resize(n+1);
    visited.resize(n+1, 0);
    parent.resize(n+1, -1);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,-1))
                break;
        }
    }

    if(start == -1)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;

    cycle.push_back(start);

    int curr = endd;

    while(curr != start)
    {
        cycle.push_back(curr);
        curr = parent[curr];
    }

    cycle.push_back(start);

    reverse(cycle.begin(), cycle.end());

    cout<<cycle.size()<<"\n";

    for(int x : cycle)
        cout<<x<<" ";
}