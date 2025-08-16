#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll solve(vector<ll> arr, ll N)
{
    
    ll ans = 0;
  
    for (ll i = 1; i < N; i++) {
        if (arr[i - 1] > arr[i]) {
            ans += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }
    // for(int i=0;i<N;i++)cout<<arr[i]<<" ";
    // cout<<endl;
    return ans;
}

int main()
{
    
    
   int n;
   cin>>n;
   vector<ll>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   cout<<solve(arr,n);
    return 0;
}