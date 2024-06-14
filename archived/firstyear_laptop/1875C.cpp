#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a ,b, m, k;

bool check(int x){
	while (x%2==0) x/= 2;
	return (x!=1);
}
int cnt(int x){
	int i = 0;
	while (x%2==0) x/= 2, i++;
	return i;
}

void solve(){
	cin >> n >> m;
	n %= m;
	int u = __gcd(n,m);
	n /= u;
	m /= u;
	long long res = 0;
	if (check(m)){
		cout << -1 << "\n";
		return;
	}
	int cc = cnt(m);
	for (int i = 0; i < 30; i++){
		bool c = (1ll<<i)&n;
		res += ((1ll<<(cc-i))-1)*c*(1ll<<i);
//		cout << res << "\n";
	}
	cout << res*u << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	
	return 0;
}
