#include <bits/stdc++.h>
#pragma GCC("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
#define ll  long long
#define db  double
#define str string
#define vl  vector<ll>
#define pii pair<int, int>
#define pll  pair<ll, ll>
#define vpii vector<pii>
#define vpll  vector<pll>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(x) x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sqr(i) i * i
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define turn_on(i, m) (m |= (1LL << i))
#define turn_off(i, m) (m &= ~(1LL << i))
#define MASK(i) (1ll << (i))
#define BIT(x, i) (((x) >> (i)) & 1) 
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const double eps = 1e-9;
const int LOG = 17;
// const ll INF = 1e18;

// ----------------------------------------
const int maxn = 2e5 + 7;
const int base = 44;
ll mod[] = {(ll)1e9 + 2277, (ll)1e9 + 5277};
ll n, k;
string ans;
vector<string> arr(maxn);
pair<ll, ll> hashVal[51][maxn];
ll pw1[maxn], pw2[maxn];

void precalc() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i < maxn; i++) {
        pw1[i] = (pw1[i - 1] * base) % mod[0];
        pw2[i] = (pw2[i - 1] * base) % mod[1];
    }
}

void Build_Hash(string s, ll pos) {
    for(int i = 1; i < s.size(); i++) {
        hashVal[pos][i].fi = (hashVal[pos][i - 1].fi * base + (s[i] - 'A' + 1)) % mod[0];
        hashVal[pos][i].se = (hashVal[pos][i - 1].se * base + (s[i] - 'A' + 1)) % mod[1];
    }
}

pll getHash(int pos, int l, int r) {
    return mp((hashVal[pos][r].fi - hashVal[pos][l - 1].fi * pw1[r - l + 1] + mod[0] * mod[0]) % mod[0]
        , (hashVal[pos][r].se - hashVal[pos][l - 1].se * pw2[r - l + 1] + mod[1] * mod[1]) % mod[1]);
}

bool check(ll len) {
    map<pll, ll> res;
    for(int i = 0; i < n; i++) {
        map<pll, ll> cnt;
        for(int j = 1; j < (int)arr[i].size() - len + 1; j++) 
            cnt[getHash(i, j, j + len - 1)]++;
        for(auto x : cnt) res[x.fi]++;
    }
    for(auto x : res) 
        if(x.se >= k) {
            for(int i = 0; i < n; i++) 
                for(int j = 1; j < (int)arr[i].size() - len + 1; j++) {
                    pll tmp = getHash(i, j, j + len - 1);
                    if(tmp.fi == x.fi.fi && tmp.se == x.fi.se) {
                        ans = arr[i].substr(j, len);;
                        return true;
                    }   
                }
        }
    return false;
}

void solve() {
    memset(hashVal, 0, sizeof(hashVal));
    cin >> n >> k;
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    for(int i = 0; i < n; i++) arr[i] = '.' + arr[i];
    for(int i = 0; i < n; i++) Build_Hash(arr[i], i);
}

int main(){ 
    // clock_t tStart = clock();
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    freopen("thuyvan.inp", "r", stdin);
    freopen("thuyvan.out", "w", stdout);
    #endif
    precalc();
    bool ok = false;
    if(ok) {
        int t; cin >> t;
        while(t--)  solve();
    }   
    else
        solve();
    // clog << "\nTime taken: "<<(((double)clock() - tStart)/CLOCKS_PER_SEC) << "s"; 
}



