#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >>t;
	while (t--){
		cin >> n;
		if (n&1) {
			for (int i = 1; i <= n; i++) cout << "27052005 ";
		} else {
			cout << "5 15 ";
			for (int i = 1; i <= n; i++) cout << "10 ";
		}
		cout << "\n";
	}
	
	
	return 0;
}
