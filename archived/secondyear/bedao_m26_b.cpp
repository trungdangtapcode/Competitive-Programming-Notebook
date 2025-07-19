#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	set<int> s, res;
	for (int i = 1; i <= n; i++){
		set<int> tmp;
		s.insert(0);
		for (int it: s)
			tmp.insert(it|a[i]),
			res.insert(it|a[i]);
		s = tmp;
	}
	cout << res.size() << "\n"; 
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

