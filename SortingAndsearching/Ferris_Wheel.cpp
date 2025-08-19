#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>

void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    int result = 0;

    while (i <= j) {
        if (a[i] + a[j] <= x) {
         
            i++;
            j--;
        } else {
            
            j--;
        }
        result++;
    }

    cout << result << "\n";
}

int main() {
    fastio;
    solve();
    return 0;
}
