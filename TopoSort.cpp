int n, m;
int visited[MAXN], ans[MAXN];
vector<int> adj[MAXN];
stack<int> topo;

void dfs(int u) {
    visited[u] = 1;
    for(int v : adj[u]) {
        if(!visited[v]) 
            dfs(v);
    }
    topo.push(u);
    visited[u] = 2;
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for(int i = 1; i <= n; i++) 
        if(!visited[i]) dfs(i);
    int time = 0;
    while(topo.size()) {
        ans[topo.top()] = ++time;
        topo.pop();
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}

