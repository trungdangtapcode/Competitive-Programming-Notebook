#include<bits/stdc++.h>

using namespace std;

int a[1005][1005], q, n, m;

int gett(int x, int y, int u, int v){
	return a[u][v] - (x==0?0:a[x-1][v]) - (y==0?0:a[u][y-1]) + (x==0||y==0?0:a[x-1][y-1]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		cin >> a[i][j];
		a[i][j+m] = a[i+n][j] = a[i+n][j+m] = a[i][j];
	}
	for (int i = 0; i < 2*n; i++) for (int j = 0; j < 2*m; j++){
		a[i][j] += (i==0?0:a[i-1][j]) + (j==0?0:a[i][j-1]) - (i==0||j==0?0:a[i-1][j-1]);
	}
	cin >> q;
	int x = 0, y = 0;
	while (q--){
		int p, s, t, u, v;
		cin >> p;
		if (p){
			cin >> s >> t >> u >> v;
			s--; t--; u--; v--;
			s += x; t += y; u += x; v += y;
			cout << gett(s,t,u,v) << "\n";
		} else {
			cin >> t >> s;
			x = (x+s)%n;
			y = (y+t)%m;
		}
	}
	
	return 0;
}
