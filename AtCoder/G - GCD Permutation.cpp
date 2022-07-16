#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using ll = long long;
using pll = pair<ll, ll>;
 using vl = vector<ll>;
using vb = vector<bool>;
using vpll = vector<pll>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
//pairs
#define mp make_pair
#define fi first
#define se second
#define MASK(i) (1LL << (i))

//vectors
#define pb push_back
#define pf push_front
// 1 << i :  2 ^ i
// x << y :  x * (2 ^ y) 
// x >> Y :  x / (2 ^ y)
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ll MAXN = 100000;
const ll N = 200010;

void solve(){
    ll n, arr[N], mu[N], num[N], ans = 0;
    bool pr[N], used[N];
    vl m, d[N], cand;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        pr[i] = true;
        mu[i] = -1;
    }
    pr[1] = false;
    mu[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(pr[i]) {
            mu[i] = -mu[i];
            for(int j = 2; (i * j) <= n; j++) {
                pr[i*j] = false;
                if(j % i == 0)
                    mu[i * j] = 0;
                else 
                    mu[i * j] = - mu[i * j];
            }
        }
        if(mu[i] != 0) {
            m.pb(i);
            for(int j = i; j <= n; j += i)
                d[j].pb(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        used[i] = false;
        num[i] = 0;
    }
    for(auto &a : m) {
        for(int i = a; i <= n; i += a) {
            for(auto &j : d[arr[i]]) {
                num[j]++;
                if (!used[j]) {
                    used[j] = true;
                    cand.pb(j);
                }
            }
        }
        for(auto &b : cand) {
            ans += mu[a] * mu[b] * ((num[b] * (num[b] + 1)) / 2);
            num[b] = 0;
            used[b] = false;
        }
        cand.clear();
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
