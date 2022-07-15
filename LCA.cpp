#define MAX   100100
#define LOG   17
int numNode;
vector<int> adj[MAX]; // danh sách kề
int par[MAX][LOG + 1]; // mảng cha
int high[MAX]; // số cạnh từ một đỉnh tới gốc (độ sâu)

void dfs(int u) {
	for (int v : adj[u]) if (v != par[u][0]) {
		par[v][0] = u; // cha trực tiếp của v là u
		high[v] = high[u] + 1;
		dfs(v);
	}
}

// chuẩn bị ban đầu
high[0] = -1; // rất quan trọng, không thể bỏ sót
dfs(1);
for (int j = 1; j <= LOG; j++) for (int i = 1; i <= numNode; i++)
	par[i][j] = par[par[i][j - 1]][j - 1];

int lca(int u, int v) {
	// nếu v có độ sâu lớn hơn u, đổi chỗ u và v
	if (high[v] > high[u]) return lca(v, u);
	
	// bước 1: nhảy u lên để u có độ sâu bằng v
	for (int j = LOG; j >= 0; j--) if (par[u][j] >= par[v]) u = par[u][j];
	
	// nếu sau bước 1, hai đỉnh u và v đã bằng nhau rồi, kết luận đây là lca
	if (u == v) return u;

	// bước 2: nhảy đồng thời u và v đến vị trí xa nhất mà chưa gặp nhau
	for (int j = LOG; j >= 0; j--) if (par[u][j] != par[v][j]) {
		u = par[u][j]; v = par[v][j];
	}

	// nhảy thêm một bước nữa là tới lca
	return par[u][0];
}
