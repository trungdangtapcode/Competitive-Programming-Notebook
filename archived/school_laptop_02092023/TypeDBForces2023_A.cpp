#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		if (n%2){
			cout << -1 << "\n";
			continue;
		}
		cout << 1 << " " << n/2 << "\n";
	}
	
	return 0;
}
