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
ll inf = 1e18;
#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238

// Directions for grid movement
int dx[4] = {0, 0, -1, 1}; // Left, Right, Up, Down
int dy[4] = {-1, 1, 0, 0};

// Check if a position is valid inside the grid
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// Fast I/O
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Random Number Generator
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

// Mathematical Functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll modExp(ll x, ll y, ll p) {
    ll res = 1; x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1; x = (x * x) % p;
    }
    return res;
}
bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
vi findFactors(int n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i)
                factors.push_back(n / i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}
vector<int> primeFactors(int n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}
vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
    return prime;
}
vector<ll> fact(100001, 1);
void precomputeFactorial(int n, ll mod) {
    for (int i = 2; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}
ll modInverse(ll n, ll mod) { return modExp(n, mod - 2, mod); }
ll nCr(ll n, ll r, ll mod) {
    if (r > n) return 0;
    return (fact[n] * modInverse(fact[r], mod) % mod * modInverse(fact[n - r], mod) % mod) % mod;
}

// Solution Template
void solve() {
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) {
        cin >> a[i];
    }
    ll res=a[0];
    ll maxEnding=a[0];
    for(int i=1;i<n;i++){
        maxEnding=max(a[i],maxEnding+a[i]);
        res=max(res,maxEnding);
    }
    cout<<res<<endl;
}

int main() {
    fastio;
    int t;
   t=1;
    while (t--) {
        solve();
    }
    return 0;
}