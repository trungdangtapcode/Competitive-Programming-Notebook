#include<bits/stdc++.h>

using namespace std;
int n, a[505][505];
int gett(int x, int y, int u, int v){
	return (a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1]);
}

int main(){
	freopen("chiadat.inp","r",stdin);
	freopen("chiadat.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
		cin >> a[i][j];
		a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
	}
	
	int res = 1e9+1;
	for (int i = 1; i < n; i++) for (int j = 1; j < n; j++){
		int tmp1 = gett(1,1,i,j), tmp2 = gett(1,j+1,i,n), tmp3 = gett(i+1,1,n,j), tmp4 = gett(i+1,j+1,n,n);
		int big = max({tmp1,tmp2,tmp3,tmp4}), little = min({tmp1,tmp2,tmp3,tmp4});
		res = min(res,big-little);
	}
	cout << res;
	
	return 0;
}
