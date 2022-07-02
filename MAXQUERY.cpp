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
 
//pairs
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define fi first
#define se second
 
//vectors
#define pb push_back
#define pf push_front
#define low_b lower_bound
#define up_b upper_bound
 
bool minimize(ll &x, ll y) { // hàm có tác dụng gán x = min(x, y);
    if (x > y) {
        x = y;
        return true;
    } 
    else
        return false;
}

const int MAX = 3000001;
const int MOD = 998244353;
const ll INF = 1e18;

const int LOG = 19;
const int MAXN = 6e3+77;
const int N = 20;

ll n, m;
ll tree[600001], x , y;

void build() {
    for(int i = n-1; i > 0; i--)
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

ll query(ll l, ll r) {
    l += n, r += n;
    ll cur = 0;
    while(l < r) {
        if(l % 2 != 0) 
            cur = max(cur, tree[l++]);
        if(r % 2 != 0) 
            cur = max(cur, tree[--r]);
        l /= 2;
        r /= 2;
    }
    return cur;
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> tree[i + n];
    build();
    for(int j = 0; j < m; j++) {
        ll x, y, v;
        cin >> x >> y;
        cout << query(x-1, y) << '\n';
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
