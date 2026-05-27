#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>graph;
vector<int>result;

// void dfs(int node,vector<int>&curr,vector<bool>&visited){

//     if(node==n){
//         if(curr.size()>result.size()){
//             result=curr;
//         }
//         return;
//     }

//     for(auto v:graph[node]){
//         if(!visited[v]){
//             curr.push_back(v);
//             visited[v]=true;

//             dfs(v,curr,visited);

//             curr.pop_back();
//             visited[v]=false;
//         }
//     }
// }

int main(){

    cin>>n>>m;

    graph.resize(n+1);

    while(m--){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    vector<int>indegree(n+1,0);
    for(int u=1;u<=n;u++){
        for(int v:graph[u])indegree[v]++;
    }
    queue<int>q;
    vector<int>order;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }
     while(!q.empty()){
        int u=q.front();
        q.pop();
        order.push_back(u);
        for(int v:graph[u]){
            indegree[v]--;
            if(!indegree[v])q.push(v);
        }
     }
     vector<int>dp(n+1,INT_MIN);
     vector<int>parent(n+1,-1);
     dp[1]=0;
     for(int u:order){
        if(dp[u]==INT_MIN)continue;
       for(int v:graph[u]){
    if(dp[v] < dp[u] + 1){
        dp[v] = dp[u] + 1;
        parent[v] = u;
    }
}
     }
     if(dp[n]==INT_MIN){
        cout<<"IMPOSSIBLE\n";
        return 0;
     }
     vector<int>path;
     int curr=n;
     while(curr!=-1){
        path.push_back(curr);
        curr=parent[curr];
     }
     reverse(path.begin(),path.end());
     cout<<path.size()<<'\n';
     for(auto e:path)cout<<e<<" ";
     cout<<endl;
     return 0;
}