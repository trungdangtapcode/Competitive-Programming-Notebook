#include<bits/stdc++.h>

using namespace std;
#define int long long
int t, n, m;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		priority_queue<int,vector<int>,greater<int>> pq;
		cin >> n >> m;
		for (int i = 0, x; i < n; i++){
			cin >> x;
			pq.push(x);
		}
		while (m--){
			int x; cin >> x;
			pq.pop();
			pq.push(x);
		}
		int res = 0;
		while (!pq.empty()){
			res += pq.top();
			pq.pop();
		}
		cout << res << "\n";
	}
	
	return 0;
}
