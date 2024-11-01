#include<bits/stdc++.h>

using namespace std;
long long n;
void solve(){
	cin >> n;
	long long x = sqrt(n);
	if (x*x!=n||x%4){
		cout << "0\n";
		return;
	}
	x /= 4;
	long long res = 1;
	for (int i = 2; i*i <= x; i++){
		if (x%i) continue;
		int cnt = 1;
		while (x%i==0) cnt++, x /= i;
		res *= cnt;
	}
	if (x!=1) res *= 2;
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

