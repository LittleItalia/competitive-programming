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
const int MAXN = 400000 + 77;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void comb(int i, int n, int m, int cur[], int curLen) {
    if(curLen == m) {
        for(int j = 0; j < m; j++)
            cout << cur[j] << " ";
        cout << '\n';
        return;
    }
    if(i == n)  
        return;
    cur[curLen] = i + 1;
    comb(i + 1, n, m, cur, curLen + 1);
    comb(i + 1, n, m, cur, curLen);
}

void solve() {
    int cur[10];
    comb(0, 5, 2, cur, 0);
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
