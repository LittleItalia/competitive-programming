struct Hashing2D {
    vector<vector<int>> hs;
    vector<int> pwX, pwY;
    int n, m;
    static const int baseX = 3731, baseY = 2999, mod = 998244353;
    Hashing2D() {}
    Hashing2D(vector<string>& s) {
        n = (int)s.size(), m = (int)s[0].size();
        hs.assign(n + 10, vector<int>(m + 10, 0));

        pwX.assign(n + 10, 1);
        pwY.assign(m + 10, 1);

        for(int i = 0; i < n; i++) pwX[i + 1] = 1ll * pwX[i] * baseX % mod;
        for(int i = 0; i < m; i++) pwY[i + 1] = 1ll * pwY[i] * baseY % mod;

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                hs[i + 1][j + 1] = s[i][j] - 'a' + 1;

        for(int i = 0; i <= n; i++) 
            for(int j = 0; j < m; j++) 
                hs[i][j + 1] = (hs[i][j + 1] + 1ll * hs[i][j] * baseY % mod) % mod;

        for(int i = 0; i < n; i++) 
            for(int j = 0; j <= m; j++) 
                hs[i + 1][j] = (hs[i + 1][j] + 1ll * hs[i][j] * baseX % mod) % mod;
    }

    ll get_hash(int x1, int y1, int x2, int y2) { 
        x1--; y1--;
        int dx = x2 - x1, dy = y2 - y1;
        return (1ll * (hs[x2][y2] - 1ll * hs[x2][y1] * pwY[dy] % mod + mod) % mod -
        1ll * (hs[x1][y2] - 1ll * hs[x1][y1] * pwY[dy] % mod + mod) % mod * pwX[dx] % mod + mod) % mod;
    }
};
