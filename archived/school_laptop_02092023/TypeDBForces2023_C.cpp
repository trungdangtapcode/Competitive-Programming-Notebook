#include<bits/stdc++.h>

using namespace std;
long long n, s, x[200005][2], a[200005], f[200005][2];
void solve(){
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n-1; i++){
		if (2*s<=a[i]){
			x[i][0] = s;
			x[i][1] = a[i]-s;
		} else if (a[i]>=s){
			x[i][0] = a[i]-s;
			x[i][1] = s; 
		} else {
			x[i][0] = 0;
			x[i][1] = a[i];
		}
//		cout << x[i][0] << " " << x[i][1] << "\n";
		for (int j = 0; j < 2; j++){
			if (i==2){
				f[i][j] = x[i][j]*a[1];
				continue;
			}
			f[i][j] = 1e18;
			for (int k = 0; k < 2; k++) f[i][j] = min(f[i][j],f[i-1][k]+x[i][j]*x[i-1][!k]);
		}
	}
	long long res = min(f[n-1][0]+x[n-1][1]*a[n],f[n-1][1]+x[n-1][0]*a[n]);
	cout << res << "\n";
	
	
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
