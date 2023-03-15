const int maxn = 2e5 + 7;
const int base = 44;
ll mod[] = {(ll)1e9 + 2277, (ll)1e9 + 5277};
ll n, k;
string ans;
vector<string> arr(maxn);
pair<ll, ll> hashVal[51][maxn];
ll pw1[maxn], pw2[maxn];

void precalc() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i < maxn; i++) {
        pw1[i] = (pw1[i - 1] * base) % mod[0];
        pw2[i] = (pw2[i - 1] * base) % mod[1];
    }
}

void Build_Hash(string s, ll pos) {
    for(int i = 1; i < s.size(); i++) {
        hashVal[pos][i].fi = (hashVal[pos][i - 1].fi * base + (s[i] - 'A' + 1)) % mod[0];
        hashVal[pos][i].se = (hashVal[pos][i - 1].se * base + (s[i] - 'A' + 1)) % mod[1];
    }
}

pll getHash(int pos, int l, int r) {
    return mp((hashVal[pos][r].fi - hashVal[pos][l - 1].fi * pw1[r - l + 1] + mod[0] * mod[0]) % mod[0]
        , (hashVal[pos][r].se - hashVal[pos][l - 1].se * pw2[r - l + 1] + mod[1] * mod[1]) % mod[1]);
}

bool check(ll len) {
    map<pll, ll> res;
    for(int i = 0; i < n; i++) {
        map<pll, ll> cnt;
        for(int j = 1; j < (int)arr[i].size() - len + 1; j++) 
            cnt[getHash(i, j, j + len - 1)]++;
        for(auto x : cnt) res[x.fi]++;
    }
    for(auto x : res) 
        if(x.se >= k) {
            for(int i = 0; i < n; i++) 
                for(int j = 1; j < (int)arr[i].size() - len + 1; j++) {
                    pll tmp = getHash(i, j, j + len - 1);
                    if(tmp.fi == x.fi.fi && tmp.se == x.fi.se) {
                        ans = arr[i].substr(j, len);;
                        return true;
                    }   
                }
        }
    return false;
}

void solve() {
    memset(hashVal, 0, sizeof(hashVal));
    cin >> n >> k;
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    for(int i = 0; i < n; i++) arr[i] = '.' + arr[i];
    for(int i = 0; i < n; i++) Build_Hash(arr[i], i);
}


