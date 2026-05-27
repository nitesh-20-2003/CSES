#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>graph;
void topobfs(){
    vector<int>indegree(n+1);
    for(int i=1;i<=n;i++){
        for(auto v:graph[i]){
            indegree[v]++;
        }
    }
    queue<int>q;
    for(int i=1;i<indegree.size();i++){
        if(!indegree[i]){
         
            q.push(i);
        }
        
    }
    set<int>visited;
    int count=0;
    vector<int>order;
    while (!q.empty())
    {
        
        auto node=q.front();
        q.pop();
        order.push_back(node);
        visited.insert(node);
        
        for(auto v:graph[node]){
            indegree[v]--;
            if(!visited.count(v)&&!indegree[v]){
                q.push(v);
            }
        }
    }
    
    if(order.size()==n){
        for(auto ele:order)cout<<ele<<" ";
        cout<<'\n';
        return;
    }
    else cout<<"IMPOSSIBLE\n";

    
    
}
int  main(){
    cin>>n>>m;
    graph.resize(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    topobfs();


}