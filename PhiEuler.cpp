#include <bits/stdc++.h>
using namespace;

using ll = long long;

ll phi(ll n) {  
    ll res = 0;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            res -= res / i;
            while(n % i == 0) 
                n /= i;
        }
    }
    if(n > 1) 
        res -= res / n;
    return res;
}

int main() {

}
