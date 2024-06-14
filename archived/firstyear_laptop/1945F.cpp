#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxN = 2e5+5;
int cha[maxN], n, p[maxN];
int a[maxN];
void solve(){
	cin >> n;
	set<ii> s;
	priority_queue<ii> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		q.push({a[i],i});		
	}
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}
	ii res = {0,0};
	for (int k = 1; k <= n; k++){
		while (s.size() < k && q.size()){
			if (a[q.top().second] != 0){
				s.insert(ii{a[q.top().second],q.top().second});
			}
			q.pop();
		}
//		cout << k << ": ";
//		for (auto it: s) cout << it.first << " "; cout << "\n";
		if (s.size() >= k) res = max(res,{(*s.begin()).first*k,-(int)s.size()});
		int pos = p[k];
		if (s.find({a[pos],pos})!=s.end()){
			s.erase({a[pos],pos});
		}
		a[pos] = 0;
	}
	cout << res.first << " " << -res.second << "\n";
}


main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

