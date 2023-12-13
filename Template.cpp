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

// ---------------------------------------- 

void solve() {
    
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
