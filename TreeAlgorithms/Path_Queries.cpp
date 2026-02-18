#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> tree;

vector<int> tin, tout;

vector<ll> vals;

vector<ll> euler;

vector<ll> seg;

int timer = 0;

int n,q;




void dfs(int v,int p)
{
    tin[v] = timer;

    euler[timer] = vals[v];

    timer++;

    for(int to : tree[v])
    {
        if(to==p) continue;

        dfs(to,v);
    }

    tout[v] = timer;

    euler[timer] = -vals[v];

    timer++;
}




void build(int i,int l,int r)
{
    if(l==r)
    {
        seg[i] = euler[l];
        return;
    }

    int mid=(l+r)/2;

    build(2*i+1,l,mid);
    build(2*i+2,mid+1,r);

    seg[i] = seg[2*i+1] + seg[2*i+2];
}



void update(int i,int l,int r,int idx,ll val)
{
    if(l==r)
    {
        seg[i] += val;
        return;
    }

    int mid=(l+r)/2;

    if(idx<=mid)
        update(2*i+1,l,mid,idx,val);

    else
        update(2*i+2,mid+1,r,idx,val);

    seg[i] = seg[2*i+1] + seg[2*i+2];
}



ll query(int i,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql) return 0;

    if(l>=ql && r<=qr)
        return seg[i];

    int mid=(l+r)/2;

    return query(2*i+1,l,mid,ql,qr)
         + query(2*i+2,mid+1,r,ql,qr);
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>n>>q;

    tree.resize(n+1);

    vals.resize(n+1);

    tin.resize(n+1);

    tout.resize(n+1);


    for(int i=1;i<=n;i++)
        cin>>vals[i];


    for(int i=0;i<n-1;i++)
    {
        int a,b;

        cin>>a>>b;

        tree[a].push_back(b);

        tree[b].push_back(a);
    }



    // Euler array size = 2*n
    euler.resize(2*n);

    dfs(1,0);



    seg.resize(8*n);

    build(0,0,2*n-1);




    while(q--)
    {
        int type;

        cin>>type;


        if(type==1)
        {
            int s;

            ll x;

            cin>>s>>x;

            ll diff = x - vals[s];

            vals[s] = x;


            // update entry
            update(0,0,2*n-1,tin[s],diff);

            // update exit
            update(0,0,2*n-1,tout[s],-diff);
        }


        else
        {
            int s;

            cin>>s;


            // prefix sum query
            cout<<query(0,0,2*n-1,0,tin[s])<<"\n";
        }
    }
}
