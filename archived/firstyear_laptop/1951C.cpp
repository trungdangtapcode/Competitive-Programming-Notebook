#include<bits/stdc++.h>

using namespace std;
int n, m, k;
void solve(){
	cin >> n >> m >> k;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		pq.push(a);
	}
	long long res = 1ll*k*k;
	while (k>0){
		int cnt = min(m,k);
		res += 2ll*cnt*pq.top()-1ll*cnt*cnt; pq.pop();
		k -= cnt;
	}
	cout << res/2 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

