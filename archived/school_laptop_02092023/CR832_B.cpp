#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		cout << (n+1)/2 << "\n";
		for (int i = 1; i <= 3*(n/2); i+=3){
			cout << i << " " << i+3*(n/2)+1 << "\n";
		}
		if (n%2) cout << 3*n-1 << " " << 3*n << "\n";
	}
	
	
	return 0;
}
