#include<bits/stdc++.h>

using namespace std;

int n, a[1005][1005], sumr[1005][1005], sumc[1005][1005], f[1005][1005];

int dp(int i, int j){
	if (f[i][j]!=-1) return f[i][j];
	f[i][j] = 0;
	if (sumr[i][j]==0) f[i][j] |= !dp(i-1,j);
	if (sumc[i][j]==0) f[i][j] |= !dp(i,j-1);
	return f[i][j];
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			sumr[i][j] = (a[i][j] + sumr[i][j-1])%2;
			sumc[i][j] = (a[i][j] + sumc[i-1][j])%2;
			f[i][j] = -1;
		}
	}
	cout << (dp(n,n)?"YES\n":"NO\n");
	
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
