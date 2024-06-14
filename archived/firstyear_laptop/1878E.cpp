#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, rmq[maxN][20], a[maxN];

int query(int l, int r){
	int h = __lg(r-l+1);
	return rmq[l][h]&rmq[r-(1<<h)+1][h];
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		rmq[i][0] = a[i];
	}
	for (int j = 1; j < 20; j++){
		for (int i = 1; i + (1<<j) - 1 <= n; i++){
			rmq[i][j] = rmq[i][j-1]&rmq[i+(1<<(j-1))][j-1];
		}
	}
	int q; cin >> q;
	while (q--){
		int l, k;
		cin >> l >> k;
		int lf = l, rt = n, m, res  = -1;
		while (lf<=rt){
			m = (lf+rt)/2;
			if (query(l,m)>=k){
				res = m;
				lf = m+1;
			} else rt = m-1;
		} 
		cout << res << " ";
	}
	cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
