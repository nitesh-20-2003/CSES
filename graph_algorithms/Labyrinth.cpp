#include<bits/stdc++.h>
using namespace std;

int n,m;

vector<pair<int,int>>dir = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

vector<char> moveChar = {
    'D','U','R','L'
};

int main()
{
    cin>>n>>m;

    vector<string> grid(n);

    for(auto &row:grid)
        cin>>row;

    queue<pair<int,int>>q;

    vector<vector<bool>>visited(n,vector<bool>(m,false));

    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m));

    vector<vector<char>>path(n,vector<char>(m));

    int sx,sy,ex,ey;

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]=='A')
        {
            sx=i;
            sy=j;
        }

        if(grid[i][j]=='B')
        {
            ex=i;
            ey=j;
        }
    }

    q.push({sx,sy});
    visited[sx][sy]=true;

    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=x+dir[i].first;
            int ny=y+dir[i].second;

            if(nx>=0 && ny>=0 && nx<n && ny<m &&
               !visited[nx][ny] && grid[nx][ny]!='#')
            {
                visited[nx][ny]=true;

                parent[nx][ny]={x,y};

                path[nx][ny]=moveChar[i];

                q.push({nx,ny});
            }
        }
    }

    if(!visited[ex][ey])
    {
        cout<<"NO";
        return 0;
    }

    cout<<"YES\n";

    string ans="";

    int x=ex,y=ey;

    while(x!=sx || y!=sy)
    {
        ans.push_back(path[x][y]);

        auto p=parent[x][y];

        x=p.first;
        y=p.second;
    }

    reverse(ans.begin(),ans.end());

    cout<<ans.size()<<"\n";

    cout<<ans;
}