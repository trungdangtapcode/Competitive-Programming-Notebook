#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n, res[maxN], a[maxN][maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) res[i] = ((1<<30)-1);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			if (i!=j) res[i] &= a[i][j];
		}
	}
	int ok = 1;
//	for (int i = 1; i <= n; i++) cout << res[i] << ", "; cout << "\n";
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
//			if (i!=j) cout << (res[i]|res[j]) << " ";
//			else cout << 0 << " ";
			if (i!=j&&(res[i]|res[j])!=a[i][j]) ok = 0;
		}
//		cout << "\n";
	}
	if (ok){
		cout << "YES\n";
		for (int i = 1; i <= n; i++) cout << res[i] << " "; cout << "\n";
	} else cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
