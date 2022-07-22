#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll powMod(ll a, ll b, ll c) {
    ll res = 1;
    a %= c;
    while(b) {
        if(b % 2) {
            res *= a;
            res %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    return res;
}

int main() {
    cout << powMod(a, b, c) << '\n';
}
