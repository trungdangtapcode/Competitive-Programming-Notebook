#include<bits/stdc++.h>

using namespace std;
int n, m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 0, x, y; i < m; i++){
			cin >> x >> y;
		}
		cout << (m<n?"YES\n":"NO\n");
	}
	
	return 0;
}
