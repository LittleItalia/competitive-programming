int numNode;
vector<int> adj[MAX]; // mảng danh sách kề 
int par[MAX]; // mảng lưu cha của các nút
int high[MAX]; // mảng lưu độ sâu của các nút (gốc cây có độ sâu là 0)

void dfs(int u) {
	for (int v : adj[u]) if (v != par[u])) {
		par[v] = u;
		high[v] = high[u] + 1;
		dfs(v);
	}
}
dfs(1);

int lcaSlow(int u, int v) { // tìm tổ tiên chung gần nhất giữa u và v
	// nếu v có độ sâu lớn hơn u, đổi chỗ u và v để ta luôn có thể giả sử u có độ sâu lớn hơn hoặc bằng v.
	if (high[v] > high[u]) return lcaSlow(v, u);
	
	// cân bằng độ sâu: di chuyển nút u lên trên cho đến khi có độ sâu bằng v
	while (high[u] > high[v]) u = par[u];
	
	// di chuyển u và v cùng lúc cho đến khi hai nút gặp nhau 
	while (u != v) {
		u = par[u];
		v = par[v];
	}

	return u; // tổ tiên chung gần nhất chính là điểm gặp nhau đầu tiên
}
