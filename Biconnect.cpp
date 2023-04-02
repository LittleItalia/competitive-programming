ll root[MAXN], active[MAXN], n, m;
bool vt[MAXN];
vl st, adj[MAXN];

ll find(ll u) {
    if(root[u] != u)
        root[u] = find(root[u]);
    return root[u];
}

void dfs(ll u) {
    vt[u] = true;
    root[u] = u;
    st.pb(u);
    for(int v : adj[u]) 
        if(vt[v]) {
            v = find(active[v]);
            while(st.back() != v) {
                root[find(st.back())] = v;
                st.pop_back();
            }
        }
    for(int v : adj[u]) 
        if(!vt[v]) {
            active[u] = v;
            dfs(v);
        }
    if(st.back() == u)
        st.pop_back();
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++) 
        if(!vt[i])
            dfs(i);
    
}
