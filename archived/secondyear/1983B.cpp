#include<bits/stdc++.h>

using namespace std;
const int maxN = 505;
int n, a[maxN][maxN], m, b[maxN][maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			char c; cin >> c;
			a[i][j] = c-'0';
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			char c; cin >> c;
			b[i][j] = c-'0';
		}
	}
	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			if (a[i][j]==b[i][j]) continue;
			if ((a[i][j]-b[i][j]+3)%3==1){
				(b[i][j] += 1)%=3;
				(b[i+1][j+1] += 1)%=3;
				(b[i][j+1] += 2)%=3;
				(b[i+1][j] += 2)%=3;
				continue;
			}
			if ((a[i][j]-b[i][j]+3)%3==2){
				(b[i][j] += 2)%=3;
				(b[i+1][j+1] += 2)%=3;
				(b[i][j+1] += 1)%=3;
				(b[i+1][j] += 1)%=3;
				continue;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j= 1; j <= m; j++){
			if (a[i][j]!=b[i][j]){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

