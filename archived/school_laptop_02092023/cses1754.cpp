#include<bits/stdc++.h>

using namespace std;
int a, b;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> a >> b;
		cout << (2*a>=b&&2*b>=a&&(2*a-b)%3==0&&(2*b-a)%3==0?"YES\n":"NO\n");
	}
	return 0;
}
