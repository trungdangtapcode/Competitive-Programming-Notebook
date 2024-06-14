#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 105, maxM = 2e5+5;
int a[maxN][maxM], n, k, m, d, f[maxM], cost[maxN];
int calc(int row){
	f[1] = 1;
	deque<int> dq;
	dq.push_back(1);
	for (int i = 2; i <= m; i++){
		while (dq.size()&&dq.front()<i-d-1) dq.pop_front();
		f[i] = f[dq.front()] + a[row][i] + 1;
		while (dq.size()&&f[dq.back()]>=f[i]) dq.pop_back();
		dq.push_back(i);
	}
	return f[m];
}

void solve(){
	cin >> n >> m >> k >> d;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> a[i][j];
		cost[i] = calc(i);
		cost[i] += cost[i-1];
	}
	int res = 1e18;
	for (int i = k; i <= n; i++) res = min(res,cost[i]-cost[i-k]);
	cout << res << "\n"; 
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

