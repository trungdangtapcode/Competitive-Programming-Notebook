#include<bits/stdc++.h>

using namespace std;
int n, mmin = 1e9;
vector<int> a;
priority_queue<int> pq[2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n,0);
		pq[0] = pq[1] = priority_queue<int>();
		mmin = 1e9;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0, x; i < n; i++){
			cin >> x;
			pq[a[i]].push(x);
			mmin = min(mmin,x);
		}
		long long int res = 0;
		if (pq[0].size()==pq[1].size()) res -= mmin;
		while (!pq[0].empty()&&!pq[1].empty()) res += 2ll*pq[0].top()+2ll*pq[1].top(), pq[0].pop(), pq[1].pop();
		while (!pq[0].empty()) res += pq[0].top(), pq[0].pop();
		while (!pq[1].empty()) res += pq[1].top(), pq[1].pop();
		cout << res << "\n";
	}
	return 0;
}
