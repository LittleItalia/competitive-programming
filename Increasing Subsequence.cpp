// Minh Tú 

#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define db  double
#define pll  pair<ll, ll>
#define vl  vector<ll>
#define vpll  vector<pll>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define fi first
#define pb push_back
#define se second
#define sqr(i) i * i
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1) // lấy ra bit thứ i của số x
// x << y :  x * (2 ^ y) 
// x >> y :  x / (2 ^ y)
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 777;

void solve() {
    ll n;
    cin >> n;
    vl arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vl dp(n + 10, 1e18); // dp[i] là phần tử nhỏ nhất mà tại đó dãy con có độ dài i chấm dứt
    dp[0] = -1e18;
    for(int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (dp[j - 1] < arr[i] && arr[i] < dp[j])
            dp[j] = arr[i];
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) 
        if(dp[i] < 1e18)
            ans = i;
    cout << ans;
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
