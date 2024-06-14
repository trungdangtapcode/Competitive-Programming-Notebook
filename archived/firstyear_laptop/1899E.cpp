#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	int idx = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i]<a[idx]) idx = i;
	}
	int res = 1;
	for (int i = idx; i < n; i++){
		if (a[i]>a[i+1]) res = 0;
	}
	cout << (res?idx-1:-1) << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
