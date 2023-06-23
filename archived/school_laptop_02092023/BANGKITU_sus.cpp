#include<bits/stdc++.h>

using namespace std;
int a[2001105], n, m, k;
char c;
int idx(int i, int j){
	return (m+2)*i+j+50;
}
int gett(int x, int y, int u, int v){
	return a[idx(u,v)] - a[idx(x-1,v)] - a[idx(u,y-1)] + a[idx(x-1,y-1)];
}
main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> c;
				a[idx(i,j)] = (c=='A'?1:-1);
				a[idx(i,j)] += a[idx(i-1,j)] + a[idx(i,j-1)] - a[idx(i-1,j-1)];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; j++){
			for (int u = n; u >= i; --u) for (int v = m; v >= j; --v){
				if (abs(gett(i,j,u,v))<=k) ans = max(ans,(u-i+1)*(v-j+1));
				if ((u-i+1)*(v-j+1)<=ans) break; 
			}
			if ((n-i+1)*(m-j+1)<=ans) break;
		}
		cout << ans << "\n";
	}
	return 0;
}
