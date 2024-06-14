#include<bits/stdc++.h>

using namespace std;
const int maxN = 5005;
int n, g[5][maxN], cmp[maxN], used[maxN];
vector<int> edge[maxN], redge[maxN];
vector<int> order;
void dfs1(int v) {
    used[v] = true;
    for (int u : redge[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}
void dfs(int u, int lt){
	cmp[u] = lt;
	for (int v: edge[u]) if (cmp[v]==-1){
		dfs(v,lt);
	}
}
void solve(){
	cin >> n;
	for (int r = 1; r <= 3; r++)for (int i = 1; i <= n; i++){
		cin >> g[r][i];
	}
	order.clear();
	for (int i = 0; i <= 2*n; i++) edge[i].clear(), redge[i].clear(), cmp[i] = -1, used[i] = 0;
	for (int i = 1; i <= n; i++){
		edge[-g[1][i]+n].push_back(g[2][i]+n);
		edge[-g[1][i]+n].push_back(g[3][i]+n);
		edge[-g[2][i]+n].push_back(g[1][i]+n);
		edge[-g[2][i]+n].push_back(g[3][i]+n);
		edge[-g[3][i]+n].push_back(g[1][i]+n);
		edge[-g[3][i]+n].push_back(g[2][i]+n);
		
		redge[g[1][i]+n].push_back(-g[2][i]+n);
		redge[g[1][i]+n].push_back(-g[3][i]+n);
		redge[g[2][i]+n].push_back(-g[1][i]+n);
		redge[g[2][i]+n].push_back(-g[3][i]+n);
		redge[g[3][i]+n].push_back(-g[1][i]+n);
		redge[g[3][i]+n].push_back(-g[2][i]+n);
//		break;
//		if (i==2) break;
	}
	int lt = 0;
	for (int i = 0; i <= 2*n; i++) if (!used[i]){
		dfs1(i);
	}
	reverse(order.begin(),order.end());
//	for (int i: order) cout << i-n << ", "; cout << "\n";
//	for (int i = 0; i <= 2*n; i++) for (int v: edge[i]){
//		cout << i-n << " " << v-n << "\n";
//	}
	for (int i: order) if (cmp[i]==-1){
		dfs(i, ++lt);
	}
	for (int i = 1; i <= n; i++){
		if (cmp[i+n]==cmp[-i+n]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
//	for (int i = -n; i <= n; i++){
//		cout << i << " = " << cmp[i+n] << "\n";
//	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

