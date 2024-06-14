#include<bits/stdc++.h>

using namespace std;
int n, k;
void solve(){
	cin >>  n >> k;
	map<int,int> mp;
	int res = 0;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		mp[a]++;
		res = max(res,mp[a]);
	}
	cout << (res<k?n:k-1) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

