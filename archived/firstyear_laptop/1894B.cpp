#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n, a[maxN], res[maxN];
vector<int> v[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= 100; i++) v[i].clear();
	for (int i = 1; i <= n; i++) v[a[i]].push_back(i);
	int cnt =0;
	for (int i = 1; i <= 100; i++){
//		if (v[i].size()>2){
//			cout << -1 << "\n";
//			return;
//		}
		if (v[i].size()<1) continue;
		if (v[i].size()<2){
			res[v[i][0]] = 1;
			continue;
		}
		cnt++;
		for (int j = 0; j < v[i].size(); j++){
			res[v[i][j]] = 1;
			res[v[i][0]] = (cnt+1<=3?cnt+1:1);
		}
	}
	if (cnt<2){
		cout << -1 << "\n";
		return;
	}
	for (int i = 1; i<= n; i++) cout << res[i] << " "; cout << "\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
