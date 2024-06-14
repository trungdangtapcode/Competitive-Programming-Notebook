#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (mp.count(a[n]-a[i-1])) res = max(res,mp[a[n]-a[i-1]]+(n-i+1));
		mp[a[i]] = max(mp[a[i]], i);
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

