#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, k;
void solve(){
	cin >> n >> k;
	int x = n-k+1;
	if (k==n){
		cout << "YES\n1\n1\n";
		return;
	}
	if (k>n){
		cout << "NO\n";
		return;
	}
	if (n/x>1){
		cout << "NO\n";
	} else {
		cout << "YES\n2\n" << x << " " << 1 << "\n";
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}
//base, math, greedy, trick
//https://codeforces.com/contest/1951/submission/255884425
//	if (2*k>n){
//		cout << 2*k;
//		cout << "NO\n";
//	}
//	else if (2*k==n){
//		cout << "YES\n1\n2\n";
//	} 
//	else {
//		cout << "YES\n2\n" << n-k+1 << " " << 1 << "\n" ;		
//	}

