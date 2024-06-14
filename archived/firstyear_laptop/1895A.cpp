#include<bits/stdc++.h>

using namespace std;
int x, y, k;
void solve(){
	cin >> x >> y >> k;
	if (y<x){
		cout << x << "\n";
	} else {
		int tmp = y-x;
		cout << y + max(tmp-k,0) << "\n";
	}
}

int main(){
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
