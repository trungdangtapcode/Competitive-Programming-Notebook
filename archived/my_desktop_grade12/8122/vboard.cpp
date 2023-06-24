#include<bits/stdc++.h>

using namespace std;
int n, a[505][505], q, x, y, u, v, sign[] = {1,-1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
		cin >> a[i][j];
		a[i][j] = sign[(i+j)%2]*a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
	}
	cin >> q;
	while (q--){
		cin >> x >> y >> u >> v;
		cout << abs(a[u][v]-a[x-1][v]-a[u][y-1]+a[x-1][y-1]) << "\n";
	}
	
	return 0;
}
