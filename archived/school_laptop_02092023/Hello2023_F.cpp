#include<bits/stdc++.h>

//bo de 1: tong xor_sum. sum v roi sum u nhu nhau. nhung nho phep gan ta co tinh chat chan le
//bo de 2: subtree chan => ok => xor_sum = 0 (tai u) hoac default (tai to tien cua u). nguoc lai la le chi co the la defaut
//bo de 3: nhung subtree chan la mau chot thay doi tong xor_sum => dp

using namespace std;
//f[u][sum]: able to xor_sum of subtree root [u] is [sum]
//trace[v][sum]: at the time after check [v], is subtree root [u] able to xor_sum is [sum]  
bool f[200005][32], trace[200005][32], sz[200005];
int a[200005], n;
vector<int> res, edge[200005];

void dfs(int u){
	sz[u] = 1;
	f[u][a[u]] = 1;
	for (int v: edge[u]){
		dfs(v);
		sz[u] ^= sz[v];
		for (int i = 0; i < 32; i++) for (int j = 0; j < 32; j++) if (f[u][i]&&f[v][j]) trace[v][i^j] = 1;
		for (int i = 0; i < 32; i++) f[u][i] = trace[v][i];
	}
	if (sz[u]==0) f[u][0] = 1;
}
void truyvet(int u, int c){
	if (c==0&&sz[u]==0){
		res.push_back(u);
		return;
	}
	for (int i = edge[u].size()-1; i >= 1; i--){
		int v = edge[u][i], vv = edge[u][i-1];
		for (int j = 0; j < 32; j++) if (trace[vv][j]&&f[v][c^j]){
			truyvet(v,c^j);
			c = j;
			break;
		}
	}
	if (edge[u].size()&&f[*edge[u].begin()][c^a[u]]==0) cout << "ngu vl r \n";
	if (edge[u].size()) truyvet(*edge[u].begin(),c^a[u]);
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2, p; i <= n; i++){
		cin >> p;
		edge[p].push_back(i);
	}
	dfs(1);
	if (!f[1][0]) return cout << -1,0;
	truyvet(1,0);
	
	
	res.push_back(1);
	cout << res.size() << "\n";
	for (int x: res) cout << x << " ";
	
	
	
	return 0;
}
