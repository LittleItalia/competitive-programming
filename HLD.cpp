#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define db  double
#define vl  vector<ll>
#define pll  pair<ll, ll>
#define vpll  vector<pll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define __lcm(a, b) (1ll * ((a) / __gcd((a), (b))) * (b))
#define BIT(x, i) (((x) >> (i)) & 1) 

#define PROBLEM "test"

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int mod[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9+ 9277};
const double eps = 1e-9;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

const int maxn = 1e5 + 777;

struct SegmentTree {
    ll seg[4 * maxn], lazy[4 * maxn];

    SegmentTree() {
        memset(seg, 0, sizeof(seg));
        memset(lazy, 0, sizeof(lazy));
    }

    void push(int id, int l, int r) {
        int mid = (l + r) >> 1;

        seg[id << 1] += lazy[id] * (mid - l + 1);
        seg[id << 1 | 1] += lazy[id] * (r - mid);

        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];

        lazy[id] = 0;
    }

    void update(int id, int l, int r, int from, int to, ll value) {
        if(r < from || l > to) return;
        if(from <= l && r <= to) {
            seg[id] += 1ll * value * (r - l + 1);
            lazy[id] += value;
            return;
        }
        int mid = (l + r) >> 1;
        push(id, l, r);
        update(id << 1, l, mid, from, to, value);
        update(id << 1 | 1, mid + 1, r, from, to, value);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }

    ll query(int id, int l, int r, int from, int to) {
        if(r < from || l > to) return 0;
        if(from <= l && r <= to) return seg[id];
        int mid = (l + r) >> 1;
        push(id, l, r);
        return query(id << 1, l, mid, from, to) + query(id << 1 | 1, mid + 1, r, from, to);
    }
} seg1, seg2, seg3; 

// ---------------------------------------- 
int n, q, timeDfs = 0;
int par[maxn][LOG + 1], high[maxn], tour[maxn], st[maxn], en[maxn];
int nchild[maxn], chainHead[maxn], chainInd[maxn], PosInBase[maxn], nchain = 0, nbase = 0;

vector<int> adj[maxn];

void dfs(int u) {
	tour[++timeDfs] = u;
	st[u] = timeDfs;

    nchild[u] = 1;

    for(int v : adj[u]) 
        if(v != par[u][0]) {
            par[v][0] = u; 
            high[v] = high[u] + 1;
            
            dfs(v);

            nchild[u] += nchild[v];
        }

    en[u] = timeDfs;
}

void prepare() {
    high[0] = -1; 
    dfs(1);
    for(int j = 1; j <= LOG; j++) 
        for(int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int u, int v) {
    if(high[v] > high[u])  return lca(v, u);
    
    for(int j = LOG; j >= 0; j--) 
        if(high[par[u][j]] >= high[v]) 
            u = par[u][j];
    
    if(u == v)  return u;
    
    for(int j = LOG; j >= 0; j--) 
        if(par[u][j] != par[v][j]) {
            u = par[u][j]; 
            v = par[v][j];
    }
    
    return par[u][0];
}

void hld(int u) {
    if(chainHead[nchain] == 0) chainHead[nchain] = u;

    chainInd[u] = nchain;
    PosInBase[u] = ++nbase;

    int spec = -1;
    for(int v : adj[u]) {
        if(v == par[u][0]) continue;
        if(spec == -1 || nchild[v] > nchild[spec])
            spec = v;
    }

    if(spec != -1) hld(spec);

    for(int v : adj[u]) {
        if(v == par[u][0]) continue;
        if(v != spec) {
            nchain++;
            hld(v);
        }
    }
}

void modify(int u, int v, ll val) {
    while(1) {
        if(chainInd[u] == chainInd[v]) {
            seg2.update(1, 1, nbase, PosInBase[v], PosInBase[u], val);
            return;
        }
        seg2.update(1, 1, nbase, PosInBase[chainHead[chainInd[u]]], PosInBase[u], val);

        u = par[chainHead[chainInd[u]]][0];
    }
}

void solve() {
    cin >> n >> q;

    for(int i = 1; i < n; i++) {
    	int u, v; cin >> u >> v;

    	adj[u].pb(v); adj[v].pb(u);
    }

    prepare();
    hld(1);

    while(q--) {
        int tp; cin >> tp;

        if(tp == 1) { // nang gia tri cua cac dinh nam trong cay con goc u len val don vi
            ll u, val; cin >> u >> val;

            seg1.update(1, 1, n, st[u], en[u], val);
        }
        if(tp == 2) { // nang gia tri cua cac dinh nam ngoai cay con goc u len val don vi
            ll u, val; cin >> u >> val;

            if(st[u] - 1 >= 1) seg1.update(1, 1, n, 1, st[u] - 1, val);
            if(en[u] + 1 <= n) seg1.update(1, 1, n, en[u] + 1, n, val);
        }
        if(tp == 3) { // nang gia tri cac dinh nam tren duong di tu u den v len val don vi
            ll u, v, val; cin >> u >> v >> val;

            int cha = lca(u, v);
            modify(u, cha, val);
            modify(v, cha, val);
            seg2.update(1, 1, nbase, PosInBase[cha], PosInBase[cha], -val);
        }   
        if(tp == 4) { // nang gia tri cac dinh khong nam tren duong di tu u den v len val don vi
            ll u, v, val; cin >> u >> v >> val;

            int cha = lca(u, v);
            seg2.update(1, 1, nbase, 1, nbase, val);
            modify(u, cha, -val);
            modify(v, cha, -val);
            seg2.update(1, 1, nbase, PosInBase[cha], PosInBase[cha], val);
        }
        if(tp == 5) { // nang cac gia tri duoc danh so tu u den v len val don vi
            ll u, v, val; cin >> u >> v >> val;
            if(u > v) swap(u, v);

            seg3.update(1, 1, n, u, v, val);
        }
        if(tp == 6) { // nang cac gia tri khong duoc danh so tu u den v len val don vi
            ll u, v, val; cin >> u >> v >> val;
            if(u > v) swap(u, v);

            if(u - 1 >= 1) seg3.update(1, 1, n, 1, u - 1, val);
            if(v + 1 <= n) seg3.update(1, 1, n, v + 1, n, val);
        }
        if(tp == 7) { // in ra gia tri cua nut u
            int u; cin >> u;

            ll sum = 0;
            sum += seg1.query(1, 1, n, st[u], st[u]);
            sum += seg2.query(1, 1, n, PosInBase[u], PosInBase[u]);
            sum += seg3.query(1, 1, n, u, u);

            cout << sum << '\n';            
        }
    }
}

int main(){ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    if (fopen(PROBLEM".inp", "r")){
        freopen(PROBLEM".inp", "r", stdin);
        freopen(PROBLEM".out", "w", stdout);
    }
    bool ok = false;
    if(ok) {
        int t; cin >> t;
        while(t--)  solve();
    }   
    else
        solve();
}
