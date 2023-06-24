#include <bits/stdc++.h>

using namespace std;

int n;
string a[25];
int f[105][105], cost[25][25], g[(1<<21)+5];
string u, v;
int findcost(int x, int y){
	if (x>=u.length()) return v.length()-y;
	if (y>=v.length()) return u.length()-x;
	if (f[x][y]!=-1) return f[x][y];
	f[x][y] = 1e9;
	f[x][y] = min(f[x][y],min(findcost(x+1,y),findcost(x,y+1))+1);
	if (u[x]==v[y]) f[x][y] = min(f[x][y],findcost(x+1,y+1)+1);
	return f[x][y];
}
int solve(int k, int mask){
	if (k>=2*n) return 0;
	if (mask&(1<<k)) return solve(k+1,mask);
	if (g[mask]!=-1) return g[mask];
	g[mask] = 1e9;
	for (int i = k+1; i < 2*n; ++i) if (!(mask&(1<<i)))
		g[mask] = min(g[mask],max(solve(k+1,mask|(1<<i)),cost[k][i]));
	return g[mask];
}

int main(){
	cin >> n;
	for (int i = 0; i < 2*n; ++i) cin >> a[i];
	
	for (int i = 0; i < 2*n; ++i) for (int j = i + 1; j < 2*n; ++j){
		memset(f,-1,sizeof(f));
		u = a[i];
		v = a[j];
		cost[i][j] = findcost(0,0);
	}
	
	memset(g,-1,sizeof(g));
	cout << solve(0,0);
	
	return 0;
}
