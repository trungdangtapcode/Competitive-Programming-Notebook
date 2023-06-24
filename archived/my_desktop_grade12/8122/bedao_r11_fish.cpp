#include<bits/stdc++.h>

using namespace std;
int n, m, u[1005][1005], f[1005][1005], p[1005][1005], r[1005][1005], l[1005][1005];
int main(){
	cin >> n >> m;
	for (int i = 1; i < n; i++){
		for (int j = 1; j <= m; j++) cin >> u[i][j];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < m; j++) cin >> r[i][j];
	}	
	for (int i = 1; i <= n; i++){
		for (int j = 2; j <= m; j++) cin >> l[i][j];
	}	
	for (int i = 1, x, y; i <= n; i++){
		cin >> x >> y;
		p[i][x] = y;
	}	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] = -1e9;
	f[1][1] = p[1][1];
	for (int i = 2; i <= m; i++){
		f[1][i] = f[1][i-1] - r[1][i-1] + p[1][i];
	}
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= m; j++) f[i][j] = f[i-1][j] - u[i-1][j] + p[i][j];
		for (int j = 2; j <= m; j++) f[i][j] = max(f[i][j],f[i][j-1] - r[i][j-1] + p[i][j]);
		for (int j = m-1; j >= 1; j--) f[i][j] = max(f[i][j],f[i][j+1] - l[i+1][j+1] + p[i][j]);
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++) cout << f[i][j] << " ";
//		cout << endl;
//	}
	cout << -f[n][m] << endl;
	return 0;
}
