#include<bits/stdc++.h>

using namespace std;
int n, m, x, y, res = 0, a[105][105];
bool visited[105][105];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int dfs(int ux, int uy){
	int res = 0;
	visited[ux][uy] = true;
	for (int i = 0; i < 4; i++){
		int vx = ux + dx[i], vy = uy + dy[i];
		if (vx<1||vx>n||vy<1||vy>m) continue;
		if (a[vx][vy]==1) continue;
		if (visited[vx][vy]) continue;
		res = max(res,dfs(vx,vy));
	}
	visited[ux][uy] = false;
	return res+1;
}

int main(){
	freopen("TRONGCAY.INP","r",stdin);
	freopen("TRONGCAY.OUT","w",stdout);
	
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	cout << dfs(x,y);
	
	
	return 0;
}
