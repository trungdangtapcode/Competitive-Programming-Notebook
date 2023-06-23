#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		long long p = 1;
		for (int i = 0, a; i < n; i++){
			cin >> a;
			p *= a;
		}
		cout << (p+n-1)*2022 << "\n";
	}
	
	return 0;
}
