#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    int i,j;
    i=j=0;
    int n=a.size();
    int mx=1;
    while(j<n){
        int count=0;
        while(a[i]==a[j]){
            count++;
            j++;
        }
        mx=max(mx,count);
        i=j;
    }
    cout<<mx<<endl;
    return 0;
}