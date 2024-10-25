#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<ii,ii> i4;
const int maxN = 105, dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int n, m, c, mp[maxN][maxN], dist[15][maxN][maxN], cx[15], cy[15], f[15][1<<15];
string s[maxN];
bool check(int x, int y){
	return (0<=x&&x<n&&0<=y&&y<m&&s[x][y]!='#');
}
void bfs(int idx, int sx, int sy){
	queue<ii> q;
	q.push({sx, sy});
	dist[idx][sx][sy] = 0;
	while (q.size()){
		int ux = q.front().first, uy = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int vx = ux+dx[i], vy = uy+dy[i];
			if (!check(vx,vy)) continue;
			if (dist[idx][vx][vy]>1+dist[idx][ux][uy]){
				dist[idx][vx][vy]=1+dist[idx][ux][uy];
				q.push({vx,vy});
			}
		}
	}
}
void solve(){
	cin >> n >> m >> c;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < m; j++) if (s[i][j]=='S'){
			cx[cnt] = i, cy[cnt] = j;
			mp[i][j] = cnt++;
		}
	}
	assert(cnt==c);
	memset(dist,0x3f,sizeof(dist));
	for (int i = 0; i < c; i++){
		bfs(i,cx[i],cy[i]);
	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++) cout << dist[0][i][j] << " ";
//		cout << '\n';
//	}
	queue<ii> q;
	memset(f,0x3f,sizeof(f));
	for (int i = 0; i < c; i++){
		q.push({1<<i,i});
		f[i][1<<i] = 0;
	}
	int res = 1e9;
	while (q.size()){
		int u = q.front().second, umask = q.front().first; q.pop();
		if (umask==(1<<c)-1){
			res = min(res,dist[u][0][0]+f[u][umask]);
		}
		for (int v = 0; v < c; v++) if ((umask>>v&1)==0){
			int vmask = umask^(1<<v);
			if (f[v][vmask]>f[u][umask]+dist[u][cx[v]][cy[v]]){
				f[v][vmask]=f[u][umask]+dist[u][cx[v]][cy[v]];
				q.push({vmask,v});
			}
		}
	}
	if (res==1e9){
		cout << -1 << "\n";
		return;
	}
	cout << res  << '\n';
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}
//https://pastebin.pl/view/c78e448d

