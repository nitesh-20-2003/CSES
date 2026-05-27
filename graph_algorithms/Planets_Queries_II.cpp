#include<bits/stdc++.h>
using namespace std;
vector<int>first;
int maxlog=30;
vector<vector<int>>up;
bool query(int start,int jumps,int target){
    int curr=start;
    for(int i=0;i<maxlog;i++){
        if(jumps&(1<<i)){
            curr=up[i][curr];
        }
    }
    return curr==target;
}
int  main(){
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    first.resize(n+1);
     up.assign(maxlog,vector<int>(n));
    // first ancestor
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        first[i]=x;
        up[0][i]=x;
    }
    // from 2nd row
    for(int i=1;i<maxlog;i++){
        for(int j=0;j<n;j++){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    while(q--){
        int src,dest;
        cin>>src>>dest;
        bool result=false;
        for(int i=0;i<maxlog;i++){
            if(query(src,i,dest)){
                cout<<i<<" ";
                result=true;
                break;
            }
        }
        if(!result){
            cout<<-1<<"  ";
        }

    }
    cout<<'\n';
    return 0;
}