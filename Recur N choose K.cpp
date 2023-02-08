void comb(int i, int n, int m, int cur[], int curLen) {
    if(curLen == m) {
        for(int j = 0; j < m; j++)
            cout << cur[j] << " ";
        cout << '\n';
        return;
    }
    if(i == n)  
        return;
    cur[curLen] = i + 1;
    comb(i + 1, n, m, cur, curLen + 1);
    comb(i + 1, n, m, cur, curLen);
}

void solve() {
    int cur[10];
    comb(0, 5, 2, cur, 0);
}
