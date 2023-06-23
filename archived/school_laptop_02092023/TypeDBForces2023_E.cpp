#include<bits/stdc++.h>

using namespace std;
int n, k, x;
void solve(){
	cin >> n >> k >> x;
	vector<int> used(n+1,false);
	vector<vector<int>> v;
	for (int i = 1; i <= n; i++){
		if (i==x){
			used[i] = 1;
			v.push_back({i});
			continue;
		}
		int ii = i^x;
		if (ii>n||used[ii]||used[i]) continue;
		used[ii] = used[i] = 1;
		v.push_back({ii,i});
	}
	vector<int> cur;
	int total = 0;
	for (int i = 1; i <= n; i++) if (!used[i]){
		total ^= i;
		cur.push_back(i);
	}
	for (int i = k-1; i < v.size(); i++) for (int x: v[i]){
		total ^= x;
		cur.push_back(x);
	}
	if (v.size()<k||total!=x) return cout << "NO\n", void();
	cout << "YES\n";
	for (int i = 0; i < k-1; i++){
		cout << v[i].size() << " ";
		for (int j: v[i]) cout << j << " ";
		cout << "\n";
	}
	cout << cur.size() << " ";
	for (int x: cur) cout << x << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
