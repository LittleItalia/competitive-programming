#include <bits/stdc++.h>

#define ll long long 
#define fi first 
#define se second 

using namespace std;

const int MAXN = 2e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int LOG = 20;

int par[MAXN], sum[MAXN];

int find(int u) {
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

bool unite(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return false;
    par[max(u, v)] = min(u, v);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int m = 3, n = 4;
    cout << m << ' ' << n << '\n';
    for(int i = 1; i <= m; i++)
        cout << rng() % 5 << ' ' << rng() % 5 << '\n';
    for(int i = 1; i <= n; i++) 
        cout << rng() % 5 << ' ' << rng() % 5 << '\n';

    return 0;
}
-----------------------------------------------------------------

@echo off
set "stress_test = 1"
g++ -O2 -std=c++14 -Wshadow -Wno-unused-result -o solution solution.cpp
if "%stress_test%" == "1" (
    g++ -O2 -std=c++14 -Wshadow -Wno-unused-result -o brute brute.cpp
    g++ -O2 -std=c++14 -Wshadow -Wno-unused-result -o gen gen.cpp
)

-----------------------------------------------------------------

@echo off

for /l %%i in (1, 1, 100000) do (

    gen.exe > test.inp
    solution.exe < test.inp > test.out
    brute.exe < test.inp > answer.out
    fc test.out answer.out > 0 || echo TEST %%i [WA] && type test.inp && goto :out
    echo TEST %%i [AC]

)

:out
