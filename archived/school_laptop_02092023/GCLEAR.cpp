#include<bits/stdc++.h>

using namespace std;
int d[1005][1005], n, m, x, y, z, t, a[1005][1005];
string s;
int dx[] = {1,0,-1,0}, dy[] = {0,-1,0,1};
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

void dijkstra(){
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({0,{z,t}});
	d[z][t] = 0;
	
	while (!pq.empty()){
		int ux = pq.top().second.first, uy = pq.top().second.second, du = pq.top().first;
		pq.pop();
		
		if (d[ux][uy]!=du) continue;
		for (int i = 0; i < 4; i++){
			int vx = ux + dx[i], vy = uy + dy[i];
			if (vx<1||vx>n||vy<1||vy>m||a[vx][vy]) continue;
			if (d[vx][vy]>du+1){
				d[vx][vy]=du+1;
				pq.push({d[vx][vy],{vx,vy}});
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s;
		for (int j = 1; j <= m; j++) a[i][j] = s[j-1]-'0';
		for (int j = 1; j <= m; j++) d[i][j] = 1e9;
	}
	cin >> x >> y >> s;
	cin >> z >> t;
	dijkstra();
//	for (int i = 1; i <= n; i++){
//		for (int j= 1; j <= m; j++) cout << d[i][j] << " ";
//		cout << endl;
//	}
	int res = 1e9;
	if (d[x][y]==0) {
		cout << 0;
		return 0;
	};
	for (int i = 0; i < s.length(); i++){
		int t = i+1;
		if (s[i]=='U') x--;
		if (s[i]=='D') x++;
		if (s[i]=='L') y--;
		if (s[i]=='R') y++;
		if (d[x][y]<=t&&(d[x][y]-t)%2==0){
			cout << t;
			return 0;
		};
	}
	cout << -1;
	
	return 0;
}
