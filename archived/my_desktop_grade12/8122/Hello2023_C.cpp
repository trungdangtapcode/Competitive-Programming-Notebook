#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, m, a[200005], pref[200005];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) pref[i] = a[i] + pref[i-1];
		priority_queue<int> pq;
		int res = 0;
		int curr = pref[m];
		for (int i = m; i >= 1; i--){
			int tmp = pref[i];
			while (tmp<curr){
				curr -= 2*pq.top();
				pq.pop();
				res++;
			}
			if (a[i]>0) pq.push(a[i]);
		}
		while (pq.size()) pq.pop();
		curr = pref[m];
		for (int i = m+1; i <= n; i++){
			if (a[i]<0) pq.push(-a[i]);
			int tmp = pref[i];
			while (tmp<curr){
				curr -= 2*pq.top();
				pq.pop();
				res++;
			}
	//		cout << curr << " " << tmp << " " << res << endl;
		}
		cout << res << "\n";
	}
	
	
	return 0;
}
