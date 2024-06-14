#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5+5;
int a[maxN], n;

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int p[] = {1,2,n-1,n};
	int ans = 0;
	do {
		int res = 0;
		for (int i = 1; i <= 4; i++) res += abs(a[p[i%4]]-a[p[i-1]]);
		ans = max(ans,res);
	} while (next_permutation(p,p+4));
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
