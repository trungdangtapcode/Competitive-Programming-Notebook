#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5+5;
#define int long long
int n, cnt1[30][2], cnt2[30][2], a[maxN], pref[maxN];

void solve(){
	cin >> n;
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1]^a[i];	
		for (int j = 29; j >= 0; j--) cnt2[j][pref[i]>>j&1]++;	
	}
	for (int i = 29; i >= 0; i--) cnt1[i][0] = 1;
	int res = 0;
	for (int i = 1; i <= n; i++){
		int h = (int)__lg(a[i]);
//		cout << i << " " << h << " " << "\n";
		res += cnt1[h][0]*cnt2[h][0] + cnt1[h][1]*cnt2[h][1];
		for (int j = 29; j >= 0; j--) cnt1[j][pref[i]>>j&1]++;	
		for (int j = 29; j >= 0; j--) cnt2[j][pref[i]>>j&1]--;	
	}
	cout << res << "\n";

}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}


/*
struct Trie{
	int root;
	Trie(){
		root = ++ntrie;
	}
	void add(int x){
		int u = root;
		cnt[u]++;
		for (int i = 29; i >= 0; i--){
			bool c = (x>>i&1);
			if (to[u][c]==0) to[u][c] = ++ntrie;
			u = to[u][c];
			cnt[u]++;
		}
	}
	void remov(int x){
		int u = root;
		cnt[u]--;
		for (int i = 30; i >= 0; i--){
			bool c = (x>>i&1);
			u = to[u][c];
			cnt[u]--;
		}
	}
	void updt(int x){
		int u = root;
		for (int i = 30; i >= 0; i--){
			bool c = (x>>i&1);
			if (to[u][c]==0) return;
			u = to[u][c];
		}
	}
};
*/
