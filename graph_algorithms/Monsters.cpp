#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n,m;

vector<pair<int,int>> dir = {
    {1,0},{-1,0},{0,1},{0,-1}
};

string dch = "DURL";

int main()
{
    cin>>n>>m;

    vector<string> grid(n);

    for(auto &x:grid)
    cin>>x;

    queue<pair<int,int>> q;

    vector<vector<int>> monster(n,vector<int>(m,1e9));

    vector<vector<int>> dist(n,vector<int>(m,1e9));

    pair<int,int> start;

  
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]=='M')
        {
            q.push({i,j});
            monster[i][j]=0;
        }

        if(grid[i][j]=='A')
        start={i,j};
    }


    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();

        for(auto [dx,dy]:dir)
        {
            int nx=x+dx;
            int ny=y+dy;

            if(nx>=0 && ny>=0 && nx<n && ny<m
               && grid[nx][ny]!='#'
               && monster[nx][ny]>monster[x][y]+1)
            {
                monster[nx][ny]=monster[x][y]+1;
                q.push({nx,ny});
            }
        }
    }


    queue<pair<int,int>> q2;

    q2.push(start);

    dist[start.first][start.second]=0;

    vector<vector<pair<int,int>>> parent(n,
    vector<pair<int,int>>(m,{-1,-1}));

    vector<vector<char>> move(n,
    vector<char>(m));

    while(!q2.empty())
    {
        auto [x,y]=q2.front();
        q2.pop();

        if(x==0||y==0||x==n-1||y==m-1)
        {
            cout<<"YES\n";

            string path;

            while(parent[x][y]!=make_pair(-1,-1))
            {
                path.push_back(move[x][y]);

                auto p=parent[x][y];

                x=p.first;
                y=p.second;
            }

            reverse(path.begin(),path.end());

            cout<<path.size()<<"\n";
            cout<<path<<"\n";

            return 0;
        }

        for(int i=0;i<4;i++)
        {
            int nx=x+dir[i].first;
            int ny=y+dir[i].second;

            if(nx>=0 && ny>=0 && nx<n && ny<m
               && grid[nx][ny]!='#'
               && dist[nx][ny]==1e9
               && dist[x][y]+1 < monster[nx][ny])
            {
                dist[nx][ny]=dist[x][y]+1;

                parent[nx][ny]={x,y};

                move[nx][ny]=dch[i];

                q2.push({nx,ny});
            }
        }
    }

    cout<<"NO\n";
}