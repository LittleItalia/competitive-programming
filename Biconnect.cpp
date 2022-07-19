#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using ll = long long;
using pll = pair<ll, ll>;
 using vl = vector<ll>;
using vb = vector<bool>;
using vpll = vector<pll>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
//pairs
#define mp make_pair
#define fi first
#define se second
#define MASK(i) (1LL << (i))

//vectors
#define pb push_back
#define pf push_front
// 1 << i :  2 ^ i
// x << y :  x * (2 ^ y) 
// x >> y :  x / (2 ^ y)
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int MAXN = 30005;

ll root[MAXN], active[MAXN], n, m;
bool vt[MAXN];
vl st, adj[MAXN];

ll find(ll u) {
    if(root[u] != u)
        root[u] = find(root[u]);
    return root[u];
}

void dfs(ll u) {
    vt[u] = true;
    root[u] = u;
    st.pb(u);
    for(int v : adj[u]) 
        if(vt[v]) {
            v = find(active[v]);
            while(st.back() != v) {
                root[find(st.back())] = v;
                st.pop_back();
            }
        }
    for(int v : adj[u]) 
        if(!vt[v]) {
            active[u] = v;
            dfs(v);
        }
    if(st.back() == u)
        st.pop_back();
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++) 
        if(!vt[i])
            dfs(i);
    
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
