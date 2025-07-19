#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxN = 205, maxL = 51;

void solve(){
	cin >> n >> s;
    vector<int> l(3);
    vector<vector<ll>> c(3), r(3), prefix_cost(3), prefix_rate(3);
	for (int i = 0; i < 3; ++i) {
		cin >> l[i];
		c[i].resize(l[i]);
		r[i].resize(l[i]);
		for (int j = 0; j < l[i]; ++j) cin >> c[i][j];
		for (int j = 0; j < l[i]; ++j) cin >> r[i][j];
		prefix_cost[i].resize(l[i] + 1, 0);
		prefix_rate[i].resize(l[i] + 1, 0);
		for (int j = 1; j <= l[i]; ++j) {
			prefix_cost[i][j] = prefix_cost[i][j - 1] + c[i][j - 1];
			prefix_rate[i][j] = prefix_rate[i][j - 1] + r[i][j - 1];
		}
	}
	

        
        
	exit(0);
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

