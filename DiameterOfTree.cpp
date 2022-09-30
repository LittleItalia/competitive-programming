// Minh Tú 

#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define db  double
#define pll  pair<ll, ll>
#define vl  vector<ll>
#define vpll  vector<pll>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define fi first
#define pb push_back
#define se second
#define sqr(i) i * i
#define MASK(i) (1ll << (i))
#define BIT(x, i) (((x) >> (i)) & 1) // lấy ra bit thứ i của số x
// x << y :  x * (2 ^ y) 
// x >> y :  x / (2 ^ y)
const int MAXN = 70000;
const int LOG = 17;
const ll MOD = 998244353;

int n, k, query, m, d, subtask;
vector<int> adj[MAXN]; 
int dp2[MAXN], dp1[MAXN];
vector<pair<int, int>> res[MAXN]; 

void dfs(int u, int p) {
    res[u].pb({-1e8, 0});
    res[u].pb({-1e8, 0});
    for(int v : adj[u]) 
        if(v != p) {
            dfs(v, u);
            dp1[u] = max(dp1[u], dp1[v] + 1);
            res[u].pb({dp1[v] + 1, v});
        }
    sort(res[u].begin(), res[u].end());
    reverse(res[u].begin(), res[u].end());
}

void dfs1(int u, int par, int val) {
    dp2[u] = max(dp2[u], val);
    for(int v : adj[u]) {
        if(v == par) continue;
        if(res[u][0].se == v) 
            dfs1(v, u, max(val + 1, res[u][1].fi + 1));
        else
            dfs1(v, u, max(val + 1, res[u][0].fi + 1));
    }
}

void solve() { 
    cin >> subtask >> n;
    for(int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    dfs(1, 1);
    dfs1(1, 1, -1e8);
    int ans = 0;
        for(int i = 1; i <= n; i++) 
        ans = max({ans, dp1[i], dp2[i]});
    cout << ans << '\n';
} 

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    freopen("diameter.inp", "r", stdin);
    freopen("diameter.out", "w", stdout);
    #endif
    solve();
}

