// Minh Tú

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vpll = vector<pll>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define fi first
#define se second
#define MASK(i) (1LL << (i))
#define sqr(i) i * i
#define pb push_back
#define pf push_front
// x << y :  x * (2 ^ y)
// x >> y :  x / (2 ^ y)
// const int MOD = 1e9 + 19972207;
const ll INF = 1e18;
const int MAXN = 2e6;

int fact[MAXN + 100], ivfact[MAXN + 100];
 
ll exp(ll a, ll n){  // a ^ n % MOD;
    ll res = 1;
    while(n){
        if(n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
 
ll C(ll k, ll n){
    if(n == 0)
        return 1;
    return (ll)(fact[n]) * ivfact[k] % MOD * ivfact[n - k] % MOD;
}
 
void calc(){
    fact[0] = fact[1] = ivfact[0] = ivfact[1] = 1;
    for(int i = 2;i <= MAXN; i++)
        fact[i] = (ll)(fact[i - 1]) * i % MOD;
    ivfact[MAXN] = exp(fact[MAXN], MOD - 2);
    for(int i = MAXN - 1; i >= 0; i--)
        ivfact[i] = ivfact[i + 1] * (i + 1ll) % MOD;
}

void solve() {
    calc();
}
