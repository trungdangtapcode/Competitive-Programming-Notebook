#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
typedef pair<int,int> ii;
int n, a[maxN], b[maxN], m;
vector<int> res[maxN];
void solve(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i <= n; i++) res[i].clear();
	sort(b,b+m);
	vector<ii> v;
	for (int i = 0; i < n; i++){
		v.push_back({a[i],-i});
	}
	v.push_back({-1e9-1,-n});
	sort(v.begin(),v.end());
	v.push_back({1e9+1,-1});
	for (int i = 0, j = 0; i <= n; i++){
		int x = v[i].first, y = -v[i].second;
		if (x!=-1e9-1) res[y].push_back(x);
		while (j < m && b[j] < v[i+1].first) res[y].push_back(b[j++]);
	}
	for (int i = 0; i <= n; i++){
		reverse(res[i].begin(),res[i].end());
		for (int x: res[i]) cout << x << " ";
	}
	cout << "\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
