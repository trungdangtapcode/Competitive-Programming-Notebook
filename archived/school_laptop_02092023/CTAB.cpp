#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, a[1005][1005], b[1005][1005], c[1005][1005], par[1005], sz[1005], x[1005], sum[1005], cost[1005],cnt[1005];
vector<int> pos[1005];
vector<ii> edge[1005];
bool flag;

void dfs(int u){
	for (auto it: edge[u]){
		int v = it.first, c = it.second;
		if (par[v]&&x[v]!=x[u]^c) flag = true;
		if (par[v]) continue;
		x[v] = x[u]^c;
		par[v] = par[u];
		sum[par[u]] += x[v];
		dfs(v);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("CTAB.INP","r",stdin);
	freopen("CTAB.OUT","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for (int i = 1, x; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> b[i][j];
			x = a[i][j] + b[i][j];
			if (x==-1||x==1) return cout << -1,0;
			if (a[i][j]==0&&b[i][j]==0) c[i][j] = -1;
			else c[i][j] = (x==0);
			if (c[i][j]!=-1) pos[i].push_back(j);
		};
	}
	for (int i = 1; i <= n; i++) x[i] = -1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < pos[i].size(); j++) edge[pos[i][j-1]].push_back({pos[i][j],c[i][pos[i][j-1]]^c[i][pos[i][j]]});
	}
	for (int i = 1; i <= n; i++) if (par[i]==0){
		par[i] = i;
		x[i] = 0;
		dfs(i);
	}
	for (int i = 1; i <= n; i++) if (par[i]){
		sz[par[i]]++;
	}
	
	if (flag) return cout << -1, 0;
//	cout << "flag = " << flag << "\n";
//	for (int i = 1; i <= n; i++) cout << x[i] << " "; cout << "\n";
	for (int i = 1; i <= n; i++) if (pos[i].size()){
		int cmp = par[pos[i][0]];
		if (c[i][pos[i][0]]!=x[pos[i][0]]) cost[cmp]++;
		cnt[cmp]++;
	}
	
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++) cout << c[i][j] << " ";
//		cout << "\n";
//	}
	int res = 0;
	for (int i = 1; i <= n; i++) if (par[i]==i){
		res += min(sum[i]+cost[i],sz[i]-sum[i]+cnt[i]-cost[i]);
	}
	cout << res << "\n";
//	cout << cnt[1] << " " << sum[1] << "+" << cost[1] << "\n";
	
	
	return 0;
}
