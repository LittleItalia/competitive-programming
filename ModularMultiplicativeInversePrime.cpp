#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll powMod(ll a, ll b, ll c) {
    ll res = 1;
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

ll inv(ll a, ll b) {
    return powMod(a, b - 2, b);
}

int main() {
    cout << ind(a, b);
}
