const int maxn = 1e5 + 15;
vector<ll> adj[maxn];
ll n, m, val[maxn], Din[maxn], cnt[maxn];
bool vis[maxn];
queue<ll> q[3];
str s;

void solve() {
    cin >> n >> m >> s;

    for (int i = 1; i <= n; i++)
        val[i] = (s[i - 1] - 'A');

    mem(vis, false);
    mem(Din, 0);
    mem(cnt, 0);
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(v);
        Din[v]++;
    }

    for (int i = 1; i <= n; i++)
        if (!Din[i]) q[val[i]].push(i);

    for (ll res = 0; ; res++) {
        while(q[res % 2].size() || q[2].size()) {
            ll u;
            if (q[res % 2].size()) u = q[res % 2].front(), q[res % 2].pop();
            else u = q[2].front(), q[2].pop();

            if(vis[u]) continue;

            vis[u] = true;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    cnt[v]++;
                    if(cnt[v] == Din[v]) q[val[v]].push(v);
                }
            }
        }

        if(q[0].empty() && q[1].empty() && q[2].empty()) {
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {
                    cout << -1 << '\n';
                    return;
                }
            }

            cout << res << '\n';
            return;
        }
    }
}
