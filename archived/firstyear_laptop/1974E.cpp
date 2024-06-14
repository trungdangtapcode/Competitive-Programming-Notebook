#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int m, x, c[51], h[51];
long long f[51][maxN];
void solve(){
	cin >> m >> x;
	for (int i = 1; i <= m; i++) cin >> c[i]>> h[i];
	int s = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 0; j <= s+h[i]; j++) f[i][j] = -1e18;
		for (int j = 0; j <= s; j++){
			f[i][j] = max(f[i][j],f[i-1][j]+x);
			if (f[i-1][j]>=c[i]) f[i][j+h[i]] = max(f[i][j+h[i]],f[i-1][j]-c[i]+x);
//			if (f[i-1][j]>=c[i]) cout << "hi\n";
//			cout << i << ", " << j << " = " << f[i-1][j] << " " << c[i] << "\n";
		}
		s += h[i];
	}
	for (int i = s; i >= 0; i--){
		if (f[m][i]>=0){
			cout << i << "\n";
			break;
		}
	}
//	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	for (int i = 1; i <= 1e5; i++) f[0][i] = -1e18;
	int t; cin >> t;
	while (t--)
	solve();
}

