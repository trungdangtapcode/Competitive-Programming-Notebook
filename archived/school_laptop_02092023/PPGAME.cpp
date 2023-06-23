#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;
int n, m, k, dp[2][361][361][361];
string s[361];
inline int f(int x, int y, int u, int v, bool ok){
	if (dp[ok][x][y][u]!=-1) return dp[ok][x][y][u];
	int& res = dp[ok][x][y][u] = 0;
	if (s[x][y]!=s[u][v]&&!ok) return res = 0;
	if (x>u||y>v) return res = 0;
	if (abs(x-u)+abs(y-v)<=1) return res = 1;
	if (s[x][y]==s[u][v]){
		res += f(x+1,y,u-1,v,ok);
		if (res>=k) res-=k;
		res += f(x,y+1,u-1,v,ok);
		if (res>=k) res-=k;
		res += f(x+1,y,u,v-1,ok);
		if (res>=k) res-=k;
		res += f(x,y+1,u,v-1,ok);
		if (res>=k) res-=k;
	} else {
		res += f(x+1,y,u-1,v,0);
		if (res>=k) res-=k;
		res += f(x,y+1,u-1,v,0);
		if (res>=k) res-=k;
		res += f(x+1,y,u,v-1,0);
		if (res>=k) res-=k;
		res += f(x,y+1,u,v-1,0);
		if (res>=k) res-=k;
	}
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
//	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int k = 1; k <= n; k++) dp[0][i][j][k] = dp[1][i][j][k] = -1;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = "#" + s[i]; 
	}
	auto start = high_resolution_clock::now();
	cout << f(1,1,n,m,1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
 
//    cout << "Time taken by function: "
//         << duration.count() << " microseconds" << endl;
	return 0;
}
