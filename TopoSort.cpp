// Minh Tú 

#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define db  double
#define pll  pair<ll, ll>
#define pii pair<int, int>
#define vpii vector<pii>
#define vl  vector<ll>
#define vpll  vector<pll>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define fi first
#define pb push_back
#define se second
#define sqr(i) i * i
#define turn_on(i, m) (m |= (1LL << i))
#define turn_off(i, m) (m &= ~(1LL << i))
#define getbit(i, m) ((m >> i) & 1)
#define MASK(i) (1ll << (i))
#define BIT(x, i) (((x) >> (i)) & 1) // lấy ra bit thứ i của số x
// x << y :  x * (2 ^ y) 
// x >> y :  x / (2 ^ y)
// ((m >> i) & 1) : gia tri m co bit thu i bat
// (m |= (1LL << i)) : bat bit thu i cua m len
// (m &= ~(1LL << i)) : tat bit thu i cua m
const int MAXN = 200000;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 3e18 + 7;
const int N = 505;

int n, m;
int visited[MAXN], ans[MAXN];
vector<int> adj[MAXN];
stack<int> topo;

void dfs(int u) {
    visited[u] = 1;
    for(int v : adj[u]) {
        if(!visited[v]) 
            dfs(v);
    }
    topo.push(u);
    visited[u] = 2;
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for(int i = 1; i <= n; i++) 
        if(!visited[i]) dfs(i);
    int time = 0;
    while(topo.size()) {
        ans[topo.top()] = ++time;
        topo.pop();
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}

