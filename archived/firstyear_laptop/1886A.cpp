#include<bits/stdc++.h>

using namespace std;
int n, t;
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		if ((n-3)<=2||(n-3)%3==0&&(n-5)<=4){
			cout << "NO\n";
		} else {
			cout << "YES\n";
			if ((n-3)%3){
				cout << 1 << " " << 2 << " " << n-3 << "\n";
			} else {
				cout << 1 << " " << 4 << " " << n-5 << "\n";
			}
		}
	}
	
	return 0;
}
