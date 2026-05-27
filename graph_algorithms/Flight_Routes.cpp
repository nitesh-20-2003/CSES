#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

int main(){

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,int>>> graph(n+1);

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    vector<int> cnt(n+1,0);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0,1});

    while(!pq.empty()){
        auto [dist,node]=pq.top();
        pq.pop();

        cnt[node]++;

        if(cnt[node]>k) continue;

        if(node==n) cout<<dist<<" ";

        for(auto [next,w]:graph[node]){
            pq.push({dist+w,next});
        }
    }

}