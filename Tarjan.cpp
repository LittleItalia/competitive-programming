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
const ll MAXN = 500005;

ll n, m, num[MAXN], low[MAXN], cnt = 0, ans = 0;
vl adj[MAXN];
bool del[MAXN];
stack<ll> st;

void visit(int u) {
    low[u] = num[u] = cnt++;
    st.push(u);
    for(int v : adj[u]) {
        if(del[v])
            continue;
        if(num[v])
            low[u] = min(low[u], num[v]);
        else {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(num[u] == low[u]) {  
        ans++;
        ll v;
        while(v != u) {
            v = st.top();
            st.pop();
            del[v] = true;
        } 
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for(int i = 1; i <= n; i++)
        if(!num[i])
            visit(i);
    cout << ans << '\n';
}   

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
