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

const int MOD = 998244353;
const int MAXN = 6e3+77;

void solve() {
    ll n;
    while(cin >> n) {
        ll ans = 0;
        for(int i = 1; i <= sqrt(n); i++) {
            if(n % i == 0) {
                ans++ ;
                if(n / i != i) 
                    ans++ ;
            }
        }
        cout << ans << '\n';
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