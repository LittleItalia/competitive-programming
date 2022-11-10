// Tim luong cuc dai 

#include <bits/stdc++.h>
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
// x << y :  x * (2 ^ y) 
// x >> y :  x / (2 ^ y)
// (((x) >> i) & 1) : lay ra bit thu i cua x
// (m |= (1LL << i)) : bat bit thu i cua m len
// (m &= ~(1LL << i)) : tat bit thu i cua m
// __builtin_clz(n)) : dem so luong so 0 dung dau 
// __builtin_ctz(n)) : dem so luong so 0 dung cuoi
// __builtin_popcount(n) : dem so luong so 1 trong bit
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MAXN = 2000;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double eps = 1e-9;

ll n, m;
ll adj[MAXN][MAXN], par[MAXN], visited[MAXN];
ll arr[MAXN][MAXN];

bool dfs(int s, int t) {
    if(s == t) return true;
    visited[s] = true;
    for(int u = 1; u <= n; u++) 
        if(arr[s][u] > 0 && !visited[u]) {
            par[u] = s;
            if(dfs(u, t))
                return true;
        }
    return false;
}

ll Maximum_Flow(int s, int t) {
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            arr[i][j] = adj[i][j];
    ll res = 0, path_flow;
    while(dfs(s, t)) {
        memset(visited, false, sizeof(visited));
        path_flow = 1e18;
        for(int v = t; v != s; v = par[v]){
            int u = par[v];
            path_flow = min(path_flow, arr[u][v]);
        }
        for(int v = t; v != s; v = par[v]){
            int u = par[v];
            arr[u][v] -= path_flow;
            arr[v][u] += path_flow;
        }
        res += path_flow;
    }
    return res;
}

void solve() {
    memset(adj, 0, sizeof(adj));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }
    cout << Maximum_Flow(1, n);
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
