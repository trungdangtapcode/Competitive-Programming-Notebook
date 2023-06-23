#include<bits/stdc++.h>

using namespace std;
int n;
int cur;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		cin >> cur;
		for (int i = 1, a; i < n; i++){
			cin >> a;
			cur = __gcd(cur,a);
		}
		if (cur==1){
			cout << 0 << "\n";
			continue;
		} else if (__gcd(n,cur)==1){
			cout << 1 << "\n";
		} else if (__gcd(n-1,cur)==1){
			cout << 2 << "\n";
		} else {
			cout << 3 << "\n";
		}
	}
	return 0;
}
