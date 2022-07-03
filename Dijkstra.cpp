#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <string.h> 
#include <map>
using namespace std;
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
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

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
const ll MAXN = 201;

int n, m;
vpii arr[MAXN];
int d[MAXN];

void dijkstra(ll st) {
    priority_queue <pii, vpii, greater<pii>> q;
    for(int i = 1; i <= n; i++)
        d[i] = 1e18;
    d[st] = 0;
    q.push({0, st});
    while(q.size()) {
        ll u = q.top().se;
        ll du = q.top().fi;
        q.pop();
        if(du != d[u])
            continue;
        for(int i = 0; i < arr[u].size(); i++) {
            ll v = arr[u][i].se;
            ll dv = arr[u][i].fi;
            if(d[v] > du+dv) {
                d[v] = du+dv;
                q.push({d[v], v});
                tr[v] = u;
            }
        }
    }
}

void solve() {

}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
