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
			cout << 1 << " ";
			for (int i = n/2+1; i >= 2; i--) cout << i << " " << i + n/2 << " ";
			cout << "\n";
		} else {
			for (int i = n/2; i >= 1; i--) cout << i << " " << i + n/2 << " ";
			cout << "\n";
		}
	}
	
	return 0;
}
