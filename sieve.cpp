const int maxn = 1e8;
int coef[maxn + 1], divs[maxn + 1];
bool comp[maxn + 1];
vector<int> prime;

void sieve() {
    memset(comp, false, sizeof(comp));

    for(int i = 2; i <= maxn; i++) {
        if(!comp[i]) {
            coef[i] = 1;
            divs[i] = 2;

            prime.pb(i);
        }

        for(int j = 0; j < prime.size() && 1ll * i * prime[j] <= maxn; j++) {
            comp[i * prime[j]] = true;

            if(i % prime[j]) {
                coef[i * prime[j]] = 1;
                divs[i * prime[j]] = divs[i] * divs[prime[j]];
            }
            else {
                coef[i * prime[j]] = coef[i] + 1;
                divs[i * prime[j]] = divs[i] / (coef[i] + 1) * (coef[i * prime[j]] + 1);

                break;
            }
        }
    }
}
