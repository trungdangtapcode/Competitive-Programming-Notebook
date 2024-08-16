#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n;
void solve(){
	cin >> n;
	map<int,int> mp;
	int mmax = 0;
	for (int i = 1; i<= n; i++){
		int c; cin >> c;
		mp[c]++;
		mmax = max(mmax,c);
	}
	int res =0;
	for (auto it: mp){
		if (it.second%2){
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

