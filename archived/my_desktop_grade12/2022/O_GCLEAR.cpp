#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m, x, y, z, t;
string a[105], moveList;
int d[105][105];
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

void bfs(){
	for (int i =0; i < n; i++) for (int j = 0; j < m; j++) d[i][j] = 1e9;
	queue<ii> q;
	d[x][y] = 0;
	q.push({x,y});
	while (!q.empty()){
		int ux = q.front().first, uy = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int vx = ux + dx[i], vy = uy + dy[i];
			if (vx<0||vy<0||vx>=n||vy>=m||a[vx][vy]=='1') continue;
			if (d[vx][vy]==1e9) d[vx][vy] = d[ux][uy] + 1, q.push({vx,vy});
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> z >> t >> moveList >> x >> y;
	x--; y--; z--; t--;
	bfs();
	if (d[z][t]==0) return cout << 0,0;
	int timer = 0;
	for (char c: moveList){
		++timer;
		if (c=='U') z--;
		if (c=='D') z++;
		if (c=='L') t--;
		if (c=='R') t++;
		if (d[z][t]<=timer&&(d[z][t]-timer)%2==0) return cout << timer, 0;
	}
	cout << -1;
	
	return 0;
}
