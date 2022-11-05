// Minh Tú 

#include <bits/stdc++.h>
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
// x << y :  x * (2 ^ y) 
// x >> y :  x / (2 ^ y)
// (((x) >> i) & 1) : lay ra bit thu i cua x
// (m |= (1LL << i)) : bat bit thu i cua m len
// (m &= ~(1LL << i)) : tat bit thu i cua m
// __builtin_clz(n)) : dem so luong so 0 dung dau 
// __builtin_ctz(n)) : dem so luong so 0 dung cuoi
// __builtin_popcount(n) : dem so luong so 1 trong bit
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MAXN = 2e5 + 1000;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll n;
ll tree[2 * MAXN];

void Build() {
    for(int i = n - 1; i > 0; i--) 
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void Modify(int pos, int val) {
    for(tree[pos += n] = val; pos > 1; pos >>= 1)
        tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
}

ll Query(ll l, ll r) {
    ll res = 0;
    l += n, r += n;
    while(l < r) {
        if(l & 1) 
            res += tree[l++];
        if(r & 1)
            res += tree[--r];
        l /= 2;
        r /= 2;
    }
    return res;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> tree[n + i];
    Build();
    // Modify(0, 1);
    cout << Query(1, 4);
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
