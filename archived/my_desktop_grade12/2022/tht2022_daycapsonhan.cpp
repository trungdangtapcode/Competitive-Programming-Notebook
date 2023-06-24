#include<bits/stdc++.h>

using namespace std;
const int T = 30;
map<int,int> mp[T];
int n, a[100005], q;
const int mod = 1e9+7;
int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		++mp[0][a[i]];
		if (a[i]%q) continue;
		for (int j = 1; j < T; j++){
			(mp[j][a[i]] += mp[j-1][a[i]/q])%= mod;
		}
	}
	for (int i = 1; i < n; i++){
		int res = 0;
		if (i<T) for (auto it: mp[i]) (res += it.second)%= mod;
		cout << res << " ";
	}
	
	return 0;
}
