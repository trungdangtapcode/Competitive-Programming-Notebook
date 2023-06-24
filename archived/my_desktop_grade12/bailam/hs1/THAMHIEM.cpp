#include <bits/stdc++.h>

using namespace std;

int n, L, P;
vector<pair<int,int>> a;

int main(){
	freopen("THAMHIEM.INP","r",stdin);
	freopen("THAMHIEM.OUT","w",stdout);
	
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n+5,pair<int,int>());
		for (int i = 1; i <= n; i++){
			cin >> a[i].first >> a[i].second;
		}
		cin >> L >> P;
		L -= P; 
		priority_queue<int> pq; 
		int j = n, res = 0;
		while (L > 0){
			while (j>0&&a[j].first>=L) pq.push(a[j--].second);
			if (pq.empty()) {
				res = -1;
				break;
			}
			L -= pq.top();
			pq.pop();
			res++;
		}
		cout << res << '\n';
	}
	
	return 0;
}
