#include <bits/stdc++.h>

using namespace std;
int a, b, c;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> a >> b >> c;
		cout << (a==b+c||b==a+c||c==b+a?"YES\n":"NO\n");
	}
	
	return 0;
}
