#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> Edge;
int main(){
    int n,m;
    cin>>n>>m;
    vector<Edge>edges;
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    vector<ll>dist(n+1,0);
    vector<int>relaxant(n+1,-1);
    int x=-1;
    for(int i=0;i<n;i++){
        x=-1;
        for(auto [u,v,w]:edges){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                relaxant[v]=u;
                x=v;
            }
        }
    }
    if(x==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)x=relaxant[x];
    vector<int>cycle;
    for(int curr=x;;curr=relaxant[curr]){
        cycle.push_back(curr);
        if(curr==x&&cycle.size()>1)break;
    }
    reverse(cycle.begin(),cycle.end());
    cout<<"YES"<<endl;
    for(int node:cycle){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
}