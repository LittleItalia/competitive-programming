#include <bits/stdc++.h>
#pragma GCC("Ofast")
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
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const double eps = 1e-9;
const int MAXN = 500000 + 77;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int n, m;
ll seg[4 * MAXN], lazy[4 * MAXN], arr[MAXN];

void build(int ind, int l, int r) {
    if(l >= r) {
        seg[ind] = arr[ind];
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l, mid);
    build(ind * 2 + 1, mid + 1, r);
    seg[mid] = max(seg[mid * 2], seg[mid * 2 + 1]);
}

void push(int ind, int l, int r) {
    seg[ind * 2] += lazy[ind];
    lazy[ind * 2] += lazy[ind];
    seg[ind * 2 + 1] += lazy[ind];
    lazy[ind * 2 + 1] += lazy[ind];
    lazy[ind] = 0;
}

void update(int ind, int l, int r, int from, int to, int value) {
    if(r < from || l > to) return;
    if(from <= l && r <= to) {
        seg[ind] += value;
        lazy[ind] += value;
        return;
    }
    push(ind, l, r);
    int mid = (l + r) / 2;
    update(ind * 2, l, mid, from, to, value);
    update(ind * 2 + 1, mid + 1, r, from, to, value);
    seg[ind] = max(seg[ind * 2], seg[ind * 2 + 1]);
}

ll query(int ind, int l, int r, int from, int to) {
    push(ind, l, r);
    if(r < from || l > to) return -1e18;
    if(from <= l && r <= to) return seg[ind];
    int mid = (l + r) / 2;
    ll val1 = query(ind * 2, l, mid, from, to);
    ll val2 = query(ind * 2 + 1, mid + 1, r, from, to);
    return max(val1, val2);
}

void solve() {
    cin >> n >> m;
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
    for(int i = 1; i <= n; i++) arr[i] = 0;
    build(1, 1, n);
    for(int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if(type == 0) {
            int x, y, k;
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << '\n';
        }
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
