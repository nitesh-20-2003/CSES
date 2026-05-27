#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>graph;
vector<bool>visited,recStack;
vector<int>parent;
int cycleStart=-1;
int cycleEnd=-1;
bool dfs(int u){
    visited[u]=true;
    recStack[u]=true;
    for(int v:graph[u]){
        if(!visited[v]){
            parent[v]=u;
            if(dfs(v))return true;
        } else if(recStack[v]){
            cycleEnd=u;
            cycleStart=v;
            return true;
        }

    }
    recStack[u]=false;
    return false;
}
int main(){
    cin>>n>>m;
    graph.resize(n+1);
    visited.resize(n+1,false);
    recStack.resize(n+1,false);
    parent.resize(n+1,0);
    while(m--){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    for(int u=1;u<=n;u++){
        if(!visited[u]&&dfs(u))break;

    }
    if(cycleStart==-1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int>cycle;
    cycle.push_back(cycleStart);
    for(int v=cycleEnd;v!=cycleStart;v=parent[v]){
        cycle.push_back(v);
    }
    cycle.push_back(cycleStart);
    reverse(cycle.begin(),cycle.end());
    cout<<cycle.size()<<"\n";
    for(auto a:cycle)cout<<a<<" ";
    return 0;

}