#include <bits/stdc++.h>
using namespace std;

const int MAXLOG = 20;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> dp(n + 1, vector<int>(MAXLOG, -1));

    // dp[i][0] = direct boss
    for (int i = 2; i <= n; i++) {
        cin >> dp[i][0];
    }

    // precompute
    for (int j = 1; j < MAXLOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[ dp[i][j - 1] ][j - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int j = 0; j < MAXLOG; j++) {
            if (x == -1) break;
            if (k & (1 << j)) {
                x = dp[x][j];
            }
        }

        cout << x << "\n";
    }

    return 0;
}
