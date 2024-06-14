#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int visited[maxN][2];
vector<int> edge[maxN];
int n, m, cnt[maxN][3];

void dfs(int u, int p, int c, int cmp){
	visited[u][c] = cmp;
	for (int v: edge[u]) if (!visited[v][c^1]){
		dfs(v,u,c^1,cmp);
	}
}
long long f(int x){
	return 1ll*x*x;
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1, lt = 1; i <= n; i++){
		if (!visited[i][0]||!visited[i][1]) dfs(i,0,0,lt++);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 2; j++) if (visited[i][j]) cnt[visited[i][j]][j]++;
		if (visited[i][0]&&visited[i][1]) cnt[visited[i][0]][2]++;
	}
//	cout << cnt[0] << " " << cnt[1] << " " << cnt[3] << '\n';
	long long res = 0;
	for (int i = 1; i <= n; i++) res += f(cnt[i][0]) + f(cnt[i][1]) - f(cnt[i][2]);
	cout << res;
	
	return 0;
}
