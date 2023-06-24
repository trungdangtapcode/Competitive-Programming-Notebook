#include<bits/stdc++.h>

using namespace std;
int a[4], b[4]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		for (int i = 0; i < 3; i++) cin >> a[i] >> b[i];
		sort(a,a+3);
		sort(b,b+3);
		cout << (a[0]<a[1]&&a[1]<a[2]||b[0]<b[1]&&b[1]<b[2]?"YES\n":"NO\n");
	}
		
	
	return 0;
}
