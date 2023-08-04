ll n, m, num[maxn], low[maxn], id = 1, scc = 0;
vl adj[MAXN];
bool onstack[maxn];
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


