#include<bits/stdc++.h>
using namespace std;
#define pt pair<long long,long long>
vector<vector<pt>>graph;
long long sz=0;
unordered_map<long long,long long> dij(){
    unordered_map<long long,long long>dist;// to calcualte distance of node i from start
    set<long long>visited;
    for(long long i=1;i<=sz;i++){
        dist[i]= LONG_MAX;
    }
    dist[1]=0;
    priority_queue<pt,vector<pt>,greater<pt>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,node]=pq.top();
        pq.pop();
        if(visited.count(node))continue;
        visited.insert(node);
        for(auto [neighbor, weight]:graph[node]){
            if(!visited.count(neighbor)){
                if(dist[neighbor]>dist[node]+weight){
                    dist[neighbor]=dist[node]+weight;
                    pq.push({dist[neighbor],neighbor});
                }

            }
        }
    }
    return dist;
}
int main(){
    long long n,m;
    cin>>n>>m;
    sz=n;
    graph.resize(n+1);
    while(m--){
        long long a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
   auto distance= dij();
   vector<long long>ans(n+1);
   for(auto [key,val]:distance){
    ans[key]=val;
   }
   for(long long i=1;i<=n;i++)cout<<ans[i]<<" ";

   cout<<"\n";
   return 0;

}

