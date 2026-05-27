#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);
    vector<int> indeg(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indeg[b]++;
    }

    vector<long long> dp(n+1,0);
    dp[1]=1;

    queue<int> q;

    for(int i=1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v:graph[u]){
            dp[v]=(dp[v]+dp[u])%MOD;
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }

    cout<<dp[n]<<endl;
}