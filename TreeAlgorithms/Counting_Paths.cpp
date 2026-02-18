#include<bits/stdc++.h>
using namespace std;
static const int MAXN = 200000;
static const int LOG = 20;   // because 2^18 > 2e5

vector<int> tree[MAXN + 1];
int up[MAXN + 1][LOG];
int depth[MAXN + 1];
long long cnt[MAXN+1];
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
int lift(int a,int k){
    for(int i=0;i<LOG;i++){
        if(k&(1<<i)){
            a=up[a][i];
        }
    }
    return a;
}
int lca(int a,int b){
    if(depth[a]<depth[b]){
        swap(a,b);
    }
   a=lift(a,depth[a]-depth[b]);
   if(a==b)return a;
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
void dfs2(int v, int p){
    for(int to : tree[v]){
        if(to == p) continue;
        dfs2(to, v);
        cnt[v] += cnt[to];
    }
}

int main()
{
int n,m;
cin>>n>>m;
for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
}
depth[1]=0;
dfs(1,0);
// precompute table
for(int j=1;j<LOG;j++){
    for(int i=1;i<=n;i++){
        up[i][j]=up[up[i][j-1]][j-1];
    }
}
while(m--){
    int a,b;
    cin>>a>>b;
    int c=lca(a,b);
    cnt[a]++;
    cnt[b]++;
    cnt[c]--;
    if(up[c][0] != 0)
    cnt[up[c][0]]--;

}
dfs2(1,0);
for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";

return 0;
}