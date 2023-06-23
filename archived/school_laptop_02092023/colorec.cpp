#include<bits/stdc++.h>

using namespace std;
const int T = 200;
int n, a[505][505], cnt[25];
int main(){
	cin >> n;
	for (int i = 1, x, y, c; i <= n; i++){
		cin >> x >> y >> c;
		x += T, y += T;
		a[x][y] = c;
	}	
	long long res =0;
	for (int i = 0; i <= 2*T; i++){
		for (int j = i+1; j <= 2*T; j++){
			memset(cnt,0,sizeof(cnt));
			for (int k = 0; k <= 2*T; k++) if (a[i][k]!=a[j][k]&&a[i][k]&&a[j][k]){
				int nc1 = a[i][k], nc2 = a[j][k];
				res += cnt[24/nc1/nc2];
				cnt[nc1*nc2]++;  
			}
		}
	}
	cout << res;
	
	return 0;
}
