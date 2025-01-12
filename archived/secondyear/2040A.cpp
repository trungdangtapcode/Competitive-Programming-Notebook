#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, k, a[maxN];
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	map<int,int> mp;
	for (int i = 1; i  <= n; i++){
		mp[a[i]%k]++;
	}
	for (int i = 1; i <= n; i++) if (mp[a[i]%k]==1){
		cout << "YES\n";
		cout << i << "\n";
		return;
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

