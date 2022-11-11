// Minh Tú 

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
const int MAXN = 1000 + 77;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double eps = 1e-9;

ll n, m, s, t;
ll level[MAXN], d[MAXN];
ll c[MAXN][MAXN];
vl adj[MAXN];
bool used[MAXN][MAXN];

bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) 
            if(level[v] == -1 && c[u][v] > 0) {
                q.push(v);
                level[v] = level[u] + 1;
            }
    }
    return level[t] > 0;
}

ll find_flow(ll u, ll t, ll flow) {
    if(u == t) 
        return flow;
    for(int v : adj[u]) 
        if(level[v] == level[u] + 1 && c[u][v] > 0) {
            ll val = find_flow(v, t, min(flow, c[u][v]));
            if(val > 0) {
                c[u][v] -= val;
                c[v][u] += val;
                return val;
            }
        }
    return 0;
}

ll Max_Flow(int s, int t) {
    ll res = 0;
    while(bfs(s, t)) {
        while(ll val = find_flow(s, t, 1e18))
            res += val;
    }
    return res;
}

void solve() {
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(v);
        adj[v].pb(u);
        c[u][v] += w;
    }
    ll res = Max_Flow(s, t);
    cout << res << '\n';;
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
