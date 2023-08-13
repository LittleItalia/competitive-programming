ll binpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) 
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;  
        b >>= 1;
    }
    return ans;
}

ll C(ll n, ll k) {
    return fact[n] * finv[n - k] % MOD * finv[k] % MOD;
}

void precalc() {
    fact[0] = 1;
    for(int i = 1; i <= maxn; i++) 
        fact[i] = 1ll * fact[i - 1] * i % MOD;    
    finv[maxn] = binpow(fact[maxn], MOD - 2);
    for(int i = maxn - 1; i >= 0; i--) 
        finv[i] = 1ll * finv[i + 1] * (i + 1) % MOD;
}
