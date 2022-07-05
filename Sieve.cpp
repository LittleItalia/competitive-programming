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

using namespace std;

vector<long long> res ;
vector<bool> arr(sqrt(1000000000)+1 , true) ;

void sieve() {
    for (long long i = 2; i <= sqrt(1000000000); i++ ){
        if (arr[i] == true) {
            res.push_back(i) ; 
            for (long long  j = i*i; j <= sqrt(1000000000); j += i) {
                arr[j] = false ;
            }
        }
    }
}

void solve(){
    
}

int main() {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    sieve();
    solve();
    return 0;
}
