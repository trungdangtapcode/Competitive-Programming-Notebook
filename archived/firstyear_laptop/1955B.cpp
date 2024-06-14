#include<bits/stdc++.h>

using namespace std;
int n, c, d, a[500005];
void solve(){
	multiset<int> ms;
	cin >> n >> c >> d;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ms.insert(i*c+j*d);
	for (int i = 1; i <= n*n; i++) cin >> a[i];
	sort(a+1,a+n*n+1);
	for (int i = 2; i <= n*n; i++) a[i] -= a[1];
	a[1] = 0;
	for (int i = 1; i <= n*n; i++){
//		cout << a[i] << "\n";
		if (ms.find(a[i])==ms.end()){
//			cout << a[i] << "\n";
			cout << "NO\n";
			return;
		} else ms.erase(ms.find(a[i]));
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

