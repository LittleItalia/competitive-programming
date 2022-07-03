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
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)

//pairs
#define sz(x) (int)(x.size())
#define mp make_pair
#define fi first
#define se second
 
//vectors
#define pb push_back
#define pf push_front

//loops
#define FOR(i, a, b) for(int i=(int)a;i<(int)b;++i)
#define ROF(i, a, b) for(int i=(int)a-1;i>=(int)b;i--)
#define rep(a, x) for(auto& a : x)

const int MOD = 1e9+7;
//const int MOD = 998244353;
const ll INF = 1e18;

const int MAXN = 2e5+777;

ll n, m, s;
ll par[MAXN];
vector<pair<pll, pll>> edge;

ll getPar(ll x){
    while(x != par[x])
        x = par[x];
    return x;
}

void unite(ll x, ll y){
    ll p1 = getPar(x);
    ll p2 = getPar(y);
    if(p1 < p2)
        par[p1] = y;
    else 
        par[p2] = x;
}

void solve(){
    cin >> n >> m;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        par[i] = i;
    FOR(i, 0 ,m) {
        ll u, v, c;
        cin >> u >> v >> c;
        cout << u << " " << v << " " << c << '\n';
        edge.pb(mp(mp(c, 0), mp(u, v)));
    }  
    FOR(i, 0, edge.size()) 
        cout << edge[i].se.fi << " " << edge[i].se.se << '\n';
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++){
        ll u = edge[i].se.fi, v = edge[i].se.se;
        if(getPar(u) != getPar(v)){
            unite(u, v);
            ans += edge[i].fi.fi;
        }
    }
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
