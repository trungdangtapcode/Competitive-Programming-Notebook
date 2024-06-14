#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], p[maxN], x, c[maxN];
void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		p[a[i]] = i;
		c[i] = 0;
	}
	if (x==1){
		cout << 1 << "\n" << 1 << " " << p[1] << "\n";
		return;
	}
	int l = 1, r = n+1, pos = -1, m;
	while (l < r-1){
		m = (l+r)/2;
		c[m] = 1;
//		cout << m << " " << a[m] << " " << x << "\n";
		if (a[m]==x) pos = m;
		if (a[m]<=x){
			l = m;
		} else r = m;
	}
	if (pos==-1||a[l]<=x) cout << 1 << "\n" << p[x] << " " << l << "\n";
	else {
		for (int i = 1; i <= n; i++) if (a[i]<x&&!c[i]){
			cout << 2 << "\n" << p[x] << " " << i << "\n" << i << " " << l << "\n";
			break;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

