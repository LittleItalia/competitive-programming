#include <bits/stdc++.h>
using namespace std;
using db = double;
using ldb = long double;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vpll = vector<pll>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define fi first
#define se second
#define MASK(i) (1ll << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define pb push_back
#define pf push_front
const int LOG = 17;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

struct TPoint{
    ll x, y;
};

using TVector = TPoint;

ll SqrLen(const TVector& u){
    return u.x*u.x+u.y*u.y;
}

TVector operator +(const TVector& u, const TVector& v){
    return {u.x+v.x, u.y+v.y};
}

TVector operator -(const TVector& u, const TVector& v){
    return {u.x-v.x, u.y-v.y};
}

ll operator *(const TVector& u, const TVector& v){
    return u.x*v.x+u.y*v.y;
}

ll operator /(const TVector& u, const TVector& v){
    return u.x*v.y-u.y*v.x;
}

const int MAXN = 1e5+5;
ll n, m;
TPoint p[MAXN], q[MAXN], A;

bool CCW(const TPoint& D, const TPoint& E, const TPoint& F){
    return (E - D) / (F - E) > 0;
}

void GrahamScan(){
    sort(p+1, p+n, [](const TPoint& B, const TPoint& C){
        TVector u = B-A, v = C-A;
        ll temp = u/v;
        return temp > 0 || (temp == 0 && SqrLen(u) < SqrLen(v));
    });
}

void BuildConvexHull(){
    m = 0;
    for(int i = 0; i < n; i++){
        while (m >= 2 && !CCW(q[m - 2], q[m - 1], p[i]))
            --m;
        q[m++] = p[i];
    }
}

void solve(){
    cin >> n;
    ll pos = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }
    A = p[0];
    for(int i = 1; i < n; i++){
        if(p[i].y < A.y){
            A = p[i];
            pos = i;
        }
        if(p[i].y == A.y){
            if(p[i].x < A.x){
                A.x = p[i].x;
                pos = i;
            }
        }
    }
    swap(p[0], p[pos]);
    GrahamScan();
    BuildConvexHull();
    cout << m << '\n';
    ll ans = 0;
    q[m] = q[0];
    for(int i = 1; i <= m; i++) 
        ans += (q[i - 1].x * q[i].y) - (q[i - 1].y * q[i].x);
    ans = abs(ans);
    if(ans % 2 == 0)
        cout << ans / 2 << ".0" << '\n';
    else
        cout << ans / 2 << ".5" << '\n';
    for(int i = 0; i < m; i++)
        cout << q[i].x << " " << q[i].y << '\n';
}


int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
