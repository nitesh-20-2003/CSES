#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> a;
vector<vector<bool>> vis;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = true;

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int k=0; k<4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && a[nx][ny]=='.') {
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    a.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m,false));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];

    int rooms = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j]=='.' && !vis[i][j]) {
                bfs(i,j);
                rooms++;
            }
        }
    }

    cout << rooms << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
