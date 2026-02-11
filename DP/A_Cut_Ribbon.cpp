#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
vector<int> dp;

int solve(int len) {
    if (len == 0) return 0;        // exact cut
    if (len < 0) return -1e9;      // impossible
    if (dp[len] != -1) return dp[len];

    int res = max({1 + solve(len - a), 
                   1 + solve(len - b), 
                   1 + solve(len - c)});
    return dp[len] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> b >> c;
    dp.assign(n + 1, -1);

    cout << solve(n) << "\n";
    return 0;
}
