#include<bits/stdc++.h>
using namespace std;
int maxlog=30;
vector<vector<int>>up;
int query(int start,int jumps){
    int curr=start;
    for(int i=0;i<maxlog;i++){
        if(jumps&(1<<i)){
            curr=up[i][curr];
        }
    }
    return curr;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    up.assign(maxlog,vector<int>(n));
        // 1st ancestor
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        up[0][i]=x;
    }
    for(int i=1;i<maxlog;i++){// starting from 2nd row
        for(int j=0;j<n;j++){
            up[i][j]=up[i-1][up[i-1][j]]; 
        }

    }
    while(q--){
        int a,k;
        cin>>a>>k;
        a--;
        cout<<query(a,k)+1<<"\n";

    }

    return 0;
}