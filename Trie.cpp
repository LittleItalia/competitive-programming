// Minh Tú 

#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define db  double
#define pll  pair<ll, ll>
#define str string
#define pii pair<int, int>
#define vpii vector<pii>
#define vl  vector<ll>
#define vpll  vector<pll>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define sz(x) x.size()
#define fi first
#define pb push_back
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
const int MAXN = 2e5 + 1;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

struct TrieNode {
    TrieNode* child[26];
    int cnt;
    bool seen;
    TrieNode() {
        for(int i = 0; i < 26; i++) 
            child[i] = NULL;
        cnt = 0;
        seen = false;
    }
};

TrieNode* root = new TrieNode();

void TrieInsert(const string &s) {
    int n = s.size();
    TrieNode* p = root;
    for(int i = 0; i < n; i++) {
        int nxt = s[i] - 'a';
        if(p->child[nxt] == NULL)
            p->child[nxt] = new TrieNode();
        p = p->child[nxt];
        p->cnt++;
    }
}

bool TrieFind(const string &s) {
    int n = s.size();
    TrieNode* p = root;
    for(int i = 0; i < n; i++) {
        int nxt = s[i] - 'a';
        if(p->child[nxt] == NULL)
            return false;
        p = p->child[nxt];
    }
    return p->cnt>0;
}

void solve(){
    
}

int main(){ 
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // #else
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    #endif
    solve();
}
