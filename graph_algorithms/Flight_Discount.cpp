#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,int>
const ll INF=1e18;
vector<vector<pair<int,int>>>graph;

int main()
{
 int n,m;
 cin>>n>>m;
 graph.resize(n+1);
while(m--){
    int a,b,c;
    cin>>a>>b>>c;
    graph[a].push_back({b,c});
}
vector<vector<ll>>dist(n+1,vector<ll>(2,INF));
dist[1][0]=0;
priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<>>pq;
pq.push({0,1,0});// cost,node,state
while(!pq.empty()){
    auto [currDist,node,used]=pq.top();
    pq.pop();
    if(currDist>dist[node][used])continue;
    for(auto [nbr,w]:graph[node]){
        if(used==0){
            if(currDist+w<dist[nbr][0]){
                dist[nbr][0]=currDist+w;
                pq.push({dist[nbr][0],nbr,0});
            }
            if(currDist+floor(w/2)<dist[nbr][1]){
                dist[nbr][1]=currDist+w/2;
                pq.push({dist[nbr][1],nbr,1});
            }
            
        }
        else{
            if(currDist+w<dist[nbr][1]){
                dist[nbr][1]=currDist+w;
                pq.push({dist[nbr][1],nbr,1});
            }
        }
    }

}
cout<<dist[n][1]<<endl;
return 0;
}