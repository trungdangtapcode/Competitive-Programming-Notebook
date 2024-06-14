#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 5e5+5;
int n, a[maxN], b[maxN], x, res[maxN];
ii ax[maxN];
//string s;
void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++){
		cin >> ax[i].first;
		ax[i].second = i;
		a[i] = ax[i].first;
	}
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(ax+1,ax+n+1);
	sort(b+1,b+n+1);
//	a[0] = -1e9; b[n+1] = 1e9;
//	if (ax[n-x+1].first<=b[x]){
//		cout << "NO\n";
//		return;
//	} 
//	multiset<int> ms;
//	for (int i = x+1; i <= n; i++){
//		ms.insert(b[i]);
//	}
//	cout << ms.size() << " " << n-x << "\n";
//	for (int i = 1; i <= n-x; i++){
//		auto it = ms.upper_bound(ax[i].first);
//		cout << *it << "\n";
//		if (it==ms.begin()){
//			cout << "NO\n";
//			return;
//		}
//		it--;
//		res[ax[i].second] = *it;
//		ms.erase(it);
//	}
	for (int i = 1, j = x+1; i <= n-x; i++, j++){
		if (ax[i].first>b[j]){
			cout << "NO\n";
			return;
		}
		res[ax[i].second] = b[j];
	}
	for (int i = n-x+1, j = 1; i <= n; i++, j++){
		if (ax[i].first<=b[j]){
			cout << "NO\n";
			return;
		}
		res[ax[i].second] = b[j];
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++){
		cout << res[i] << " ";
	} cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
