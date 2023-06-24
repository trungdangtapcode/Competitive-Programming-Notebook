#include <bits/stdc++.h>

using namespace std;
long long int f[105][505], g[105][505];
int n, a[105], m, k;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		a[x]++;
	}
	for (int i = 1, p, x, y, need; i <= m; i++) for (int j = 0; j <= k; j++){
		need = j+1; //duoi j lan thi can chia cho j+1 don vi
		p = a[i]/need; y = a[i]%need; x = need-y;
		f[i][j] = 1ll*x*p*(p+1)/2+1ll*y*(p+1)*(p+2)/2;
	}
	for (int i = 1; i <= m; i++) for (int j = 0; j <= k; j++){
		g[i][j] = 1e18;
		for (int c = 0; c <= j; c++) g[i][j] = min(g[i][j],g[i-1][j-c]+f[i][c]);
	}
	cout << g[m][k];
	
	return 0;
}
