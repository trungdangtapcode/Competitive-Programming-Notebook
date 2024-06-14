#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e5+5;
int n, a[maxN];

void check(){
	multiset<int> ms;
	for (int i = 1; i <= n; i++){
		ms.insert(a[i]+i-1);
		ms.insert(a[i]);
	}
	int res = 1e18;
	for (int i = 1; i <= n; i++){
		ms.erase(ms.find(a[i]+i-1));
		res = min(res,*ms.rbegin());
		ms.insert(a[i]+n-i);
	}
	cout << res << "\n";
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	check();
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
	
	return 0;
}
