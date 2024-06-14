#include<bits/stdc++.h>

using namespace std;
const int maxN = 55;
int n, k[maxN], pos[55][55], c[55];
vector<int> v[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= 50; i++) v[i].clear(), c[i] = 0;
	memset(pos,0,sizeof(pos));
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			int x;
			cin >> x;
			pos[x][i] = 1;
			c[x] = 1;
			v[i].push_back(x);
		}
	}
	int res = 0;
	for (int i = 1; i <= 50;i++) if (c[i]){
		set<int> st;
//		for (int j = 1; j <= 50; j++) check[j] = 0;
		for (int j = 1; j <= n; j++) if (!pos[i][j]){
			for (int x: v[j]) st.insert(x);
		} 
//		if (st.size()){
//			cout << i << "h ";
//			for (int x: st) cout << x << " ";
//			cout << "\n";
//		}
		res = max(res,(int)st.size());
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
