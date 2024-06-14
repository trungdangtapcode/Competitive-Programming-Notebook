#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e4+5;
int n, a[maxN];
void solve(){
	cin >> n;
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		for (int j = 2; j*j <= a[i]; j++) if (a[i]%j==0){
			int cnt = 0;
			while (a[i]%j==0) cnt++, a[i] /= j;
			mp[j] += cnt;
		}
		if (a[i]>1) mp[a[i]]++;
	}
	for (auto it: mp){
		if (it.second%n){
			cout << "NO\n";
			return;
		};
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

