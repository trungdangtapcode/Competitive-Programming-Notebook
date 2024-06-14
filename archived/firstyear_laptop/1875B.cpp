#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a ,b, m, k;

void solve(){
	long long res = 0, sum1 = 0, sum2 = 0, m1 = 2e9, m2 = 2e9, b1 = 0, b2 = 0;
	cin >> n >> m >> k;
	for (int i = 0, x; i < n; i++){
		cin  >> x;
		sum1 += x;
		b1 = max(b1,1ll*x);
		m1 = min(m1,1ll*x);
	}
	for (int i = 0, x; i < m; i++){
		cin >> x;
		sum2 += x; 
		b2 = max(b2,1ll*x);
		m2 = min(m2,1ll*x);
	}
	if (m1>b2){
		cout << (k%2?sum1:sum1-b1+m2) << "\n";
	} else if (m2>b1){
		cout << (k%2?sum1-m1+b2:sum1) << "\n";
	} else {
		int sum = sum1-m1+b2;
		cout << (k%2?sum:sum-max(b1,b2)+min(m1,m2)) << "\n";
	} 
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	
	return 0;
}
