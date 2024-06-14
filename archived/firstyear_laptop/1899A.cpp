#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	cout << (n%3==0?"Second\n":"First\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
