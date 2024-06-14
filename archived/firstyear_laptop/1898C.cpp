#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e3+5;
int n, m, res1[maxN][maxN], res2[maxN][maxN], k;
void solve(){
	cin >> n >> m >> k;
	int path = n+m-2;
	if (k<path){
		cout << "NO" << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) res1[i][j] = res2[i][j] = 0;
	}
	if (k%2!=path%2){
		cout << "NO" << "\n";
		return;
	}
	cout << "YES\n";
	int last = 0;
	for (int i = 1; i < n; i++){
		last ^= 1;
		res2[i][1] = last;
	}
	for (int i = 1; i < m; i++){
		last ^= 1;
		res1[n][i] = last;
	}
	res1[1][1] = res1[1][2] = res2[1][1]^1;
	res2[1][2] = res2[1][1];
	res2[n-1][m] = res2[n-1][m-1] = res1[n][m-1];
	res1[n-1][m-1] = res1[n][m-1]^1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < m; j++) cout << (res1[i][j]?'R':'B') << " ";
		cout << "\n";
	}
	for (int i = 1; i < n; i++){
		for (int j = 1; j <= m; j++) cout << (res2[i][j]?'R':'B') << " ";
		cout << "\n";
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
