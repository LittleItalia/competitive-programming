// Tim max trên đoạn l -> r 

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

ll tree[4 * MAXN], arr[MAXN];
ll n, m;

void build(ll id, ll l, ll r) {
    if(l == r) {
        tree[id] = arr[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}   

ll get(ll id, ll l, ll r, ll u, ll v) {
    if(u > r || v < l)
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
    for(int i = 1; i <= n; i++) 
        cin >> arr[i];
    build(1, 1, n);
    for(int j = 0; j < m; j++) {
        ll x, y, v;
        cin >> x >> y;
        cout << get(1, 1, n, x, y) << '\n';
    }
}   

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
