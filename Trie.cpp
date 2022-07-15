#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vpii = vector<pii>;
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

ll ans = 1;
ll trie[1000000][26];

void build(string s){
    ll v = 0;
    for(int i = 0; i < s.size(); i++) {
        if(trie[v][s[i] - 'a'] == 0) {
            trie[v][s[i] - 'a'] = ans;
            v = trie[v][s[i] - 'a'];
            ans++;
        }
        else
            v = trie[v][s[i] - 'a'];
    }
}

void solve(){
    memset(trie, 0, sizeof(trie));
    
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
