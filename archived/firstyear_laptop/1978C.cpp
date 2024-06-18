#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
long long k;
typedef pair<int,int> ii;
void solve(){
	cin >> n >> k;
	if (k%2){
		cout << "No\n";
		return;
	}
	k /= 2;
	for (int i = 1; i <= n; i++) a[i] = i;
	multiset<ii> ms;
	ms.insert({1,1});
	for (int i = 2; i <= n; i++) if (k){
//		int x = min(k,1ll*i-1);
		auto it = ms.upper_bound(ii{i-k,-1e9});
//		cout << (*it).first << " " << (*it).second << "\n";
//		if (it==ms.begin()) continue;
		if (it==ms.end()) continue;
//		it--;
		int x = (*it).second; 
		k -= i-(*it).first;
		ms.erase(it);
		ms.insert({i,x});
		ms.insert({i,i});
//		cout << i << ".." << x << "\n";
		swap(a[i],a[x]);
//		for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "k = " << k << "\n";
	}
	if (k){
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
//	for (int i = 1; i <= n; i++) cout << abs(a[i]-i) << " "; cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

