#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, result = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {  
            result++;
            i++; j++; 
        }
        else if (b[j] < a[i] - k) {  
            j++;  
        }
        else {  
            i++;  
        }
    }

    cout << result << "\n";
}

int main() {
    fastio;
    solve();
    return 0;
}
