#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int n, x;
vector<int> coins;
vector<int> dp;

int solve(int s) {
    if (s == 0) return 0;
    if (s < 0) return INF;
    if (dp[s] != -1) return dp[s];

    int best = INF;
    for (int c : coins) {
        best = min(best, solve(s - c) + 1);
    }
    return dp[s] = best;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    coins.resize(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    dp.assign(x + 1, -1);

    int ans = solve(x);
    cout << (ans >= INF ? -1 : ans) << "\n";
}
