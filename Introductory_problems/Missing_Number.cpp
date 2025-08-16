#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1);

    for (int i = 0; i < n - 1; i++) cin >> a[i];

    int allxor = 0, currxor = 0;
    for (int i = 1; i <= n; i++) allxor ^= i;
    for (int i = 0; i < n - 1; i++) currxor ^= a[i];

    cout << (allxor ^ currxor) << "\n";
    return 0;
}
