int n, m;
ll seg[4 * MAXN], lazy[4 * MAXN], arr[MAXN];

void build(int ind, int l, int r) {
    if(l >= r) {
        seg[ind] = arr[ind];
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l, mid);
    build(ind * 2 + 1, mid + 1, r);
    seg[mid] = max(seg[mid * 2], seg[mid * 2 + 1]);
}

void push(int ind, int l, int r) {
    seg[ind * 2] += lazy[ind];
    lazy[ind * 2] += lazy[ind];
    seg[ind * 2 + 1] += lazy[ind];
    lazy[ind * 2 + 1] += lazy[ind];
    lazy[ind] = 0;
}

void update(int ind, int l, int r, int from, int to, int value) {
    if(r < from || l > to) return;
    if(from <= l && r <= to) {
        seg[ind] += value;
        lazy[ind] += value;
        return;
    }
    push(ind, l, r);
    int mid = (l + r) / 2;
    update(ind * 2, l, mid, from, to, value);
    update(ind * 2 + 1, mid + 1, r, from, to, value);
    seg[ind] = max(seg[ind * 2], seg[ind * 2 + 1]);
}

ll query(int ind, int l, int r, int from, int to) {
    push(ind, l, r);
    if(r < from || l > to) return -1e18;
    if(from <= l && r <= to) return seg[ind];
    int mid = (l + r) / 2;
    ll val1 = query(ind * 2, l, mid, from, to);
    ll val2 = query(ind * 2 + 1, mid + 1, r, from, to);
    return max(val1, val2);
}

void solve() {
    cin >> n >> m;
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
    for(int i = 1; i <= n; i++) arr[i] = 0;
    build(1, 1, n);
    for(int i = 0; i < m; i++) {
        int type;
        cin >> type;
        if(type == 0) {
            int x, y, k;
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
}

