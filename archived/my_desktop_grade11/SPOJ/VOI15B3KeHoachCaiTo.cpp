#include <bits/stdc++.h>

using namespace std;

int n, m, tplt, cau;
vector<int> edge[200005];
int low[200005], num[200005], child[200005];
long long int res;

int timer = 0;
void dfs(int u, int p){
	num[u] = low[u] = ++timer;
	for (auto v: edge[u]) if (v!=p){ //di ve con
		if (num[v]) low[u] = min(low[u],num[v]); //da di roi
		else { //chua di
			dfs(v,u);
			child[u] += child[v];
			low[u] = min(low[u],low[v]);
			if (low[v]>num[u]){ //sau khi di va do la cau
				cau++;
				res += 1ll*child[v]*(n-child[v])-1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0, x, y; i < m; i++){
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) child[i] = 1;
	for (int i = 1; i <= n; i++){
		if (!num[i]){
			tplt++;
			dfs(i,-1);
		}
	}
	if (tplt>2){
		cout << 0;
	}
	if (tplt==2){
		cout << 1ll*(m-cau)*child[1]*(n-child[1]);
	}
	if (tplt==1){
		res += 1ll*(m-cau)*(1ll*n*(n-1)/2-m);
		cout << res;
	}
	
	return 0;
}
