#include<bits/stdc++.h>

using namespace std;
map<int,multiset<int>> mp;
void solve(){
	mp.clear();
	int n, x; cin >> n >> x;
	for (int i = 1; i<= n; i++){
		int a; cin >> a;
		mp[a%x].insert(a);
	}
	int res = 0;
	while (true){
		if (!mp.count(res%x)){
			break;
		}
		multiset<int>& ms = mp[res%x];
		auto it = ms.upper_bound(res);
		if (it==ms.begin()) break;
		ms.erase(--it);
		res++;
	}
	cout << res << "\n";
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

