#include<bits/stdc++.h>

using namespace std;
int n, m, x, y, f[305][305][305];
string a[305], s;
int main(){
	
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = "#" + a[i] + "#";
	}
	a[0].assign(m+2,'#');
	a[n+1].assign(m+2,'#');
	cin >> s;
	s = "#" + s;
	for (int i = 0; i < s.length(); i++) for (int j = 0; j <= n+1; j++) for (int k = 0; k <= m+1; k++) f[i][j][k] = 1e9;
	f[0][x][y] = 0;
	for (int i = 0; i < s.length(); i++){
		for (int x = 1; x <= n; x++) for (int y = 1; y <= m; y++) if (s[i]==a[x][y]&&i>0) f[i][x][y] = min(f[i][x][y],f[i-1][x][y]);
		for (int x = 1; x <= n; x++) for (int y = 1; y <= m; y++) f[i][x][y] = min(f[i][x][y],f[i][x][y-1]+1);
		for (int x = 1; x <= n; x++) for (int y = 1; y <= m; y++) f[i][x][y] = min(f[i][x][y],f[i][x-1][y]+1);
		for (int x = n; x >= 1; x--) for (int y = m; y >= 1; y--) f[i][x][y] = min(f[i][x][y],f[i][x+1][y]+1);
		for (int x = n; x >= 1; x--) for (int y = m; y >= 1; y--) f[i][x][y] = min(f[i][x][y],f[i][x][y+1]+1);
	}
	int res = 1e9;
	for (int x = 1; x <= n; x++){
//		for (int y = 1; y <= m; y++) cout << f[s.length()-1][x][y] <<" ";
//		cout <<endl;
		for (int y = 1; y <= m; y++) res = min(res,f[s.length()-1][x][y]);
	}
	cout << res;
	
	
	return 0;
}
