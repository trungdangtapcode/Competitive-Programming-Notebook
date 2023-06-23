#include<bits/stdc++.h>

using namespace std;
int n, a[100005], p[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
//		sort(a+1,a+n+1);
		int g = 1;
		iota(p,p+n+1,0);
		sort(p+1,p+n+1,[&](int x, int y){
			return a[x]<a[y];
		});
		vector<pair<int,int>> res;
		for (int i = 1; i <= n; i++){
			int id = p[i];
			if (a[id]%g){
				res.push_back({id,g-a[id]%g});
				a[id] += g-a[id]%g;
			}
			g = a[id];
		}
		cout << res.size() << "\n";
		for (auto it: res) cout << it.first << " " << it.second << "\n";
	}
	
	return 0;
}
