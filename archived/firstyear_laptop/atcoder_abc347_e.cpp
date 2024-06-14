#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, q, x[maxN], val[maxN];
vector<int> pos[maxN];
void solve(){
	cin >> n >> q;
	set<int> s;
	for (int i = 1; i <= n; i++) pos[i].clear();
	for (int i = 1; i <= q; i++){
		cin >> x[i];
		if (s.count(x[i])) s.erase(x[i]);
		else s.insert(x[i]);
		pos[x[i]].push_back(i);
		val[i] = s.size();
	}
	for (int i = 1; i <= q; i++) val[i] += val[i-1]; 
	for (int i = 1; i <= n; i++){
		pos[i].push_back(q+1);
		int res = 0;
		for (int j = 0; j < pos[i].size()-1; j += 2){
			res += val[pos[i][j+1]-1]-val[pos[i][j]-1];
		}
		cout << res << " ";
	}
}

main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

