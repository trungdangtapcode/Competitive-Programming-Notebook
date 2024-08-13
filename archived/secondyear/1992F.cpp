#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], x;
void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	set<int> s;
	s.insert(x);
	int res = 0;
	for (int i = 1; i <= n; i++){
		bool flag = 0;
		for (int d: s){
			if (d%a[i]) continue;
			if (d==a[i]){
				res++;
				s.clear();
				s.insert(x);
				break;
			}
		}
		for (int d: s){
			if (d%a[i]) continue;
			s.insert(d/a[i]);
		}
	}
	cout << res+1 << "\n";
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

