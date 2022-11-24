#include <bits/stdc++.h>
#pragma GCC("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
#define ll  long long
#define db  double
#define vl  vector<ll>
#define pii pair<int, int>
#define pll  pair<ll, ll>
#define vpii vector<pii>
#define vpll  vector<pll>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
const int MAXN = 400000 + 77;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll n, m, x, y, times = 0;
vpll edge, ans;
vl adj[MAXN], mark(MAXN);
bool used[MAXN];
ll visited[MAXN];

bool dfs(int u) {
    if(visited[u] != times) 
        visited[u] = times;
    else 
        return false;
    for(int v : adj[u]) 
        if(!mark[v] || dfs(mark[v])) {
            mark[v] = u;
            return true;
        }
    return false;
}

void solve() {
    cin >> n >> m;
    while(cin >> x >> y) edge.pb({x, y});
    ll cnt = 0;
    for(int i = 0; i < edge.size(); i++)
        adj[edge[i].fi].pb(edge[i].se);
    for(int i = 1; i <= n; i++) {
        times++;
        cnt += dfs(i);
    }
    cout << cnt << '\n';
    for(int i = 1; i <= m; i++) 
        if(int j = mark[i]) 
            cout << j << " " << i << '\n';
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
