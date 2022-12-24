void dijkstra(int st) {
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e8;
        vis[i] = false;
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[st] = 0;
    pq.push({0, st});

    while(pq.size()){
        int u = pq.top().se; pq.pop();

        if(vis[u]) continue;

        vis[u] = true;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v] && dist[v] > dist[u] + cost[u][i]){
                dist[v] = dist[u] + cost[u][i];
                pq.push({dist[v], v});
            }
        }
    }
}
