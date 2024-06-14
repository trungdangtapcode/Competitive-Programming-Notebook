#include<bits/stdc++.h>

using namespace std;
#define int long long
void solve(){
	int n = 1, k, c; cin >> k;
	for (int i = 0; i < k; i++){
		int a;
		cin >> a;
		if (n<=1e19/a) n*= a;
		else {
			n = 1000000000000000001l;
		}
	}
//	long long tmp =1000000000000000001l;
//	cout << tmp << "\n";
	cin >> c;
	for (int i =0; i <= 1e6; i++) if (i*i*i%n==c){
		cout << i << "\n";
		return;
	}
	
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
//	int t; cin >> t;
//	while (t--)
	solve();
}

