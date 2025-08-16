#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 1 << n; 
    for (int k = 0; k < total; k++) {
        int gray = k ^ (k >> 1);
        string s = "";
        for (int i = n - 1; i >= 0; i--) {
            s += ((gray >> i) & 1) ? '1' : '0';
        }
        cout << s << "\n";
    }
    return 0;
}
