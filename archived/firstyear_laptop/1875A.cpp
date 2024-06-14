#include<bits/stdc++.h>

using namespace std;
int n, a ,b;

void solve(){
	long long res = 0;
	cin >> a >> b >> n;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		res += min(x,a-1);
	}
	res += b;
	cout << res <<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	
	return 0;
}
