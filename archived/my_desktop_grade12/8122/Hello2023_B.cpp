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
			if (n==3) cout << "NO\n";
			else {
				cout << "YES\n";
				for (int i = 1; i <= n; i++){
					if (i%2) cout << n/2-1 << " ";
					else cout << -n/2 << " ";
				}		
			}
			continue;
		}
		cout << "YES\n";
		for (int i = 1; i <= n; i++){
			if (i%2) cout << "1 ";
			else cout << "-1 ";
		}
		cout << "\n";
	}
	
}
