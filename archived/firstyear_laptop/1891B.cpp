#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int a[maxN], n, q, cnt[35];
void solve(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int mn = 1e9;
	deque<int> d;
	for (int i = 1; i <= q; i++){
		int x;
		cin >> x;
//		while (d.size()&&d.back()) d.pop_back();
		if (d.empty()||d.back()>x) d.push_back(x);
	}
	int m = d.size();
	for (int i = 1; i <= m; i++) cnt[i] = d.front(), d.pop_front();
	for (int i = 1; i <= n; i++){
		int cur = 0;
		while (a[i]%2==0) cur++, a[i] /= 2;
		a[i] *= (1<<cur);
		for (int j = 1; j <= m; j++){
			if (cnt[j]<=cur) a[i] += (1<<(cnt[j]-1));
		}
	}
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	solve();
	return 0;
}
