#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m, q, k;
ii a[30005], b[100005], c[30005];

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> a[i].second;
	for (int i = 0; i < m; i++) cin >> b[i].first;
	for (int i = 0; i < m; i++) cin >> b[i].second;
	sort(a,a+n);
	
//	q = 1;
	while (q--){
		cin >> k;
		for (int i = 0; i < n; i++) c[i] = b[i+k-1];
		sort(c,c+n);
		multiset<int> ms;
		int res = 0;
		for (int i = 0, j = 0; i < n; i++){
			while (j<n&&c[j].first<a[i].first) ms.insert(c[j++].second);
			if (ms.empty()||*ms.begin()>=a[i].second) continue;	
			auto it  = ms.lower_bound(a[i].second);
			it--; res++; ms.erase(it);
		}
		cout << res << '\n';
	}
	
	return 0;
}
