#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;

bool check(int k){
	priority_queue<int> pq;
	for (int i = k-1; i < n; i++) pq.push(a[i]);
	for (int q = k; q >= 1; q--){
		if (pq.empty()) return false;
		while (!pq.empty()){
			int x = pq.top(); pq.pop();
			if (x<=q) break;
			if (pq.empty()) return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n,0);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(),a.end());
		int l = 1, h = n, m, res = 0;
		while (l<=h){
			m = (l+h)/2;
			if (check(m)){
				res = max(res,m);
				l = m+1;
			} else h = m-1;
		}
		cout << res << "\n";
	}
	
	return 0;
}
