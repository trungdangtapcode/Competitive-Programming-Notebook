#include<bits/stdc++.h>

using namespace std;
int n, a[105];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >>  a[i];
	int res = 0;
	for (int j = n-1; j >= 1; j--){
		res = max(res,a[n]+a[j]);
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

