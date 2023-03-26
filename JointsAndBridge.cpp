ll n, m, bridge = 0, timeDFS = 0;
ll low[MAXN], num[MAXN];
bool joint[MAXN];
vl adj[MAXN];

void dfs(int u, int par) {
    int child = 0;
    num[u] = low[u] = ++timeDFS;
    for(int v : adj[u]) {
        if(v == par) 
            continue;
        if(!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) bridge++;
            child++;
            if(u == par) {
                if(child > 1) joint[u] = true;
            }
            else 
                if(low[v] >= num[u]) joint[u] = true;
        }
        else 
            low[u] = min(low[u], num[v]);
    }
}

void solve() {
    memset(joint, false, sizeof(joint));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++)
        if(!num[i])
            dfs(i, i);
    ll cntJoint = 0;
    for(int i = 1; i <= n; i++) 
        cntJoint += joint[i];
    cout << cntJoint << " " << bridge;
}   

