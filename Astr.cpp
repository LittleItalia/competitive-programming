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

#define PROBLEM "test"

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const double eps = 1e-9;
const int LOG = 17;
const ll INF = 1e18;

// ----------------------------------------
const ll MOD = 111539786;
ll n;
string s;
vector<vl> dp, nxt;

ll binpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

void precalc(string pat) {
    int m = pat.size();
    vector<vl>(2, vl(m, 0)).swap(nxt);
    
    nxt[pat[0] - '0'][0] = 1;
    for(int i = 0, j = 1; j < m; j++) {
        for(int c = 0; c < 2; c++) 
            nxt[c][j] = nxt[c][i];
        nxt[pat[j] - '0'][j] = j + 1;

        i = nxt[pat[j] - '0'][i];
    }
}

vector<vl> mul(vector<vl> m1, vector<vl> m2) {
    int len = m1.size();
    vector<vl> res(len, vl(len, 0));
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++)
            for(int k = 0; k < len; k++) 
                res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;
    return res;
}

vector<vl> matrixToPower(vector<vl> a, ll p) {
    if(p == 1) 
        return a;
    if(p & 1) 
        return mul(matrixToPower(a, p - 1), a);
    vector<vl> tmp = matrixToPower(a, p / 2);
    return mul(tmp, tmp);
}

void solve() {
    precalc(s);   

    vector<vl>(s.size() + 1, vl(s.size() + 1, 0)).swap(dp);

    for(int k = 0; k < 2; k++)
        for(int i = 0; i < s.size(); i++) 
            dp[i][nxt[k][i]]++;

    dp[s.size()][s.size()] = 2;
    dp = matrixToPower(dp, n);

    ll ans = dp[0][s.size()];
    ans = (binpow(2, n) - ans + MOD);
    ans %= MOD;

    cout << ans << '\n';
}

int main(){ 
    // clock_t tStart = clock();
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    if (fopen(PROBLEM".inp", "r")){
        freopen(PROBLEM".inp", "r", stdin);
        freopen(PROBLEM".out", "w", stdout);
    }
    while(cin >> n >> s)
        solve();
    // clog << "\nTime taken: "<<(((double)clock() - tStart)/CLOCKS_PER_SEC) << "s"; 
}



