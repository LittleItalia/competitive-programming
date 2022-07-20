
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vpll = vector<pll>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define fi first
#define se second
#define MASK(i) (1LL << (i))
#define pb push_back
#define pf push_front
#define MAX   100100
#define LOG   17

long long n, k;
int numNode;
vector<int> adj[MAX]; 
int par[MAX][LOG + 1]; 
int high[MAX]; 

void dfs(int u) {
    for(int v : adj[u]) 
        if(v != par[u][0]) {
            par[v][0] = u; 
            high[v] = high[u] + 1;
            dfs(v);
        }
}

void prepare() {
    high[0] = -1; 
    dfs(1);
    for(int j = 1; j <= LOG; j++) 
        for(int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int u, int v) {
    if(high[v] > high[u]) 
        return lca(v, u);
    for(int j = LOG; j >= 0; j--) 
        if(high[par[u][j]] >= high[v]) 
            u = par[u][j];
    if(u == v) 
        return u;
    for(int j = LOG; j >= 0; j--) 
        if(par[u][j] != par[v][j]) {
            u = par[u][j]; 
            v = par[v][j];
    }
    return par[u][0];
}

void solve() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    prepare();
    
} 

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}

