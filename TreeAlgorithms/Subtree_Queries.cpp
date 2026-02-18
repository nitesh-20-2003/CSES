#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>tree;
vector<ll>tin;
vector<ll>tout;
vector<ll>vals;
ll timer=0;
void dfs(ll v,ll p){
    tin[v]=++timer;
    for(ll to:tree[v]){
        if(to==p)continue;
        dfs(to,v);
    }
    tout[v]=timer;
}
void build(ll i,ll l,ll r,vector<ll>&seg,vector<ll>&arr){
    if(l==r){
        seg[i]=arr[l];
        return;
    }
    ll mid=l+(r-l)/2;
    build(2*i+1,l,mid,seg,arr);
    build(2*i+2,mid+1,r,seg,arr);
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
// poll update
void update(ll idx,ll val,ll i,ll l,ll r,vector<ll>&seg){
    if(l==r){
        seg[i]=val;
        return;
    }
    ll mid=(l+r)/2;
    if(idx<=mid){
        update(idx,val,2*i+1,l,mid,seg);
    }
    else{
        update(idx,val,2*i+2,mid+1,r,seg);
    }
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
// range query
 ll querySegmentTree(ll start, ll end, ll i, ll l, ll r, vector<ll>& segmentTree) {
        if(l > end || r < start) {
            return 0;
        }
        
        if(l >= start && r <= end) {
            return segmentTree[i];
        }
        
        ll mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l,    mid, segmentTree) + 
               querySegmentTree(start, end, 2*i+2, mid+1, r, segmentTree);
    }
int main()
{
ll n,q;
cin>>n>>q;
tree.resize(n+1);
vals.resize(n+1);
tin.resize(n+1);
tout.resize(n+1);
for(ll i=1;i<=n;i++)cin>>vals[i];
ll k=n-1;
while(k--){
    ll a,b;
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);

}
dfs(1,0);
vector<ll> flat(n+1);
for(ll i=1;i<=n;i++){
    flat[tin[i]] = vals[i];
}

vector<ll> seg(4*n);
build(0,1,n,seg,flat);
while(q--){
    ll type;
    cin>>type;

    if(type==1){
        ll s,x;
        cin>>s>>x;

       
        vals[s] = x;

     
        update(tin[s], x, 0, 1, n, seg);
    }
    else{
        ll s;
        cin>>s;

        ll ans = querySegmentTree(tin[s], tout[s], 0, 1, n, seg);
        cout << ans << "\n";
    }
}

return 0;
}