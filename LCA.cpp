long long n, k, query;
int numNode, mx = -1e9;
vector<int> adj[MAXN]; 
int par[MAXN][LOG + 1], dp[MAXN], tree[4 * MAXN], arr[MAXN]; 
int high[MAXN]; 

void dfs(int u) {
    dp[u] = 1;
    for(int v : adj[u]) 
        if(v != par[u][0]) {
            par[v][0] = u; 
            high[v] = high[u] + 1;
            dfs(v);
            dp[u] += dp[v];
        }
}

void prepare() {
    high[0] = -1; 
    dfs(1);
    for(int j = 1; j <= LOG; j++) 
        for(int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int u, int v) {
    if(u == -1)
        return v;
    if(v == -1)
        return u;
    if(high[v] > high[u]) 
        return lca(v, u);
    for(int j = LOG; j >= 0; j--) 
        if(high[par[u][j]] >= high[v]) 
            u = par[u][j];
    if(u == v) 
        return u;
    for(int j = LOG; j >= 0; j--) 
        if(par[u][j] != par[v][j]) {
            u = par[u][j]; 
            v = par[v][j];
    }
    return par[u][0];
}

int getNearest(int x, int p){
    for(int j = LOG; j >= 0; j--)
        if(high[par[p][j]] > high[x])
            p = par[p][j];
    return p;
}

ll distance(ll u, ll v) {
    return high[u] + high[v] - 2 * high[lca(u, v)];
}

// nhảy từ đỉnh u lên dist bước
ll mid(ll u, ll dist) {
    for(int i = LOG; i >= 0; i--) 
        if(dist - (1ll << i) >= 0) 
            u = par[u][i], dist -= 1ll << i;
    return u;
}


