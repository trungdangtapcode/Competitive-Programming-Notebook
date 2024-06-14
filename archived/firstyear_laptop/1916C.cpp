#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, n, sum, odd;
void solve(){
	cin >> n;
	sum = 0;
	odd = 0;
	for (int i = 1; i <= n; i++){
		cin >> a;
		sum += a;
		odd += a%2;
//		int even = i-a;
//		int x = (i+1)/2, y = i/2;
		int tmp = (odd)/3+(odd%3==1);
		if (i==1) tmp = 0;
//		if (even<=1) ;
//		if (i==2&&odd==1) tmp = 1;
		cout << sum-tmp << " ";
	}
	cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
