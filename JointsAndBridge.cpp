// đếm số lượng đỉnh khớp và cạnh cầu trong đồ thị 

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
const int MAXN = 300005;

ll n, m, bridge = 0, timeDFS = 0;
ll low[MAXN], num[MAXN];
bool joint[MAXN];
vl adj[MAXN];

void dfs(int u, int par) {
    int child = 0;
    num[u] = low[u] = ++timeDFS;
    for(int v : adj[u]) {
        if(v == par) 
            continue;
        if(!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) 
                bridge++;
            child++;
            if(u == par) {
                if(child > 1) 
                    joint[u] = true;
            }
            else 
                if(low[v] >= num[u]) 
                    joint[u] = true;
        }
        else 
            low[u] = min(low[u], num[v]);
    }
}

void solve() {
    memset(joint, false, sizeof(joint));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++)
        if(!num[i])
            dfs(i, i);
    ll cntJoint = 0;
    for(int i = 1; i <= n; i++) 
        cntJoint += joint[i];
    cout << cntJoint << " " << bridge;
}   

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
