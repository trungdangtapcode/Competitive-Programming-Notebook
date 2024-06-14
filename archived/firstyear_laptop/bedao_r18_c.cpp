#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
typedef pair<int,int> ii;
int n;
ii a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	for (int i = 1; i <= n; i++) cin >> a[i].second;
	sort(a+1,a+n+1);
	priority_queue<int> pq;
	long long res = 0;
	for (int t = n, p = n; t >= 1; t--){
		while (p>0&&a[p].first>=t) pq.push(a[p].second), p--;
		if (pq.size()){
			res += pq.top();
			pq.pop();
		}
	}
	cout << res << "\n";
}

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

