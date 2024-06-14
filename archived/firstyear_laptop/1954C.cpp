#include<bits/stdc++.h>

using namespace std;
string x, y;
void solve(){
	cin >> x >> y;
	int n = x.length();
	for (int i = 0, c = 0; i < n; i++){
		if (x[i]==y[i]) continue;
		if (x[i]>y[i]&&c) swap(x[i],y[i]);
		if (x[i]<y[i]&&!c) swap(x[i],y[i]);
		c = 1;
	}
	cout << x << "\n" << y << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

