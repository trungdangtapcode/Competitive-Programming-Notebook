#include<bits/stdc++.h>

using namespace std;
const int maxN = 1505;
int n, m, a[maxN], b[maxN][maxN], l, f0[maxN][maxN], f1[maxN][maxN];
void solve(){
	cin >> l >> n >> m ;
	for (int i = 1; i <= l; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> b[i][j];
	}
	map<int,int> mp;
	for (int i = 1, cnt = 0; i <= l; i++){
//		if (!mp.count(a[i])) mp[a[i]] = ++cnt; ??????
		if (!mp.count(a[i])) mp[a[i]] = i; 
	}
	for (int i = n+1; i >= 0; i--){
		for (int j = m+1; j >= 0; j--){
			f0[i][j] = f1[i][j] = 1e9;
		}
	}
	
	for (int i = n; i >= 1; i--){
		for (int j = m; j >= 1; j--){
			f0[i][j] = min(f0[i+1][j],f0[i][j+1]);
			f1[i][j] = min(f1[i+1][j],f1[i][j+1]);
			if (!mp.count(b[i][j])) continue;
			int idx = mp[b[i][j]];
			if (idx%2==0&&idx+1<f1[i+1][j+1]) f0[i][j] = min(idx,f0[i][j]);
			if (idx%2==1&&idx+1<f0[i+1][j+1]) f1[i][j] = min(idx,f1[i][j]);
		}
	}
	cout << (f1[1][1]==1?"T\n":"N\n");
	

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

