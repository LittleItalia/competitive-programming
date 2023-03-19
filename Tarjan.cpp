ll n, m, num[MAXN], low[MAXN], id = 1, scc = 0;
vl adj[MAXN];
bool onstack[MAXN];
stack<ll> st;

void dfs(int u){
    onstack[u] = true;
    num[u] = low[u] = id++;
    st.push(u);
    for(int v : adj[u]){
        if(!num[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        if(onstack[v])
            low[u] = min(low[u], low[v]);
    }
    if(low[u] == num[u]){
        while(st.size()){
            int cur = st.top();
            st.pop();
            onstack[cur] = false;
            if(cur == u)
                break;
        }
        scc++;
    }
} 

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for(int i = 1; i <= n; i++)
        if(!num[i])
            dfs(i);
    cout << scc << '\n';
}   

