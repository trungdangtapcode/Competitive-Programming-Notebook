#include<bits/stdc++.h>

using namespace std;
int a[2][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cin >> a[i][j];
		bool res = false;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++){
			res |= (a[i][j]>a[!i][j]&&a[i][j]>a[i][!j]&&a[!i][!j]<a[!i][j]&&a[!i][!j]<a[i][!j]);
		}
		cout << (res?"YES\n":"NO\n");
	}
	
	return 0;
}
