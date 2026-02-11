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
#define vvpll vector<vpll>
#define vvvi vector<vvi>

// Macros
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define yn(ans) printf("%s\n", (ans) ? "Yes" : "No")
#define YN(ans) printf("%s\n", (ans) ? "YES" : "NO")
#define FOR(i, s, e, t) for (int (i) = (s); (i) < (e); (i) += (t))
#define rep(i, e) for (int i = 0; i < (e); ++i)
#define rep1(i, s, e) for (int i = (s); i < (e); ++i)
#define rrep(i, e) for (int i = (e); i >= 0; --i)
#define rrep1(i, e, s) for (int i = (e); i >= (s); --i)
#define DEBUG printf("%d\n", __LINE__); fflush(stdout);

// Constants
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;
ll inf = 1e18;

// Fast I/O
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Random Number Generator
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

// Math Functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Modular Exponentiation
ll modExp(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}

// Modular Inverse (Fermat's Little Theorem)
ll modInverse(ll a, ll p) { return modExp(a, p - 2, p); }

// Factorial & Inverse Factorial Precomputation
const int MAX = 2e5 + 5;
ll fact[MAX], invFact[MAX];

void precomputeFactorials() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = modInverse(fact[MAX - 1], MOD);
    for (int i = MAX - 2; i >= 1; --i) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD);
}

// Sieve of Eratosthenes
vector<bool> isPrime;
void sieve(int n) {
    isPrime.assign(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}
// get primefactors of given no
 vector<int> getPrimeFactors(int n){
vector<int> factors;
for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
factors.push_back(i);
 while (n % i == 0) n /= i; 
}
 }
if (n > 1) factors.push_back(n); 
  return factors;
}

// Solution Template
void solve() {
 
    // Your code here
    int n,q;
    cin>>n>>q;
    vll a(n,0),b(n,0);
    rep(i,n)cin>>a[i];
    b[0]=a[0];
    for(int i=1;i<n;i++)b[i]=a[i]+b[i-1];
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(x==0){
            cout<<b[y]<<endl;
        }
        else{
            cout<<b[y]-b[x-1]<<endl;
        }
    }
    cout<<"\n";

}

int main() {
    fastio;
    precomputeFactorials();
    int t;
    t=1;
    while (t--) {
        solve();
    }
    return 0;
}
/*quu..__
 $$b  `---.__
  "$b        `--.                          ___.---uuudP
   `$b           `.__.------.__     __.---'      $$$$"              .
     "b          -'            `-.-'            $$$"              .'|
       ".                                       d$"             _.'  |
         `.   /                              ..."             .'     |
           `./                           ..::-'            _.'       |
              /                         .:::-'           .-'         |
             :                          ::''\          _.'            |
            .' .-.             .-.           `.      .'               |
            : /'$$|           .@"$\           `.   .'              _.-'
           .'|u$$|          |$$,$$|           |  <            _.-'
           | `:$$:'          :$$$$$:           `.  `.       .-'
           :                  `"--'             |    `-.     \
          :##.       ==             .###.       `.      `.    `\
          |##:                      :###:        |        >     >
          |#'     `..'`..'          `###'        x:      /     /
           \                                   xXX|     /    ./
            \                                xXXX'|    /   ./
            /`-.                                  `.  /   /
           :    `-  ...........,                   | /  .'
           |         ``:::::::'       .            |<    `.
           |             ```          |           x| \ `.:``.
           |                         .'    /'   xXX|  `:`M`M':.
           |    |                    ;    /:' xXXX'|  -'MMMMM:'
           `.  .'                   :    /:'       |-'MMMM.-'
            |  |                   .'   /'        .'MMM.-'
            `'`'                   :  ,'          |MMM<
              |                     `'            |tbap\
               \                                  :MM.-'
                \                 |              .''
                 \.               `.            /
                  /     .:::::::.. :           /
                 |     .:::::::::::`.         /
                 |   .:::------------\       /
                /   .''               >::'  /
                `',:                 :    .'
                                     `:.:'
*/