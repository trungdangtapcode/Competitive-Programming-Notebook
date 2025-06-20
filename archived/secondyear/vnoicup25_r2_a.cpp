#include<bits/stdc++.h>

using namespace std;
const int maxN = 105;
int n, m, a[maxN][maxN], b[maxN][maxN];

void solve(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			a[i+n][j] = a[i][j+m] = a[i+n][j+m] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> b[i][j];
			b[i+n][j] = b[i][j+m] = b[i+n][j+m] = b[i][j];
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		bool match = true;
		for (int k = i; (k < i+n)&&match; k++) for (int l = j; (l < j+m)&&match; l++){
			if (a[k][l]!=b[k-i][l-j]) match = false;
		}
		if (match){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	
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

