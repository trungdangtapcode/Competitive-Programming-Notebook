#include <bits/stdc++.h>

using namespace std;
int n, m, k, a[50005], b[50005];
typedef pair<int,pair<int,int>> iii;
priority_queue<iii,vector<iii>,greater<iii>> pq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a,a+n); sort(b,b+m);
	for (int i = 0; i < n; i++) pq.push({a[i]+b[0],{i,0}});
	for (int i = 0; i < k; i++){
		auto x = pq.top(); pq.pop();
		cout << x.first <<'\n';
		if (x.second.second<m-1){ //den thanh phan cuoi cung thoi nghi
			x.second.second++;
			x.first = a[x.second.first] + b[x.second.second];
			pq.push(x);
		}
	}
	
	return 0;
}
