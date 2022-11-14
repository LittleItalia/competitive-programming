#define MASK(i)   (1LL << (i))
#define MAX   300300
#define LOG   19

long long c[MAX];
long long f[MAX][LOG + 1];
int lg2[MAX]; // lg2[i] = số k lớn nhất để 2^k <= i

// chuẩn bị
for (int i = 1; i <= n; i++) 
  f[i][0] = c[i];
for (int j = 1; j <= LOG; j++) 
    for (int i = 1; i <= n - MASK(j) + 1; i++) 
	      f[i][j] = max(f[i][j - 1], f[i + MASK(j - 1)][j - 1]);

lg2[1] = 0;
for (int i = 2; i <= n; i++) 
    lg2[i] = lg2[i / 2] + 1;

// trả về giá trị max trong đoạn từ l đến r
long long getMax(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1); // lg2[r - l + 1]
	return max(f[l][k], f[r - MASK(k) + 1][k]);
}
