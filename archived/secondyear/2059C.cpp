#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n, a[maxN][maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++){
		int cnt = 0;
		for (int j = n; j >= 1; j--){
			if (a[i][j]!=1) break;
			cnt++;
		}
		pq.push(cnt);
	}
	int res = 0;
	while (pq.size()){
		int x = pq.top(); pq.pop();
		res += (x>=res);
	}
	cout << res << '\n';
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

