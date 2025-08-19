#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tickets.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto it = tickets.upper_bound(t); 
        if (it == tickets.begin()) {
            cout << -1 << "\n"; 
        } else {
            --it; 
            cout << *it << "\n";
            tickets.erase(it); 
        }
    }
}

int main() {
    fastio;
    solve();
    return 0;
}
