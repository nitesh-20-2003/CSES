#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define umi unordered_map<int,int>
#define vi vector<int>
#define mh priority_queue<int,vi>
#define mhi priority_queue<int,vi,greater<int>>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define vpll vector<pll>
#define vpii vector<pii>
#define vpdd vector<pdd>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvpii vector<vpii>
#define vvpll ve ctor<vpll>
#define vvvi vector<vvi>

// Macros
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define yn(ans) printf("%s\n", (ans) ? "Yes" : "No")
#define YN(ans) printf("%s\n", (ans) ? "YES" : "NO")
#define FOR(i, s, e, t) for (int (i) = (s); (i) < (e); (i) += (t))
#define REP(i, e) for (int i = 0; i < (e); ++i)
#define REP1(i, s, e) for (int i = (s); i < (e); ++i)
#define RREP(i, e) for (int i = (e); i >= 0; --i)
#define RREP1(i, e, s) for (int i = (e); i >= (s); --i)
#define DEBUG printf("%d\n", __LINE__); fflush(stdout);

// Constants
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
ll inf = 1e18;

// Fast I/O
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Random Number Generator
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());


// Solution Template
void solve(string input,string output) {
    if(sz(input)==0){
        cout<<output<<endl;
        return;
    }
        REP(i,sz(input)){
            char ch=input[i];
            string left=input.substr(0,i);
            string right=input.substr(i+1,sz(input));
            solve(left+right,output+ch);
         }
}
// optimized code using backtracking
int perm_count=0;
void backtrack(string &input ,int idx)

{
    if(idx==sz(input)-1){

        cout<<input<<endl;
        perm_count++;
        return;
    }
        REP1(i,idx,sz(input)){
            swap(input[i],input[idx]); 
            backtrack(input,idx+1);
            swap(input[i],input[idx]);
        }
}

int main() {
    fastio;
    string input;
    cin>>input;
        backtrack(input,0);
        cout<<perm_count<<endl;
    // solve(input,"");
    return 0;
}