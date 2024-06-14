#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, m, a[maxN], b[maxN];
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	deque<int> d;
	for (int i = 1; i <= m; i++){
//		while (d.size()&&d.back()<=b[i]) d.pop_back();
//		d.push_back(b[i]);
		if (d.empty()||d.back()>b[i]) d.push_back(b[i]);
	}
	m = 0;
	while (d.size()){
		b[++m] = -d.front();
		d.pop_front();
	}
	for (int i = 1; i <= m; i++) cout << -b[i] << " "; cout << "\n";
	for (int i = 1; i <= n; i++){
		int cur = a[i], p = 0;
		cur %= b[1];
		while (-cur<=b[m]){ //cur >= b[i], -cur <= -b[i]
			int np = lower_bound(b+1,b+m+1,-cur)-b;
			cur %= b[np];
		}
		cout << cur << " ";
	} 
	
	return 0;
}
