#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e3+5;
typedef pair<int,int> ii;
const int dx[] = {0,1,1,1,0,-1,-1,-1}, dy[] = {1,1,0,-1,-1,-1,0,1};
int n, a[maxN][maxN], d[maxN][maxN];
vector<ii> ls[maxN*maxN];
bool bfs(int k){
	queue<ii> q;
	for (auto u: ls[k]){
		if (u.first!=n&&u.second!=1) continue;
		d[u.first][u.second] = 1;
		q.push(u);
	}
	while (q.size()){
		ii u = q.front(); q.pop();
		int ux = u.first, uy = u.second;
		for (int i = 0; i < 8; i++){
			int vx = ux + dx[i], vy = uy + dy[i];
			if (vx>n||vx<1||vy>n||vy<1||d[vx][vy]||a[vx][vy]!=k) continue;
			d[vx][vy] = 1;
			q.push({vx,vy});
		}
	}
	bool res = 0;
	for (auto u: ls[k]){
		if (u.first!=1&&u.second!=n) continue;
		if (d[u.first][u.second]) res = 1;
	}
	for (auto u: ls[k]){
		d[u.first][u.second] = 0;
	}
	return res;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n*n; i++) ls[i].clear();
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			ls[a[i][j]].push_back({i,j});
		}
	}
	for (int i = 1; i <= n*n; i++){
		if (!bfs(i)){
			cout << i << "\n";
			return;
		}
	}
//	cout << bfs(1) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

