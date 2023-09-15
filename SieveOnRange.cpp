void sieve(ll l, ll r) {
    vector<bool> prime(r - l + 1, true);
    for(ll i = 2; i <= sqrt(r); i++) 
        for(ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) 
            prime[r - l] = false;
    for(ll i = max(l, 2ll); i <= r; i++) 
        if(prime[i - l])
            cout << i << " ";
}

