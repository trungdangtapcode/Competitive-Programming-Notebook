#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 2; i < n; i++){
		int tmp = a[i-1];
		a[i] -= 2*tmp;
		a[i+1] -= tmp;
		if (a[i]<0||a[i+1]<0){
			cout << "NO\n";
			return;
		}
	}
	cout << (a[n]==0&&a[n-1]==0?"YES\n":"NO\n");
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

