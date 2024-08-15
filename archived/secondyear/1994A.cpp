#include<bits/stdc++.h>

using namespace std;
int n, m;
void solve(){
	cin >> n >> m;
	if (n*m==1){
		cin >> n;
		cout << "-1\n";
		return;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int a;
			cin >> a;
			cout << a%(n*m)+1 << " ";
		}
		cout << "\n";
	}
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

