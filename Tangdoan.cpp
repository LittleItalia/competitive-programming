// Tăng các phần tử từ l -> r lên val đơn vị

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using db = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;
using vi = vector<int>;
using vl = vector<ll>;
using vdb = vector<db>;
using vb = vector<bool>;
using vs = vector<str>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdb = vector<pdb>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front

const int MOD = 998244353;
const int MAXN = 3e5+77;

ll tree[4 * MAXN], arr[MAXN], lazy[4 * MAXN];
ll n, m;

void build(ll id, ll l, ll r) {
    if(l == r) {
        tree[id] = arr[l];
        return;
    }
    ll mid = l + r >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}   

void push(ll id, ll l, ll r) {
    tree[2 * id] += lazy[id];
    lazy[2 * id] += lazy[id];
    tree[2 * id + 1] += lazy[id];
    lazy[2 * id + 1] += lazy[id];
    lazy[id] = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val) {
    if(l > v || r < u) 
        return;
    if(u <= l && r <= v) {
        lazy[id] += val;
        tree[id] += val;
        return;
    }
    push(id, l, r);
    ll mid = l + r >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    push(id, l, r);
    if(l > v || r < u) 
        return -1e18;
    if(u <= l && r <= v)
        return tree[id];
    ll mid = (l + r) >> 1; 
    ll get1 = get(2 * id, l, mid, u, v);
    ll get2 = get(2 * id + 1, mid + 1, r, u, v);
    return max(get1, get2);
}

void solve() {
    cin >> n >> m;
    memset(lazy, 0, sizeof(lazy));
    for(int i = 1; i <= n; i++) 
        arr[i] = 0;
    build(1, 1, n);
    for(int j = 0; j < m; j++) {
        ll x, y, v;
        cin >> x >> y >> v;
        update(1, 1, n, x, y, v);
    }
    for(ll i = 1; i <= n; i++)
        cout << get(1, 1, n, i, i) << " ";
}   

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
