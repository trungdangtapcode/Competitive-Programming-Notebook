#include<bits/stdc++.h>

using namespace std;
long long n;
const int p = 1e9+7;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		long long res = 1;
		for (int i = 2; i <= n; i++) res = res*i%p;
		res = res*n%p*(n-1)%p;
		cout << res << "\n";
	}
	
	
	return 0;
}
