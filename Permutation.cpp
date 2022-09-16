// in ra các hoán vị độ dài n

#include <bits/stdc++.h>
using namespace std;

int n, arr[MAXN];
ll cur[MAXN];

void recur(ll i) {
    if(i == n) {
        for(int j = 1; j <= n; j++)
            cout << cur[j] << " ";
        cout << '\n';
        return;
    }
    cur[i + 1] = 0;
    recur(i + 1);
    cur[i + 1] = 1;
    recur(i + 1);
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    recur(0);
}   
