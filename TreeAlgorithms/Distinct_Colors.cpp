#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 200005;

vector<int> tree[MAX];

int color[MAX];

int answer[MAX];




set<int>* dfs(int v,int parent)
{
    // create set for current node
    set<int>* curr = new set<int>();

    curr->insert(color[v]);


    for(int child : tree[v])
    {
        if(child == parent) continue;

        set<int>* childSet = dfs(child, v);


        // always merge smaller into bigger
        if(childSet->size() > curr->size())
            swap(curr, childSet);


        // merge child into current
        for(int c : *childSet)
            curr->insert(c);

    }


    answer[v] = curr->size();

    return curr;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n;

    cin>>n;


    for(int i=1;i<=n;i++)
        cin>>color[i];


    for(int i=0;i<n-1;i++)
    {
        int a,b;

        cin>>a>>b;

        tree[a].push_back(b);

        tree[b].push_back(a);
    }


    dfs(1,0);


    for(int i=1;i<=n;i++)
        cout<<answer[i]<<" ";

}
