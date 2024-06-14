#include<bits/stdc++.h>

using namespace std;
int m, b;
void solve(){
	cin >> m >> b;
	long long res = 0;
	for (int i = 0; i <= b; i++){
		int x = i*m, y = -i+b;
		long long s = 1ll*(x+1)*(y+1)*y/2 + 1ll*(y+1)*(x+1)*x/2;
		res = max(res,s);
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

