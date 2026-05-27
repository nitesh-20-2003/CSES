#include<bits/stdc++.h>
using  namespace std;
#define ll long long
const ll INF=1e18;
const int mod=1e9+7;
#define pt pair<ll,ll>
vector<vector<pt>>graph;
int main(){
    ll n,m;
    cin>>n>>m;
    graph.resize(n+1);
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    priority_queue<pt,vector<pt>,greater<pt>>pq;// dist ,node
   
        /*dp[node]={
            min cost to reach node,
            no of shortest paths to node,
            min number of edges in those paths,
            max number of edges in those paths
            dp[1]={0,1,0,0}// starting at node 1 with cost 0 ,one path and 0 flights
        }*/ 
      vector<vector<ll>> dp(n+1, vector<ll>(4, INF));

dp[1][0] = 0;
dp[1][1] = 1;
dp[1][2] = 0;
dp[1][3] = 0;

pq.push({0,1});

while(!pq.empty()){
    auto [dist,node] = pq.top();
    pq.pop();

    if(dist > dp[node][0]) continue;

    for(auto [nbr,wt]:graph[node]){
        ll newDist = dist + wt;

        if(newDist < dp[nbr][0]){
            dp[nbr][0] = newDist;
            dp[nbr][1] = dp[node][1];
            dp[nbr][2] = dp[node][2] + 1;
            dp[nbr][3] = dp[node][3] + 1;

            pq.push({newDist, nbr});
        }
        else if(newDist == dp[nbr][0]){
            dp[nbr][1] = (dp[nbr][1] + dp[node][1]) % mod;
            dp[nbr][2] = min(dp[nbr][2], dp[node][2] + 1);
            dp[nbr][3] = max(dp[nbr][3], dp[node][3] + 1);
        }
    }
}
       cout<<dp[n][0]<<" "<<dp[n][1]<<" "<<dp[n][2]<<" "<<dp[n][3]<<"\n";

    return 0;
}