#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> color(n+1, 0);

    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v : g[u]) {
                    if(color[v] == 0) {
                        color[v] = 3 - color[u]; // switch: 1→2 or 2→1
                        q.push(v);
                    }
                    else if(color[v] == color[u]) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << color[i] << " ";

    return 0;
}
