#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	map<int,int> mp;
	int mmax = 0;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		mp[a]++;
		mmax = max(mmax, mp[a]);
	}
	int res = n - mmax;
	while (mmax<n){
		mmax *= 2;
		res++;
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

