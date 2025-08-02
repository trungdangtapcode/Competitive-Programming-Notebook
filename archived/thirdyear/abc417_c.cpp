#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	map<int,int> mp;
	cin >> n;
	long long res = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if (mp.count(i-x)) res += mp[i-x]; 
		++mp[i+x];
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

