#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		cout << 1 << " ";
		for (int i = n; i >= 2; i--) cout << i << " ";
		cout << "\n";
	}
	return 0;
}
