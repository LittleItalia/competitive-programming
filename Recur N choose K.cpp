void recur(int pos, int n, int k, int len) {
    if(len == k) {
        for(int i = 1; i <= k; i++)
            cout << cur[i] << ' ';
        cout << '\n';
        return;
    }

    if(pos == n) return;

    cur[len + 1] = pos + 1;

    recur(pos + 1, n, k, len + 1);
    recur(pos + 1, n, k, len);
}
