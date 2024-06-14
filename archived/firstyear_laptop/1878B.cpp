#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5;
int n;
void solve(){
	cin >> n;
	int a = 2, b = 3;
	cout << a << " " << b << " ";
	for (int i = 3; i <= n;i++ ){
		int c = b+1;
		while (3*c%(a+b)==0) c++; 
		cout << c << " ";
		a = b; b = c;
	}
	cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
