#include<bits/stdc++.h>

using namespace std;
int n, m, a[1005][1005];

int main(){
	freopen("DUONGDI.INP","r",stdin);
	freopen("DUONGDI.OUT","w",stdout);
	
	cin >> n >> m;
	memset(a,1,sizeof(a));
	for (int i = 1, tmp; i <= n; i++) for (int j = 1; j <= m; j++){
		cin >> tmp;
		if (i==1&&j==1){
			a[i][j] = tmp;
			continue;
		}
		a[i][j] = min(a[i-1][j],a[i][j-1]) + tmp;
//		if (i==1000) cout << i << " " << j  << " "<< tmp <<endl;
//		a[i][j] = 1e9;
//		if (i>0) a[i][j] = min(a[i][j],tmp+a[i-1][j]);
//		if (j>0) a[i][j] = min(a[i][j],tmp+a[i][j-1]);
	}
	cout << a[n][m];
	
	return 0;
}
