#include <bits/stdc++.h>

#define ll long long
#define str string
#define db double

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdb pair<db, db>

#define vi vector<int>
#define vl vector<ll>
#define vdb vector<db>
#define vb vector<bool>
#define vs vector<str>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpd vector<pd>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)

//pairs
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
const ll INF = 1e18;
const int N = 10005;
const int MAXN = 2e5 + 777;

using namespace std;

string sub(string a, string b) {
    while(a.size() < b.size())
        a = '0' + a;
    while(b.size() < a.size())
        b = '0' + b;
    int d = 0, cur  = 0;
    string ans;
    for(int i = a.size() - 1; i >= 0; i--) {
        d = (a[i] - '0') - (b[i] - '0') - cur;
        if(d < 0) {
            d += 10;
            cur = 1;
        }
        else 
            cur = 0;
        ans = (char)(d + '0') + ans;
    }
    while(ans.size() > 1 && ans.front() == '0')
        ans.erase(ans.begin());
    return ans;
}

void solve(){

}

int main() {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    solve();
    return 0;
}
