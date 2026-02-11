#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int>dp;
const int mod=1e9+7;
int ways(int x) {
    if (x == 0) return 1; 
    // if (x < 0) return 0;  
    if(dp[x]!=-1)return dp[x];
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
      if(x-a[i]>=0)  ans += ways(x - a[i]);
    }
    return dp[x]=ans;
}
int fbu(int x,int n)
{

vector<int>dp(x+1,0);
dp[0]=1;
for(int k=0;k<=x;k++){
    for(int i=0;i<a.size();i++){
        if(k-a[i]>=0){
            dp[k]=(dp[k]+dp[k-a[i]])%mod;
        }
    }
}
return dp[x];
}


int main() {
    int n, x;
    cin >> n >> x;
    dp.resize(x+1,-1);
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // cout << ways(x) << "\n";
    cout<<fbu(x,n);
    return 0;
}
