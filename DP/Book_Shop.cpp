#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> wts(n), pages(n);
    for (int i = 0; i < n; i++) cin >> wts[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= x; j++) {
            int notPick = dp[i+1][j];
            int pick = 0;
            if (wts[i] <= j) pick = pages[i] + dp[i+1][j - wts[i]];
            dp[i][j] = max(pick, notPick);
        }
    }

    cout << dp[0][x] << "\n";
}
