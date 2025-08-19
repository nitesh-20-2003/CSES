#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
sort(a.begin(),a.end());
    long long  reach=0;
    for(auto c:a){
        if(c<=reach+1){
            reach+=c;
        }
        else {
            cout<<reach+1<<endl;
            return 0;
        }
    }
    cout<<reach+1<<endl;
    return 0;
}
