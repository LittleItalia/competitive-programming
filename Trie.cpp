// Minh Tú 

#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define db  double
#define pll  pair<ll, ll>
#define pii pair<int, int>
#define vpii vector<pii>
#define vl  vector<ll>
#define vpll  vector<pll>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define fi first
#define pb push_back
#define se second
#define sqr(i) i * i
#define turn_on(i, m) (m |= (1LL << i))
#define turn_off(i, m) (m &= ~(1LL << i))
#define getbit(i, m) ((m >> i) & 1)
#define MASK(i) (1ll << (i))
#define BIT(x, i) (((x) >> (i)) & 1) // lấy ra bit thứ i của số x
// x << y :  x * (2 ^ y) 
// x >> y :  x / (2 ^ y)
// ((m >> i) & 1) : gia tri m co bit thu i bat
// (m |= (1LL << i)) : bat bit thu i cua m len
// (m &= ~(1LL << i)) : tat bit thu i cua m
const int MAXN = 2000000;
const int LOG = 17;
const ll MOD = 1e9 + 7;
const ll INF = 3e18 + 7;
const int N = 505;

int n, x, q;

struct TrieNode {
    TrieNode* bit[2];
    TrieNode() {
        bit[0] = bit[1] = NULL;
    }
} 

*root = new TrieNode();

string make_binary(int x) {   
    string ans = "";
    for (int i = 0; i < 31; i++) 
        ans = (char)(getbit(i, x) + 48) + ans;
    return ans;
}

int make_int(string s) {
    reverse(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < s.size(); i++) 
        ans += MASK(i) * (s[i] - 48);
    return ans;
}

void insert(string s) {
    TrieNode *p = root;
    for(char v : s) {
        int cur = v - 48;
        if(p -> bit[cur] == NULL) 
            p -> bit[cur] = new TrieNode();
        p = p -> bit[cur];
    }
}

string get(string s) {
    TrieNode *p = root;
    string ans = "";
    for (char v : s) {
        int cur = v - 48;
        if (p -> bit[1 - cur] != NULL)  {
            ans += (char) (1 - cur + 48);
            p = p -> bit[1 - cur]; 
        }
        else { 
            ans += (char) (cur + 48);
            p = p -> bit[cur];
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    while(n--) {
        cin >> x;
        insert(make_binary(x));
    }
    if(root -> bit[1] != NULL) 
        cout << 1;
    cin >> q;
    while (q--) {
        cin >> x;
        cout << make_int(get(make_binary(x))) << " ";
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

