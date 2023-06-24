#include <bits/stdc++.h>

using namespace std;
long long int a[1005][1005];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
		long long int x = 1e9+50;
		cin >> a[i][j];
		if (i!=1) x =  min(x,a[i-1][j]);
		if (j!=1) x =  min(x,a[i][j-1]);
		if (j==1) x = 0;
		//if (i==1&&j==1) x = -a[i][j];
		a[i][j] += x;
	}
//	for (int i = 1; i <= m; i++){ for (int j = 1; j <= n; j++) 
//		cout << a[i][j] << " "; cout << endl;
//	}
	long long int result = 1e10;
	for (int i = 1; i <= m; i++) result = min(result,a[i][n]);
	cout << result;
	return 0;
}
