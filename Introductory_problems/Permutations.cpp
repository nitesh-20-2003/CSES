#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return;
    }

    // print evens
    for (int i = 2; i <= n; i += 2) cout << i << " ";
    // then odds
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
