#include<bits/stdc++.h>

using namespace std;
#define int long long
int n;
bool check(int x){
	for (int i = 2; 1ll*i*i <= x; i++) if (x%i==0) return false;
	return true;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		cout << n-1 << "\n";
	}
	return 0;
}
