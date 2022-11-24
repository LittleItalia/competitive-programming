// Cach 1

ll n, m, x, y, times = 0;
vpll edge, ans;
vl adj[MAXN], mark(MAXN);
bool used[MAXN];
ll visited[MAXN];

bool dfs(int u) {
    if(visited[u] != times) 
        visited[u] = times;
    else 
        return false;
    for(int v : adj[u]) 
        if(!mark[v] || dfs(mark[v])) {
            mark[v] = u;
            return true;
        }
    return false;
}

void solve() {
    cin >> n >> m;
    while(cin >> x >> y) edge.pb({x, y});
    ll cnt = 0;
    for(int i = 0; i < edge.size(); i++)
        adj[edge[i].fi].pb(edge[i].se);
    for(int i = 1; i <= n; i++) {
        times++;
        cnt += dfs(i);
    }
    cout << cnt << '\n';
    for(int i = 1; i <= m; i++) 
        if(int j = mark[i]) 
            cout << j << " " << i << '\n';
}


// Cach 2

int n, m, u, v;
int matchX[MAXN], matchY[MAXN], trace[MAXN];
vector<int> a[MAXN], b[MAXN];
vpii ans;

int findPath() {
    queue<int> st;
    for(int i = 1; i <= m; i++) trace[i] = 0;
    for(int i = 1; i <= n; i++) 
        if(matchX[i] == 0)  st.push(i);
    while(!st.empty()) {
        int u = st.front();
        st.pop();
        for(int v : a[u]) {
            if(trace[v]) continue;
            trace[v] = u;
            if(matchY[v] == 0) return v;
            st.push(matchY[v]);
        }
    }
    return -1;
}

void solve() {
    cin >> n >> m;
    int u, v;
    while(cin >> u >> v) 
        a[u].pb(v), b[v].pb(u);
    while(true) {
        v = findPath();
        if(v == -1) break;
        while(v != 0) {
            u = trace[v];
            int k = matchX[u];
            matchX[u] = v;
            matchY[v] = u;
            v = k;
        }
    }
    for(int i = 1; i <= n; i++) 
        if(matchX[i]) ans.pb({i, matchX[i]});
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) 
        cout << ans[i].fi << " " << ans[i].se << '\n';
}

